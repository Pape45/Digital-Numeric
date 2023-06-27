#include <stdio.h>
#include <math.h>

// Fonction dont on cherche la racine
double f(double x)
{
    return x - exp(-1/x); // Exemple de fonction, vous pouvez la modifier selon vos besoins
}

// Dérivée de la fonction
double df(double x)
{
    return 1 - exp(-1/x) / (x * x); // Exemple de dérivée, vous pouvez la modifier selon vos besoins
}

// Méthode de Newton pour trouver la racine
double newton(double x0, double a, double b)
{
    double x = x0;
    double epsilon = 0.000001; // Tolerance (critère d'arrêt)

    while (fabs(f(x)) > epsilon && x >= a && x <= b)
    {
        x = x - f(x) / df(x);
    }

    return x;
}

int main()
{
    double x0; // Point initial
    printf("Entrez la valeur du point initial x0 : ");
    scanf("%lf", &x0);

    double a, b; // Bornes de l'intervalle [a, b]
    printf("Entrez la borne inférieure a : ");
    scanf("%lf", &a);
    printf("Entrez la borne supérieure b : ");
    scanf("%lf", &b);

    double root = newton(x0, a, b);

    if (root >= a && root <= b)
    {
        printf("La racine de la fonction dans l'intervalle [%f, %f] est : %f\n", a, b, root);
    }
    else
    {
        printf("Aucune racine trouvée dans l'intervalle [%f, %f]\n", a, b);
    }

    return 0;
}
