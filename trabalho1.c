#include"trabalho1.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char *lerArquivo(){
	FILE *p_Arquivo;
	char *string=(char *)malloc(1000000000*sizeof(char));
	int i;
	int c;
  p_Arquivo = fopen("Entrada.txt","r");
  for(i=0;!feof(p_Arquivo);i++){
		c=fgetc(p_Arquivo);
			string[i]=c;
	}
	string[i-1]='\0';
  fclose(p_Arquivo);
	return string;
}

Dicionario *buscaPalavra(Dicionario *dicionario,char *string){
	Dicionario *d=NULL;

	for(d=dicionario;d!=NULL && strcmp(d->palavra,string)!=0;d=d->proxD){

	}
	return d;
}

No *inicializarNo(){
	return NULL;
}
No *inserirNo(No *n,int linhaAtual){
	No *novo=(No *)malloc(sizeof(No));
	novo->linha=linhaAtual;
	novo->repeticoes=1;

	novo->prox=n;
	n=novo;

	return novo;
}
Dicionario *inicializarDicionario(){
	return NULL;
}
Dicionario *inserirDicionario(Dicionario *dicionario,char *string){
	Dicionario *novo=(Dicionario *)malloc(sizeof(Dicionario));
	novo->proxN=inicializarNo();
	strcpy(novo->palavra,string);
	novo->proxD=dicionario;
	dicionario=novo;

	return novo;
}


Dicionario *definirDicionario(Dicionario *dicionario,char *string){
	int i;
	int j=0;
	int linhaAtual=0;
	Dicionario *daux=NULL;

	for(i=0;i<strlen(string);j=0){
		char *auxPalavra=(char *)malloc(20*sizeof(char));
		while(string[i]!=' ' && string[i]!='\n' && string[i]!=13){//13 se refere a retorno do começo da linha
			auxPalavra[j]=string[i];
			i++;
			j++;
		}

//Remover lixo que ficou armazenado no vetor após a leitura do arquivo
	if(auxPalavra[3]<32){
		if(auxPalavra[1]==47)
			auxPalavra[1]='\0';
		else if(auxPalavra[2]==46)
			auxPalavra[2]='\0';
		else
			auxPalavra[3]='\0';
	}
	if(auxPalavra[11]<32){
		if(auxPalavra[8]==40)
			auxPalavra[8]='\0';
		else if(auxPalavra[9]==47)
			auxPalavra[9]='\0';
		else if(auxPalavra[10]==46)
			auxPalavra[10]='\0';
		else
			auxPalavra[11]='\0';
		}

	daux=buscaPalavra(dicionario,auxPalavra);

	if(daux==NULL){//Palavra nova que não está no dicionário
		dicionario=inserirDicionario(dicionario,auxPalavra);
		dicionario->proxN=inserirNo(dicionario->proxN,linhaAtual);
	}
	else if(daux->proxN->linha==linhaAtual){//Repetição de palavra na mesma linha
		daux->proxN->repeticoes++;
	}
	else{//Repetição de palavra em linha diferente
		daux->proxN=inserirNo(daux->proxN,linhaAtual);
	}

	 while(string[i]==' ' || string[i]==13)//pular espaços
		i++;

	 if(string[i]=='\n'){//Mudança de linha
	 	 linhaAtual++;
		 i++;
	 }


	free(auxPalavra);//Libera a palavra para ser utilizada novamente
}
	return dicionario;
}

void imprimirDicionario(Dicionario *dicionario){
	Dicionario *d;
	No *n;

	for(d=dicionario;d!=NULL;d=d->proxD){
		printf("%s:",d->palavra);
		for(n=d->proxN;n!=NULL;n=n->prox){
			if(n->prox==NULL)
				printf("(%d,%d)",n->linha,n->repeticoes);
			else
				printf("(%d,%d), ",n->linha,n->repeticoes);
		}
		printf("\n");
	}
}
