//CRNumber.cpp
//2012-6-12-15:53

#include "CRNumber.h"
#include <string>

void CRNumber::setNumber(int n)
{
	number = n;
}

string CRNumber::getLine1()
{
	switch(number){
	case 1:
		line = "    *";
		break;
	case 4:
		line = "*   *";
		break;
	case 2:
	case 3:
	case 5:
	case 6:
	case 7:
	case 8:
	case 9:
	case 0:
		line = "* * *";
		break;
	}
	return line;
}

string CRNumber::getLine2()
{
	switch(number){
	case 1:
	case 2:
	case 3:
	case 7:
		line = "    *";
		break;
	case 4:
	case 8:
	case 9:
	case 0:
		line = "*   *";
		break;
	case 5:
	case 6:
		line = "*    ";
		break;
	}
	return line;
}

string CRNumber::getLine3()
{
	switch(number){
	case 2:
	case 3:
	case 4:
	case 5:
	case 6:
	case 8:
	case 9:
		line = "* * *";
		break;
	case 1:
	case 7:
		line = "    *";
		break;
	case 0:
		line = "*   *";
		break;
	}
	return line;
}


string CRNumber::getLine4()
{
	switch(number){
	case 1:
	case 3:
	case 4:
	case 5:
	case 7:
	case 9:
		line = "    *";
		break;
	case 2:
		line = "*    ";
		break;
	case 6:
	case 8:
	case 0:
		line = "*   *";
		break;
	}
	return line;
}

string CRNumber::getLine5()
{
	switch(number){
	case 2:
	case 3:
	case 5:
	case 6:
	case 8:
	case 9:
	case 0:
		line ="* * *";
		break;
	case 1:
	case 4:
	case 7:
		line = "    *";
		break;
	}
	return line;
}

