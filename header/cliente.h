void addCliente(void);
void deleteCliente(void);
void editCliente(void);
void readCliente(void);
void searchCliente(void);

typedef struct{
	char name[51];
	char cpf[15];
	char email[51];
	char phone[21];
	char birth[11];
	char existence;
}Cliente;