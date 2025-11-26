#include <stdio.h>

// Approximate a resistance to the nearest E12 normalized value
// E12 series base values
const double E12[12] = {
    1.0, 1.2, 1.5, 1.8,
    2.2, 2.7, 3.3, 3.9,
    4.7, 5.6, 6.8, 8.2
};

// Return closest E12 value
// Example: 4700 -> returns ~4.7k

double nearest_E12(double value) {
    int pow10 = 0;

    while (value >= 10) {
        value /= 10;
        pow10++;
    }
    while (value < 1) {
        value *= 10;
        pow10--;
    }

    double best = E12[0];
    double best_diff = (value - E12[0] > 0) ? value - E12[0] : E12[0] - value;

    for (int i = 1; i < 12; i++) {
        double diff = (value - E12[i] > 0) ? value - E12[i] : E12[i] - value;
        if (diff < best_diff) {
            best_diff = diff;
            best = E12[i];
        }
    }

    while (pow10 > 0) {
        best *= 10;
        pow10--;
    }
    while (pow10 < 0) {
        best /= 10;
        pow10++;
    }

    return best;
}

// Series equivalent: R = R1 + R2

double series(double R1, double R2) {
    return R1 + R2;
}

// Parallel equivalent: R = (R1 * R2) / (R1 + R2)

double parallel(double R1, double R2) {
    return (R1 * R2) / (R1 + R2);
}

// Try to approximate a resistance with two E12 resistors in series

double simple_best_series(double target, double *outA, double *outB) {
    double best_err = 1e9;
    double bestA = 0, bestB = 0;

    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            for (int p = -1; p <= 3; p++) {
                double A = E12[i];
                double B = E12[j];

                for (int k = 0; k < p; k++) {
                    A *= 10;
                    B *= 10;
                }
                for (int k = 0; k > p; k--) {
                    A /= 10;
                    B /= 10;
                }

                double eq = A + B;
                double err = eq - target;
                if (err < 0) err = -err;

                if (err < best_err) {
                    best_err = err;
                    bestA = A;
                    bestB = B;
                }
            }
        }
    }

    *outA = bestA;
    *outB = bestB;
    return best_err;
}

int main() {
    double target = 1500;  // Example

    printf("Nearest E12 to %.0f = %.2f\n", target, nearest_E12(target));

    double A, B;
    simple_best_series(target, &A, &B);
    printf("Best simple series: %.2f + %.2f = %.2f\n", A, B, A + B);

    printf("Parallel example (1k || 1k) = %.2f\n", parallel(1000, 1000));

    return 0;
}
