
#include <stdio.h>
#include <string.h>


void asciiToBinary(char ch) {
    // On parcourt les 8 bits du caractère, du bit de poids fort au bit de poids faible
    for (int i = 7; i >= 0; i--) {
        // Décalage à droite pour isoler le bit et appliquer un masque avec & 1
        printf("%d", (ch >> i) & 1);
    }
}

int main(void) {
    // Exemple de chaîne de caractères ASCII
    char message[] = "Hello, ASCII!";
    size_t len = strlen(message);

    printf("Message original : %s\n", message);
    printf("Conversion en binaire :\n");

    // Pour chaque caractère du message, afficher sa représentation binaire
    for (size_t i = 0; i < len; i++) {
        asciiToBinary(message[i]);
        printf(" ");  // Séparateur entre les caractères
    }
    printf("\n");

    return 0;
}
