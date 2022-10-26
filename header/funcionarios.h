//struct para funcionarios

typedef struct{
	char name[51];
	char cpf[15];
	char email[51];
	char andreas[51];
	char birth[11];
	char phone[21];
}Funcionario;

//struct para os entry de funcionario

typedef struct
{
	GtkWidget *name;
	GtkWidget *cpf;
	GtkWidget *andreas;
	GtkWidget *birth;
	GtkWidget *email;
	GtkWidget *phone;
}EntryFuncionario;

// asssinatutas das funcoes

void delete_values_funcionario(GtkWidget *widget,EntryFuncionario *entrys,gpointer data);
void cadastar_funcionario(GtkWidget *btn,GtkWidget *widget,gpointer data);
void get_value_cadastro(GtkWidget *widget,EntryFuncionario *values,gpointer data);
