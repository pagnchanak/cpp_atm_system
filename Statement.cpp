/* AUTOMATIC TELLER MACHINE (ATM) SYSTEM
 * OBJECT-ORIENTED PROGRAMMING USING C++
 * FINAL PROJECT
 * AUTHOR: PAGNCHANAK CHEA
 * GROUP: PT-SD-12
 * COPYRIGHT 2021
 */

#ifndef STATEMENT_H
#define STATEMENT_H

#include <iostream>

using namespace std;

class Statement{
private:
    double deposit;
    double withdrawal;
    double balance;

public:
    Statement():deposit(0), withdrawal(0), balance(0){}
    Statement(double deposit, double withdrawal, double balance):deposit(deposit), withdrawal(withdrawal), balance(balance){}

    double getDeposit(){
        return deposit;
    }

    void setDeposit(double deposit){
        this->deposit=deposit;
    }

    double getWithdrawal(){
        return withdrawal;
    }

    void setWithdrawal(double withdrawal){
        this->withdrawal=withdrawal;
    }

    double getBalance(){
        return balance;
    }

    void setBalance(double balance){
        this->balance=balance;
    }

    void inputDeposit(){
        cout<<"ENTER AMOUNT TO DEPOSIT: ";
        cin>>deposit;
    }

    void inputWithdrawal(){
        cout<<"ENTER AMOUNT TO WITHDRAW: ";
        cin>>withdrawal;
    }

    void showBalance(){
        cout<<"CURRENT BALANCE: "<<balance<<endl<<endl;
    }

    void displayData(){
        cout<<deposit<<"\t\t"<<withdrawal<<"\t\t\t"<<balance<<endl;
    }
};

#endif