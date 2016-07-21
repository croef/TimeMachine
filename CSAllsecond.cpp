#include "CSAllsecond.h"
#include <iostream>
#include "LDay.h"

using namespace std;

int CSAllsecond::getday()
{
	return day;
}

void CSAllsecond::getSecond()
{
	beginsecond=hour1*3600+minute1*60+second1;
	endsecond=hour2*3600+minute2*60+second2;
}
double CSAllsecond::getWucha()
{
    getSecond();
	if(beginsecond>endsecond)
	    wucha=-1;
	else
	    wucha=1;	
    return wucha;
}

double CSAllsecond::getChasecond()
{

	chasecond=(endsecond-beginsecond)*getWucha();
	return chasecond;
}

 void CSAllsecond::setAllSecond(Date date1, Date date2)
 {
	 hour1 = date1.hour;
     minute1 = date1.minute;
	 second1 = date2.second;
	 hour2 = date2.hour;
     minute2 = date2.minute;
	 second2 = date2.second;
	 LDay d;
	 d.setDay(date1, date2);
	 day = d.showDay();
 }
