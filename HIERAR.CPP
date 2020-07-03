#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<dos.h>
class Account{
protected:
	double balance;
	int accountNumber;
	char name[20];
public:
	void getdata()
	{
	cout<<"Enter account number ";
	cin>>accountNumber;
	cout<<"Enter your name ";
	cin>>name;
	cout<<"Enter balance in the account ";
	cin>>balance;
	}
	virtual void withdraw(double amount) = 0;
	void deposite(int amount)
	{
	balance = balance + amount;
	cout<<"\n\tDeposit successfull"<<endl;
	}
	void show()
	{
	cout<<"\n\tName of the Account Holder :"<<name;
	cout<<"\n\tBalance : "<<balance;
	}
};
class Savings : public Account
{
	public:
	  void withdraw(double amount)
	  {
	  if(balance-amount<500)
	  cout<<"\nInsufficient Balance : You can't withdraw";
	  else
	  balance = balance-amount;
	  cout<<"\nWithdraw Successfull"<<endl;
	  }
};
class Current : public Account
{
double limit;
   public:
     void withdraw(double amount)
     {
	cout<<"\nEnter your credit limit ";
	cin>>limit;
	if(balance-amount<limit)
	cout<<"\nYou can't withdraw : credit limit reached";
	else
	{
	balance=balance-amount;
	cout<<"\n\tWithdraw Successfull"<<endl;
	}
     }
};
void main()
{
int type,choice,amount;
clrscr();
	cout<<"\n 1 : Saving \n 2 : Current "<<endl;
	cout<<"Enter type of account : ";
	cin>>type;
  Account *account;
	if(type==1)
account = new Savings();
	else if(type==2)
account = new Current();
	else
	{
cout<<"\nInvalid type of account : Please try again\n";
delay(1000);
getch();
exit(0);
	}
account->getdata();
	cout<<"\n 1 : Deposite\n 2 : Withdraw"<<endl;
	cout<<"Enter your choice : ";
	cin>>choice;
	cout<<"Enter amount ";
	cin>>amount;
   if(choice==1)
account->deposite(amount);
   else if(choice==2)
account->withdraw(amount);
  getch();
  clrscr();
account->show();
  getch();
}