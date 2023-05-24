#define func 1
#include <stdio.h>
#define TOT 11

typedef struct depto
{
  int matr;
  int idade;
}Depto;

void inicializa(Depto v[])
{
    int cont;
    for(cont=0;cont<TOT;cont++){
      v[cont].idade=0;
      v[cont].matr=0;
    }
}

void exibe(Depto v[])
{
    int cont;
    for(cont=0;cont<TOT;cont++)
    {
      printf("\nDepartamento: %d\n",cont+10);
      printf("Matricula mais velho: %d\n",v[cont].matr);
      printf("Idade mais velho: %d\n",v[cont].idade);
    }
}

int main(void)
{
  Depto velho[TOT];
  int cod,idade,matr;
  inicializa(velho);
  for(int cont=0;cont<func;cont++)
    {
      printf("Digite codigo(10 a 20) do seu departamento:");
      scanf("%d",&cod);
      
      printf("Digite a idade:");
      scanf("%d",&idade);
      
      printf("Digite a matricula:");
      scanf("%d",&matr);

      if(idade>velho[cod-10].idade)
      {
        velho[cod-10].idade=idade;
        velho[cod-10].matr=matr;
      }
    }
  exibe(velho);
return 0;
}
