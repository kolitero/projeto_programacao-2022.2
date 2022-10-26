#include <gtk/gtk.h>
#include "../header/components.h"

//funcao ativada quando o programa e iniciado

void init(GtkApplication *app,gpointer user_data){
	//janela do programa
	GtkWidget *window;
	//linha principal do programa
	GtkWidget *mainline;
	// criacao e configuracao da janela
	window = gtk_application_window_new(app);
	gtk_window_set_title(GTK_WINDOW(window),"SIG-CLINIC");
	gtk_window_set_default_size(GTK_WINDOW(window),1280,720);
	gtk_window_set_resizable(GTK_WINDOW(window),FALSE);
	gtk_container_set_border_width(GTK_CONTAINER(window),10);
	// criacao da linha principal
	mainline = gtk_box_new(GTK_ORIENTATION_HORIZONTAL,0);
	gtk_container_set_border_width(GTK_CONTAINER(mainline),0);
	gtk_container_add(GTK_CONTAINER(window),mainline);
	//sidebar
	create_sidebar(mainline);
	gtk_widget_show_all (window);
}

// funcao main do programa

int main(int argc,char **argv) {
	GtkApplication *app;
	int status;
	app = gtk_application_new("br.isayan",G_APPLICATION_DEFAULT_FLAGS);
	g_signal_connect(app,"activate",G_CALLBACK(init),NULL);
	status = g_application_run (G_APPLICATION (app), argc, argv);
  	g_object_unref (app);
  	return status;
}



