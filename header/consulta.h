void addConsulta(void);
void deleteConsulta(void);
void editConsulta(void);
void readConsulta(void);
void searchConsulta(void);
void arquivarConsulta(void);

typedef struct{
	char value[10];
	char cpf[15];
    char doctor[15];
    char date[11];
}Pagamento;


typedef struct{
	char name[51];
	char cpf[15];
	char phone[21];
    char doctor[15];
    char date[11];
}Consulta;