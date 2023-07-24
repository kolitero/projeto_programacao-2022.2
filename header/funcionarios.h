//struct para funcionarios

typedef struct{
	char name[51];
	char cpf[15];
	char email[51];
	char andreas[51];
	char birth[11];
	char phone[21];
	char avaliable;
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


typedef struct parament_pesquise
{
	GtkWidget *vbox;
	GtkWidget *entry;
}Parament_pesquise;

// asssinatutas das funcoes

void func_edit_activate(GtkWidget *widget,Parament_pesquise *container,gpointer data);
void func_show_activate(GtkWidget *widget,Parament_pesquise *container,gpointer data);
void func_show_all_activate(Parament_pesquise *container);
void delete_value_funcionario(GtkWidget *widget,GtkWidget *entry,gpointer data);
void delete_values_funcionario(GtkWidget *widget,EntryFuncionario *entrys,gpointer data);
void cadastar_funcionario(GtkWidget *btn,GtkWidget *widget,gpointer data);
void pesquisar_funcionario(GtkWidget *btn,GtkWidget *widget,gpointer data);
void show_funcionario(GtkWidget *btn,GtkWidget *widget,gpointer data);
void show_all_funcionario(GtkWidget *btn,GtkWidget *widget,gpointer data);
void editar_funcionario(GtkWidget *widget,Funcionario func);
void monstrar_funcionario(GtkWidget *widget,Funcionario func);
void delete_funcionario(GtkWidget *btn,GtkWidget *widget,gpointer data);
void cadastar_value_funcionario(GtkWidget *widget,EntryFuncionario *values,gpointer data);
void edit_value_funcionario(GtkWidget *widget,EntryFuncionario *values ,gpointer data);
