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
    if(x.c != y.l)
    {
        return false;
    }

    l = x.l;
    c = y.c;
    int aux = 0;

    for(int i=0; i<x.l; i++)
    {
        for(int j=0; j<y.c; j++)
        {
                 mat[i][j]=0;
                 for(int z=0; z<y.l; z++)
                 {
                  aux = aux + (x.mat[i][z] * y.mat[z][j]);
                 }
                 mat[i][j] = aux;
                 aux = 0;
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

bool matriz::matantsim()
{
    for(int i=1;i<l;i++)
    {
       for(int j=0;j<c && i != j; j++)
       {
         if((mat[i][j] + mat[j][i]) != 0)
         {
             return false;
         }
       }
    }
             return true;
}

bool matriz::matidentidade()
{
     for(int i=0;i<l;i++)
    {
       for(int j=0;j<c && i == j; j++)
       {
         if(mat[i][j] != 1)
         {
             return false;
         }
       }
    }

    for(int i=1;i<l;i++)
    {
       for(int j=0;j<c && i != j; j++)
       {
         if(mat[i][j] != 0)
         {
             return false;
         }
       }
    }

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

void matriz::mattransposta()
{
   if(l == c)
   {
       for(int i=0;i<l;i++)
	   {
		 for(int j=0;j<c;j++)
		 {
			cout<<mat[j][i]<<" ";
		 }
		    cout<<"\n";
	   }
   }

   else
   {
       int aux;
       aux = l;
       l = c;
       c = aux;

       for(int i=0;i<l;i++)
	   {
		 for(int j=0;j<c;j++)
		 {
			cout<<mat[j][i]<<" ";
		 }
		    cout<<"\n";
	   }

   }

}
bool matriz::matrizigual(matriz x)
{
    if(l != x.l || c != x.c)
    {
        return false;
    }

    for(int i=0; i<l; i++)
    {
        for(int j=0; j<c; j++)
        {
            if(mat[i][j] != x.mat[i][j])
                {
                    return false;
                }
        }
    }

                    return true;


}

bool matriz::matrizdiferente(matriz x)
{
    if(l != x.l || c != x.c)
    {
        return true;
    }


    for(int i=0; i<l; i++)
    {
        for(int j=0; j<c; j++)
        {
            if(mat[i][j] != x.mat[i][j])
                {
                   return true;
                }
        }
    }

                   return false;

}


matriz::~matriz()
{
	for(int i=0; i<l;i++)
	{
		delete []mat[i];
	}
	delete[]mat;
}
