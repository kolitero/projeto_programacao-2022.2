void addProfissional(void);
void deleteProfissional(void);
void editProfissional(void);
void readProfissional(void);
void searchProfissional(void);

typedef struct{
	char name[51];
	char cpf[15];
	char email[51];
	char andreas[51];
	char birth[11];
	char existence;
}Profissional;