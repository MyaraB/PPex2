#ifndef _MYBANK_H
#define _MYBANK_H
float NewAccount (float amount);
float Amount (float account);
float Deposit (float account,float amount);
float Withdraw(float account,float amount);
void Close(float account);
void Interest(float intrest);
void Print();
void Exit();
void Boot();
#endif
