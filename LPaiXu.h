//LPaiXu.h
//2012-6-14-17:22

#ifndef LPAIXU_H
#define LPAIXU_H


#include "CRMenu.h"

class LPaiXu
{
private:
	int i;
	int j;
	int size;
	daoShuRi temp;
	daoShuRi aDaoShuRi[80];
public:
	daoShuRi putpaiXu(int a);
	void setShuZu(daoShuRi aDaoShu, int k);
	void setSize(int m);
	void paiXuDaDaoXiao();
};

#endif