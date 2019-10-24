
 typedef struct {
	char *name;
	char *cpf;
	char *telefone;
	char *matricula;
	char *senha;
	int admin;
	
} Usuario;

 Usuario newUsuario(char *name, char *cpf, char *telefone, char *matricula, int admin) {
	Usuario usuario;
	usuario.name = name;
	usuario.cpf = cpf;
	usuario.telefone = telefone;
	usuario.matricula = matricula;
	usuario.admin = admin;
	return usuario;
}

 void registrarAdmin(Usuario usuario) {
	FILE *file = fopen("c:\\src\\newprogram.txt","r");
	char *teste[1000];
	char str[255];
	int i = 0, j = 0;
    while (fgets(str, 255, file) != NULL){
    	teste[i] = str;
    	i++;
	}
    fclose(file);
    FILE *file2 = fopen("c:\\src\\newprogram.txt","w");
    for(j = 0; j < i; j++) {
    	fprintf(file2,"%s", teste[j]);
	}
	fprintf(file2,"%s\n", usuario.name);
	fprintf(file2,"%s\n", usuario.telefone);
	fprintf(file2,"%s\n",usuario.cpf);
	fclose(file2);
}
