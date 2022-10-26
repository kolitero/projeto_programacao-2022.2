#include <gtk/gtk.h>
#include "../../header/components.h"
#include "../../header/utils.h"
#include "../../header/funcionarios.h"

//criar um menu que chamar as telas funcionario de cadastrar,deletar,editar,procurar e listar

void create_menu_funcionarios(GtkWidget *btn,GtkWidget *widget,gpointer data){
	//deletar a tela secundaria anterior
	delete_screen(widget);
	//definicao dos ponteiros
	GtkWidget *box;
	GtkWidget *frame;
	GtkWidget *button;
	GtkWidget *label;
	GtkWidget *separator;
	//frame que fica dentro de um box horizontal
	frame = gtk_frame_new(NULL);
	gtk_box_pack_start(GTK_BOX(widget),frame,TRUE,TRUE,100);
	//uma box vertical dentro do frame
	box = gtk_box_new(GTK_ORIENTATION_VERTICAL,0);
	gtk_container_set_border_width(GTK_CONTAINER(box),0);
	gtk_container_add(GTK_CONTAINER(frame),box);
	//label dentro da box vertfical
	label = gtk_label_new("menu funcionários");
	gtk_label_set_justify(GTK_LABEL(label),GTK_JUSTIFY_CENTER);
	gtk_box_pack_start(GTK_BOX(box), label,FALSE,FALSE,20);
	//separa o label dos buttons
	separator = gtk_separator_new(GTK_ORIENTATION_VERTICAL);
	gtk_box_pack_start(GTK_BOX(box), separator,FALSE,FALSE,0);
	//buttoes dentro de uma box vertfical
	button = gtk_button_new_with_label("cadastrar funcionário");
	gtk_box_pack_start(GTK_BOX(box), button,TRUE,TRUE,0);
	gtk_button_set_relief(GTK_BUTTON(button),GTK_RELIEF_NONE);
	g_signal_connect(button,"clicked",G_CALLBACK(cadastar_funcionario),widget);
	button = gtk_button_new_with_label("deletar funcionário");
	gtk_box_pack_start(GTK_BOX(box), button,TRUE,TRUE,0);
	gtk_button_set_relief(GTK_BUTTON(button),GTK_RELIEF_NONE);
	button = gtk_button_new_with_label("editar funcionários");
	gtk_box_pack_start(GTK_BOX(box), button,TRUE,TRUE,0);
	gtk_button_set_relief(GTK_BUTTON(button),GTK_RELIEF_NONE);
	button = gtk_button_new_with_label("procurar funcionários");
	gtk_box_pack_start(GTK_BOX(box), button,TRUE,TRUE,0);
	gtk_button_set_relief(GTK_BUTTON(button),GTK_RELIEF_NONE);
	button = gtk_button_new_with_label("listar todos os funcionários");
	gtk_box_pack_start(GTK_BOX(box), button,TRUE,TRUE,0);
	gtk_button_set_relief(GTK_BUTTON(button),GTK_RELIEF_NONE);
	//mostrar tudo dentro do frame
	gtk_widget_show_all(frame);
} 