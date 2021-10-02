/* AUTOMATIC TELLER MACHINE (ATM) SYSTEM
 * OBJECT-ORIENTED PROGRAMMING USING C++
 * FINAL PROJECT
 * AUTHOR: PAGNCHANAK CHEA
 * GROUP: PT-SD-12
 * COPYRIGHT 2021
 */

#ifndef ACCOUNTSERVICE_H
#define ACCOUNTSERVICE_H

#include <iostream>
#include <fstream>
#include <string>
#include "Account.cpp"
#include "Statement.cpp"

using namespace std;

class AccountService{
private:
    Account account;
    Statement statement;

public:
    bool firstLogin(){
        ifstream fin;
        fin.open("account.bin", ios::in | ios::binary);
        if(!fin){
            return true;
        }
        else{
            fin.close();
        }
        return false;
    }

    void setAccountInfo(){
        account.getData();
        ofstream fout;
        fout.open("account.bin", ios::out | ios::binary | ios::app);
        fout.write((char*)&account, sizeof(account));
        fout.close();

        statement.setDeposit(0);
        statement.setWithdrawal(0);
        statement.setBalance(account.getBalance());
        fout.open("entries.bin", ios::out | ios::binary | ios::app);
        fout.write((char*)&statement, sizeof(statement));
        fout.close();
        cout<<"\nAccount info has been set successfully!"<<endl;
    }

    void balanceInquiry(){
        ifstream fin;
        fin.open("entries.bin", ios::in | ios::binary | ios::app);
        fin.seekg(-1,ios::end);
        fin.read((char*)&statement, sizeof(statement));
        statement.showBalance();
        fin.close();
    }

    void depositToAccount(){
        double openingBalance;
        double endingBalance;
        
        ifstream fin;
        fin.open("entries.bin", ios::in | ios::binary | ios::app);
        fin.seekg(-1,ios::end);
        fin.read((char*)&statement, sizeof(statement));
        openingBalance = statement.getBalance();
        statement.inputDeposit();
        statement.setWithdrawal(0);
        endingBalance = openingBalance + statement.getDeposit() - statement.getWithdrawal();
        statement.setBalance(endingBalance);
        
        ofstream fout;
        fout.open("entries.bin", ios::out | ios::binary | ios::app);
        fout.write((char*)&statement, sizeof(statement));
        fin.close();
        fout.close();

        cout<<"\nTransaction successfully recorded!"<<endl;
    }

    void withdrawFromAccount(){
        double openingBalance;
        double endingBalance;

        ifstream fin;
        fin.open("entries.bin", ios::in | ios::binary | ios::app);
        fin.seekg(-1,ios::end);
        fin.read((char*)&statement, sizeof(statement));
        openingBalance = statement.getBalance();
        statement.setDeposit(0);
        statement.inputWithdrawal();
        endingBalance = openingBalance + statement.getDeposit() - statement.getWithdrawal();
        statement.setBalance(endingBalance);
        
        ofstream fout;
        fout.open("entries.bin", ios::out | ios::binary | ios::app);
        fout.write((char*)&statement, sizeof(statement));
        fin.close();
        fout.close();

        cout<<"\nTransaction successfully recorded!"<<endl;
    }

    void displayStatement(){
        ifstream fin;

        cout<<"==================== ACCOUNT STATEMENT ===================="<<endl;
        fin.open("account.bin", ios::in | ios::binary | ios::app);
        while(fin.read((char*)&account, sizeof(account))){
            account.displayData();
        }
        fin.close();

        cout<<"\n=================== TRANSACTION HISTORY ==================="<<endl;
        cout<<"DEPOSIT\t\tWITHDRAWAL\t\tENDING BALANCE"<<endl;
        fin.open("entries.bin", ios::in | ios::binary | ios::app);
        while(fin.read((char*)&statement, sizeof(statement))){
            statement.displayData();
        }
        fin.close();
        cout<<"\n=========================== END ==========================="<<endl<<endl;
    }
};

#endif