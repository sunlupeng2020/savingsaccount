//5_11.cpp
#include"account.h"
#include<iostream>
using namespace std;	
int main(){
	//���������˻�
	SavingsAccount sa0(1,21325302,0.015);
	SavingsAccount sa1(1,58320212,0.015);
	//������Ŀ
	sa0.deposit(5,5000);		//���ڼ��죬����Ǯ
	sa1.deposit(25,10000);
	sa0.deposit(45,5500);
	sa1.withdraw(60,4000);		//ȡ��ڶ����죬����Ǯ
	//�������90�쵽�����еļ�Ϣ�գ����������˻�����Ϣ
	sa0.settle(90);
	sa1.settle(90);
	//����˻���Ϣ��
	sa0.show();  cout<<endl;
	sa1.show();  cout<<endl;
	cout<<"Total:"<<SavingsAccount::getTotal()<<endl;
	return 0;
}
/*�汾1���н����
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

/*�汾2���н��
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