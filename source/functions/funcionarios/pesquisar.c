#include <gtk/gtk.h>
#include <string.h>
#include <stdio.h>
#include "../../../header/utils.h"
#include "../../../header/funcionarios.h"



void func_edit_activate(GtkWidget *widget,Parament_pesquise *container,gpointer data){
    char is = 'n';
    char cpf[15];
    int s;
    strncpy(cpf,gtk_entry_get_text(GTK_ENTRY(container->entry)),15);
    Funcionario func;
    FILE *file;
    file = fopen("funcionarios.dat","rb");
    if(!file){
        putchar('9');
        exit(1);
    }
    while(fread(&func,sizeof(Funcionario),1,file)){
        s = strcmp(func.cpf,cpf);
        printf("%d\n",s);
        if (s == 0 && func.avaliable == 'y'){
            putchar('1');
            putchar('2');
            putchar('3');
            is = 'y';
            break;
        }
    }
    if(is == 'n'){
        fclose(file);
        delete_screen(container->vbox);
        GtkWidget *show;
        show = gtk_label_new("inexistente");
        gtk_container_add(GTK_CONTAINER(container->vbox),show);
        gtk_widget_show_all(container->vbox);
    }else if (is == 'y'){
        delete_screen(container->vbox);
        fclose(file);
        editar_funcionario(container->vbox,func);
    }
}

void func_show_activate(GtkWidget *widget,Parament_pesquise *container,gpointer data){
    char is = 'n';
    char cpf[15];
    int s;
    strncpy(cpf,gtk_entry_get_text(GTK_ENTRY(container->entry)),15);
    Funcionario func;
    FILE *file;
    file = fopen("funcionarios.dat","rb");
    if(!file){
        putchar('9');
        exit(1);
    }
    while(fread(&func,sizeof(Funcionario),1,file)){
        s = strcmp(func.cpf,cpf);
        printf("%d\n",s);
        if (s == 0 && func.avaliable == 'y'){
            putchar('1');
            putchar('2');
            putchar('3');
            is = 'y';
            break;
        }
        
    }
    fclose(file);
    if(is == 'n'){
        delete_screen(container->vbox);
        GtkWidget *show;
        show = gtk_label_new("inexistente");
        gtk_container_add(GTK_CONTAINER(container->vbox),show);
        gtk_widget_show_all(container->vbox);
    }else if (is == 'y'){
        delete_screen(container->vbox);
        monstrar_funcionario(container->vbox,func);
    }
}

void func_show_all_activate(Parament_pesquise *container){
    Funcionario func;
    FILE *file;
    file = fopen("funcionarios.dat","rb");
    if(!file){
        putchar('9');
        exit(1);
    }
    while(fread(&func,sizeof(Funcionario),1,file)){
        if(func.avaliable == 'y'){
            monstrar_funcionario(container->vbox,func);
        }
    }
    fclose(file);
}

