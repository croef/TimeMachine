//LDay.cpp
//2012-6-12-16:56

#include<iostream>
using namespace std;

#include "LDay.h"


void LDay::setDay(Date date1,Date date2)
{
	int x;
	aBiJiao.setDate(date1, date2);
	x=aBiJiao.biJiao();
	if(x==1)
	{
		newDate=date1;
		oldDate=date2;
	}
	else if(x==0)
	{
		newDate=date2;
		oldDate=date1;
	}	
}

void LDay::getDay()
{
	days = 0;
	for(i=oldDate.year;i<newDate.year;i++)//计算从oldDate一月一号到newDate一月一号(包含闰年）的天数
	{
		if((i%4)==0&&(i%100)!=0||(i%400)==0)
			days+=366;
		else
			days+=365;
	}
	for(j=1;j<oldDate.month;j++)//计算去掉oldDate那年已过去的天数后的天数
	{
		if(j==1||j==3||j==5||j==7||j==8||j==10||j==12)
			days-=31;
		else
		{
			if(j==4||j==6||j==9||j==11)
				days-=30;
			else
			{
				if((oldDate.year%4)==0&&(oldDate.year%100)!=0||(oldDate.year%400)==0)
					days-=29;
				else
					days-=28;
			}
		}

	}
	
	days=days-oldDate.day;

	for(j=1;j<newDate.month;j++)//计算加上newDate那年已过去的天数后的天数
	{
		if(j==1||j==3||j==5||j==7||j==8||j==10||j==12)
			days+=31;
		else
		{
			if(j==4||j==6||j==9||j==11)
				days+=30;
			else
			{
				if((newDate.year%4)==0&&(newDate.year%100)!=0||(newDate.year%400)==0)
					days+=29;
				else
					days+=28;
			}
		}

	}
	days=days+newDate.day;
}

int LDay::showDay()
{
	getDay();
	return days;
}










