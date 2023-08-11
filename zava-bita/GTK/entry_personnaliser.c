#include <gtk/gtk.h>

static int quantity = 0; // Valeur à afficher et à modifier

void on_plus_button_clicked(GtkButton *button, gpointer data) {
    quantity++;
    gchar *quantity_str = g_strdup_printf("%d", quantity);
    gtk_entry_set_text(GTK_ENTRY(data), quantity_str);
    g_free(quantity_str);
}

void on_minus_button_clicked(GtkButton *button, gpointer data) {
    const gchar *text = gtk_entry_get_text(GTK_ENTRY(data));

    if (g_strcmp0(text, "Quantity") != 0 && quantity > 0) {
        quantity--;
        gchar *quantity_str = g_strdup_printf("%d", quantity);
        gtk_entry_set_text(GTK_ENTRY(data), quantity_str);
        g_free(quantity_str);
    }
}

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);

    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Increment/Decrement");
    gtk_window_set_default_size(GTK_WINDOW(window), 600, 100);
    gtk_container_set_border_width(GTK_CONTAINER(window), 10);

    GtkWidget *main_box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
    gtk_container_add(GTK_CONTAINER(window), main_box);

    GtkWidget *minus_button = gtk_button_new_with_label("-");
    GtkWidget *entry = gtk_entry_new();
    gtk_entry_set_text(GTK_ENTRY(entry), "Quantity");
    gtk_editable_set_editable(GTK_EDITABLE(entry), FALSE);
    GtkWidget *plus_button = gtk_button_new_with_label("+");
    /*gtk_button_set_relief(GTK_BUTTON(plus_button), GTK_RELIEF_HALF);*/						/// Définit le style du bouton  => GTK_RELIEF_NORMAL (par défaut) ; GTK_RELIEF_HALF ; GTK_RELIEF_NONE.

    g_signal_connect(minus_button, "clicked", G_CALLBACK(on_minus_button_clicked), entry);
    g_signal_connect(plus_button, "clicked", G_CALLBACK(on_plus_button_clicked), entry);

    gtk_box_pack_start(GTK_BOX(main_box), minus_button, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(main_box), entry, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(main_box), plus_button, FALSE, FALSE, 0);

    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    gtk_widget_show_all(window);

    gtk_main();
	//printf("%d ito no tao farany\n",quantity);
    return 0;
}

