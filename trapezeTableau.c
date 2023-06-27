#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Fonction pour calculer l'aire selon la méthode des trapèzes
double aireTrapezes(double* x, double* fx, int n, double dx) {
    double aire = 0.0;
    for (int i = 0; i < n - 1; i++) {
        aire += (fx[i] + fx[i + 1]);
    }
    return (aire * dx) / 2.0;
}

int main() {
    // Entrée des informations nécessaires
    double borneInf, borneSup;
    int nbSousIntervalles, nbElements;

    printf("Entrez la borne inférieure de l'intervalle : ");
    scanf("%lf", &borneInf);

    printf("Entrez la borne supérieure de l'intervalle : ");
    scanf("%lf", &borneSup);

    printf("Entrez le nombre d'éléments du tableau : ");
    scanf("%d", &nbElements);

    printf("Entrez le nombre de sous-intervalles : ");
    scanf("%d", &nbSousIntervalles);

    // Création du tableau dynamique pour stocker les valeurs de x et f(x)
    double* x = (double*)malloc(nbElements * sizeof(double));
    double* fx = (double*)malloc(nbElements * sizeof(double));

    // Saisie des valeurs de x
    printf("Entrez les valeurs de x : ");
    for (int i = 0; i < nbElements; i++) {
        scanf("%lf", &x[i]);
    }

    // Saisie des valeurs de f(x)
    printf("Entrez les valeurs de f(x) : ");
    for (int i = 0; i < nbElements; i++) {
        scanf("%lf", &fx[i]);
    }

    // Calcul de la largeur des sous-intervalles
    double dx = (borneSup - borneInf) / nbSousIntervalles;

    // Calcul de l'aire selon la méthode des trapèzes
    double aire_trapezes = aireTrapezes(x, fx, nbElements, dx);

    // Affichage du résultat
    printf("Aire selon la méthode des trapèzes : %.4lf\n", aire_trapezes);

    // Libération de la mémoire
    free(x);
    free(fx);

    return 0;
}
