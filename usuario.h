
 typedef struct {
	char name[255];
	char cpf[255];
	char telefone[255];
	char matricula[255];
	char senha[255];
	int admin;
	
} Usuario;

 Usuario newUsuario(char name[255], char cpf[255], char telefone[255], int admin) {
	Usuario usuario;
	strcpy(usuario.name, name);
	strcpy(usuario.cpf, cpf);
	strcpy(usuario.telefone, telefone);
	usuario.admin = admin;
	int i = 0;
	char str[255];
	char randChar;
	 while(i < 6)
    {
        randChar = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789"[rand() % sizeof("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789")];
        str[i] = randChar;
        i++;
    }
    strcpy(usuario.matricula, str);
    i = 0;
    while(i < 6) {
    	 randChar = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789"[rand() % sizeof("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789")];
        str[i] = randChar;
        i++;
	}
	strcpy(usuario.senha, str);
	return usuario;
}

 void registrarAdmin(Usuario usuario) {
	FILE *file = fopen("c:\\src\\credenciais.dll","r");
	char teste[255][255];
	char str[255];
	int i = 0, j = 0;
    while (fgets(str, 255, file) != NULL) {
    	strcpy(teste[i],str);
    	i++;
	}
    fclose(file);
    FILE *file2 = fopen("c:\\src\\credenciais.dll","w");
    for(j = 0; j < i; j++) {
    	fprintf(file2,"%s", teste[j]);
	}
	fprintf(file2,"%s\n", usuario.name);
	fprintf(file2,"%s\n", usuario.telefone);
	fprintf(file2,"%s\n",usuario.cpf);
    fprintf(file2,"%s\n", usuario.matricula);
    fprintf(file2,"%s\n", usuario.senha);
	fclose(file2);
}
