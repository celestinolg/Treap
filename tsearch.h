#include "estruturas.h"
Arv *rotacaoEsq(const void *raiz,void *V_esq);

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

Arv *rotacaoEsq(const void *raiz,void *V_dir){
  Arv *r = (Arv *)raiz;
  Arv *rd = (Arv *)V_dir;
  if(rd->esq!=NULL){/*se o valor a direita possuuir um filho ele não pode perde-lo*/
    Arv *p=r;
    Arv *q=p->dir;
    Arv *dado=q->esq;
    q->esq=p;
    p->esq=dado;
    p=q;
  }
  return r;
}

Arv *rotacaoDir(const void *raiz,void *V_esq){
  Arv *r= (Arv *)raiz;
  Arv *re= (Arv *)V_esq;

 if(re->dir!=NULL){/*se o valor a direita possuuir um filho ele não pode perde-lo*/
   Arv *p=r;
   Arv *q=p->esq;
   Arv *dado=q->dir;
   q->dir=p;
   p->esq=dado;
   r=q;
   if(r->dir < r->dir->esq){
    /* Arv *d=r->dir;
     Arv *c=r->dir->esq;
     Arv *temp=c->dir;
     c->dir=d;
     d->esq=temp;
     d=c;*/
     rotacaoDir(r->dir, r->dir->esq);
   }


   return r;
  }
  Arv *aux=r;
  r=r->esq;/*raiz recebe o seu filho na esquerda*/
  aux->esq=NULL;
  r->dir=aux;
  return r;
}

void  *tfind(const void *key, void const *rootp, int (*compar)(const void *, const void *)){
  Arv *valor= (Arv *)key;
  Arv *raiz= (Arv *)rootp;
  if (raiz==NULL){
    return NULL; /* não encontrou */
  }else{

    if(strcmp(raiz->informacao.chave,valor->informacao.chave)==0){
        return raiz;
    }
    return tfind(valor,raiz->esq,compar) || tfind(valor,raiz->dir,compar);
  }
  return NULL;

}

void *tsearch(const void *key,void **rootp,int (*comparar)(const void *, const void *)){
  Arv *valor= (Arv *)key;
  Arv *raiz= *(Arv**)rootp;

  if(tfind(valor,raiz,comparar) != NULL){
    puts("ola");
    Arv *a=tfind(valor,raiz,comparar);


      puts("oi");
    printf("%d",a->informacao.qtd);
    puts("oi");
    return NULL;
  }
  if(raiz==NULL){
    raiz=valor;
    printf("%i\n",valor->informacao.qtd);
    return raiz;
  }

  Arv *aux=raiz;
  raiz=valor;
  valor->esq=aux;
  valor->dir=NULL;
  printf("%i\n",raiz->informacao.qtd );
  if(comparar(raiz,raiz->esq)==-1){
      raiz=rotacaoDir(raiz,valor->esq);
  }

  return raiz;
}


void imprime (Arv *a){
  if(a!=NULL){

    imprime(a->esq);
    printf("%s--------%d\n", a->informacao.chave,a->informacao.prioridade);
    imprime(a->dir);
  }
}
