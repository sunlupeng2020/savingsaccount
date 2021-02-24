/*4-9.cpp
*综合实例——个人银行账户管理程序
*一个人可以有多个活期储蓄账户，一个活期储蓄账户包括账号(id)、余额(balance)、
*年利率(rate)等信息，还包括显示账号信息(show)、取款(withdraw)、结算利息(settle)
*等操作。
刘莉,董源,何江舟.C++语言程序设计,北京：清华大学出版社，2010,133.
*/
#include<account.h>
#include<iostream>
#include<cmath>
using namespace std;

double SavingsAccount::total=0;
//SavingsAccount类相关成员函数的实现
SavingsAccount::SavingsAccount(int date, int id, double rate)
		:id(id), balance(0), rate(rate), lastDate(date), accumulation(0){
		cout<<date<<"\t#"<<id<<"is created"<<endl;
	}

	void SavingsAccount::record(int date, double amount){
		accumulation=accumulate(date);
		lastDate=date;
		amount=floor(amount*100+0.5)/100;	//保留小数点后两位
		balance+=amount;
		total+=amount;	//记录各个账户的总金额
		cout<<date<<"\t#"<<id<<"\t"<<amount<<"\t"<<balance<<endl;
	}

	void SavingsAccount::deposit(int date, double amount){
		record(date, amount);
	}

	void SavingsAccount::withdraw(int date, double amount){
		if(amount>getBalance())
			cout<<"Error: not enough money"<<endl;
		else
			record(date, -amount);
	}

	void SavingsAccount::settle(int date) {	
		double interest = accumulate(date)*rate/365;	//计算年息
		if(interest!=0)
			record(date, interest);
		accumulation=0;
	}

	void SavingsAccount::show() const{
		cout<<"#"<<id<<"\tBalance:"<<balance;
	}
