#include <stdio.h>
#include <stdlib.h>

// Fonction pour calculer l'aire selon l'approche de la gauche
double aireGauche(double* x, double* fx, int n, double dx) {
    double aire = 0.0;
    for (int i = 0; i < n - 1; i++) {
        aire += fx[i];
    }
    return aire * dx;
}

// Fonction pour calculer l'aire selon l'approche de la droite
double aireDroite(double* x, double* fx, int n, double dx) {
    double aire = 0.0;
    for (int i = 1; i < n; i++) {
        aire += fx[i];
    }
    return aire * dx;
}

// Fonction pour calculer l'aire selon l'approche du milieu
double aireMilieu(double* x, double* fx, int n, double dx) {
    double aire = 0.0;
    for (int i = 0; i < n - 1; i++) {
        aire += fx[i] + fx[i + 1];
    }
    return aire * dx / 2.0;
}

int main() {
    // Entrée des informations nécessaires
    double borneInf, borneSup;
    int nbSousIntervalles, nbElements;

    printf("Entrez le nombre d'éléments du tableau : ");
    scanf("%d", &nbElements);

    printf("Entrez la borne inférieure de l'intervalle : ");
    scanf("%lf", &borneInf);

    printf("Entrez la borne supérieure de l'intervalle : ");
    scanf("%lf", &borneSup);

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

    // Calcul des aires selon les approches
    double aire_gauche = aireGauche(x, fx, nbElements, dx);
    double aire_droite = aireDroite(x, fx, nbElements, dx);
    double aire_milieu = aireMilieu(x, fx, nbElements, dx);

    // Affichage des résultats
    printf("Approche de la gauche : %.15lf\n", aire_gauche);
    printf("Approche de la droite : %.15lf\n", aire_droite);
    printf("Approche du milieu : %.15lf\n", aire_milieu);

    // Libération de la mémoire
    free(x);
    free(fx);

    return 0;
}
