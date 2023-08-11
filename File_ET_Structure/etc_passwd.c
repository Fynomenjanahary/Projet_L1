#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    FILE *file, *exel;
    file = fopen("/etc/passwd", "r");
    exel = fopen("copy_user.csv", "w"); // Nouveau fichier pour les utilisateurs redirigés

    if (file == NULL || exel == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        return 1;
    }
	char line[1000];
    char user[900];
    char home_directory[100];
    char shell[200];
    int uid, gid;
	
	srand(time(NULL));
	fprintf(exel,"USER NAME,HOME DIRECTORY,SHELL,E-MAIL,PASSWD\n");
	while (fgets(line, sizeof(line), file) != NULL) {
        if (sscanf(line, "%[^:]:%*[^:]:%d:%d:%*[^:]:%[^:]:%[^\n]", user, &uid, &gid, home_directory, shell) ==5) {
            printf("Utilisateur: %s\nUID: %d\nGID: %d\nDossier personnel: %s\nShell: %s\n\n", user, uid, gid, home_directory, shell);
            if (uid >= 1000 && gid >= 1000 && gid<2000 && uid<2000) {
                fprintf(exel, "%s,%s,%s,%s@mit.mg,%d\n", user, home_directory, shell,user,rand()%1000000);
            }
        }
    }
    fclose(file);
    fclose(exel);

    return 0;
}

