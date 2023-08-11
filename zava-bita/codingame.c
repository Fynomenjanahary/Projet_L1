/*#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main()
{
    for (int i = 0; i < 5; i++) {
        char a[101],b[100],c[100];
        scanf("%s%s%s",a,b,c);
        for(int i=0; i<strlen(a); i++){
            if(a[i]=='0') printf("%c",b[i]);
            else printf("%c",c[i]);
        }
        printf("\n");
    }

    
    return 0;
}
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main()
{
    for (int i = 0; i < 5; i++) {
        char L[101],I[101],K[101];
        scanf("%s %s %s", L, I, K); fgetc(stdin);
        for(int i=0;i<strlen(L);i++){
            printf("%c",L[i]=='0'?I[i]:K[i]);
        }
        printf("\n");
    }

    return 0;
}
/// mitady factoriel
/*
main(){int N;scanf("%d",&N);printf("%.f",tgamma(N+1));}
*/

/// script bash manova ny v rehetra ho v
/*
IFS= read -r MESSAGE

mes=${MESSAGE/v/w}
echo ${mes//v/}
*/

///  soustraction entre le min et le max 

/* PYTHON
n = int(input())
sequence = list(map(int, input().split()))
maxi = max(sequence)
mini = min(sequence)
print(maxi-mini)
*/
/* CODE en C
#include <stdio.h>
int main(){
int n;scanf("%d",&n);int b=100,m=0,r;for(int i=0;i<n;i++) {int a;scanf("%d",&a);if(b>a){b=a;}if(m<a){m=a;}}r=m-b;printf("%d\n",r);return 0;}
*/


/// affiche le 2ème minimum : CODE EN PYTHON

/*
N = int(input())  # Lecture du nombre d'entiers à lire
numbers = list(map(int, input().split()))  # Lecture de la liste d'entiers et conversion en liste

unique_numbers = list(set(numbers))  # Suppression des doublons dans la liste
unique_numbers.sort()  # Tri de la liste dans l'ordre croissant

second_smallest = unique_numbers[1]  # Récupération du deuxième plus petit nombre

print(second_smallest)  # Affichage du résultat
*/

/// renvoit la difference entre le max et le min : CODE EN PYTHON
/*
n = int(input())  # Lecture de la valeur de n
sequence = list(map(int, input().split()))  # Lecture de la séquence et conversion en liste d'entiers

min_value = min(sequence)  # Trouver la valeur minimale dans la séquence
max_value = max(sequence)  # Trouver la valeur maximale dans la séquence

difference = max_value - min_value  # Calcul de la différence entre le maximum et le minimum

print(difference)  # Affichage du résultat
*/

/// fonction qui renvoit les 2 max parmi 3 nbr donnés

/*
def deux_max(a, b, c):
    max_num = max(a, b, c)
    nums = [a, b, c]
    nums.remove(max_num)
    second_max = max(nums)
    return max_num, second_max
*/


/// calcul de droit linux

/*
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        char word[12];
        char sol[12];

        scanf("%s", word);
        
        bzero(sol, 12);
        
        char *p = &word[1];
        char *s = &sol[0];
        
        for (int j=0;j<3;++j) {
            
            if (!strncmp(p, "r--", 3))
                *(s++) = '4';
            else if (!strncmp(p, "rw-", 3))
                *(s++) = '6';
            else if (!strncmp(p, "rwx", 3))
                *(s++) = '7';
            else if (!strncmp(p, "--x", 3))
                *(s++) = '1';
            else if (!strncmp(p, "-wx", 3))
                *(s++) = '3';
            else if (!strncmp(p, "-w-", 3))
                *(s++) = '2';
            else if (!strncmp(p, "r-x", 3))
                *(s++) = '5';
            else if (!strncmp(p, "---", 3))
                *(s++) = '0';
            else
                dprintf(2, "what the fuck: %s\n", p);
            p += 3;
        }
        printf("%s\n", sol);
        
        
        
    }

    return 0;
}
*/

/// ne pas afficher les voyelles : CODE EN PYTHON

/*

import sys
import math

# Auto-generated code below aims at helping you parse
# the standard input according to the problem statement.

s = input()
answ = []
for l in s :
    if l.isalpha():
        if l not in 'aeiouAEIOU':
            answ.append(l)
    else:
        answ.append(l)
# Write an answer using print
# To debug: print("Debug messages...", file=sys.stderr, flush=True)

print(''.join(answ))

*/

/// ne pas afficher les voyelles : CODE EN cpp

/*
 
#include <iostream>
#include <string>

bool isVowel(char c) {
    c = tolower(c); 
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

std::string removeVowels(const std::string& str) {
    std::string result;
    for (char c : str) {
        if (!isVowel(c)) {
            result += c;
        }
    }
    return result;
}

int main() {
    std::string input;
    std::getline(std::cin, input);
    
    std::string output = removeVowels(input);
    std::cout << output << std::endl;
    
    return 0;
}
*/

/// affichage de ce genre : 
		///exemple :/// si n = 3 et text ='HELLO WORD'
							//HEL
							//ELL
							//LLO
							//LO 
							//O W
							// WO
							//WOR
							//ORD
/*

import sys
import math

# Auto-generated code below aims at helping you parse
# the standard input according to the problem statement.

n = int(input())
text = input()

for i in range(len(text)-n+1):
    print(text[i:i+n])
*/

