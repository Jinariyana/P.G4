#pragma once
#include"BankingService.h"
#include<iostream>
using namespace std;

double globalCash=0.0;
class BankingServiceImpl: public BankingService{
    public:

      void deposite(double cash) override{
          bool isLessOrEqualZero=(cash<0 || cash==0) ? true:false;
     if(isLessOrEqualZero){
        cout<<"Please Enter a Positive value. "<<endl;
     }else{
        globalCash+=cash;
        cout<<"Deposite Successfully. "<<endl;
        cout<<"Your Balance : "<<globalCash<<"$"<<endl;
    }
    }

     void withdraw(double cash) override{
        if(cash>globalCash){//valude dl bonjo thom jeang luy in kong
          cout<<"Cannot Withdraw: "<<cash<<"$ "<<endl;
        }else{
            globalCash-=cash;
            cout<<" You Withdraw Success. "<<endl;
            cout<<" Remaining balance: "<<globalCash<<"$ "<<endl;
        }
    }
     void getBalance() override{
        cout<<"Balance: "<<globalCash<<endl;
    }
};