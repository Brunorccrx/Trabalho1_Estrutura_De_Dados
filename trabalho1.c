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

Palavra *iniciarPalavra(){
	Palavra *nova=(Palavra *)malloc(sizeof(Palavra *));
	nova->linha=linhaAtual;
	nova->repeticoes=1;

	return nova;
}
