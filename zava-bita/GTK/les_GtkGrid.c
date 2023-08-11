#include <gtk/gtk.h>

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);

    // Création de la fenêtre principale
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Grid Example");
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 300);
    g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);

    // Création du conteneur GtkGrid
    GtkWidget *grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(window), grid);

    // Création des widgets à placer dans la grille
    GtkWidget *button1 = gtk_button_new_with_label("Button 1");
    GtkWidget *button2 = gtk_button_new_with_label("Button 2");
    GtkWidget *button3 = gtk_button_new_with_label("Button 3");
    GtkWidget *button4 = gtk_button_new_with_label("Button 4");

    // Placement des widgets dans la grille
    gtk_grid_attach(GTK_GRID(grid), button1, 0, 0, 1, 1); // (widget, colonne, ligne, largeur, hauteur)
    gtk_grid_attach(GTK_GRID(grid), button2, 1, 0, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), button3, 0, 1, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), button4, 1, 2, 1, 1);

    // Affichage de la fenêtre et de son contenu
    gtk_widget_show_all(window);

    gtk_main();
    return 0;
}

