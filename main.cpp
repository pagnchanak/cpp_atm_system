/* AUTOMATIC TELLER MACHINE (ATM) SYSTEM
 * OBJECT-ORIENTED PROGRAMMING USING C++
 * FINAL PROJECT
 * AUTHOR: PAGNCHANAK CHEA
 * GROUP: PT-SD-12
 * COPYRIGHT 2021
 */

#include <iostream>
#include "logo.cpp"
#include "Pin.cpp"
#include "Account.cpp"
#include "Statement.cpp"
#include "AccountService.cpp"

using namespace std;

enum {
    LOGIN=1,
    EXIT
};

enum{
    INQUIRY=1,
    DEPOSIT,
    WITHDRAWAL,
    VIEW_STATEMENT,
    RESET_PIN,
    RESET_ACCOUNT,
    QUIT
};

void subMenu(){
    int option;
    Pin pin;
    Account account;
    Statement statement;
    AccountService accountService;

    do{
        system("cls");

        if(accountService.firstLogin()==true){
            cout<<"First time login, please enter your account information."<<endl<<endl;
            accountService.setAccountInfo();
            system("PAUSE");
        }
        else{
            cout<<"===== ACCOUNT MANAGEMENT ====="<<endl;
            cout<<"1. BALANCE INQUIRY"<<endl;
            cout<<"2. DEPOSIT"<<endl;
            cout<<"3. WITHDRAWAL"<<endl;
            cout<<"4. VIEW STATEMENT"<<endl;
            cout<<"5. RESET PIN"<<endl;
            cout<<"6. RESET ACCOUNT"<<endl;
            cout<<"7. EXIT"<<endl;
            cout<<"=============================="<<endl;
            cout<<"ENTER YOUR CHOICE: ";
            cin>>option;

            switch(option){
                case INQUIRY:
                    system("cls");
                    accountService.balanceInquiry();
                    system("PAUSE");
                    break;

                case DEPOSIT:
                    system("cls");
                    accountService.depositToAccount();
                    system("PAUSE");
                    break;

                case WITHDRAWAL:
                    system("cls");
                    accountService.withdrawFromAccount();
                    system("PAUSE");
                    break;

                case VIEW_STATEMENT:
                    system("cls");
                    accountService.displayStatement();
                    system("PAUSE");
                    break;
                
                case RESET_PIN:
                    system("cls");
                    cout<<"===== CURRENT PIN ====="<<endl;
                    pin.inputPin();
                    pin.login();
                    if(pin.getAuth()==true){
                        system("cls");
                        cout<<"===== NEW PIN ====="<<endl;
                        pin.inputPin();
                        pin.resetPin();
                        system("PAUSE");
                    }
                    else{
                        cout<<"\nInvalid PIN!"<<endl;
                        system("PAUSE");
                    }
                    break;
                
                case RESET_ACCOUNT:
                    system("cls");
                    char ch;
                    cout<<"WARNING!!! ALL YOUR TRANSACTION HISTORY WILL BE DELETED."<<endl;
                    cout<<"CONTINUE? (Y/N): ";
                    cin>>ch;
                    if(ch == 'Y' || ch == 'y'){
                        cout<<endl;
                        remove("account.bin");
                        remove("entries.bin");
                        accountService.setAccountInfo();
                        system("PAUSE");
                    }
                    else{
                        cout<<endl;
                        system("PAUSE");
                    }
                    break;

                case QUIT:
                    exit(0);
            }
        }
    }
    while (option!=QUIT);
};

void mainMenu(){
    int option;
    Pin pin;

    do{
        system("cls");
        cout<<"===== ATM LOGIN ====="<<endl;
        cout<<"1. LOGIN"<<endl;
        cout<<"2. EXIT"<<endl;
        cout<<"====================="<<endl;
        cout<<"\nENTER YOUR CHOICE: ";
        cin>>option;
        
        switch(option){
            case LOGIN:
                system("cls");
                if(pin.firstLogin()==true){
                    cout<<"First time login, please set new PIN."<<endl<<endl;
                    pin.inputPin();
                    pin.resetPin();
                    system("PAUSE");
                }
                else{
                    pin.inputPin();
                    pin.login();
                    if(pin.getAuth()==true){
                        subMenu();
                    }
                    else{
                        cout<<"\nInvalid PIN!"<<endl;
                        system("PAUSE");
                    }
                }
                break;

            case EXIT:
                exit(0);
        }
    }
    while (option!=EXIT);
};

int main() {
    displayLogo();
    mainMenu();
}