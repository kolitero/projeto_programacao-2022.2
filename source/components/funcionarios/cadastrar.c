#include <gtk/gtk.h>
#include "../../../header/components.h"
#include "../../../header/utils.h"
#include "../../../header/funcionarios.h"

// tela de casdastro de funcionario

void cadastar_funcionario(GtkWidget *btn,GtkWidget *widget,gpointer data){
	//deletar o menu funcionario
	delete_screen(widget);
	//definicao dos ponteiros
	EntryFuncionario *entrys;
	entrys = malloc(sizeof(EntryFuncionario));
	GtkWidget *frame[7];
	GtkWidget *hbox[4];
	GtkWidget *vbox;
	GtkWidget *label;
	GtkWidget *button;
	//atribuindo valores aos ponteiros
	vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL,10);
	hbox[0] = gtk_box_new(GTK_ORIENTATION_HORIZONTAL,10);
	hbox[1] = gtk_box_new(GTK_ORIENTATION_HORIZONTAL,10);
	hbox[2] = gtk_box_new(GTK_ORIENTATION_HORIZONTAL,10);
	hbox[3] = gtk_box_new(GTK_ORIENTATION_HORIZONTAL,10);
	frame[0] = gtk_frame_new(NULL);
	frame[1] = gtk_frame_new("nome:");
	frame[2] = gtk_frame_new("cpf:");
	frame[3] = gtk_frame_new("endereço:");
	frame[4] = gtk_frame_new("email:");
	frame[5] = gtk_frame_new("data de nascimento:");
	frame[6] = gtk_frame_new("telefone:");
	entrys = malloc(sizeof(EntryFuncionario));
	entrys->name  = gtk_entry_new();
	entrys->cpf = gtk_entry_new();
	entrys->andreas = gtk_entry_new();
	entrys->email = gtk_entry_new();
	entrys->birth = gtk_entry_new();
	entrys->phone = gtk_entry_new();
	label = gtk_label_new("cadastro de funcionário");
	button = gtk_button_new_with_label("cadastrar");
	//configurando propriedades
	gtk_entry_set_has_frame(GTK_ENTRY(entrys->name),FALSE);
	gtk_entry_set_has_frame(GTK_ENTRY(entrys->cpf),FALSE);
	gtk_entry_set_has_frame(GTK_ENTRY(entrys->andreas),FALSE);
	gtk_entry_set_has_frame(GTK_ENTRY(entrys->email),FALSE);
	gtk_entry_set_has_frame(GTK_ENTRY(entrys->birth),FALSE);
	gtk_entry_set_has_frame(GTK_ENTRY(entrys->phone),FALSE);
	gtk_label_set_justify(GTK_LABEL(label),GTK_JUSTIFY_CENTER);
	//composicao dos widgets
	gtk_box_pack_start(GTK_BOX(widget),frame[0],TRUE,TRUE,20);
	gtk_container_add(GTK_CONTAINER(frame[0]),vbox);
	gtk_box_pack_start(GTK_BOX(vbox), label,FALSE,FALSE,20);
	gtk_box_pack_start(GTK_BOX(vbox),hbox[0],FALSE,FALSE,20);
	gtk_box_pack_start(GTK_BOX(vbox),hbox[1],FALSE,FALSE,20);
	gtk_box_pack_start(GTK_BOX(vbox),hbox[2],FALSE,FALSE,20);
	gtk_box_pack_end(GTK_BOX(vbox),hbox[3],FALSE,FALSE,20);
	gtk_box_pack_start(GTK_BOX(hbox[0]),frame[1],TRUE,TRUE,20);
	gtk_box_pack_start(GTK_BOX(hbox[0]),frame[2],FALSE,FALSE,20);
	gtk_box_pack_start(GTK_BOX(hbox[1]),frame[3],TRUE,TRUE,20);
	gtk_box_pack_start(GTK_BOX(hbox[1]),frame[4],TRUE,TRUE,20);
	gtk_box_pack_start(GTK_BOX(hbox[2]),frame[5],TRUE,TRUE,20);
	gtk_box_pack_start(GTK_BOX(hbox[2]),frame[6],TRUE,TRUE,20);
	gtk_box_pack_end(GTK_BOX(hbox[3]),button,FALSE,FALSE,20);
	gtk_container_add(GTK_CONTAINER(frame[1]),entrys->name );
	gtk_container_add(GTK_CONTAINER(frame[2]),entrys->cpf);
	gtk_container_add(GTK_CONTAINER(frame[3]),entrys->andreas);
	gtk_container_add(GTK_CONTAINER(frame[4]),entrys->email);
	gtk_container_add(GTK_CONTAINER(frame[5]),entrys->birth);
	gtk_container_add(GTK_CONTAINER(frame[6]),entrys->phone);
	//signal
	g_signal_connect (G_OBJECT(entrys->name),"key_release_event",G_CALLBACK(enter_detector),entrys->cpf);
	g_signal_connect (G_OBJECT(entrys->cpf),"key_release_event",G_CALLBACK(enter_detector),entrys->andreas);
	g_signal_connect (G_OBJECT(entrys->andreas),"key_release_event",G_CALLBACK(enter_detector),entrys->email);
	g_signal_connect (G_OBJECT(entrys->email),"key_release_event",G_CALLBACK(enter_detector),entrys->birth);
	g_signal_connect (G_OBJECT(entrys->birth),"key_release_event",G_CALLBACK(enter_detector),entrys->phone);
	g_signal_connect (G_OBJECT(entrys->phone),"key_release_event",G_CALLBACK(enter_detector),button);
	g_signal_connect (G_OBJECT(button),"clicked",G_CALLBACK(get_value_cadastro),entrys);
	g_signal_connect (G_OBJECT(frame[0]),"destroy",G_CALLBACK(delete_values_funcionario),entrys);
	//mostrar todos widgets dentro de frame[0]
	gtk_widget_show_all(frame[0]);
} 

//liberar a struct com ponteiros dos entry

void delete_values_funcionario(GtkWidget *widget,EntryFuncionario *entrys,gpointer data){
	free(entrys);
}