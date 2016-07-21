//LBiJiao.cpp
//2012-06-14-14:14

#include<iostream>
using namespace std;

#include "LBiJiao.h"
#include "CRMenu.h"

void LBiJiao::setDate(Date d1,Date d2)
{
	date1=d1;
    date2=d2;
}

int LBiJiao::biJiao()
{
	if(date1.year>date2.year)
		return 1;
	else if(date1.year<date2.year)
		return 0;
	else
	{
		if(date1.month>date2.month)
		    return 1;
		else if(date1.month<date2.month)
			return 0;
		else
		{
			if(date1.day>date2.day)
			    return 1;
			else
			    return 0;
		}
	}
}