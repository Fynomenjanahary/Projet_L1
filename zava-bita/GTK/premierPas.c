#include <stdlib.h>
#include <gtk/gtk.h>

void OnDestroy(GtkWidget *pWidget, gpointer pData);

int main(int argc , char** argv){ 
	GtkWidget* fenetre;	
	GtkWidget* soratra;
	gtk_init(&argc , &argv);             													/// initialisation de GTK+																	/// déclaration d'un widget
	fenetre = gtk_window_new(GTK_WINDOW_TOPLEVEL);											/// creation d'une fenêtre
	gtk_window_set_position(GTK_WINDOW(fenetre), GTK_WIN_POS_CENTER);						/// position de la fenetre dans l'écran => voir nePasOublie.gtk.txt
	gtk_window_set_title(GTK_WINDOW(fenetre), "Chapitre I.");								/// donner un titre au fenêtre (convertion de fenetre en type GtkWindow avec le macro GTK_WINDOW)
	gtk_window_set_default_size(GTK_WINDOW(fenetre), 320, 200);								/// définir la taille de la fenêtre
	/*gtk_window_iconify(GTK_WINDOW(fenetre));*/											/// Permet de minimiser la fenêtre
	/*gtk_window_deiconify(GTK_WINDOW (fenetre));*/											/// Pour réafficher la fenêtre lorsque celle-ci est minimisée.
	/*gtk_window_maximize(GTK_WINDOW(fenetre));*/											/// Permet de maximiser la fenêtre.
	/*gtk_window_unmaximize(GTK_WINDOW(fenetre));*/											/// Redonne une fenêtre maximisée sa taille précédente.
	/*gtk_window_set_decorated(GTK_WINDOW(fenetre), TRUE);	*/								/// Pour afficher(TRUE) ou ne pas afficher(FALSE)la barre de titre de la fenêtre.
	/*gtk_window_resize(GTK_WINDOW(fenetre), 900, 900);		*/								/// Pour définir la nouvelle taille de la fenêtre.
	/*gtk_window_set_resizable(GTK_WINDOW(fenetre),FALSE );	*/								/// pour dire que la taille est redimensionnable(TRUE) ou non redimentionnable(FALSE)
	soratra = gtk_label_new("sérieux à re");														/// création d'un label
	gtk_container_add(GTK_CONTAINER(fenetre), soratra);										/// insertion du label dans le conteneur
	g_signal_connect(G_OBJECT(fenetre), "destroy", G_CALLBACK(OnDestroy), NULL);			/// connection d'une signale
			
	gtk_widget_show_all(fenetre);           												/// affichage de la fenetre
			
	gtk_main();																				/// démarrage de la boucle évènementielle
	/*gtk_widget_destroy(fenetre);*/	    												/// destruction de la fenetre
	
	return 0;
}

void OnDestroy(GtkWidget *pWidget, gpointer pData){
    gtk_main_quit();																		/// Arrêt de la boucle évènementielle 
}
