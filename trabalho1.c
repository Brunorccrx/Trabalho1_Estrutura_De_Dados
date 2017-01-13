#include"trabalho1.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char *lerArquivo(){
	FILE *p_Arquivo;
	char *string=(char *)malloc(100*sizeof(char *));
	int i=0;
  p_Arquivo = fopen("Entrada.txt","r");
  for(i=0;!feof(p_Arquivo);i++)
  	string[i] = fgetc(p_Arquivo);

  fclose(p_Arquivo);

	return string;
}
Dicionario *iniciarDicionario(Dicionario *dicionario){
	return NULL;
}
Dicionario *buscaPalavra(Dicionario *dicionario,char *string){
	Dicionario *d;
	for(d=dicionario;d!=NULL && strcmp(string,d->palavra)!=0;d=d->proxD){
	}
	return d;
}


Dicionario *definirDicionario(char *string, Dicionario *dicionario){
	int i;
	int linhaAtual=0;
	char auxPalavra[20]={0};
	Dicionario *d;
	Palavra *nova;

	for(i=0;i<strlen(string)-4;){//strlen está considerando vazios e lixo por isso "-4"
		while(string[i]!=' '){
			auxPalavra[i]=string[i];
			i++;
		} 
		while(string[i]==' ')
			i++;

		d=buscaPalavra(dicionario,auxPalavra);
		if(d==NULL){
			Dicionario *novo=(Dicionario *)malloc(sizeof(Dicionario *));
			Palavra *nova=(Palavra *)malloc(sizeof(Palavra *));
			novo->proxP=NULL;
			nova->linha=linhaAtual;
			nova->repeticoes=1;

			strcpy(auxPalavra,novo->palavra);

			novo->proxD=dicionario;
			dicionario = novo;

			nova->prox=novo->proxP;
			novo->proxP=nova;
		}
		else{
			if(linhaAtual==d->proxP->linha)
				d->proxP->repeticoes++;
			else{
				Palavra *nova=(Palavra *)malloc(sizeof(Palavra *));
				nova->linha=linhaAtual;
				nova->repeticoes=1;

				nova->prox=d->proxP;
				d->proxP=nova;
			}
		}
		if(string[i]=='\n'){
			linhaAtual++;
			i++;
		}
	}
	return novo;
}
Palavra *iniciarPalavra(){
	Palavra *nova=(Palavra *)malloc(sizeof(Palavra *));
	nova->linha=linhaAtual;
	nova->repeticoes=1;

	return nova;
}
