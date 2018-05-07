#ifndef MATRIZ_H
#define MATRIZ_H


class matriz
{
private:
	int **mat;
	int ql,qc,l,c;
	
public:
	matriz(int nl, int nc);
	void lermat();
	void impmat();
	/*bool somamat(matriz x);
	bool subtmat(matriz x);
	bool multmat(matriz x);
	bool trisup();
	bool triinf();
	bool matsim();
	bool matantsim();
	*/ 
	~matriz();

};


#endif // MATRIZ_H
