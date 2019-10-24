#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <strings.h>
#include <conio.h>
#include <math.h>
#include "usuario.c"
#include "state.c"
#include "admin.c"
#include "home.c"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void requestMatricula(char *matricula) {
	printf("Insira a sua matrícula\n");
	gets(matricula);
}

void requestSenha(char *senha) {
	printf("Insira a sua senha\n");
	gets(senha);
}

int main(int argc, char *argv[]) {
	setlocale(LC_ALL, "Portuguese");
	printf("###  ##  ##########################################  ##  ###\n");
	printf("##  ####  ########################################  ####  ##\n");
	printf("##  ####  ####### Para sair insira ctrl+ c #######  ####  ##\n");
	printf("##  ####  ########################################  ####  ##\n");
	printf("##  ####  ########################################  ####  ##\n\n");
	do {
		char matricula[6];
		char senha[256];
		requestMatricula(&matricula);
		requestSenha(&senha);
		if(strcasecmp(&matricula, "123456") == 0 && strcasecmp(&senha,"123456") == 0) {
			adminScreen();
		}
		
	}while(state != EXIT);
	return 0;
}

