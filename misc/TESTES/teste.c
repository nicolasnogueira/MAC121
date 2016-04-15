#include <stdio.h>
#include <stdlib.h>

struct cel {
   /*int         conteudo;*/
   int         conteudo;
   struct cel *esq;
   struct cel *dir; 
};
typedef struct cel noh; /* nó */
 typedef noh *arvore; /* árvore */

int tam;
int qntelem;

void indent (arvore r, int k) {
   int i;
   for (i = 0; i < k; ++i)   
      printf ("   ");
   if (r == NULL) 
      printf ("%c\n", '-');
   else {
      printf ("%d\n", r->conteudo);
      indent (r->esq, k+1);
      indent (r->dir, k+1);
   }
}

void indentado (arvore r) {
   indent (r, 0);
}

/* A função recebe uma árvore de busca r e uma 
// folha novo que não pertence à árvore.
// A função insere a folha na árvore 
// de modo que a árvore continue sendo de busca
// e devolve o endereço da árvore resultante.*/

arvore insere (arvore r, noh *novo) {  
    noh *filho, *pai;
    if (r == NULL) return novo;
    filho = r;
    while (filho != NULL) {
       pai = filho;
       if (filho->conteudo > novo->conteudo)  filho = filho->esq;
       else  filho = filho->dir;
    }
    if (pai->conteudo > novo->conteudo)  pai->esq = novo;
    else  pai->dir = novo;
    return r;
}

arvore transformaV (int e, int d, int *v, arvore r) {
	if (e<=d) {
		int m;
		noh *novo;
		novo = malloc (sizeof (noh));
		r = novo;
		m = (e+d)/2;
		r->conteudo = v[m];
		r->esq = transformaV (e, m-1, v, r->esq);
		r->dir = transformaV (m+1, d, v, r->dir);
	} else r = NULL;
	return r;
}

arvore transforma (int *v, int n) {
	arvore raiz;
	raiz = NULL;
	raiz = transformaV (0, n-1, v, raiz);
	return raiz; 
}

void transforme (arvore r, int *v) {
	if (r != NULL) {
		if (qntelem >= tam) {
			tam*=2;
			v = realloc (v, tam * sizeof (int));
		}
		transforme (r->esq, v);
		v[qntelem] = r->conteudo;
		qntelem++;
		transforme (r->dir, v);
	}
}

int *transformaA (arvore r) {
	int *v;
	v = malloc (10 * sizeof (int));
	tam = 10;
	qntelem = 0;
	transforme (r, v);
	return v;
}

int main (void) {
	noh **novo;
	int i;
	arvore teste = NULL;
	int conteudos[6] = {555, 333, 111, 444, 888, 999};
	int *v;
	/*teste = transforma (v, 7);*/
	novo = malloc (6 * sizeof (noh *));
	for (i = 0; i < 6; i++) {
		novo[i] = malloc (sizeof (noh));
		novo[i]->conteudo = conteudos[i];
		novo[i]->dir = NULL;
		novo[i]->esq = NULL;
		teste = insere (teste, novo[i]);
	}
	indentado (teste);
	v = transformaA (teste);
	for (i = 0; i<qntelem; i++) {
		printf ("%d ", v[i]);
	}
	return EXIT_SUCCESS;
}