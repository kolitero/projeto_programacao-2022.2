#include <gtk/gtk.h>
#include "../../../header/components.h"
#include "../../../header/utils.h"
#include "../../../header/funcionarios.h"
// tela de casdastro de funcionario


void delete_values_funcionario(GtkWidget *widget,Entry *entrys,gpointer data);

void cadastar_funcionario(GtkWidget *btn,GtkWidget *widget,gpointer data){
	
	delete_screen(widget);

	Entry *entrys;
	entrys = malloc(sizeof(Entry));
	GtkWidget *entry[6];
	GtkWidget *frame[9];
	GtkWidget *hbox[4];
	GtkWidget *vbox;
	GtkWidget *label;
	GtkWidget *button;

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

	entry[0] = gtk_entry_new();
	entry[1] = gtk_entry_new();
	entry[2] = gtk_entry_new();
	entry[3] = gtk_entry_new();
	entry[4] = gtk_entry_new();
	entry[5] = gtk_entry_new();



	label = gtk_label_new("cadastro de funcionário");

	button = gtk_button_new_with_label("cadastrar");


	gtk_entry_set_has_frame(GTK_ENTRY(entry[0]),FALSE);
	gtk_entry_set_has_frame(GTK_ENTRY(entry[1]),FALSE);
	gtk_entry_set_has_frame(GTK_ENTRY(entry[2]),FALSE);
	gtk_entry_set_has_frame(GTK_ENTRY(entry[3]),FALSE);
	gtk_entry_set_has_frame(GTK_ENTRY(entry[4]),FALSE);
	gtk_entry_set_has_frame(GTK_ENTRY(entry[5]),FALSE);
	gtk_label_set_justify(GTK_LABEL(label),GTK_JUSTIFY_CENTER);


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
	gtk_container_add(GTK_CONTAINER(frame[1]),entry[0]);
	gtk_container_add(GTK_CONTAINER(frame[2]),entry[1]);
	gtk_container_add(GTK_CONTAINER(frame[3]),entry[2]);
	gtk_container_add(GTK_CONTAINER(frame[4]),entry[3]);
	gtk_container_add(GTK_CONTAINER(frame[5]),entry[4]);
	gtk_container_add(GTK_CONTAINER(frame[6]),entry[5]);

	entrys->name = entry[0];
	entrys->cpf = entry[1];
	entrys->andreas = entry[2];
	entrys->email = entry[3];
	entrys->birth = entry[4];
	entrys->phone = entry[5];

	//signal
	g_signal_connect (G_OBJECT(entry[0]),"key_release_event",G_CALLBACK(enter_detector),entry[1]);
	g_signal_connect (G_OBJECT(entry[1]),"key_release_event",G_CALLBACK(enter_detector),entry[2]);
	g_signal_connect (G_OBJECT(entry[2]),"key_release_event",G_CALLBACK(enter_detector),entry[3]);
	g_signal_connect (G_OBJECT(entry[3]),"key_release_event",G_CALLBACK(enter_detector),entry[4]);
	g_signal_connect (G_OBJECT(entry[4]),"key_release_event",G_CALLBACK(enter_detector),entry[5]);
	g_signal_connect (G_OBJECT(entry[5]),"key_release_event",G_CALLBACK(enter_detector),button);
	g_signal_connect (G_OBJECT(button),"clicked",G_CALLBACK(get_value_cadastro),entrys);
	g_signal_connect (G_OBJECT(frame[0]),"destroy",G_CALLBACK(delete_values_funcionario),entrys);

	gtk_widget_show_all(frame[0]);
	
} 

void delete_values_funcionario(GtkWidget *widget,Entry *entrys,gpointer data){
	free(entrys);
}