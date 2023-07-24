#include <gtk/gtk.h>
#include "../../../header/components.h"
#include "../../../header/utils.h"
#include "../../../header/funcionarios.h"


// monstrar um funcionario

void monstrar_funcionario(GtkWidget *widget,Funcionario func){
	//definicao dos ponteiros
	EntryFuncionario *entrys;
	entrys = malloc(sizeof(EntryFuncionario));
	GtkWidget *frame[7];
	GtkWidget *hbox[3];
	GtkWidget *vbox;
	GtkWidget *label;
	//atribuindo valores aos ponteiros
	vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL,10);
	hbox[0] = gtk_box_new(GTK_ORIENTATION_HORIZONTAL,10);
	hbox[1] = gtk_box_new(GTK_ORIENTATION_HORIZONTAL,10);
	hbox[2] = gtk_box_new(GTK_ORIENTATION_HORIZONTAL,10);
	frame[0] = gtk_frame_new(NULL);
	frame[1] = gtk_frame_new("nome:");
	frame[2] = gtk_frame_new("cpf:");
	frame[3] = gtk_frame_new("endereço:");
	frame[4] = gtk_frame_new("email:");
	frame[5] = gtk_frame_new("data de nascimento:");
	frame[6] = gtk_frame_new("telefone:");
	entrys = malloc(sizeof(EntryFuncionario));
	entrys->name  = gtk_label_new(func.name);
	entrys->cpf = gtk_label_new(func.cpf);
	entrys->andreas = gtk_label_new(func.andreas);
	entrys->email = gtk_label_new(func.email);
	entrys->birth = gtk_label_new(func.birth);
	entrys->phone = gtk_label_new(func.phone);
	label = gtk_label_new("funcionário:");
	//configurando propriedades
    gtk_label_set_justify(GTK_LABEL(entrys->name),GTK_JUSTIFY_LEFT);
    gtk_label_set_justify(GTK_LABEL(entrys->cpf),GTK_JUSTIFY_LEFT);
    gtk_label_set_justify(GTK_LABEL(entrys->andreas),GTK_JUSTIFY_LEFT);
    gtk_label_set_justify(GTK_LABEL(entrys->email),GTK_JUSTIFY_LEFT);
    gtk_label_set_justify(GTK_LABEL(entrys->birth),GTK_JUSTIFY_LEFT);
    gtk_label_set_justify(GTK_LABEL(entrys->phone),GTK_JUSTIFY_LEFT);
	gtk_label_set_justify(GTK_LABEL(label),GTK_JUSTIFY_CENTER);
	//composicao dos widgets
	gtk_box_pack_start(GTK_BOX(widget),frame[0],TRUE,TRUE,20);
	gtk_container_add(GTK_CONTAINER(frame[0]),vbox);
	gtk_box_pack_start(GTK_BOX(vbox), label,FALSE,FALSE,20);
	gtk_box_pack_start(GTK_BOX(vbox),hbox[0],FALSE,FALSE,20);
	gtk_box_pack_start(GTK_BOX(vbox),hbox[1],FALSE,FALSE,20);
	gtk_box_pack_start(GTK_BOX(vbox),hbox[2],FALSE,FALSE,20);
	gtk_box_pack_start(GTK_BOX(hbox[0]),frame[1],TRUE,TRUE,20);
	gtk_box_pack_start(GTK_BOX(hbox[0]),frame[2],FALSE,FALSE,20);
	gtk_box_pack_start(GTK_BOX(hbox[1]),frame[3],TRUE,TRUE,20);
	gtk_box_pack_start(GTK_BOX(hbox[1]),frame[4],TRUE,TRUE,20);
	gtk_box_pack_start(GTK_BOX(hbox[2]),frame[5],TRUE,TRUE,20);
	gtk_box_pack_start(GTK_BOX(hbox[2]),frame[6],TRUE,TRUE,20);
	gtk_container_add(GTK_CONTAINER(frame[1]),entrys->name );
	gtk_container_add(GTK_CONTAINER(frame[2]),entrys->cpf);
	gtk_container_add(GTK_CONTAINER(frame[3]),entrys->andreas);
	gtk_container_add(GTK_CONTAINER(frame[4]),entrys->email);
	gtk_container_add(GTK_CONTAINER(frame[5]),entrys->birth);
	gtk_container_add(GTK_CONTAINER(frame[6]),entrys->phone);
	//signal
	g_signal_connect (G_OBJECT(frame[0]),"destroy",G_CALLBACK(delete_values_funcionario),entrys);
	//mostrar todos widgets dentro de frame[0]
	gtk_widget_show_all(frame[0]);
} 