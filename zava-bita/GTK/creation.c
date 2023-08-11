#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>
//#define g_signal_connect(instance, detailed_signal, c_handler, data);
//void callback (GtkWidget *p_widget, gpointer *user_data);

int main(int argc , char *argv[]){
    gtk_init(&argc , &argv);//initialisation
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);//Fenetre 
    gtk_window_set_default_size(GTK_WINDOW(window) , 1000 , 600);//determine la taille du fenetre [1000:ligne , 600:colonne]
    
    gtk_window_set_resizable(GTK_WINDOW(window) , FALSE);
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER_ALWAYS);//position du fenetre
    gtk_window_set_title(GTK_WINDOW(window) , "CREATION"); //asiana titre
    g_signal_connect(window , "destroy" , G_CALLBACK(gtk_main_quit) , NULL);//
    
    
    gtk_widget_show_all(window);//rendre visible la fenetre
    gtk_main();   
	
	return 0;
}/*

#include <gtk/gtk.h>

void on_button_clicked(GtkButton *button, gpointer data) {
    // Cast data back to GtkBox
    GtkBox *button_box = GTK_BOX(data);

    // Create a new button
    GtkWidget *new_button = gtk_button_new_with_label("New Button");
    
    // Add the new button to the button box
    gtk_box_pack_start(button_box, new_button, FALSE, FALSE, 5);

    // Show the new button
    gtk_widget_show(new_button);
}

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);

    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Button Example");
    gtk_window_set_default_size(GTK_WINDOW(window), 300, 200);

    GtkWidget *main_box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
    gtk_container_add(GTK_CONTAINER(window), main_box);

    GtkWidget *button = gtk_button_new_with_label("Click Me");
    gtk_box_pack_start(GTK_BOX(main_box), button, FALSE, FALSE, 5);

    // Connect the on_button_clicked function to the "clicked" signal of the button
    g_signal_connect(button, "clicked", G_CALLBACK(on_button_clicked), main_box);

    gtk_widget_show_all(window);

    gtk_main();
    return 0;
}*/
/*

#include <gtk/gtk.h>

static GtkWidget *new_button = NULL;

void on_button_clicked(GtkButton *button, gpointer data) {
    GtkGrid *grid = GTK_GRID(data);

    if (new_button == NULL) {
        // Create a new button
        new_button = gtk_button_new_with_label("New Button");
    
        // Attach the new button to the grid
        gtk_grid_attach(grid, new_button, 0, 1, 2, 1);

        // Show the new button
        gtk_widget_show(new_button);
    } else {
        // Hide the new button if it is already visible
        gtk_widget_hide(new_button);
        new_button = NULL;
    }
}

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);

    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Button Example");
    gtk_window_set_default_size(GTK_WINDOW(window), 300, 200);

    GtkWidget *grid = gtk_grid_new();
    gtk_grid_set_row_spacing(GTK_GRID(grid), 10);
    gtk_grid_set_column_spacing(GTK_GRID(grid), 10);
    gtk_container_add(GTK_CONTAINER(window), grid);

    GtkWidget *button = gtk_button_new_with_label("Click Me");
    gtk_grid_attach(GTK_GRID(grid), button, 1, 0, 1, 1);

    // Connect the on_button_clicked function to the "clicked" signal of the button
    g_signal_connect(button, "clicked", G_CALLBACK(on_button_clicked), grid);

    gtk_widget_show_all(window);

    gtk_main();
    return 0;
}
*/
