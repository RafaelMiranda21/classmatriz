#include <iostream>
#include "matriz.h"

using namespace std;


matriz::matriz(int nl, int nc)
{
	mat = new int *[nl];
	
	for(int i=0;i<x;i++)
	{
		mat[i] = new int[nc]; 
	}
	
	ql=nl;
	qc=nc;
	l=c=0;
	
}

bool matriz::lermat()
{
	for(int i=0;i<ql;i++)
	{
		for(int j=0;j<qc;j++)
		{
			cin>>mat[i][j];
		}
	}
	
}

void matriz::impmat()
{
	for(int i=0;i<ql;i++)
	{
		for(int j=0;j<qc;j++)
		{
			cout<<mat[i][j];
		}
	}
	
}

matriz::matriz()
{
	for(int i=0; i<ql;i++)
	{
		delete []mat[i];	
	}
	delete[]mat;
}
