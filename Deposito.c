#include<stdio.h>
 float Valida_deposito(float salario)
{
    float deposito;
    do
    {
        printf("Digite o valor do deposito:");
        scanf("%f",&deposito);
        if(deposito>salario*0.2){
          printf("valor inválido \nValor máximo permitido: %.2f\n",salario*0.2);
        }
    }while(deposito>salario*0.2);
    return deposito;
}
float depositos(float depositovalido,float salario,int n)
{
    float depositor1,depositor2;
    int n1;
    depositor1=0;
    depositor2=0;
    n1=1;
    while(n1<=n)
        {
            if((depositor1+depositovalido)<(salario*0.2))
            {
                depositor1=depositor1+depositovalido;
                printf("\nSemana %d: %.2f",n1,depositor1);
                depositor2=depositor2+depositor1;
            }
            else if ((depositor1+depositovalido)==(salario*0.2))
            {
                printf("\nSemana %d: %.2f",n1,depositor1);
                depositor2=depositor2+depositor1;
            }
            else
            {
                printf("\nSemana %d: %.2f",n1,depositovalido);
                depositor1=depositovalido;   
                depositor2=depositor2+depositor1;
            } 
            n1=n1+1;
        }
    return depositor2;
}
int main()
{
    int n;
    float salario,depositovalido,depositon;
    printf("Informe o salario:");
    scanf("%f",&salario);
    depositovalido=Valida_deposito(salario);
    printf("\nInforme por quantas semanas os valores serao depositados:");
    scanf("%d",&n);
    depositon=depositos(depositovalido,salario,n);
    printf("\nValor total a ser depositado: %.2f",depositon);
    return 0;
}