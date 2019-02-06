#include <search.h>
#include "estruturas.h"

int random(char chave[]){
  int result=0,i;
  for(i=0;i<strlen(chave);i++){
    result+=(int)chave[i];
  }
  return result;
}

int compararRaiz(const void *raiz, const void *valor){
  /*compara a raiz com o ultimo valor inserido*/
  Arv *r= (Arv *)raiz;
  Arv *re= (Arv *)valor;
  if ((int *) r->informacao.prioridade < (int *) re->informacao.prioridade)
    return -1;
  if ((int *) r->informacao.prioridade > (int *) re->informacao.prioridade)
    return 1;
  return 0;
}

Arv *criarNo(char infor[],int prioridade, Arv *esq, Arv *dir){
    Arv* No=(Arv*) malloc(sizeof(Arv));
    if(No!=NULL){
      strcpy(No->informacao.chave,infor);
      No->informacao.prioridade=prioridade;
      No->informacao.qtd++;
      No->dir=dir;
      No->esq=esq;
      return No;
    }
    return NULL;
}

void imprime (Arv *a){
  if(a!=NULL){

    imprime(a->esq);
    printf("%s--------%d\n", a->informacao.chave,a->informacao.prioridade);
    imprime(a->dir);
  }
}

int main(){


  Arv* raiz=NULL;
  Arv *busca=NULL;
  int cont=0,j=0;
  char v[6],acao;
  scanf("%i",&cont);

  while(cont--){
    __fpurge(stdin);
    scanf("%c %s",&acao,v);
    switch(acao){
      case 'A':
        raiz=tsearch(criarNo(v,random(v),NULL,NULL),&raiz,compararRaiz);
        break;
      case 'F':
        busca = (Arv *)tfind(criarNo(v,random(v),NULL,NULL),raiz,compararRaiz);
        if((int)busca == 0){
          puts("NULL");
        }else{
          printf("%d\n",busca->informacao.qtd);
        }
        break;
    }
  }
  imprime(raiz);
/*  puts("procurar");
  scanf("%s",v);
  int e=tfind(criarNo(v,random(v),NULL,NULL),raiz,compararRaiz);
  printf("------->%i\n",e);*/
  return 1;
}
