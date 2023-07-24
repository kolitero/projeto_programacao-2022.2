#include <gtk/gtk.h>
#include <stdio.h>
#include <string.h>
#include "../../../header/funcionarios.h"

//pegar e salvar os valores dos entry de cadastro

void cadastar_value_funcionario(GtkWidget *widget,EntryFuncionario *values ,gpointer data){
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
	func.avaliable = 'y';
	file = fopen("funcionarios.dat", "ab");
	if(!file){
            exit(1);
    }
	//salvando em binario
	fwrite(&func, 1, sizeof(Funcionario), file);
	fclose(file);
}

//editar os valores de um funcionario no aquirvo binario

void edit_value_funcionario(GtkWidget *widget,EntryFuncionario *values ,gpointer data){
	//definindo variaveis
	FILE *file,*back;
	Funcionario func,func_read;
	//atribuindo valores
	strcpy(func.name,gtk_entry_get_text(GTK_ENTRY(values->name)));
	strcpy(func.cpf,gtk_label_get_label(GTK_LABEL(values->cpf)));
	strcpy(func.andreas,gtk_entry_get_text(GTK_ENTRY(values->andreas)));
	strcpy(func.email,gtk_entry_get_text(GTK_ENTRY(values->email)));
	strcpy(func.birth,gtk_entry_get_text(GTK_ENTRY(values->birth)));
	strcpy(func.phone,gtk_entry_get_text(GTK_ENTRY(values->phone)));
	func.avaliable = 'y';
	file = fopen("funcionarios.dat", "rb");
	back = fopen("funcionariosback.dat","ab");
	if(!file){
            exit(1);
    }
	//editando em binario
	while(fread(&func_read,sizeof(Funcionario),1,file)){
		if(!strcmp(func_read.cpf,func.cpf)){
			fwrite(&func,1,sizeof(Funcionario),back);
		}else{
			fwrite(&func_read,1,sizeof(Funcionario),back);
		}
	}
	fclose(file);
	fclose(back);
	remove("funcionarios.dat");
	rename("funcionariosback.dat","funcionarios.dat");
}

// deletar um usuario

void delete_value_funcionario(GtkWidget *widget,GtkWidget *entry,gpointer data){
	//definindo variaveis
	FILE *file,*back;
	char cpf[15];
	Funcionario func_read;
    strncpy(cpf,gtk_entry_get_text(GTK_ENTRY(entry)),15);
	file = fopen("funcionarios.dat", "rb");
	back = fopen("funcionariosback.dat","ab");
	if(!file){
            exit(1);
    }
	//editando em binario
	while(fread(&func_read,sizeof(Funcionario),1,file)){
		if(!strcmp(func_read.cpf,cpf)){
			func_read.avaliable = 'n';
			fwrite(&func_read,1,sizeof(Funcionario),back);
		}else{
			fwrite(&func_read,1,sizeof(Funcionario),back);
		}
	}
	fclose(file);
	fclose(back);
	remove("funcionarios.dat");
	rename("funcionariosback.dat","funcionarios.dat");
}