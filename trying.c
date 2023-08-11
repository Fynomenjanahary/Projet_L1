/*#include <stdio.h>

int main() {
    FILE *file;
    file = fopen("/etc/passwd", "r");
    if (file == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        return 1;
    }

    char user[900];
    char home_directory[100];
    char shell[200];
    int uid, gid;

    while (fscanf(file, "%[^:]:%*[^:]:%d:%d:%*[^:]:%[^:]:%[^\n]\n", user, &uid, &gid, home_directory, shell) == 5) {
        printf("Utilisateur: %s\nUID: %d\nGID: %d\nDossier personnel: %s\nShell: %s\n\n", user, uid, gid, home_directory, shell);
    }
    fclose(file);

    return 0;
}
*/
/*#include <stdio.h>

int main() {
    FILE *file, *exel;
    file = fopen("/etc/passwd", "r");
    exel = fopen("users_over_1000.csv", "w"); // Nouveau fichier pour les utilisateurs redirigés

    if (file == NULL || exel == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        return 1;
    }

    char user[900];
    char home_directory[100];
    char shell[200];
    int uid, gid;

    while (fscanf(file, "%[^:]:%*[^:]:%d:%d:%*[^:]:%[^:]:%[^\n]\n", user, &uid, &gid, home_directory, shell) == 5) {
        printf("Utilisateur: %s\nUID: %d\nGID: %d\nDossier personnel: %s\nShell: %s\n\n", user, uid, gid, home_directory, shell);
        if (uid > 1000 && gid > 1000) {
            fprintf(exel, "%s,%s,%s\n", user, home_directory, shell);
        }
    }

    fclose(file);
    fclose(exel);

    return 0;
}*/

#include <stdio.h>

int main() {
    FILE *file, *exel;
    file = fopen("/etc/passwd", "r");
    exel = fopen("users_over_1000.csv", "w"); // Nouveau fichier pour les utilisateurs redirigés

    if (file == NULL || exel == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        return 1;
    }
	char line[1000];
    char user[900];
    char home_directory[100];
    char shell[200];
    int uid, gid;

	while (fgets(line, sizeof(line), file) != NULL) {
        if (sscanf(line, "%[^:]:%*[^:]:%d:%d:%*[^:]:%[^:]:%[^\n]", user, &uid, &gid, home_directory, shell) ==5) {
            printf("Utilisateur: %s\nUID: %d\nGID: %d\nDossier personnel: %s\nShell: %s\n\n", user, uid, gid, home_directory, shell);
            if (uid >= 1000 && gid >= 1000 && gid<2000 && uid<2000) {
                fprintf(exel, "%s,%s,%s\n", user, home_directory, shell);
            }
        }
    }
    ///PROVOQUE une BOUCLE INFINIE
    /*while (fscanf(file, "%[^:]:%*[^:]:%d:%d:%*[^:]:%[^:]:%[^\n]\n", user, &uid, &gid, home_directory, shell) != EOF) {
        printf("Utilisateur: %s\nUID: %d\nGID: %d\nDossier personnel: %s\nShell: %s\n\n", user, uid, gid, home_directory, shell);
        if (uid > 1000 && gid > 1000) {
            fprintf(exel, "%s,%s,%s\n", user, home_directory, shell);
        }
    }*/
    
    /*
    int scanned_items;
    while (fgets(line, sizeof(line), file) != NULL) {
        scanned_items = sscanf(line, "%[^:]:%*[^:]:%d:%d:%[^:]:%[^:\n]", user, &uid, &gid, home_directory, shell);
        if (scanned_items == 5) {
            // Si le scanf a réussi à lire les 5 éléments attendus, inclure l'utilisateur dans le fichier exel
            if (uid >= 1000 && gid >= 1000 && uid<2000 && gid<2000) {
                fprintf(exel, "%s,%s,%s\n", user, home_directory, shell);
            }
        } else if (scanned_items == EOF) {
            // Fin du fichier, quitter la boucle
            break;
        } else {
            // Erreur de lecture, ignorer cette ligne
            continue;
        }
    }*/
    
    /*int scanned_items;

    while (fgets(line, sizeof(line), file) != NULL) {
        scanned_items = sscanf(line, "%[^:]:%*[^:]:%d:%d:%[^:]:%[^:\n]", user, &uid, &gid, home_directory, shell);
        if (scanned_items >= 3 && uid > 1000 && gid > 1000) {
            fprintf(exel, "%s,%s,%s\n", user, home_directory, shell);
        }
    }*/
    
    fclose(file);
    fclose(exel);

    return 0;
}


