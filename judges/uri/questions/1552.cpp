#include <bits/stdc++.h>

using namespace std;

void intercala (int p, int q, int r, double arestas[], int idArestas[]) {
	double aux[r-p];
	int aux1[r-p];
	int i = p, j = q;
	int k = 0;
	while (i < q && j < r) {
		if (arestas[i] <= arestas[j]) {
			aux1[k] = idArestas[i];
			aux[k++] = arestas[i++];
		}
		else {
			aux1[k] = idArestas[j]; 
			aux[k++] = arestas[j++];
		}
	}
	while (i < q) {
		aux1[k] = idArestas[i];
		aux[k++] = arestas[i++];
	}
	while (j < r) {
		aux1[k] = idArestas[j];
		aux[k++] = arestas[j++];
	}
	for (i = p; i < r; ++i) {
		idArestas[i] = aux1[i-p];
		arestas[i] = aux[i-p];
	}
}

void mergesort (int p, int r, double arestas[], int idArestas[]) {
	if (p < r-1) {
		int q = (p + r)/2;
		mergesort (p, q, arestas, idArestas);
		mergesort (q, r, arestas, idArestas);
		intercala (p, q, r, arestas, idArestas);
	}
}

int main () {
	int c;
	cin >> c;
	
	while (c--) {
		int n;
		cin >> n;
		
		int posicao[n][2]; 
		for (int i = 0; i < n; i++)
			cin >> posicao[i][0] >> posicao[i][1];
		
		int conju[n];
		for (int i = 0; i < n; i++)
			conju[i] = 0;
			
		int numArestas = (n * (n - 1)) / 2;
		double arestas[numArestas];
		int idArestas[numArestas];
		int verticeX[numArestas];
		int verticeY[numArestas];
		
		int auxAresta = 0;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				double dist = sqrt( pow((posicao[j][0] - posicao[i][0]), 2) 
					+ pow((posicao[j][1] - posicao[i][1]), 2) );
				verticeX[auxAresta] = i;
				verticeY[auxAresta] = j;
				arestas[auxAresta] = dist;
				idArestas[auxAresta] = auxAresta;
				auxAresta++; 
			}
		}
		
		mergesort(0, numArestas, arestas, idArestas);
		
		double soma = 0.0;
		int con = 1;
		for (int i = 0; i < numArestas; i++) {
			int x = verticeX[idArestas[i]];
			int y = verticeY[idArestas[i]];
			
			if ((conju[x] != conju[y]) || (conju[x] == 0 || conju[y] == 0)) {
				int valx = conju[x], valy = conju[y];
				conju[x] = con;
				conju[y] = con;
				for (int j = 0; j < n; j++) {
					if ((valx != 0 && conju[j] == valx) || (valy != 0 &&  conju[j] == valy))
						conju[j] = con;
				}
				con++;
				soma += arestas[i];
			}
		}
		
		printf("%.2lf\n", soma / 100);
	}
	return 0;
}