/// renvoie le min et le max de la difference absolue entre i et i+1 
/*Pour résoudre le problème donné, vous pouvez suivre ces étapes :

    Lire les valeurs d'entrée :
        Lire un entier n qui représente la taille du tableau.
        Lire le tableau d'entiers séparés par des espaces.

    Initialiser les variables min et max avec des valeurs appropriées. Vous pouvez les initialiser avec la différence entre les deux premiers éléments du tableau.

    Parcourir le tableau de l'index 1 à l'index n-1 :
        Calculer la différence absolue entre l'élément courant et l'élément précédent.
        Mettre à jour les variables min et max si nécessaire.

    Afficher les valeurs min et max séparées par un espace.

Voici un exemple de code en langage C qui met en œuvre cette solution :


#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    int* array = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }

    int min = abs(array[1] - array[0]);
    int max = min;

    for (int i = 1; i < n - 1; i++) {
        int diff = abs(array[i + 1] - array[i]);
        if (diff < min) {
            min = diff;
        }
        if (diff > max) {
            max = diff;
        }
    }

    printf("%d %d\n", min, max);

    free(array);

    return 0;
}
*/

/// resaka ADN 

/*

import sys
import math

# Auto-generated code below aims at helping you parse
# the standard input according to the problem statement.

n = int(input())
dna = input()

t={'A':"T","G":"C","T":"A","C":"G"}
valid=True
for i in dna:
    if i not in "ATGC":
        valid=False
        break


if valid:
    x="".join(t[i]for i in dna)
    print(dna)
    print("|"*n)
    print(x)
else:
    print("INVALID")
*/

/// Fonction pour Palindrome

/*
bool solution(char * inputString) {
    for(int i = 0 ; i < strlen(inputString)/2+1; i++){
        if(inputString[i]!=inputString[strlen(inputString )-1-i])return false;
    }
    return true;
}
*/

/// fonction qui renvoie le charactere correspondant au code hèxadecimale donné

/*
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main()
{
    int value_count;
    scanf("%d", &value_count);
    for (int i = 0; i < value_count; i++) {
        char value[3];
        scanf("%s", value);
        char* message = (char*)malloc(sizeof(char) * (value_count / 2 + 1));
    int i, j;
    for (i = 0, j = 0; i <value_count ; i += 2, j++) {
        int code;
        sscanf(value + i, "%2x", &code); // Conversion des 2 caractères hexadécimaux en un entier
        message[j] = (char)code; // Conversion de l'entier en caractère
    }
    message[j] = '\0'; // Ajoute le caractère de fin de chaîne

    printf("%c", message[0]); // Affichage du message

        
    }

   
    return 0;
}
*/

/*
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n); // Lecture du nombre d'éléments

    char* hexCodes = (char*)malloc(sizeof(char) * (n + 1)); // Alloue de la mémoire pour les codes hexadécimaux
    scanf("%s", hexCodes); // Lecture des codes hexadécimaux

    // Conversion des codes hexadécimaux en caractères
    char* message = (char*)malloc(sizeof(char) * (n / 2 + 1));
    int i, j;
    for (i = 0, j = 0; i < n; i += 2, j++) {
        int code;
        sscanf(hexCodes + i, "%2x", &code); // Conversion des 2 caractères hexadécimaux en un entier
        message[j] = (char)code; // Conversion de l'entier en caractère
    }
    message[j] = '\0'; // Ajoute le caractère de fin de chaîne

    printf("%s\n", message); // Affichage du message

    free(hexCodes); // Libération de la mémoire
    free(message);

    return 0;
}

*/

/// fonction pour Déchiffrer le mot de passe en faisant une opération XOR  (`^`) =>(est utilisé pour effectuer une opération de chiffrement inverse en combinant la valeur ASCII avec la clé key.) entre chaque entier du mot de passe chiffré et la valeur de clé.
		//L'opérateur XOR (^) effectue un OU exclusif bit à bit entre les deux nombres. Cela signifie que chaque bit du résultat sera 1 si les bits correspondants des nombres d'origine sont différents, sinon il sera 0.
		// La méthode '.strip()' est utilisée pour supprimer les éventuels espaces supplémentaires avant et après le mot de passe déchiffré.
/*
# Fonction pour décrypter un mot de passe avec une clé donnée
def decrypt_password(encrypted_password, key):
    decrypted_password = ""
    for num in encrypted_password:
        decrypted_num = int(num) ^ key
        decrypted_password += chr(decrypted_num)
    return decrypted_password.strip()

# Lire le nombre de mots de passe chiffrés
N = int(input())

# Liste des mots de passe chiffrés
encrypted_passwords = []
for _ in range(N):
    encrypted_passwords.append(input().split())

# Chercher la clé en testant chaque valeur possible de 10 à 99
for key in range(10, 100):
    found = False
  for encrypted_password in encrypted_passwords:
        decrypted_password = decrypt_password(encrypted_password, key)
        if decrypted_password == "123456":
            found = True
            break
    if found:
        # Afficher les mots de passe déchiffrés
        for encrypted_password in encrypted_passwords:
            decrypted_password = decrypt_password(encrypted_password, key)
            print(decrypted_password)
        break

*/
