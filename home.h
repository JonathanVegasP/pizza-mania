enum {
	REGISTRAR_BEBIDAS = 1,
	REGISTRAR_SABORES = 2,
	REGISTRAR_PIZZAIOLOS = 3,
	REGISTRAR_PEDIDOS = 4,
	REGISTRAR_CLIENTES = 5,
	REGISTRAR_RECLAMACOES = 6,
	REGISTRAR_ELOGIOS = 7,
	REGISTRAR_PROMOCOES = 8,
} homeState;

 void homeScreen() {
	printf("###  ##  ##########################################  ##  ###\n");
	printf("##  ####  ########################################  ####  ##\n");
	printf("##  ####  ####### Para sair insira ctrl+ c #######  ####  ##\n");
	printf("##  ####  ########################################  ####  ##\n");
	printf("##  ####  ### Selecione um dos métodos abaixo ####  ####  ##\n");
	printf("##  ####  ########################################  ####  ##\n");
	printf("##  ####  ########################################  ####  ##\n\n");
	printf("1) Registar Bebidas\n\n");
	printf("2) Registrar Sabores\n\n");
	printf("3) Registrar Pizzaiolos\n\n");
	printf("4) Registrar Clientes\n\n");
	printf("5) Registrar Reclamações\n\n");
	printf("6) Registrar Elogios\n\n");
	printf("7) Registrar Promocoes\n\n");
	scanf("%d", &homeState);
	switch(homeState){
		case REGISTRAR_BEBIDAS:
			printf("Open the Bebidas screnn");
		break; 
		case REGISTRAR_SABORES:
			break;
		case REGISTRAR_PIZZAIOLOS:
			break;
		case REGISTRAR_CLIENTES:
			break;
		case REGISTRAR_RECLAMACOES:
			break;
		case REGISTRAR_ELOGIOS:
			break;
		case REGISTRAR_PROMOCOES:
			break;
		default:
			break;
	}
}

