//5_11.cpp
#include"account.h"
#include<iostream>
using namespace std;	
int main(){
	Date date(2008,11,1);
	//建立几个账户
	SavingsAccount accounts[]={
		SavingsAccount(date, "0375521", 0.015),
		SavingsAccount(date, "02342342", 0.015)
	};
	const int n=sizeof(accounts)/sizeof(SavingsAccount);		//账户总数
	//11月份几笔账目
	accounts[0].deposit(Date(2008,11,5),5000,"salary");
	accounts[1].deposit(Date(2008,11,25),10000,"sell stock 0323");
	//12月的几笔账目
	accounts[0].deposit(Date(2008,12,5),5500,"salary");
	accounts[1].withdraw(Date(2008,12,20),4000,"buy a laptop");
	//结算所有账户并输出各个账户信息
	cout<<endl;
	for(int i=0;i<n;i++)
	{
		accounts[i].settle(Date(2009,1,1));
		accounts[i].show();
		cout<<endl;
	}
	cout<<"Total:"<<SavingsAccount::getTotal()<<endl;
	return 0;
}
/*版本1运行结果：
1       #21325302is created
1       #58320212is created
5       #21325302       5000    5000
25      #58320212       10000   10000
45      #21325302       5500    10500
60      #58320212       -4000   6000
90      #21325302       27.64   10527.6
90      #58320212       21.78   6021.78
#21325302       Balance:10527.6
#58320212       Balance:6021.78
Press any key to continue
*/

/*版本2运行结果
1       #21325302is created
1       #58320212is created
5       #21325302       5000    5000
25      #58320212       10000   10000
45      #21325302       5500    10500
60      #58320212       -4000   6000
90      #21325302       27.64   10527.6
90      #58320212       21.78   6021.78
#21325302       Balance:10527.6
#58320212       Balance:6021.78
Total:16549.4
Press any key to continue
*/

/*
版本3运行结果
2008-11-1       #0375521is created
2008-11-1       #02342342is created
2008-11-5       #0375521        5000    5000    salary
2008-11-25      #02342342       10000   10000   sell stock 0323
2008-12-5       #0375521        5500    10500   salary
2008-12-20      #02342342       -4000   6000    buy a laptop

2009-1-1        #0375521        17.38   10517.4 interest
0375521 Balance: 10517.4
2009-1-1        #02342342       12.99   6012.99 interest
02342342        Balance: 6012.99
Total:16530.4
Press any key to continue
*/