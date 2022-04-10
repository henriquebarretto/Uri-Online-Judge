// URI 1200 OPERACOES EM ABP 1

#include <stdio.h>
#include <stdlib.h>
int esp;

typedef char tp_item;

typedef struct tp_no{
	struct tp_no *esq;
	tp_item info;
	struct tp_no *dir;
} tp_no;

typedef tp_no *tp_arvore;

tp_arvore inicializa_arvore(){
	return NULL;
}

int arvore_vazia(tp_arvore raiz){
	if(raiz==NULL) return 1;
	return 0;
}

tp_no *aloca_no(){ 
	tp_no *no;
	no = (tp_no*)malloc(sizeof(tp_no)); 
	return no;
}

int I(tp_arvore *raiz, tp_item e){
	tp_no *pai = NULL, *novo, *p = *raiz;
	novo = aloca_no();
	if(!novo) return 0;
	
	novo->info = e;
	novo->esq = NULL;
	novo->dir = NULL;
	
	while(p!=NULL){
		pai = p;
		if(e < p->info) p=p->esq;
		else p=p->dir;
	}
	
	if(pai!=NULL){
		if(e < pai->info) pai->esq = novo;
		else pai->dir = novo;
	} else *raiz = novo;

	return 1;
}

void PREFIXA(tp_no *p){
	if(p!=NULL){
        if(esp) printf(" ");
		printf("%c", p->info);
        esp = 1;
		PREFIXA(p->esq);
		PREFIXA(p->dir);
	}
}

void INFIXA(tp_no *p){
	if(p!=NULL){
		INFIXA(p->esq);
        if(esp) printf(" ");
		printf("%c", p->info);
        esp = 1;
		INFIXA(p->dir);
	}
}

void POSFIXA(tp_no *p){
	if(p!=NULL){
		POSFIXA(p->esq);
		POSFIXA(p->dir);
        if(esp) printf(" ");
		printf("%c", p->info);
        esp = 1;
	}
}

tp_no* P(tp_no *p, tp_item a){ //pesquisa
	while(p != NULL){
		if(a < p->info)
			p = p->esq;
		else{
			if(a > p->info) 
				p = p->dir;
			else return p;
		}
	}
	return NULL;
}


int main(){
    tp_arvore arvore;
	arvore = inicializa_arvore();
    char comando[20], elemento;

    while (scanf(" %s",comando)!=EOF){
        
        if (strcmp(comando, "I") == 0){
            scanf(" %c", &elemento);
            I(&arvore, elemento);
        } else if(strcmp(comando, "INFIXA") == 0){
            esp = 0;
            INFIXA(arvore);
            printf("\n");
        } else if(strcmp(comando, "PREFIXA") == 0){
            esp = 0;
            PREFIXA(arvore);
            printf("\n");
        } else if(strcmp(comando, "POSFIXA") == 0){
            esp = 0;
            POSFIXA(arvore);
            printf("\n");
        } else if(strcmp(comando, "P") == 0){
            scanf(" %c", &elemento);
            if(P(arvore, elemento)){
                printf("%c existe\n", elemento);
            }else printf("%c nao existe\n", elemento);
        }else{
            esp = 0;
            POSFIXA(arvore);
            printf("\n");
        }
    }
}