//CRNumberShow.cpp
//2012-6-12-16:42

#include "CRNumberShow.h"

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

void CRNumberShow::setShowNumber(int n)
{
	number = n;
}

void CRNumberShow::show()
{
	getASingleNumber();
	cout<<"  "<<line1<<endl;
	cout<<"  "<<line2<<endl;
	cout<<"  "<<line3<<endl;
	cout<<"  "<<line4<<endl;
	cout<<"  "<<line5<<endl;
}

string CRNumberShow::setLine(string oldLine, string newLine)
{
	space="    ";
	oldLine = oldLine + space + newLine;
	return oldLine;
}

void CRNumberShow::getASingleNumber()
{
	int i = theDigitOfTheNumber();
	do 
	{
		int x=pow(10,i-1);
		if(number>10)
			aNumber.setNumber(number/x);
		else
			aNumber.setNumber(number);

		number = number - x*(number/x);
		i--; 

		line1 = setLine(line1 , aNumber.getLine1());
		line2 = setLine(line2 , aNumber.getLine2());
		line3 = setLine(line3 , aNumber.getLine3());
		line4 = setLine(line4 , aNumber.getLine4());
		line5 = setLine(line5 , aNumber.getLine5());
	}while (i>0);
}

int CRNumberShow::theDigitOfTheNumber()
{
	int i=1, j=number;
	while (j >=10)
	{
		j=(j - j%10)/10;
		i++;
	}
	return i;
}


