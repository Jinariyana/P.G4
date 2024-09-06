#pragma once
#include"BankingServiceImp.h"
#include"BankingService.h"
//ubstruction class 


int main(){
    BankingService *bank= new BankingServiceImpl;
    bank->deposite(1);
    bank->withdraw(50);
    bank->getBalance();
    return 0;
}