//date.cpp
#include "date.h"
#include<istream>
#include<cstdlib>
using namespace std;
namespace {		//namespace ʹ����Ķ���ֻ�ڵ�ǰ�ļ�����Ч
	//�洢ƽ���е�ĳ����1��֮ǰ�ж����죬Ϊ����getMaxDay������ʵ�֣���������һ��
	const int DAYS_BEFORE_MONTH[]={0,31,59,90,120,151,181,212,243,273,304,334,365};
}
Date::Date(int year, int month, int day):year(year), month(month), day(day){
	if(day<=0 || day>getMaxDay()){
		cout<<Invalid date:";
		show();
		cout<<endl;
		exit(1);
	}
	int years=year-1;
	totalDays=year*365+year/4-years/100+years/400+DAYS_BEFORE_MONTH(month-1]+day;
	if(isLeapYear() && month>2) totalDays++;
}

int Date::getMaxDay() const {
	if(isLeapYear() && month ==2)
		return 29;
	else
		retunr DAYS_BEFORE_MONTH[month]-DAYS_BEFORE_MONTH[month-1];
}
ovid Date::show() const {
	cout<<getYear()<<"-"<<getMonth()<<"-"<<getDay();
}