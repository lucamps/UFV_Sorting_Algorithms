#include <bits/stdc++.h>
using namespace std;
/*
Comparacoes(n)= O(n²)
Trocas(n) = O(n)  . Movimenta poucos dados na memoria!

Pseudocodigo:
Para i=0 ate n-2
1) Encontre o menor elemento do subvetor
    v[i.. n-1];
2)Coloque esse elemento em v[i]

Estabilidade: só faria sentido comentar sobre a estabildade se houve + de 1 chave.
In-place: não precisa alocar memória extra.

github.com/geflx
@geflx
Ciencia da Computacao- UFV
*/

int binarysearch(int *arr,int begin,int end,int key){
    if(begin>end)
        return -1;
    int middle=(end-begin)/2 + begin;;
    if(arr[middle]==key)
        return middle;
    else if(key<arr[middle])
        return binarysearch(arr,begin,middle-1,key);
    else    
        return binarysearch(arr,middle+1,end,key);
}

int main(){
    int n;
    cin>>n;
    int *arr= new int(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int key;
    //sorting with Selection Sorte (my choice :P)
    for(int i=0;i<n-1;i++){
        long int smallest=arr[i];
        long int position_sm=i;
        for(int j=i;j<n;j++){
            if (smallest>arr[j]){
                smallest=arr[j];
                position_sm=j;
            }
        }
        arr[position_sm]=arr[i];
        arr[i]=smallest;
    }
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cin>>key;
    cout<<binarysearch(arr,0,n-1,key)<<endl;



    return 0;
}