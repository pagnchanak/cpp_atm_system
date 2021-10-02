/* AUTOMATIC TELLER MACHINE (ATM) SYSTEM
 * OBJECT-ORIENTED PROGRAMMING USING C++
 * FINAL PROJECT
 * AUTHOR: PAGNCHANAK CHEA
 * GROUP: PT-SD-12
 * COPYRIGHT 2021
 */

#ifndef PIN_H
#define PIN_H

#include <iostream>
#include <fstream>

using namespace std;

class Pin{
private:
    int code;
    bool auth;

public:
    //constructors
    Pin():code(0),auth(false){}
    Pin(int code, bool auth):code(code),auth(auth){}
    
    //setter and getter methods
    int getPin(){
        return this->code;
    }

    void setPin(int code){
        this->code=code;
    }

    int getAuth(){
        return this->auth;
    }

    void setAuth(bool auth){
        this->auth=auth;
    }
    
    //data methods
    void inputPin(){
        cout<<"Enter PIN(4-DIGIT): ";
        cin>>code;
        if(code<=0 || code>9999){
            cout<<"Invalid PIN, please enter 4 digits code only: ";
            cin>>code;
        }
    }

    void resetPin(){
        ofstream fout;
        fout.open("pin.bin", ios::out | ios::binary);
        fout.write((char*)&code, sizeof(code));
        fout.close();
        cout<<"\nPIN has been set successfully!"<<endl;
    }
    
    void login(){
        int correctPin;
        ifstream fin;
        fin.open("pin.bin", ios::in | ios::binary);
        fin.read((char*)&correctPin,sizeof(correctPin));
        if(code == correctPin){
            auth=true;
        }else{
            auth=false;
        }
        fin.close();
    }

    bool firstLogin(){
        ifstream fin;
        fin.open("pin.bin", ios::in | ios::binary);
        if(!fin){
            return true;
        }
        return false;
    }
};

#endif
