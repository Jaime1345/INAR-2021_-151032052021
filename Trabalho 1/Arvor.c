#include <stdio.h>
#include <stdlib.h>

//Criacao de  
struct node{
	int valor;
	struct node *direito;
	struct node *esquerdo;
};

typedef struct node Arvore;

Arvore *criar(){
	return NULL;
}

Arvore *inserir(Arvore *raiz, int x){

	if(raiz == NULL){
		Arvore *aux=(Arvore*)malloc(sizeof(Arvore));		
		aux->valor=x;
		aux->direito=NULL;
		aux->esquerdo=NULL;

		return aux;
	}else{
		if(x < raiz->valor){
			raiz->esquerdo = inserir(raiz->esquerdo, x);
			printf("\nO %d foi inserido a esquerda do %d\n", x, raiz->valor);
		
		}else if(x > raiz->valor){
			raiz->direito = inserir(raiz->direito, x);
			printf("\nO %d foi inserido a direita do %d\n", x, raiz->valor);

		}else{
			//Opcional
			printf("\nO %d ja existe\n",x);
		}
	
	}

	
	return raiz;

}


Arvore *busca(Arvore *raiz, int x)
{
    if (raiz != NULL)
    {
        if (raiz->valor == x)
            return NULL;
        else
        {
            if (x > raiz->valor)
                return busca(raiz->direito, x);
            else
                return busca(raiz->esquerdo, x);
        }
    }
    return NULL;
}

void imprimirNaOrdem(Arvore *raiz){
	if(raiz!=NULL){
		imprimirNaOrdem(raiz->esquerdo);
		printf(" %d ",raiz->valor);
		imprimirNaOrdem(raiz->direito);
	}

}

void imprimirNaPosOrdem(Arvore *raiz){
	if(raiz !=NULL){
		imprimirNaPosOrdem(raiz->esquerdo);
		imprimirNaPosOrdem(raiz->direito);
		printf(" %d ", raiz->valor);		
	}
}


int main(){
	Arvore *raiz=criar();
	raiz=inserir(raiz,20);
	raiz=inserir(raiz,10);
	raiz=inserir(raiz,17);
	raiz=inserir(raiz,18);
	raiz=inserir(raiz,50);

	printf("\n");
	
	imprimirNaOrdem(raiz);
	printf("\n");

	return 0;
}
