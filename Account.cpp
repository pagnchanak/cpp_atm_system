/* AUTOMATIC TELLER MACHINE (ATM) SYSTEM
 * OBJECT-ORIENTED PROGRAMMING USING C++
 * FINAL PROJECT
 * AUTHOR: PAGNCHANAK CHEA
 * GROUP: PT-SD-12
 * COPYRIGHT 2021
 */

#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>

using namespace std;

class Account{
private:
    int number;
    string name;
    double balance;

public:
    Account():number(0), name("Unknown"), balance(0){}
    Account(int number, string name, double balance):number(number), name(name), balance(balance){}

    //setter and getter methods
    int getAccountNumber(){
        return number;
    }

    void setAccountNumber(int number){
        this->number=number;
    }

    string getName(){
        return name;
    }

    void setName(string name){
        this->name=name;
    }

    double getBalance(){
        return balance;
    }

    void setBalance(double balance){
        this->balance=balance;
    }

    void getData(){
        cout<<"ENTER ACCOUNT NUMBER : ";
        cin>>number;
        cout<<"ENTER ACCOUNT NAME   : ";
        cin>>name;
        cout<<"ENTER BALANCE        : ";
        cin>>balance;
    }

    void displayData(){
        cout<<"ACCOUNT NUMBER  : "<<number<<endl;
        //cout<<"ACCOUNT NAME    : "<<name<<endl;
        cout<<"INITIAL BALANCE : "<<balance<<endl;
    }

    void showBalance(){
        cout<<"CURRENT BALANCE: "<<balance<<endl<<endl;
    }
};

#endif
