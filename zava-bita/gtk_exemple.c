#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>

gboolean on_click_button (GtkWidget *button , GdkEventButton *event , gpointer data){
	printf("Hello World!\n");
	return FALSE;
}

int main(int argc , char** argv){
	GtkWidget *window;
	GtkWidget *hbox;
	GtkWidget *button;
	GtkWidget *label;
	GtkWidget *entry;
	
	gtk_init( &argc , &argv);
	
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	hbox = gtk_box_new(TRUE,10);
	button = gtk_button_new_with_label("FRANÇAIS");
	label = gtk_label_new("blabla");
	entry = gtk_entry_new();
	
	gtk_container_add(GTK_CONTAINER(window) , hbox);
	
	gtk_box_pack_start (GTK_BOX(hbox) , entry , TRUE , TRUE , 10);
	gtk_box_pack_start (GTK_BOX(hbox) , button , TRUE , TRUE , 10);
	gtk_box_pack_start (GTK_BOX(hbox) , label , TRUE , TRUE , 10);
	
	g_signal_connect(button , "clicked" , (GCallback)on_click_button, NULL);
	
	gtk_widget_show_all(window);
	
	gtk_main();
	
	return 0;
}
