#include<iostream>
#define n 5
using namespace std;

void insertion(int A[]){
    int aux,i,j,comp;
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(A[i]>A[j]){

                aux=A[i];
                A[i]=A[j];
                A[j]=aux;

                for(comp=j-1;comp>0;comp--){
                    if(A[comp]>A[j]){
                        aux=A[comp];
                        A[comp]=A[j];
                        A[j]=aux;
                    }
                }
            }
        }
    }
}

int main(){

    int A[n],i;

    for(i=0;i<n;i++){

        cout<<"Entre com o valor "<<i+1<<":";
        cin>>A[i];
    }

    insertion(A);

    for(i=0;i<n;i++){
        cout<<"\n"<<A[i];
    }
    return 0;
}
