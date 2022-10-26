#include <gtk/gtk.h>
#include "../../header/components.h"
#include "../../header/utils.h"

//criar um siderbar usado para se tranfirir entre os modulos

void create_sidebar(GtkWidget *widget){
	//definifacao dos ponteiros
	GtkWidget *box;
	GtkWidget *frame;
	GtkWidget *button;
	GtkWidget *label;
	//frame que fica dentro de um box horizontal
	frame = gtk_frame_new(NULL);
	gtk_box_pack_start(GTK_BOX(widget),frame,FALSE,FALSE,0);
	//uma box vertical dentro do frame
	box = gtk_box_new(GTK_ORIENTATION_VERTICAL,0);
	gtk_container_set_border_width(GTK_CONTAINER(box),0);
	gtk_container_add(GTK_CONTAINER(frame),box);
	//4 buttons dentro da uma box vertical
	button = gtk_button_new_with_label("consultas");
	gtk_box_pack_start(GTK_BOX(box), button,TRUE,TRUE,0);
	gtk_button_set_relief(GTK_BUTTON(button),GTK_RELIEF_NONE);
	g_signal_connect(button,"clicked",G_CALLBACK(create_menu_consultas),widget);
	button = gtk_button_new_with_label("clientes");
	gtk_box_pack_start(GTK_BOX(box), button,TRUE,TRUE,0);
	gtk_button_set_relief(GTK_BUTTON(button),GTK_RELIEF_NONE);
	g_signal_connect(button,"clicked",G_CALLBACK(create_menu_clientes),widget);
	button = gtk_button_new_with_label("funcionários");
	gtk_box_pack_start(GTK_BOX(box), button,TRUE,TRUE,0);
	gtk_button_set_relief(GTK_BUTTON(button),GTK_RELIEF_NONE);
	g_signal_connect(button,"clicked",G_CALLBACK(create_menu_funcionarios),widget);
	button = gtk_button_new_with_label("Relatório");
	gtk_box_pack_start(GTK_BOX(box), button,TRUE,TRUE,0);
	gtk_button_set_relief(GTK_BUTTON(button),GTK_RELIEF_NONE);
	//um label dentro da box vertical
	label = gtk_label_new("\n\nALUNO DO CURSO DE\nBACHARELADO EM\nSISTEMAS DE INFORMAÇÃO\nUFRN/CERES\n\t ISAYAN DEIVID N. MONTEIRO \t\n20220043737");
	gtk_label_set_justify(GTK_LABEL(label),GTK_JUSTIFY_CENTER);
	gtk_box_pack_start(GTK_BOX(box), label,FALSE,FALSE,20);
} 