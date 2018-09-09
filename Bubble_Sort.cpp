#include <bits/stdc++.h>
using namespace std;
/*
Uma completa porcaria.
Trocas(n){
	Melhor caso= O(n)  (utopia)
	Caso Médio= O(n²)
	Pior Caso= O(n²) (se ordenado inversamente)
}
In-place, não precisa de memória extra.
Algoritmo Estavel:  preserva-se a ordem de registros de chaves iguais. 
Isto é, se tais registros aparecem na sequência ordenada na mesma ordem em que estão na sequência inicial.

@geflx
github.com/geflx
Ciencia da Computacao

*/

void bubbleSort(int *arr,int n){
	int i,j;
	for(i=0;i<n-1;i++){
		for(j=0;j<n-1-i;j++){
			if(arr[j]>arr[j+1]){
				int temp=arr[j+1];
				arr[j+1]=arr[j];
				arr[j]=temp;
			}
		}
	}
}
int main(){
	int n;
	cin>>n;
	int *arr=new int(n);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	bubbleSort(arr,n);
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	return 0;
}