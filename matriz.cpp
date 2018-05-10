#include "matriz.h"
#include <iostream>
using namespace std;

matriz::matriz(int nl, int nc)
{
	mat = new int *[nl];

	for(int i=0;i<nl;i++)
	{
		mat[i] = new int[nc];
	}

	ql=nl;
	qc=nc;
	l=c=0;

}

void matriz::lermat()
{

	for(int i=0;i<ql;i++)
	{
		for(int j=0;j<qc;j++)
		{
		  cin>>mat[i][j];
		}
	}
	l = ql;
	c = qc;

}

void matriz::impmat()
{
	for(int i=0;i<l;i++)
	{
		for(int j=0;j<c;j++)
		{
			cout<<mat[i][j]<<" ";
		}
		cout<<"\n";
	}

}

bool matriz::somamat(matriz x , matriz y)
{
    if(x.l != y.l || x.c != y.c)
    {
        return false;
    }

    l = x.l;
    c = x.c;

    for(int i=0;i<l;i++)
    {
        for(int j=0;j<c;j++)
        {
            mat[i][j] = x.mat[i][j] + y.mat[i][j];
        }
    }

        return true;
}

bool matriz::subtmat(matriz x , matriz y)
{
    if(x.l != y.l || x.c != y.c)
    {
        return false;
    }

    l = x.l;
    c = x.c;

    for(int i=0;i<l;i++)
    {
        for(int j=0;j<c;j++)
        {
            mat[i][j] = x.mat[i][j] - y.mat[i][j];
        }
    }

        return true;

}


bool matriz::multmat(matriz x , matriz y)
{
    if(x.l != y.l || x.c != y.c)
    {
        return false;
    }

    l = x.l;
    c = x.c;

    for(int i=0;i<l;i++)
    {
        for(int j=0;j<c;j++)
        {
            mat[i][j] = x.mat[i][j] * y.mat[i][j];
        }
    }

        return true;

}

bool matriz::trisup()
{
    for(int i=0;i<l;i++)
    {
        for(int j=0;j<c && i != j; j++)
        {
            if(mat[i][j] != 0)
            {
                return false;
            }
        }
    }
                return true;
}

bool matriz::triinf()
{
    for(int i=0;i<l-1;i++)
    {
        for(int j=i+1;j<c && i != j; j++)
        {
            if(mat[i][j] != 0)
            {
                return false;
            }
        }
    }
                return true;
}

bool matriz::matsim()
{
    for(int i=0;i<l;i++)
    {
        for(int j=0;j<c && i != j; j++)
        {
           if(mat[i][j] != mat[j][i])
           {
               return false;
           }
        }
    }
               return true;
}

matriz::~matriz()
{
	for(int i=0; i<l;i++)
	{
		delete []mat[i];
	}
	delete[]mat;
}
