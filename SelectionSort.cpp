#include<iostream>
#define n 5

using namespace std;

void selection(int A[]){

    int aux,i,j,menor;

    for(i=0;i<n;i++){
        menor=i;
        for(j=i+1;j<n+1;j++){
            if(A[menor]>A[j]){
                menor=j;
            }   
        }
        aux=A[i];
        A[i]=A[menor];
        A[menor]=aux;
    }
}

int main(){
    
    int A[n],i;

    for(i=0;i<n;i++){
        cout<<"Informe o valor "<<i+1<<":";
        cin>>A[i];
    }
    
    selection(A);

    for(i=0;i<n;i++){
        cout<<"\n"<<A[i];
    }
    return 0;
}