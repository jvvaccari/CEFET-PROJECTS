#include <stdio.h> //entrada e saída de dados
#include <stdlib.h> //controle e gerenciamento de memória e processador
#include <math.h>

int main(){

    float a,b,c,delta,x1,x2,yv,xv;

    printf("Digite os coeficientes(a,b,c) da eq do segundo grau:\n");
    scanf("%f%f%f",&a,&b,&c);
    delta=((b*b)-(4*a*c));
    x1=(-b+(sqrt(delta))) / (2*a);
    x2=(-b-(sqrt(delta))) / (2*a);
    xv=(-b/(2*a));
    yv=-delta/(4*a);

    printf("delta=%.2f\n",delta);
    printf("raizes:\n");
    printf("x1=%.2f\t",x1);
    printf("x2=%.2f\n",x2);
    printf("Y do vertice:%.2f\t",yv);
    printf("X do vertice:%.2f\n",xv);

    if(a<0){
        printf("concavidade para baixo\n");
    }
    if(a>0){
        printf("concavidade para cima\n");
    }
    if(a==0){
        printf("nao e uma eq. do segundo grau");
    }
    return 0;
}