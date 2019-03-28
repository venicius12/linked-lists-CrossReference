#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

struct nodo{
  char info[30];
  int cont;
  struct nodo *prox;
}palavras;

struct hash{
struct hash *ant;
  char letra;
  struct nodo *pal;
  struct hash *prox;
}letras;

void inserePalavras ( struct hash ** prim ,char val[] )
{
   struct hash *next = *prim;
  while(next != NULL){
	 if(next->letra == val[0]){

struct nodo *ptaux,*pant,*ptnovo=(struct nodo *)malloc(sizeof(palavras));
strcpy(ptnovo->info,val);
ptnovo->prox=next->pal;
ptnovo->cont = 1;
if (next->pal==NULL || strcmp((next->pal)->info,val)>=0)
{
next->pal=ptnovo;
return;
}
ptaux=next->pal;
while (ptaux->prox!=NULL && strcmp(ptaux->prox->info,val)<0)
ptaux=ptaux->prox;
ptnovo->prox=ptaux->prox;
ptaux->prox=ptnovo;

}
	 next = next->prox;
  }
}

void insereLetra ( struct hash ** prim , struct hash ** ultm ,char val[] )
{
struct hash * ptaux =( struct hash *) malloc ( sizeof ( letras ));
ptaux -> letra= val[0];
ptaux ->pal=NULL;
if (* prim == NULL || (* prim )->letra==val[0] )
{
ptaux -> prox =* prim ;
ptaux -> ant = NULL ;
if (* prim != NULL )
{ (* prim )-> ant = ptaux ;}
else * ultm = ptaux ;
{* prim = ptaux ;}

return ;
}
struct hash * ptaux2 =* prim ;
while ( ptaux2 -> prox != NULL && ptaux2 ->prox ->letra==val[0] )
ptaux2 = ptaux2 -> prox ;
ptaux -> prox =ptaux2 -> prox ;
ptaux -> ant = ptaux2 ;
ptaux2 -> prox = ptaux ;
if (ptaux -> prox == NULL ) // inserção no final da lista
(* ultm )= ptaux ;
else
ptaux ->prox -> ant = ptaux ;
return ;
}


void insere(  struct hash ** prim, struct hash ** ultm ,char valor[])
{
  int resp = 0, tem = 0;

  struct hash *next = *prim;
  while(next != NULL){
	 if(next->letra == valor[0]){
        tem = 1;

        struct nodo *first = next->pal;
        while(first != NULL){
	    if(strcmp(first->info,valor)==0)
            {
                resp = 1;
                first->cont ++;
            }
	    first=first->prox;

     }
        if(resp == 0)
            {
             inserePalavras(&(*prim),valor);
            }
     }
	 next = next->prox;

  }

  if(tem == 0)
    {
        insereLetra(&(*prim),&(*ultm),valor);
       inserePalavras(&(*prim),valor);
    }
}

void escreve(struct hash **prim)
{
  struct hash *primeiro = *prim;
  if(primeiro == NULL){
     printf("Lista Vazia\n");
  }
  else{
     while(primeiro != NULL){
	    printf("Elemento: %c \n",primeiro->letra);
	    primeiro=primeiro->prox;
     }
   }
}

void referencia_letra(struct hash **prim,char v)
{
  struct hash *primeiro = *prim;
  if(primeiro == NULL){
     printf("Lista Vazia\n");
  }
  else{


  while(primeiro != NULL){
	 if(primeiro->letra == v){
  struct nodo *next = primeiro->pal;
        while(next != NULL){
	    printf("Elemento: %s quantidade: %d\n",next->info,next->cont);
	    next=next->prox;

     }
  }
primeiro = primeiro->prox;
   }
   return;
}
return;
}

int  quantidade_palavras_letra(struct hash **prim,char v)
{
    int total=0;
  struct hash *primeiro = *prim;
  if(primeiro == NULL){
     printf("Lista Vazia\n");
  }
  else{


  while(primeiro != NULL){
	 if(primeiro->letra == v){
  struct nodo *next = primeiro->pal;
        while(next != NULL){
	    total++;
	    next=next->prox;

     }

  }
primeiro = primeiro->prox;a
   }
   return total;
}
return total;
}

