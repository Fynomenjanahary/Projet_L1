#include <gtk/gtk.h>

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);

    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Fenêtre blue");
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 600);

    /*GdkRGBA border_color, background_color;
    gdk_rgba_parse(&border_color, "#FF00FF"); // Rose fuchsia en code hexadécimal
    gdk_rgba_parse(&background_color, "white");*/

    GtkCssProvider *provider = gtk_css_provider_new();
    gtk_css_provider_load_from_data(provider,
        "window { border: 10px solid pink; background-color: white; }",
        -1, NULL);

    GtkStyleContext *context = gtk_widget_get_style_context(window);
    gtk_style_context_add_provider(context,
    GTK_STYLE_PROVIDER(provider),
    GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);

    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
    GtkWidget *box=gtk_box_new(GTK_ORIENTATION_HORIZONTAL , 3);
    
    gtk_container_set_border_width(GTK_CONTAINER(box) , 10);
    gtk_container_add(GTK_CONTAINER(window), box);
    
    GtkWidget *grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(box), grid);

    // Création des widgets à placer dans la grille
    GtkWidget *entre = gtk_entry_new();
    gtk_entry_set_text(GTK_ENTRY(entre), "MATH");
    gtk_editable_set_editable(GTK_EDITABLE(entre), FALSE);
    
    GtkWidget *button1 = gtk_button_new_with_label("Button 1");
    GtkWidget *button2 = gtk_button_new_with_label("Button 2");
    GtkWidget *button3 = gtk_button_new_with_label("Button 3");
    GtkWidget *button4 = gtk_button_new_with_label("Button 4");
    
    gtk_grid_attach(GTK_GRID(grid), entre, 0, 0, 6, 6);
    GtkWidget *ebox=gtk_box_new(GTK_ORIENTATION_HORIZONTAL , 3);
    gtk_container_add(GTK_CONTAINER(box), ebox);
    gtk_grid_attach(GTK_GRID(grid), button1, 0, 20, 1, 1); // (widget, colonne, ligne, largeur, hauteur)
    gtk_grid_attach(GTK_GRID(grid), button2, 1, 20, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), button3, 2, 20, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), button4, 3, 20, 1, 1);

    gtk_widget_show_all(window);

    gtk_main();

    return 0;
}
