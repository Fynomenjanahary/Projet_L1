#include <stdlib.h>
#include <gtk/gtk.h> 
#define EXEMPLE_1 0
#define EXEMPLE_2 1
#define EXEMPLE_3 2
void AddBtn(GtkWidget *pWindow, gint iExemple);
int main(int argc, char **argv)
{ 
    GtkWidget* pWindow;
    gtk_init(&argc, &argv);
    /* Creation de la fenetre */
    pWindow = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_default_size(GTK_WINDOW(pWindow), 320 ,200); 
 
    /* Connexion du signal "destroy" de la fenêtre */
    g_signal_connect(G_OBJECT(pWindow), "destroy", G_CALLBACK(gtk_main_quit), NULL);
    /* Insertion du bouton */
    AddBtn(pWindow, EXEMPLE_3);
    /* Affichage de la fenêtre */
    gtk_widget_show_all(pWindow); 
    /* Demarrage de la boucle évènementielle */
    gtk_main();
    return EXIT_SUCCESS; 
}
/*
  void AddBtn(GtkWidget *pWindow, gint iExemple)
  
  Fonction en charge d'insérer le bouton dans la fenêtre
 
  Parametre :
  - pWindow : fenetre parente
  - iExemple : mode de création 
  EXEMPLE_1 pour un bouton label
  EXEMPLE_2 pour un bouton EXEMPLE_1 + raccourci
  EXEMPLE_3 pour un bouton EXEMPLE_2 + image
*/
void AddBtn(GtkWidget *pWindow, gint iExemple)
{
    GtkWidget *pQuitBtn;
    GtkWidget *pImage;
    switch(iExemple)
    {
    default:
    case EXEMPLE_1:
        /* Bouton avec un label */
        pQuitBtn = gtk_button_new_with_label("Quitter");
        gtk_window_set_title(GTK_WINDOW(pWindow), "Les boutons - Exemple 1");
        break;
    case EXEMPLE_2:
        /* Bouton avec un label et un raccourci */
        pQuitBtn = gtk_button_new_with_mnemonic("_Quitter");
        gtk_window_set_title(GTK_WINDOW(pWindow), "Les boutons - Exemple 2");
        break;
    case EXEMPLE_3:
        /* Bouton avec un label, un raccourci et une image */
        pQuitBtn = gtk_button_new();
        gtk_window_set_title(GTK_WINDOW(pWindow), "Les boutons - Exemple 3");
        pImage = gtk_image_new_from_icon_name("application-exit", GTK_ICON_SIZE_BUTTON);
        gtk_button_set_image(GTK_BUTTON(pQuitBtn), pImage);
        break;
    }
    /* Connexion du signal "clicked" du bouton */
    g_signal_connect(G_OBJECT(pQuitBtn), "clicked", G_CALLBACK(gtk_main_quit), NULL);
    /* Insertion du bouton dans la fenêtre */
    gtk_container_add(GTK_CONTAINER(pWindow), pQuitBtn);
}