void referencia_total(struct hash **prim)
{
  struct hash *primeiro = *prim;
  if(primeiro == NULL){
     printf("Lista Vazia\n");
  }
  else{


  while(primeiro != NULL){

  struct nodo *next = primeiro->pal;
        while(next != NULL){
	    printf("Elemento: %s quantidade: %d\n",next->info,next->cont);
	    next=next->prox;

     }
	 primeiro = primeiro->prox;


   }
   return;
}
return;
}

int  quantidade_palavras(struct hash **prim)
{
    int total=0;
  struct hash *primeiro = *prim;
  if(primeiro == NULL){
     printf("Lista Vazia\n");
  }
  else{


  while(primeiro != NULL){

  struct nodo *next = primeiro->pal;
        while(next != NULL){
	    total++;
	    next=next->prox;

     }
	 primeiro = primeiro->prox;


   }
   return total;
}
return total;
}

void maior_quantidade(struct hash **prim)
{
    char p[30];
    int x=0;
  struct hash *primeiro = *prim;
  if(primeiro == NULL){
     printf("Lista Vazia\n");
  }
  else{


  while(primeiro != NULL){

  struct nodo *next = primeiro->pal;
        while(next != NULL){
	    if(next->cont>x)
            {
                strcpy(p,next->info);
                x=next->cont;
            }

	    next=next->prox;

     }
	 primeiro = primeiro->prox;


   }
   printf("a palavra com maior quantidade e: %s \n",p);
   return;
}
return;
}

void remove_palavra(struct hash **prim, char val[])
{
 struct hash *next = *prim;
  while(next != NULL){
	 if(next->letra == val[0]){

     if(next->pal->prox == NULL){ //testa se a lista só possui um elemento
          // Valor existe na lista, mas a lista só possui um elemento
             free(next->pal);
             next->pal = NULL;
          }
            else {
                    struct nodo *first = next->pal;
                    struct nodo *ant = NULL;
                    while(strcmp(first->info,val)!=0){
                     ant = first;
                     first = first->prox;
                  }
                  ant->prox = first->prox;
                  free(first);
            }

	 }
	 next = next->prox;

}
}


void menu(){
     printf("1 - Insere palavra\n");
     printf("2 - mostra letras\n");
     printf("3 - mostra as palavras e quantidade referente a letra informada\n");
     printf("4 - mostra o total de palavras referente a letra informada\n");
     printf("5 - mostra o totas as palavras e a quantidade \n");
     printf("6 - mostra total de palavras \n");
     printf("7 - mostra a palavra que foi armazenada mais numero de vezes \n");
}

int main()
{
    int resp;
    char v;
    char palav[30];

    struct hash *prim = NULL;
    struct hash *ultm = NULL;

    menu();
  fflush(stdin);
  printf("Digite sua opcao:\n");
  resp=getch();
  while((resp>='1') && (resp<='8')){
     switch(resp)
        {case '1': printf("Digite a palavra:\n");
                  scanf("%s",palav);
                  fflush(stdin);
                  insere(&prim,&ultm,palav);
                  break;
         case '2': escreve(&prim);
                  break;
         case '3': printf("Digite a letra: \n");
                   scanf("%c",&v);
                   referencia_letra(&prim,v);
                   break;
        case '4': printf("Digite a letra: \n");
                   scanf("%c",&v);
                   printf("total de palavras: %d\n",quantidade_palavras_letra(&prim,v));
                   break;
        case '5':  referencia_total(&prim);
                   break;
        case '6': printf("total de palavras: %d\n",quantidade_palavras(&prim));
                  break;
        case '7': printf("palavra com maior quantidade \n");
                  maior_quantidade(&prim);
                  break;
        case '8': remove_palavra(&prim,"vovo");
                  break;
        }

       menu();
     fflush(stdin);
	 printf("Digite sua opcao:\n");
	 resp=getch();
    }
}
