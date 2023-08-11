#include <gtk/gtk.h>

static GtkWidget *new_button = NULL;

void on_button_clicked(GtkButton *button, gpointer data) {
    GtkBox *button_box = GTK_BOX(data);

    if (new_button == NULL) {
        // Create a new button
        new_button = gtk_button_new_with_label("New Button");
    
        // Add the new button to the button box
        gtk_box_pack_start(button_box, new_button, FALSE, FALSE, 5);

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
    gtk_window_set_default_size(GTK_WINDOW(window), 1000, 600);

    GtkWidget *main_box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
    gtk_container_set_border_width(GTK_CONTAINER(main_box) , 0);

    gtk_container_add(GTK_CONTAINER(window), main_box);
    
    GtkWidget *grid = gtk_grid_new();
    //gtk_grid_set_row_spacing(GTK_GRID(grid) , 10);
    //gtk_grid_set_column_spacing(GTK_GRID(grid) , 10);
    gtk_container_add(GTK_CONTAINER(main_box) , grid);

	//GtkWidget *fix = gtk_fixed_new();
	//gtk_box_pack_start()

    GtkWidget *button = gtk_button_new_with_label("Click Me");
    gtk_grid_attach(GTK_GRID(grid) , button, 1 , 0 , 1 , 1);
    gtk_widget_set_halign(button , GTK_ALIGN_END);

    // Connect the on_button_clicked function to the "clicked" signal of the button
    g_signal_connect(button, "clicked", G_CALLBACK(on_button_clicked), main_box);

    gtk_widget_show_all(window);

    gtk_main();
    return 0;
}
