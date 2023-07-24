#include <gtk/gtk.h>
#include "../../../header/components.h"
#include "../../../header/utils.h"
#include "../../../header/funcionarios.h"




// tela de pesquisa

void pesquisar_funcionario(GtkWidget *btn,GtkWidget *widget,gpointer data){
	//deletar o menu funcionario
	delete_screen(widget);
	//definindo ponteiros

	Parament_pesquise *parament;
	GtkWidget *hbox;
	GtkWidget *block;
	GtkWidget *search;
	GtkWidget *button;
	//alocando memoria
	parament = malloc(sizeof(struct parament_pesquise));
	//atribuindo valores aos ponteiros
	parament->vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL,20);
	parament->entry = gtk_entry_new();
	hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL,10);
	block = gtk_frame_new(NULL);
	search = gtk_frame_new("pesquisar por cpf");
	button = gtk_button_new();
	//configurando propriedades
	gtk_entry_set_has_frame(GTK_ENTRY(parament->entry),FALSE);
	//composicao dos widgets
	gtk_box_pack_start(GTK_BOX(widget),block,TRUE,TRUE,20);
	gtk_container_add(GTK_CONTAINER(block),parament->vbox);
	gtk_box_pack_start(GTK_BOX(parament->vbox),hbox,FALSE,FALSE,20);
	gtk_box_pack_start(GTK_BOX(hbox),search,TRUE,TRUE,20);
	gtk_box_pack_start(GTK_BOX(hbox),button,FALSE,FALSE,20);
	gtk_container_add(GTK_CONTAINER(search),parament->entry);
	//signal
	g_signal_connect(G_OBJECT(block),"destroy",G_CALLBACK(free_widget),parament);
	g_signal_connect(G_OBJECT(button),"clicked",G_CALLBACK(func_edit_activate),parament);
	//mostra
	gtk_widget_show_all(widget);
}

// tela de pesquisa

void show_funcionario(GtkWidget *btn,GtkWidget *widget,gpointer data){
	//deletar o menu funcionario
	delete_screen(widget);
	//definindo ponteiros

	Parament_pesquise *parament;
	GtkWidget *hbox;
	GtkWidget *block;
	GtkWidget *search;
	GtkWidget *button;
	//alocando memoria
	parament = malloc(sizeof(struct parament_pesquise));
	//atribuindo valores aos ponteiros
	parament->vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL,20);
	parament->entry = gtk_entry_new();
	hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL,10);
	block = gtk_frame_new(NULL);
	search = gtk_frame_new("pesquisar por cpf");
	button = gtk_button_new();
	//configurando propriedades
	gtk_entry_set_has_frame(GTK_ENTRY(parament->entry),FALSE);
	//composicao dos widgets
	gtk_box_pack_start(GTK_BOX(widget),block,TRUE,TRUE,20);
	gtk_container_add(GTK_CONTAINER(block),parament->vbox);
	gtk_box_pack_start(GTK_BOX(parament->vbox),hbox,FALSE,FALSE,20);
	gtk_box_pack_start(GTK_BOX(hbox),search,TRUE,TRUE,20);
	gtk_box_pack_start(GTK_BOX(hbox),button,FALSE,FALSE,20);
	gtk_container_add(GTK_CONTAINER(search),parament->entry);
	//signal
	g_signal_connect(G_OBJECT(block),"destroy",G_CALLBACK(free_widget),parament);
	g_signal_connect(G_OBJECT(button),"clicked",G_CALLBACK(func_show_activate),parament);
	//mostra
	gtk_widget_show_all(widget);
}

void show_all_funcionario(GtkWidget *btn,GtkWidget *widget,gpointer data){
	//deletar o menu funcionario
	delete_screen(widget);
	//definindo ponteiros
	Parament_pesquise *parament;
	GtkWidget *scrool;
	//alocando memoria
	parament = malloc(sizeof(struct parament_pesquise));
	//atribuindo valores aos ponteiros
	scrool = gtk_scrolled_window_new(NULL,NULL);
	parament->vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL,20);
	//configurando propriedades
	gtk_scrolled_window_set_min_content_width(GTK_SCROLLED_WINDOW(scrool),1000);

	//composicao dos widgets
	gtk_container_add(GTK_CONTAINER(scrool),parament->vbox);
	gtk_container_add(GTK_CONTAINER(widget),scrool);
	//signal
	g_signal_connect(G_OBJECT(scrool),"destroy",G_CALLBACK(free_widget),parament);
	//monstrar funcionarios
	func_show_all_activate(parament);
	//mostra
	gtk_widget_show_all(widget);
}

void delete_funcionario(GtkWidget *btn,GtkWidget *widget,gpointer data){
	//deletar o menu funcionario
	delete_screen(widget);
	//definindo ponteiros

	Parament_pesquise *parament;
	GtkWidget *hbox;
	GtkWidget *block;
	GtkWidget *search;
	GtkWidget *button;
	//alocando memoria
	parament = malloc(sizeof(struct parament_pesquise));
	//atribuindo valores aos ponteiros
	parament->vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL,20);
	parament->entry = gtk_entry_new();
	hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL,10);
	block = gtk_frame_new(NULL);
	search = gtk_frame_new("pesquisar por cpf");
	button = gtk_button_new();
	//configurando propriedades
	gtk_entry_set_has_frame(GTK_ENTRY(parament->entry),FALSE);
	//composicao dos widgets
	gtk_box_pack_start(GTK_BOX(widget),block,TRUE,TRUE,20);
	gtk_container_add(GTK_CONTAINER(block),parament->vbox);
	gtk_box_pack_start(GTK_BOX(parament->vbox),hbox,FALSE,FALSE,20);
	gtk_box_pack_start(GTK_BOX(hbox),search,TRUE,TRUE,20);
	gtk_box_pack_start(GTK_BOX(hbox),button,FALSE,FALSE,20);
	gtk_container_add(GTK_CONTAINER(search),parament->entry);
	//signal
	g_signal_connect(G_OBJECT(block),"destroy",G_CALLBACK(free_widget),parament);
	g_signal_connect(G_OBJECT(button),"clicked",G_CALLBACK(delete_value_funcionario),(parament->entry));
	//mostra
	gtk_widget_show_all(widget);
}





