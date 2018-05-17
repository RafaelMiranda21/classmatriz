#ifndef MATRIZ_H
#define MATRIZ_H



class matriz
{
private:
	int ** mat;
	int ql,qc,l,c;

public:
	matriz(int nl, int nc);
	void lermat();
	void impmat();
	bool somamat(matriz x ,  matriz y);
	bool subtmat(matriz x , matriz y);
	bool multmat(matriz x , matriz y);
	bool trisup();
	bool triinf();
	bool matsim();
	bool matantsim();
	bool matidentidade();
	void mattransposta();
	//bool potmat(matriz x);
	bool matrizigual(matriz x);
	bool matrizdiferente(matriz x);

	~matriz();

};


#endif // MATRIZ_H
