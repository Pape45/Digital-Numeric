#include <stdio.h>
#include <math.h>

// Fonction dont on cherche la racine
double f(double x)
{
    return 10 * x - 9 * exp(-x); // Exemple de fonction, vous pouvez la modifier selon vos besoins
}

// Méthode de dichotomie pour trouver la racine
double dichotomy(double a, double b, double epsilon)
{
    double c;
    int iterations = 0;

    while ((b - a) > epsilon)
    {
        c = (a + b) / 2;

        if (f(c) == 0.0)
            break;
        else if (f(c) * f(a) < 0)
            b = c;
        else
            a = c;

        iterations++; // Incrémenter le compteur d'itérations à chaque itération
    }

    printf("Nombre d'itérations : %d\n", iterations); // Afficher le nombre d'itérations

    return c;
}

int main()
{
    double a, b; // Bornes de l'intervalle [a, b]
    printf("Entrez la borne inférieure a : ");
    scanf("%lf", &a);
    printf("Entrez la borne supérieure b : ");
    scanf("%lf", &b);

    double epsilon; // Tolérance (critère d'arrêt)
    printf("Entrez la tolérance epsilon : ");
    scanf("%lf", &epsilon);

    double root = dichotomy(a, b, epsilon);

    printf("La racine de la fonction est : %f\n", root);

    return 0;
}
