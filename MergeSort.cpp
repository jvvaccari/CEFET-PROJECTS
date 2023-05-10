//Merge Sort
#include <iostream>
#define n 5

using namespace std;

void intercala(int A[],int inicio,int meio,int fim){
    
    int i,aux[n],inicioA1=inicio,inicioA2=meio+1,plivre=inicio;

    while(inicioA1<=meio && inicioA2<=fim){
        if(A[inicioA1]>A[inicioA2]){

            aux[plivre]=A[inicioA2];
            inicioA2++;
        }else{
            aux[plivre]=A[inicioA1];
            inicioA1++;
        }plivre++;
    }

        for(i=inicioA1;i<=meio;i++){
            aux[plivre]=A[i];
            plivre++;
        }
        for(i=inicioA2;i<=fim;i++){
            aux[plivre]=A[i];
            plivre++;
        }
        for(i=inicio;i<=fim;i++){
            A[i]=aux[i];
        }
       
}

void mergesort(int A[],int inicio,int fim){

    int meio;
    if(inicio<fim){
        meio=(inicio+fim)/2;
        mergesort(A,inicio,meio);
        mergesort(A,meio+1,fim);
        intercala(A,inicio,meio,fim);
    }
}

int main(){

    int A[n],inicio,fim,i;

    for(i=0;i<n;i++){
        cout<<"Entre com o valor "<<i+1<<":";
        cin>>A[i];
    }
    inicio=0;
    fim=n-1;
    mergesort(A,inicio,fim);
    for(i=0;i<n;i++){
        cout<<"\n"<<A[i];
    }
    return 0;
}