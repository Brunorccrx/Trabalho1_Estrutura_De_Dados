typedef struct no{
	int linha;
	int repeticoes;
	struct no *prox;
}No;

typedef struct dicionario{
	char palavra[20];
	struct no *proxN;
	struct dicionario *proxD;
}Dicionario;

char *lerArquivo();
Dicionario *buscaPalavra(Dicionario *dicionario,char *string);
Dicionario *inicializarDicionario();
Dicionario *inserirDicionario(Dicionario *dicionario,char *string);
No *inicializarNo();
No *inserirNo(No *n,int linhaAtual);
Dicionario *definirDicionario(Dicionario *dicionario,char *string);
void imprimirDicionario(Dicionario *dicionario);
