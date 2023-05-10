#include<stdio.h>
#include<stdlib.h>

/*
    Lista Simplismente Encadeada 
    Como inserir no início da lista?
*/

typedef struct no{
    int valor;
    struct no *proximo;
}No;

// procedimento para inserir no início

void inserir_no_inicio(No **lista,int num){
    No *novo = malloc(sizeof(No));

    if(novo){
        novo->valor=num;
        novo->proximo= *lista;
        *lista = novo;
    }
    else
        printf("Erro ao alocar memoria!\n");
}

// procedimento para inserir no fim

void inserir_no_fim(No **lista,int num){
    No *aux,*novo = malloc(sizeof(No));
    if(novo){
        novo->valor=num;
        novo->proximo= NULL;
        
        // é o primeiro?
        if(*lista==NULL)
            *lista=novo;
        else{
            aux= *lista;
            while(aux->proximo)
                aux = aux->proximo;
            aux->proximo = novo; 
        }
    }
    else
        printf("Erro ao alocar memoria!\n");
}

//procedimento para inserir no meio

void inserir_no_meio(No **lista,int num,int anterior){
    No *aux,*novo=malloc(sizeof(No));
    if(novo){
        novo->valor= num;
        // é o primeiro nó? A lista está vazia?
        if(*lista == NULL){
            novo->proximo=NULL;
            *lista=novo;
        }
        else{
            novo->proximo = *lista;
            aux = *lista;
            while(aux->valor!=anterior && aux->proximo){
                aux=aux->proximo;}
                novo->proximo = aux->proximo;
                aux->proximo = novo;
            
        }
    }
    else{
         printf("Erro ao alocar memoria!\n");
    }
}

void inserir_ordenado(No **lista,int num){
    No *aux,*novo = malloc(sizeof(No));

    if(novo){
        novo->valor = num;

        //A lista está vazia?

        if(*lista==NULL){
            novo->proximo = NULL;
            *lista = novo;
        }
        
        //é o menor?

        else if(novo->valor < (*lista)->valor ){
            novo->proximo = *lista;
            *lista= novo;
        
        }
        else{
            aux = *lista;
            while(aux->proximo && novo->valor > aux->proximo->valor){
                aux = aux->proximo;}
                novo->proximo = aux->proximo;
                aux->proximo=novo;
        }
    }

    // num é o menor valor?

    else{ printf("Erro ao alocar memoria!\n");}
}

//remover um nó de uma lista

No* remover(No **lista,int num){
    No *aux,*remover=NULL;//sem alocar,pois queremos encontrar o elemento

    if(*lista){
        
        if((*lista)->valor == num){
            remover = *lista;
            *lista = remover->proximo;
        }
        else{
            aux= *lista;
            while(aux->proximo && aux->proximo->valor != num){
                aux = aux->proximo;
            }
            if(aux->proximo){//se existir,a repetição foi quebrada pois o valor foi encontrado
                remover = aux->proximo;
                aux->proximo = remover->proximo;
            }
        }
    }

    return remover;
}
//buscar um elemento
No* busca(No **lista,int num){
    No *aux,*no = NULL;
    aux=*lista;
    while(aux && aux->valor != num ){
        aux = aux->proximo;
    }
    if(aux->proximo){
        no = aux;
    }
    
    return no;
}
//imprimir e restar a lista encadeada

void imprimir(No *no){
    printf("\n\tLista:");
    while(no){
        printf("%d ",no->valor);
        no = no->proximo;
    }
    printf("\n\n");
}
int main(){
    int opcao,valor,anterior;
    No *buscar,*remove,*lista = NULL;
    do{
        printf("\n\t0 - Sair\n\t1 - InserirI\n\t2 - InserirM\n\t3 - InserirF\n\t4 - InserirO\n\t5 - Remover\n\t6 - Imprimir\n\t7 - Buscar\n\t");
        scanf("%d",&opcao);

        switch(opcao){
            case 1:
                printf("Digite um valor: ");
                scanf("%d",&valor);
                inserir_no_inicio(&lista,valor);
                break;
            case 2:
                printf("Digite um valor e o valor de referencia: ");
                scanf("%d%d",&valor,&anterior);
                inserir_no_meio(&lista,valor,anterior);
                break;
            case 3:
                printf("Digite um valor: ");
                scanf("%d",&valor);
                inserir_no_fim(&lista,valor);
                break;
            case 4:
                printf("Digite um valor:");
                scanf("%d",&valor);
                inserir_ordenado(&lista,valor);
                break;
            case 5:
                printf("Digite um valor:");
                scanf("%d",&valor);
                remove=remover(&lista,valor);
                if(remove){
                    printf("Elemento removido: %d",remove->valor);}
                    free(remove);
                break;
            case 6:
                imprimir(lista);
                break;
            case 7:
                printf("Digite um valor:");
                scanf("%d",&valor);
                buscar= busca(&lista,valor);
                if(buscar){
                    printf("Valor %d encontrado\n",buscar->valor);
                }
                else
                {printf("Valor nao encontrado");}
                break;
            default:
                if(opcao!=0)
                printf("Opcao invalida!\n");
        }
    }while(opcao!=0);

    return 0;
}
