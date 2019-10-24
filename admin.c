enum {
	REGISTRAR_ADMINISTRADOR = 1,
	VISUALIZAR_RELATORIOS = 2,
} adminState;

void registrarAdm() {
	char name[256];
	char telefone[15];
	char cpf[14];
	char matricula[6];
	printf("Insira o nome do administrador");
	gets(name);
	printf("Insira o número para contato do administrador");
	gets(telefone);
	printf("Insira o cpf do administrador");
	gets(cpf);
	Usuario user = newUsuario(&name,&cpf,&telefone,&matricula,1);
	user.registrarAdm();
	user.
}

void adminScreen() {
	printf("###  ##  ##########################################  ##  ###\n");
	printf("##  ####  ########################################  ####  ##\n");
	printf("##  ####  ####### Para sair insira ctrl+ c #######  ####  ##\n");
	printf("##  ####  ########################################  ####  ##\n");
	printf("##  ####  ### Selecione um dos métodos abaixo ####  ####  ##\n");
	printf("##  ####  ########################################  ####  ##\n");
	printf("##  ####  ########################################  ####  ##\n\n");
	printf("1) Registar um administrador da aplicação\n\n");
	printf("2) Visualizar o relatório\n\n");
	scanf("%d", &adminState);
	switch(adminState) {
		case REGISTRAR_ADMINISTRADOR:
			registrarAdm();
			break;
		case VISUALIZAR_RELATORIOS:
			break;
	}
	
}
