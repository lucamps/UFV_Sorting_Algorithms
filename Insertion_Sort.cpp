#include <bits/stdc++.h>
using namespace std;
/*
Ele eh ruim para array muito desordenado. Para quase ordenado e bom d+, linear.


Pseudocodigo: entrada arr, n
	Para i=1 até n-1
	Insira v[i] no subvetor arr[0,..,n-1] 
	de forma que v[0,...,i] esteja ordenado

Parafraseando: para cada i do vetor, vá ordenando arr[i] pelo metodo de insercao (salvando o menor)
In-place: não precisa alocar memória extra
Comparacoes(n)= Trocas(n){
	Melhor Caso: O(n)
	Caso médio: O(n²)
	Pior caso: O(n²)
	"Quase ordenado": O(n)
}
Algoritmo Estavel:  preserva-se a ordem de registros de chaves iguais. 
Isto é, se tais registros aparecem na sequência ordenada na mesma ordem em que estão na sequência inicial.
------------------
@geflx
github.com/geflx
Ciencia da Computacao

*/
void insertionSort(int *arr, int n){
	for(int i=1;i<n;i++){
		int elementoInserir=arr[i];
		int j= i-1;
		while(j>=0 && arr[j]>elementoInserir){
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=elementoInserir;
	}
	return;
}

int main(){
	int n;
	cin>>n;
	int *arr=new int(n);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	insertionSort(arr,n);
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	return 0;
}