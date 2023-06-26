#include <stdio.h>

// Fonction à intégrer
double fonction(double x) {
    return 14 * x * x + 7; // Exemple : fonction x^2
}

// Méthode des rectangles à gauche
double rectanglesGauche(double a, double b, int n) {
    double largeur = (b - a) / n;
    double somme = 0.0;
    double x;

    for (int i = 0; i < n; i++) {
        x = a + i * largeur;
        somme += fonction(x);
    }

    return largeur * somme;
}

// Méthode des rectangles à droite
double rectanglesDroite(double a, double b, int n) {
    double largeur = (b - a) / n;
    double somme = 0.0;
    double x;

    for (int i = 1; i <= n; i++) {
        x = a + i * largeur;
        somme += fonction(x);
    }

    return largeur * somme;
}

// Méthode des rectangles du point milieu
double rectanglesPointMilieu(double a, double b, int n) {
    double largeur = (b - a) / n;
    double somme = 0.0;
    double x;

    for (int i = 0; i < n; i++) {
        x = a + (i + 0.5) * largeur;
        somme += fonction(x);
    }

    return largeur * somme;
}

int main() {
    double a, b; // Bornes de l'intervalle
    int n;       // Nombre de sous-intervalles

    printf("Calcul de l'integrale par la methode des rectangles\n");
    printf("Entrez la borne inferieure de l'intervalle : ");
    scanf("%lf", &a);
    printf("Entrez la borne superieure de l'intervalle : ");
    scanf("%lf", &b);
    printf("Entrez le nombre de sous-intervalles : ");
    scanf("%d", &n);

    double resultatGauche = rectanglesGauche(a, b, n);
    double resultatDroite = rectanglesDroite(a, b, n);
    double resultatPointMilieu = rectanglesPointMilieu(a, b, n);

    printf("L'approximation de l'integrale par la methode des rectangles a gauche est : %.6f\n", resultatGauche);
    printf("L'approximation de l'integrale par la methode des rectangles a droite est : %.6f\n", resultatDroite);
    printf("L'approximation de l'integrale par la methode des rectangles du point milieu est : %.6f\n", resultatPointMilieu);

    return 0;
}
