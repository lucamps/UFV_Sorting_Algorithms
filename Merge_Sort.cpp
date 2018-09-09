#include <bits/stdc++.h>
using namespace std;
/*
Comparacoes(n) = O(n)
Trocas(n) = O(n)
Memoria(n) = O(n)

Parafraseando: Chama recursivamente /2 até chegar no vetor unitario,
			dai quebra a recursao e intercala ate chegar ao topo.

Algoritmo not-in-place pois cria um vetor auxiliar.
Estavel.

Consideracoes:
- Realiza O(n log (n)) comparações.
- Não existe pior ou melhor caso, todos são O(nlog(n)).
------------------
@geflx
github.com/geflx
Ciencia da Computacao
*/

/* Supondo que v[p...q-1] e v[q...r-1] estejam ordenador */
void merge(int *v, int p, int q, int r){ //Intercala
	int tam= r-p;
	int *aux = new int [tam];
	int i = p; //Cursor 1
	int j = q; //Cursor 2
	int k = 0; //Cursor para aux
	while(i<q && j<r){
		if(v[i] <= v[j])
			aux[k++] = v[i++];
		else
			aux[k++] = v[j++];
	}
	while(i < q) //Dois while para preencher o restante
		aux[k++] = v[i++];
	while(j < r)
		aux[k++] = v[j++];
	for(k=0;k < tam; k++) //transferindo o ordenado p/ o original
		v[p+k] = aux[k];
	delete []aux;
}
void mergeSort(int *v, int p, int r){ //Divide and conquer
	if(p< r-1){
		int meio= (p+r)/2;
		mergeSort(v,p,meio);
		mergeSort(v,meio,r);
		merge(v,p,meio,r); /* intercala */
	}
}

int main(){
	int n;
	cin>>n;
	int *arr=new int(n);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	mergeSort(arr,0,n);
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	return 0;
}