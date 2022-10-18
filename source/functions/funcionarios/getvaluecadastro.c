#include <gtk/gtk.h>
#include <stdio.h>
#include <string.h>
#include "../../../header/funcionarios.h"


void get_value_cadastro(GtkWidget *widget,Entry *values ,gpointer data){


	Funcionario func;
	strcpy(func.name,gtk_entry_get_text(GTK_ENTRY(values->name)));
	strcpy(func.cpf,gtk_entry_get_text(GTK_ENTRY(values->cpf)));
	strcpy(func.andreas,gtk_entry_get_text(GTK_ENTRY(values->andreas)));
	strcpy(func.email,gtk_entry_get_text(GTK_ENTRY(values->email)));
	strcpy(func.birth,gtk_entry_get_text(GTK_ENTRY(values->birth)));
	strcpy(func.phone,gtk_entry_get_text(GTK_ENTRY(values->phone)));
	FILE *file;
	file = fopen("funcionarios.dat", "ab");
	fwrite(&func, 1, sizeof(Funcionario), file);
	fclose(file);

}