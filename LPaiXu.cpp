//LPaiXu.cpp
//2012-6-14-17:22

#include<iostream>
#include "LPaiXu.h"
using namespace std;


daoShuRi LPaiXu::putpaiXu(int a)
{
	return aDaoShuRi[a];
}


void LPaiXu::setShuZu(daoShuRi aDaoShu, int k)
{
	aDaoShuRi[k]=aDaoShu;
}

void LPaiXu::setSize(int m)
{
	size = m;
}

void LPaiXu::paiXuDaDaoXiao()
{
	for(i=0;i<size;i++)
	{
		for(j=0;j<size-i;j++)
		{
			if(aDaoShuRi[j].day<aDaoShuRi[j+1].day)
			{
				temp=aDaoShuRi[j];
				aDaoShuRi[j]=aDaoShuRi[j+1];
				aDaoShuRi[j+1]=temp;
			}

		}
	}
}