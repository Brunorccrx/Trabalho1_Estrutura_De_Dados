#include<stdio.h>
#include"trabalho1.h"
#include<string.h>
#include <stdlib.h>

int main(void){

char *string;
Dicionario *dicionario;
dicionario=inicializarDicionario();


string=lerArquivo();

dicionario=definirDicionario(dicionario,string);

imprimirDicionario(dicionario);
return 0;
}

/*Saida
a(8,1)
Rayman(6,1)
DonkeyKong(6,1)
KaiginAtlasReactor(5,2)
Kirby(4,2)
Caixa(3,1)
Crash(3,1)(6,2)(7,1)
rupee(2,1)
Link(2,1)
anel(1,1)
Sonic(1,1)(4,1)
casco(0,1)
estrela(0,1)
bau (0,1)(2,1)
Mario (0,1)(4,1)
*/
