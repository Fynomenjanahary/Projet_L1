/// scrolle tsotra

/*#include <gtk/gtk.h>

static void add_entry(GtkWidget *button, gpointer user_data) {
    GtkWidget *entry = gtk_entry_new();
    gtk_container_add(GTK_CONTAINER(user_data), entry);
    gtk_widget_show_all(GTK_WIDGET(user_data));
}

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);

    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_default_size(GTK_WINDOW(window), 300, 400);
    gtk_window_set_title(GTK_WINDOW(window), "Dynamic Entries");

    GtkWidget *scroll_window = gtk_scrolled_window_new(NULL, NULL);
    gtk_container_set_border_width(GTK_CONTAINER(scroll_window), 10);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scroll_window),
    GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);

    GtkWidget *entry_container = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_container_add(GTK_CONTAINER(scroll_window), entry_container);

    GtkWidget *button_add = gtk_button_new_with_label("Add Entry");
    g_signal_connect(button_add, "clicked", G_CALLBACK(add_entry), entry_container);

    GtkWidget *main_box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_box_pack_start(GTK_BOX(main_box), button_add, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(main_box), scroll_window, TRUE, TRUE, 0);

    gtk_container_add(GTK_CONTAINER(window), main_box);
    gtk_widget_show_all(window);

    gtk_main();
    return 0;
}*/

/*#include <gtk/gtk.h>

static void add_medicine_entry(GtkWidget *button, gpointer user_data) {
    GtkWidget *medicines_container = GTK_WIDGET(user_data);
    // Clear previous entries
    gtk_container_foreach(GTK_CONTAINER(medicines_container), (GtkCallback)gtk_widget_destroy, NULL);

    const char *medicines[] = {
        "Aspirin", "Ibuprofen", "Paracetamol", "Loratadine", "Amoxicillin",
        "Vitamin C", "Cetirizine", "Omeprazole", "Ranitidine", "Metformin"
        // Add more medicines
    };

    // Sort medicines alphabetically
    int num_medicines = sizeof(medicines) / sizeof(medicines[0]);
    qsort(medicines, num_medicines, sizeof(const char *), (int (*)(const void *, const void *))strcmp);

    for (int i = 0; i < num_medicines; i++) {
        GtkWidget *entry = gtk_entry_new();
        gtk_entry_set_text(GTK_ENTRY(entry), medicines[i]);
        gtk_container_add(GTK_CONTAINER(medicines_container), entry);
        gtk_widget_show(entry);
    }

    gtk_widget_show_all(medicines_container);
}

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);

    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_default_size(GTK_WINDOW(window), 300, 400);
    gtk_window_set_title(GTK_WINDOW(window), "Medicine List");

    GtkWidget *scroll_window = gtk_scrolled_window_new(NULL, NULL);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scroll_window),
                                   GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);

    GtkWidget *medicines_container = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_container_add(GTK_CONTAINER(scroll_window), medicines_container);

    GtkWidget *alphabet_container = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_widget_set_margin_top(alphabet_container, 10);
    gtk_widget_set_margin_end(alphabet_container, 10);
    gtk_widget_set_margin_bottom(alphabet_container, 10);

    for (char letter = 'A'; letter <= 'Z'; letter++) {
        GtkWidget *button = gtk_button_new_with_label(g_strdup_printf("%c", letter));
        g_signal_connect(button, "clicked", G_CALLBACK(add_medicine_entry), medicines_container);
        gtk_box_pack_start(GTK_BOX(alphabet_container), button, FALSE, FALSE, 0);
    }

    GtkWidget *main_box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);
    gtk_container_add(GTK_CONTAINER(main_box), alphabet_container);
    gtk_container_add(GTK_CONTAINER(main_box), scroll_window);

    gtk_container_add(GTK_CONTAINER(window), main_box);
    gtk_widget_show_all(window);

    gtk_main();
    return 0;
}
*/

#include <gtk/gtk.h>
#include <math.h>

static const char *medicines[26][2] = {
    {"Aspirin", "Azithromycin"},   // A
    {"Benadryl", "Buspirone"},     // B
    {"Calcium", "Ciprofloxacin"},  // C
    {"Diazepam", "Doxycycline"},   // D
    // Add more medicines for each letter
    // ...
    {"Vitamin C", "Venlafaxine"},  // V
    {"Warfarin", "Wellbutrin"},    // W
    // Y and Z may not have many examples, so just duplicate the last entries
    {"Zoloft", "Zyrtec"}           // Z
};

static void show_medicines(GtkWidget *button, gpointer user_data) {
    const char *letter = (const char *)user_data;
    const char *medicine1 = medicines[tolower(letter[0]) - 'a'][0];
    const char *medicine2 = medicines[tolower(letter[0]) - 'a'][1];

    GtkWidget *entry1 = gtk_entry_new();
    GtkWidget *entry2 = gtk_entry_new();

    gtk_entry_set_text(GTK_ENTRY(entry1), medicine1);
    gtk_entry_set_text(GTK_ENTRY(entry2), medicine2);

    GtkWidget *container = GTK_WIDGET(gtk_widget_get_parent(button));
    gtk_container_add(GTK_CONTAINER(container), entry1);
    gtk_container_add(GTK_CONTAINER(container), entry2);
    gtk_widget_show_all(container);
}

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);

    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 800);
    gtk_window_set_title(GTK_WINDOW(window), "Medicine List");

    GtkWidget *scrolled_window = gtk_scrolled_window_new(NULL, NULL);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scrolled_window), GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
    gtk_container_add(GTK_CONTAINER(window), scrolled_window);

    GtkWidget *main_box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_container_add(GTK_CONTAINER(scrolled_window), main_box);

    GtkWidget *grid = gtk_grid_new();
    gtk_grid_set_row_spacing(GTK_GRID(grid), 5);
    gtk_grid_set_column_spacing(GTK_GRID(grid), 5);
    gtk_box_pack_start(GTK_BOX(main_box), grid, FALSE, FALSE, 0);

    double radius = 10.0; // 2cm in GtkUnits
    double center_x = 20.0; // Distance from the left edge

    for (char letter = 'A'; letter <= 'Z'; letter++) {
        GtkWidget *button = gtk_button_new_with_label(g_strdup_printf("%c", letter));
        g_signal_connect(button, "clicked", G_CALLBACK(show_medicines), g_strdup_printf("%c", letter));

        double angle = (letter - 'A') * (2 * G_PI / 26);
        int x = center_x + radius * cos(angle);
        int y = radius * sin(angle);

        gtk_grid_attach(GTK_GRID(grid), button, x, y, 1, 1);
    }

    gtk_widget_show_all(window);

    gtk_main();
    return 0;
}
