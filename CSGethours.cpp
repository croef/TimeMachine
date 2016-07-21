#include "CSGethours.h"
#include "iostream"
using namespace std;

double CSGethours::getZonghours(){
	zonghours=(getday()-1)*24+getWucha()*24+getHours();
	return zonghours;
}

int CSGethours::getHours(){
	hours=getChasecond()/3600;
	return hours;
}
