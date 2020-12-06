#include<stdio.h>
#include "myBank.h"


float accounts[50][3];

void Boot(){
	for(int i=0; i<50; i++){
		accounts[i][0]=(float)901+i;
      		accounts[i][1]=0;
   		accounts[i][2]=0;
	}
}
      
float NewAccount (float amount){
	int acCount = 0;
	while(amount != -1 && acCount <= 49){
		if(accounts[acCount][1] == 0){
			accounts[acCount][2] = amount;
			accounts[acCount][1] = 1;
			amount = -1;
		}
		acCount++;
	}
	if(amount != -1)
		return -1;
	else
		return (float)(acCount + 900);
}



float Amount (float account){
if(account>=901 && account <=950){
	if(accounts[(int)account - 901][1] == 1)
		return accounts[(int)account - 901][2];
	}
return -1;
}




float Deposit (float account,float amount){
if(account>=900 && account <=950 && amount > 0)
	if(accounts[(int)account - 901][1] == 1){
		accounts[(int)account-901][2]+=amount;
		return accounts[(int)account-901][2];
		}
return -1;
}



float Withdraw(float account,float amount){
if(account>=900 && account <=950){
	if(accounts[(int)account - 901][1] == 1)
		if(accounts[(int)account-901][2]-amount >=0){
			accounts[(int)account-901][2]-=amount;
			return accounts[(int)account-901][2];
		}
	}
	return -1;
}

void Close(float account){
if(account<= 900 || account >950)
	printf("unvalid account number");
else
	if(accounts[(int)account - 901][1] == 1)
		accounts[(int)account - 901][1] = 0;
}

void Interest(float intrest){
float temp;
if(intrest>0)
	for(int i=0; i<50; i++){
		temp=accounts[i][2];
		accounts[i][2]=temp*(1+(0.01*intrest));
	}
	
}

void Print(){
int i;
for(i=0; i<50; i++)
	if( accounts[i][1] == 1)
		printf("\n The balance of account number %lf is %.2lf \n ",accounts[i][0], accounts[i][2]);
}

void Exit(){
int i;
for(i=0; i<50; i++)
	accounts[i][1]=0;
}

