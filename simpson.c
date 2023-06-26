#include <stdio.h>
#include <math.h>

// Fonction à intégrer
double fonction(double x) {
    // Remplacez cette fonction par celle que vous souhaitez intégrer
    return 14 * x * x + 7;
}

// Méthode de Simpson pour le calcul numérique de l'intégrale
double methodeSimpson(double a, double b, int n) {
    double h = (b - a) / n; // Largeur de chaque sous-intervalle
    double sum = fonction(a) + fonction(b); // Somme des valeurs de la fonction aux extrémités

    // Calcul des valeurs de la fonction à l'intérieur des sous-intervalles
    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        if (i % 2 == 0) {
            sum += 2 * fonction(x);
        } else {
            sum += 4 * fonction(x);
        }
    }

    return (h / 3) * sum; // Calcul de l'approximation de l'intégrale
}

int main() {
    double a, b; // Bornes de l'intervalle d'intégration
    int n; // Nombre de sous-intervalles

    // Saisie des bornes de l'intervalle et du nombre de sous-intervalles
    printf("Entrez la borne inférieure a : ");
    scanf("%lf", &a);
    printf("Entrez la borne supérieure b : ");
    scanf("%lf", &b);
    printf("Entrez le nombre de sous-intervalles n : ");
    scanf("%d", &n);

    // Calcul de l'intégrale en utilisant la méthode de Simpson
    double resultat = methodeSimpson(a, b, n);
    double h = (b - a) / n; // Calcul de la largeur de chaque sous-intervalle

    // Affichage des résultats
    printf("L'approximation de l'intégrale est : %lf\n", resultat);
    printf("La largeur de chaque sous-intervalle h est : %lf\n", h);

    return 0;
}
