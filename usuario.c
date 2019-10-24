typedef struct {
	char *name;
	char *cpf;
	char *telefone;
	char *matricula;
	char *senha;
	int admin;
	
registrarAdm registrar;
} Usuario, *registrarAdm;

registrarAdm registerAdmin() {
	
}

Usuario newUsuario(char *name, char *cpf, char *telefone, char *matricula, int admin) {
	Usuario usuario;
	usuario.name = name;
	usuario.cpf = cpf;
	usuario.telefone = telefone;
	usuario.matricula = matricula;
	usuario.admin = admin;
	return usuario;
}

void registrarAdm(Usuario *)
