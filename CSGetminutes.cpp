#include <iostream>
#include "CSGetminutes.h"
using namespace std;

double CSGetminutes::getZongminutes()
{
   zongminutes=getZonghours()*60+getMinutes();
   return zongminutes;
}
int CSGetminutes::getMinutes(){
	minutes=(int)getChasecond()/60-getHours()*60;
	return minutes;
}