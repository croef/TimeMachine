#include "CSGetseconds.h"
#include <iostream>
using namespace std;

double CSGetseconds::getZongseconds(){
	zongseconds=getZongminutes()*60+getSeconds();
	return zongseconds;
}
int CSGetseconds::getSeconds(){
	seconds=(int)getChasecond()%3600;
	return seconds;
}
