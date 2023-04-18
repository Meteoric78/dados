#include <stdio.h>
#include <stdlib.h>

typedef struct no{
	int dado;
	struct no *prox;
}No;

No * criar_no(int valor){
	No *novo = (No *)malloc(sizeof(No));
	novo->dado = valor;
	novo->prox = NULL;
	return novo;
}

void linkar_nos(No *no1, No *no2){
	no1->prox = no2;
}

void mostrar_no(No *nodezinho){
	printf("%d\n", nodezinho->dado);
}

void mostrar_nos(No *nodezinho){
	No *p;
	for (p=nodezinho->prox; p!=NULL; p=p->prox){
		printf("%d\n", nodezinho->dado);
	}
}

int main() {
	No *node1 = criar_no(7);
	mostrar_no(node1);
	No *node2 = criar_no(9);
	mostrar_no(node2);
	linkar_nos(node1, node2);
	mostrar_nos(node1);

}
