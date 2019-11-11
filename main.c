#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <strings.h>
#include <conio.h>
#include <math.h>
#include "usuario.h"
#include "state.h"
#include "admin.h"
#include "home.h"
#include "tools.h"
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
		FILE *file;
		Usuario user[4];
		if((file = fopen("c:\\src\\credenciais.dll","r")) != NULL) {
			int i =0, j = 0;
			char string[255];
			while(fgets(string,255,file) != NULL) {
				switch(i) {
					case 0:
						strrep(string,"\n","");
					strcpy(user[j].name,string);
					i++;
					break;
					case  1:
						strrep(string,"\n","");
					strcpy(user[j].telefone,string);
					i++;
					break;
					case 2:
						strrep(string,"\n","");
						strcpy(user[j].cpf, string);
						i++;
						break;
					case 3:
						strrep(string,"\n","");
						strcpy(user[j].matricula,string);
						i++;
						break;
					case 4:
						strrep(string,"\n","");
						printf("%s",string);
						strcpy(user[j].senha,string);
						i = 0;
						j++;
						break;
				}
			}
			fclose(file);
		}
		char matricula[6];
		char senha[255];
		requestMatricula(matricula);
		requestSenha(senha);
		int i;
		for(i = 0; i< sizeof(user); i++) {
			if(file != NULL && user[i].matricula != NULL)
			if(strcmp(matricula, user[i].matricula) == 0 && strcmp(senha,user[i].senha) == 0) {
				while(state != EXIT) {
					system("cls");
					adminScreen();
				}
				break;
			} else {
				
			}
		}
		
		
	}while(state != EXIT);
	return 0;
}

