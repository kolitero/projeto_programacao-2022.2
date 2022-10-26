#include <gtk/gtk.h>
#include "../../header/utils.h"
#include <stdio.h>

//deletar tudo tirando o primeiro item

void delete_screen(GtkWidget *widget){
	GList *children, *iter;
	children = gtk_container_get_children(GTK_CONTAINER(widget));
	if((children = g_list_next(children))){
		for(iter = children; iter != NULL; iter = g_list_next(iter)){
		gtk_widget_destroy(GTK_WIDGET(iter->data));
		}
	}
	g_list_free(children);
}

//deletar tudo

void delete_all(GtkWidget *widget){
	GList *children, *iter;
	children = gtk_container_get_children(GTK_CONTAINER(widget));
	for(iter = children; iter != NULL; iter = g_list_next(iter)){
		gtk_widget_destroy(GTK_WIDGET(iter->data));
	}
	g_list_free(children);
}

//mudar o focus se for enter

void enter_detector(GtkWidget *widget,GdkEventKey event,GtkWidget *container,gpointer data){
	if(event.keyval == GDK_KEY_Return){
		gtk_widget_set_can_focus(GTK_WIDGET(container),TRUE);
		gtk_widget_grab_focus(GTK_WIDGET(container));
	}
}