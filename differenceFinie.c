#include <stdio.h>
#include <math.h>

double fonction(double x) {
    // Définissez ici votre fonction à dériver
    return exp(x);
}

double derivee_avant(double x, double h) {
    return (fonction(x + h) - fonction(x)) / h;
}

double derivee_arriere(double x, double h) {
    return (fonction(x) - fonction(x - h)) / h;
}

double derivee_centree(double x, double h) {
    return (fonction(x + h) - fonction(x - h)) / (2 * h);
}

double derivee_seconde(double x, double h) {
    return (fonction(x + h) - 2 * fonction(x) + fonction(x - h)) / (h * h);
}

int main() {
    double x = 1.5; // Valeur de x pour évaluer les dérivées
    double h = 0.1; // Pas de discrétisation

    // Calcul des dérivées
    double premiere_derivee_avant = derivee_avant(x, h);
    double premiere_derivee_arriere = derivee_arriere(x, h);
    double premiere_derivee_centree = derivee_centree(x, h);
    double seconde_derivee = derivee_seconde(x, h);

    // Affichage des résultats
    printf("Première dérivée (différence finie en avant): %.6f\n", premiere_derivee_avant);
    printf("Première dérivée (différence finie en arrière): %.6f\n", premiere_derivee_arriere);
    printf("Première dérivée (différence finie centrée): %.6f\n", premiere_derivee_centree);
    printf("Deuxième dérivée: %.6f\n", seconde_derivee);

    return 0;
}
