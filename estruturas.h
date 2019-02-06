#include <string.h>
#include <stdlib.h>
#include <stdio.h>


typedef struct{
  char chave[6];
  int prioridade;
  int qtd;
}Info;

struct arvore{
  Info informacao;
  struct arvore *dir;
  struct arvore *esq;
};
typedef struct arvore Arv ;
int cont=0;
