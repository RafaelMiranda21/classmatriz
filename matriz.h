#define MATRIZ_H
#ifndef MATRIZ_H



class matriz
{
	privete:
	int **mat;
	int ql,qc,l,c;
	
	public:
	matriz(int nl, int nc);
	bool lermat();
	void impmat();
	/*bool somamat(matriz x);
	bool subtmat(matriz x);
	bool multmat(matriz x);
	bool trisup();
	bool triinf();
	bool matsim();
	bool matantsim();
	*/ 
	matriz();
	
	
	
};


#endif // MATRIZ_H
