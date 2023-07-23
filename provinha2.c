#include "lista-encadeada.h"

TLista *cria_lista(void) {
    return NULL;
}

TLista *insere_fim_recursivo(TLista *li, int i) {
    if (li == NULL || li->prox == NULL) {
        TLista *novo = (TLista *) malloc(sizeof(TLista));
        novo->info = i;
        novo->prox = NULL;
        if (li == NULL) {
            li = novo;
        } else li->prox = novo;
    }
    else
        insere_fim_recursivo(li->prox, i);
    return li;
}

TLista *insere_ordenado_recursivo(TLista *li, int i) {
    if (li == NULL || li->prox == NULL) { //lista vazia
        TLista *novo = (TLista *) malloc(sizeof(TLista));
        novo->info = i;
        novo->prox = NULL;
        if (li == NULL)
            li = novo;
        else { /* inserir no meio da lista */
            if (li->info > i) {
                novo->prox = li;
                li = novo;
            }
            else li->prox = novo;
        }
    } else {
        if (li->info > i) {
            TLista *novo = (TLista *) malloc(sizeof(TLista));
            novo->info = i;
            novo->prox = li;
            li = novo;
        }
        else li->prox = insere_ordenado_recursivo(li->prox, i);
    }
    return li;
}


void imprime_lista(TLista *li) {
    TLista *p;
    for (p = li; p != NULL; p = p->prox)
        printf("info = %d\n", p->info);
}

TLista* exclui(TLista *li, int i){
	//Verificar se a lista está vazia e retornar
	if(li == NULL)
	    return li;

	//Se eh o elemento a ser excluido, exclui
	if(li->info == i)
	    TLista *aux = li;
	    li = li->prox;
	    free(aux);
	    return li;
	
	//Se não é, chama exclui no li->prox
	exclui(li->prox, i);
}

int main(void) {
    TLista *l1;
    TLista *l2;
    TLista *l3; /* declara listas não inicializadas */
    /* Insere elementos no inicio da lista */
    l1 = cria_lista(); /* cria e inicializa lista como vazia */
    l1 = insere_fim_recursivo(l1, 2);
    l1 = insere_fim_recursivo(l1, 3);
    l1 = insere_fim_recursivo(l1, 5);
    l1 = insere_fim_recursivo(l1, 4);
    printf("Lista 1:\n");
    imprime_lista(l1);

    /* Insere elementos no final da lista*/
    l2 = cria_lista(); /* cria e inicializa lista como vazia */
    l2 = insere_ordenado_recursivo(l2, 2);
    l2 = insere_ordenado_recursivo(l2, 5);
    l2 = insere_ordenado_recursivo(l2, 3);
    l2 = insere_ordenado_recursivo(l2, 4);
    l2 = insere_ordenado_recursivo(l2, 1);
    printf("Lista 2:\n");
    imprime_lista(l2);
    printf("Lista 2 exclui:\n");
    l2 = exclui(l2, 1);
    imprime_lista(l2);
    return 0;
}

