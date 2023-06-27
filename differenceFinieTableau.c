#include <stdio.h>
#include <math.h>

// Fonction dont on souhaite calculer les dérivées
double f(double *x, double *y, int n, double xi)
{
    int i;
    double result = 0.0;

    // Recherche de l'indice correspondant à xi
    for (i = 0; i < n; i++)
    {
        if (x[i] == xi)
        {
            result = y[i];
            break;
        }
    }

    return result;
}

// Calcul de la dérivée première avec la méthode de différence finie en avant
double forwardDifference(double *x, double *y, int n, double xi, double h)
{
    return (f(x, y, n, xi + h) - f(x, y, n, xi)) / h;
}

// Calcul de la dérivée première avec la méthode de différence finie en arrière
double backwardDifference(double *x, double *y, int n, double xi, double h)
{
    return (f(x, y, n, xi) - f(x, y, n, xi - h)) / h;
}

// Calcul de la dérivée première avec la méthode de différence finie centrée
double centralDifference(double *x, double *y, int n, double xi, double h)
{
    return (f(x, y, n, xi + h) - f(x, y, n, xi - h)) / (2 * h);
}

// Calcul de la dérivée seconde avec la méthode de différence finie centrée
double centralDifferenceSecond(double *x, double *y, int n, double xi, double h)
{
    return (f(x, y, n, xi + h) - 2 * f(x, y, n, xi) + f(x, y, n, xi - h)) / (h * h);
}

int main()
{
    int n; // Nombre de points (taille des tableaux x et y)
    printf("Entrez le nombre de points : ");
    scanf("%d", &n);

    double x[n], y[n]; // Tableaux pour les points x et f(x)
    int i;

    // Saisie des valeurs des points
    printf("Entrez les valeurs des points :\n");
    for (i = 0; i < n; i++)
    {
        printf("x%d = ", i);
        scanf("%lf", &x[i]);
        printf("f(x%d) = ", i);
        scanf("%lf", &y[i]);
    }

    double xi; // Point auquel on souhaite calculer les dérivées
    printf("Entrez la valeur du point xi : ");
    scanf("%lf", &xi);

    double h; // Pas de discrétisation
    printf("Entrez la valeur du pas de discrétisation h : ");
    scanf("%lf", &h);

    double df_forward = forwardDifference(x, y, n, xi, h);
    double df_backward = backwardDifference(x, y, n, xi, h);
    double df_central = centralDifference(x, y, n, xi, h);
    double d2f_central = centralDifferenceSecond(x, y, n, xi, h);

    printf("Dérivée première avec différence finie en avant: %f\n", df_forward);
    printf("Dérivée première avec différence finie en arrière: %f\n", df_backward);
    printf("Dérivée première avec différence finie centrée: %f\n", df_central);
    printf("Dérivée seconde avec différence finie centrée: %f\n", d2f_central);

    return 0;
}
