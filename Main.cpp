//main.cpp

#include <iostream>
#include <windows.h>
#include <fstream>
#include <string>
using namespace std;

#include "CRNumber.h"
#include "CRNumberShow.h"
#include "CRMenu.h"
#include "LDay.h"
#include "LBiJiao.h"


int main()
{
	int j;
	system("color F0");
	CRMenu aMenu;
	j = aMenu.faceMain();
	return j;
}

