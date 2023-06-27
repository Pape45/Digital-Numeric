#include <stdio.h>
#include <math.h>

// Fonction à intégrer
double fonction(double x) {
    return 14 * x * x + 7; // Exemple : fonction sin(x)
}

// Calcul de l'approximation de l'intégrale par la méthode de Simpson composite
double methodeSimpsonComposite(double (*fonction)(double), double a, double b, int n) {
    double h = (b - a) / n; // Largeur de chaque sous-intervalle
    double sum = 0.0;

    for (int i = 0; i < n; i += 2) {
        double x0 = a + i * h;
        double x1 = x0 + h;
        double x2 = x0 + 2 * h;

        double fa = fonction(x0);
        double fb = fonction(x1);
        double fc = fonction(x2);

        double area = (h / 3.0) * (fa + 4 * fb + fc);
        sum += area;
    }

    return sum;
}

int main() {
    double borneInf, borneSup;
    int nbSousIntervalles;

    printf("Entrez la borne inférieure de l'intervalle : ");
    scanf("%lf", &borneInf);

    printf("Entrez la borne supérieure de l'intervalle : ");
    scanf("%lf", &borneSup);

    printf("Entrez le nombre de sous-intervalles (doit être un multiple de 2) : ");
    scanf("%d", &nbSousIntervalles);

    // Vérification que le nombre de sous-intervalles est un multiple de 2
    if (nbSousIntervalles % 2 != 0) {
        printf("Erreur : le nombre de sous-intervalles doit être un multiple de 2.\n");
        return 1;
    }

    // Calcul de l'approximation de l'intégrale
    double approximation = methodeSimpsonComposite(fonction, borneInf, borneSup, nbSousIntervalles);

    printf("L'approximation de l'intégrale est : %.6lf\n", approximation);

    return 0;
}
