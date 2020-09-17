#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX 101

typedef struct{
	char letras[8];
} Palavra;

Palavra criarPalavra(char* l){
	Palavra p;
	strcpy(p.letras, l);
	return p;
}

typedef struct{
	int topo;
	Palavra dados[MAX];
} Pilha;

Pilha* criarPilha(){
	Pilha *p;
	p = (Pilha*)malloc(sizeof(Pilha));
	if(p != NULL){
		p->topo = 0;
	}
	return p;
}

void destruirPilha(Pilha* p){
	free(p);
}

int estahVaziaPilha(Pilha* p){
	if(p == NULL) return -1;
	else return p->topo == 0;
}

int estaCheiaPilha(Pilha* p){
	if(p == NULL) return -1;
	else return p->topo == MAX;
}

int empilhar(Pilha* p, Palavra c){
	if(p==NULL) return 0;
	if(estaCheiaPilha(p)) return 0;
	p->dados[p->topo] = c;
	p->topo++;
	return 1;
}

Palavra desempilhar(Pilha *p) { 
	Palavra temp;
	if(p != NULL || !estahVaziaPilha(p)){	
		p->topo--;  // Reduz o topo para retirar
		temp = p->dados[p->topo];
		return temp;
	}else{
		return temp;
	}
}