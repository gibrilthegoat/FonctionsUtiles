#include <stdio.h>
#include <string.h>
#include <math.h>

/* ===================== FONCTIONS SUR math.h ===================== */

/* Conversion degrés → radians */
double deg_to_rad(double deg) {
    return deg * M_PI / 180.0;
}

/* Conversion radians → degrés */
double rad_to_deg(double rad) {
    return rad * 180.0 / M_PI;
}

/* Calcul de l'hypoténuse via Pythagore */
double pythagore(double a, double b) {
    return sqrt(a * a + b * b);
}

/* Aire d'un cercle */
double circle_area(double r) {
    return M_PI * r * r;
}

/* Périmètre d'un cercle */
double circle_circumference(double r) {
    return 2.0 * M_PI * r;
}

/* Factorielle (en double) via gamma(n+1) */
double factorial_double(int n) {
    return tgamma(n + 1);
}

/* Distance entre deux points 2D */
double distance_2d(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

/* Distance entre deux points 3D */
double distance_3d(double x1, double y1, double z1, double x2, double y2, double z2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2) + pow(z2 - z1, 2));
}

/* Racine cubique manuelle */
double cube_root(double x) {
    return cbrt(x);
}

/* Résolution simple ax^2 + bx + c = 0 */
int solve_quadratic(double a, double b, double c, double *x1, double *x2) {
    double delta = b * b - 4 * a * c;

    if (delta < 0) {
        return 0;   // pas de solutions réelles
    }
    else if (delta == 0) {
        *x1 = -b / (2 * a);
        *x2 = *x1;
        return 1;   // solution unique
    }
    else {
        double sqrt_delta = sqrt(delta);
        *x1 = (-b + sqrt_delta) / (2 * a);
        *x2 = (-b - sqrt_delta) / (2 * a);
        return 2;   // deux solutions
    }
}

/* Norme vectorielle (tableau) */
double vector_norm(const double *v, size_t size) {
    double sum = 0.0;
    for (size_t i = 0; i < size; i++) {
        sum += v[i] * v[i];
    }
    return sqrt(sum);
}

/* Moyenne quadratique (RMS) */
double rms(const double *arr, size_t size) {
    double sum = 0.0;
    for (size_t i = 0; i < size; i++) {
        sum += arr[i] * arr[i];
    }
    return sqrt(sum / size);
}

/* Puissance entière positive rapide */
double fast_pow(double base, int exp) {
    double result = 1.0;
    while (exp > 0) {
        if (exp & 1) {
            result *= base;
        }
        base *= base;
        exp >>= 1;
    }
    return result;
}

/* ===================== DEMO ===================== */
int main() {
    printf("Deg to rad: %f\n", deg_to_rad(180));
    printf("Hypotenuse(3,4): %f\n", pythagore(3, 4));

    double x1, x2;
    int sol = solve_quadratic(1, -3, 2, &x1, &x2);
    printf("Solutions equation: %d (x1=%f, x2=%f)\n", sol, x1, x2);

    double vec[3] = {3, 4, 12};
    printf("Norm: %f\n", vector_norm(vec, 3));

    return 0;
}
