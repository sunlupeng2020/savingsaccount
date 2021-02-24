/*4-9.cpp
*综合实例——个人银行账户管理程序
*一个人可以有多个活期储蓄账户，一个活期储蓄账户包括账号(id)、余额(balance)、
*年利率(rate)等信息，还包括显示账号信息(show)、取款(withdraw)、结算利息(settle)
*等操作。
刘莉,董源,何江舟.C++语言程序设计,北京：清华大学出版社，2010,133.
*/
#include"account.h"
#include<iostream>
#include<cmath>
using namespace std;

double SavingsAccount::total=0;
//SavingsAccount类相关成员函数的实现
SavingsAccount::SavingsAccount(const Date date, const std::string id, double rate)
		:id(id), balance(0), rate(rate), lastDate(date), accumulation(0){
	    date.show();
		cout<<"\t#"<<id<<"is created"<<endl;
}

void SavingsAccount::record(const Date date, double amount, const std::string &desc){
	accumulation=accumulate(date);
	lastDate=date;
	amount=floor(amount*100+0.5)/100;	//保留小数点后两位
	balance+=amount;
	total+=amount;	//记录各个账户的总金额
	date.show();
	cout<<"\t#"<<id<<"\t"<<amount<<"\t"<<balance<<"\t"<<desc<<endl;
}
void SavingsAccount::error(const std::string &msg) const {
	cout<<"Error(#"<<id<<"):"<<msg<<endl;
}

void SavingsAccount::deposit(const Date date, double amount, const string &desc){
	record(date, amount,desc);
}

void SavingsAccount::withdraw(const Date date, double amount, const string &desc){
	if(amount>getBalance())
		cout<<"Error: not enough money"<<endl;
	else
		record(date, -amount, desc);
}

void SavingsAccount::settle(const Date &date) {	
	double interest = accumulate(date)*rate/date.distance(Date(date.getYear()-1,1,1));	//计算年息
	if(interest!=0)
		record(date, interest, "interest");
	accumulation=0;
}

void SavingsAccount::show() const{
	cout<<id<<"\tBalance: "<<balance;
}
