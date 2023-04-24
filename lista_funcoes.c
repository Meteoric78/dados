#include <stdio.h>
#include <stdlib.h>

typedef struct no{
	int dado;
	struct no *prox;
}No;

typedef struct desc{
	int qtd;
	struct no *ini, *fim, *maior;
}Desc;

No * criar_no(int valor){
	No *novo = (No *)malloc(sizeof(No));
	novo->dado = valor;
	novo->prox = NULL;
	return novo;
}

int def_maior(Desc *d){
	No *p;
	for(p=d->ini; p!=NULL; p=p->prox){
		if (p->dado > d->maior->dado)
			d->maior = p;
	}
	return 0;
}

int inserir_fim(Desc *d, int valor){
	No *novo = criar_no(valor);
	if (d->fim == NULL){
		d->ini = novo;
		d->fim = novo;
		d->maior = d->fim;
	}else{
		d->fim->prox = novo;
		d->fim = novo;
		def_maior(d);
	}
	d->qtd++;
	return 0;	
}


int mostrar_desc(Desc *d){
	printf("qtd = %d\n", d->qtd);
	printf("ini = %d\n", d->ini->dado);
	printf("fim = %d\n", d->fim->dado);
	printf("maior = %d\n", d->maior->dado);
	return 0;
}

void mostrar_lista(Desc *d){
	if (d->ini == NULL)
		printf("Lista vazia.\n");
	else{
		No *p;
		for (p=d->ini; p!=NULL; p=p->prox){
			printf("%i\n", p->dado);
		}
	}
}

void mostrar_negativos(Desc *d){
	if (d->ini == NULL)
		printf("Lista vazia.\n");
	else{
		No *p;
		for (p=d->ini; p!=NULL; p=p->prox){
			if(p->dado < 0)
				printf("%d\n", p->dado);
		}
	}
}

int inserir_apos(Desc *d, int ref, int a_inserir){
	int match = 0;
	No *p;
	for (p=d->ini; p!=NULL; p=p->prox){
		if (ref == p->dado)
			match = 1;
	}
	if (match){
		No *novo = criar_no(a_inserir);
		if (d->ini == d->fim){
			d->fim->prox = novo;
			d->fim = novo;
		}else{
			if (ref == d->fim->dado){
				d->fim->prox = novo;
				d->fim = novo;
			}else{
				No *p;
				for(p=d->ini; p->dado!=ref; p=p->prox);
				novo->prox = p->prox;
				p->prox = novo;
			}
		}
		def_maior(d);
		d->qtd++;
		return 0;
	}
	return 1;
}

int inserir_antes(){
}

int encontrar_posicao(){
}

void remover_posicao(){
}

void inverter_lista(){
}

void concatenar_lista(){
}

void intercalar_lista(){
}

int main() {
	Desc d;
	d.qtd = 0;
	d.ini = NULL;
	d.fim = NULL;
	d.maior = NULL;

	inserir_fim(&d, 10);
	inserir_fim(&d, -3);
	inserir_fim(&d, -7);
	inserir_fim(&d, 100);

	mostrar_desc(&d);

	mostrar_lista(&d);
	mostrar_negativos(&d);
	
	inserir_apos(&d,-3, 1002);
	mostrar_desc(&d);
	mostrar_lista(&d);

}
