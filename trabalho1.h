typedef struct palavra{
	int linha;
	int repeticoes;
	struct palavra *prox;
}Palavra;

typedef struct dicionario{
	char palavra[20];
	struct palavra *proxP;
	struct dicionario *proxD;
}Dicionario;

char *lerArquivo();
Dicionario *definirDicionario(char *string, Dicionario *lista);
Dicionario *iniciarDicionario(Dicionario *dicionario);
 
