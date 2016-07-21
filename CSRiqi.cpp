//CSRiqi.h
//2012-6-15-11:17
#include <iostream>
#include "CSRiqi.h"
using namespace std;

void CSRiqi::getdate(int y,int m,int d,int ds)
{
	year=y;
	month=m;
	day=d;
	days=ds;
}

int CSRiqi::panyear(int y)
{
	int wucha;
	int a,b;
	a=y%400;
	b=y%4;
	if(a==0)
		wucha=0;
	else
	{
		if(b==0)
			wucha=1;
		else
			wucha=0;
	}
	return wucha;
}

int CSRiqi::panmonth(int m,int y){
	int t;
	if(m==1||m==3||m==5||m==7||m==8||m==10||m==12)
		t=31;
	else
	{
		if(m==2)
			t=28+panyear(y);
		else
			t=30;
	}
	return t;
}

int CSRiqi::getyear(){
    int y,m,d,ds;
	ds=days;
	d=day;
	ds=d+ds;
	m=month;
	y=year;
	if(ds>panmonth(m,y))
	{
		for(y=year;ds>panmonth(m,y);)
		{
			for(m=month;m<=12;)
			{
				ds=ds-panmonth(m,y);
				m=m+1;
				if(m==13)
				{
					m=1;
					y=y+1;
				}      
				if(ds<=panmonth(m,y))
			    break;
			}
			y=y+1;
		}
		return y-1;
	}
	else
		return y;
 
}

int CSRiqi::getmonth()
{
    int y,m,d,ds;
	ds=days;
	d=day;
	ds=d+ds;
	m=month;
	for(y=year;ds>panmonth(m,y);y=y+1)
	{
		for(m=month;m<=12;)
		{
			ds=ds-panmonth(m,y);
			m=m+1;
			if(m==13)
			{
				m=1;
				y=y+1;
			}      
			if(ds<=panmonth(m,y))
				break;
		}
	} 
	return m;
}

int CSRiqi::getday()
{
	int y,m,d,ds;
	ds=days;
	d=day;
	ds=d+ds;
	m=month;
	for(y=year;ds>panmonth(m,y);y=y+1)
	{
		for(m=month;m<=12;)
		{
			ds=ds-panmonth(m,y);
	        m=m+1;
			if(m==13)
			{
				m=1;
				y=y+1;
		
			}
			if(ds<=panmonth(m,y))
			break;
		}
	} 
	return ds;
}