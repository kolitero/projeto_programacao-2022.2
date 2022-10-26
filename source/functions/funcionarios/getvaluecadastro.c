#include <gtk/gtk.h>
#include <stdio.h>
#include <string.h>
#include "../../../header/funcionarios.h"

//pegar e salvar os valores dos entry de cadastro

void get_value_cadastro(GtkWidget *widget,EntryFuncionario *values ,gpointer data){
	//definindo variaveis
	FILE *file;
	Funcionario func;
	//atribuindo valores
	strcpy(func.name,gtk_entry_get_text(GTK_ENTRY(values->name)));
	strcpy(func.cpf,gtk_entry_get_text(GTK_ENTRY(values->cpf)));
	strcpy(func.andreas,gtk_entry_get_text(GTK_ENTRY(values->andreas)));
	strcpy(func.email,gtk_entry_get_text(GTK_ENTRY(values->email)));
	strcpy(func.birth,gtk_entry_get_text(GTK_ENTRY(values->birth)));
	strcpy(func.phone,gtk_entry_get_text(GTK_ENTRY(values->phone)));
	file = fopen("funcionarios.dat", "ab");
	//salvando em binario
	fwrite(&func, 1, sizeof(Funcionario), file);
	fclose(file);
}