#include <stdio.h>

float funcionarios(int func) {
  float salario, saltotal;
  int matr;
  saltotal = 0;
  while (func != 0) {
    printf("Informe a matricula e o salario:");
    scanf("%d%f", &matr, &salario);
    saltotal = saltotal + salario;
    func--;
  }
  return saltotal;
}
int main(){
    int func;
    float saltotal1;
    printf("Digite o numero de colaboradores:");
    scanf("%d", &func);
    saltotal1 = funcionarios(func);
    printf("Salario total:%.2f", saltotal1);
    return 0;
}