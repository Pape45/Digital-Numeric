#include <stdio.h>

// Fonction à intégrer
double fonction(double x) {
    return 14 * x * x + 7;
}

// Méthode des trapèzes
double trapezes(double a, double b, int n) {
    double largeur = (b - a) / n;
    double somme = 0.0;
    double x;

    for (int i = 1; i < n; i++) {
        x = a + i * largeur;
        somme += fonction(x);
    }

    double resultat = (fonction(a) + fonction(b)) / 2.0 + somme;
    resultat *= largeur;

    return resultat;
}

int main() {
    double a, b; // Bornes de l'intervalle
    int n;       // Nombre de sous-intervalles

    printf("Calcul de l'integrale par la methode des trapezes\n");
    printf("Entrez la borne inferieure de l'intervalle : ");
    scanf("%lf", &a);
    printf("Entrez la borne superieure de l'intervalle : ");
    scanf("%lf", &b);
    printf("Entrez le nombre de sous-intervalles : ");
    scanf("%d", &n);

    double resultat = trapezes(a, b, n);

    printf("L'approximation de l'integrale est : %.15f\n", resultat);

    return 0;
}
