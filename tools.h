void strrep(char *string, char *old, char *new) {
	char *newString = malloc(255);
	int i,j;
	for(i = 0; i < strlen(string); i++) {
		for (j =0; j < strlen(old); j++) {
			if(string[i] == old[j]) {
				newString[i] = new[j];
				continue;
			}
			newString[i] = string[i];
		}
	}
	strcpy(string, newString);
	free(newString);
}
