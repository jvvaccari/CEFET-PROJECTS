#include<stdio.h>
int salfunc(int func)
{
  float salario,salariao;
  int matr;
  salariao=0;
  while(func!=0)
  {
    printf("Digite a matricula e o salario:");
    scanf("%d%f",&matr,&salario);
    if(salario>salariao)
    {
      salariao=salario;
    }
    func--;
  }
  return salariao;
}
int main()
{
  int func;
  float maiorsal;
  printf("Digite o numero de funcionarios:");
  scanf("%d",&func);
  maiorsal=salfunc(func);
  printf("Maior salario:%.2f",maiorsal);
  return 0;
}