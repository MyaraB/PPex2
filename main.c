#include<stdio.h>
#include "myBank.h"

int main(void){
float amount;
float account;
	Boot();
	char transaction = 'A';
	while(transaction != 'E'){
	printf("Please choose a transaction type: \n O-Open Account \n B-Balance Inquiry \n  D-Deposit \n  W-Withdrawal \n C-Close Account \n I-Interest \n P-Print \n  E-Exit \n");
	scanf("%c" , &transaction);
	switch(transaction)
	{
		case 'O':
			printf("Please enter amount for deposit: ");
			
			scanf("%f", &amount);
			account = NewAccount(amount);
			if(account == -1)
				printf("No available accounts right now");
			else
				printf("New account number is: %f",account);
			break;
		case 'B':
			printf("Please enter account number: ");
			
			scanf("%f", &account);
			amount = Amount(account);
			if(amount == -1)
				printf("unvalid account number");
			else 
				printf("The balance of account number %f.0 is: %f.2",account,amount);
			break;
		case 'D' :
			printf("Please enter account number:");

			scanf("%f", &account);
			printf("\n Please enter amount to deposit:");
			scanf("%f", &amount);
			float deposited = Deposit(account,amount);
			if(deposited == -1)
				printf("Failed to read the account number");
			else 
				printf("The balance of account number %.0f is: %.2f",account,deposited);
			break;
		case 'W' :
			printf("Please enter account number:");
			scanf("%f", &account);
			printf("\n Please enter amount to withdraw:");
			scanf("%f", &amount);
			float withdrawed = Withdraw(account,amount);
			if(withdrawed == -1)
				printf("insufficient funds");
			else 
				printf("The balance of account number %.0f is: %.2f",account,withdrawed);
			break;
		case 'C' :
			printf("Please enter account number:");
			scanf("%f", &account);
			Close(account);
			break;
		case 'I':
			printf("Please enter the precentage of interest");
			float interest;
			scanf("%f", &interest);
			Interest(interest);
			break;
		case 'P':
			Print();
			break;
		case 'E':
			Exit();
			break;
		default:
			printf("unvalid request");

	}
	printf("\n \n");
	}
	return 0;
}
