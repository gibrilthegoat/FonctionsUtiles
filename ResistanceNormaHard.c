#include <stdio.h>

// Closest normalized value from E12 series
// E12 base values (multiplied by powers of 10)
const double E12_VALUES[12] = {
    1.0, 1.2, 1.5, 1.8,
    2.2, 2.7, 3.3, 3.9,
    4.7, 5.6, 6.8, 8.2
};

// Find closest normalized value in E12
// Example: value = 3450 => returns ~ 3.3k or 3.9k
// depending on which is closest
//
// We scale the resistor into [1..10) range, compare, then rescale

double closest_E12(double value) {
    int power = 0;

    while (value >= 10.0) {
        value /= 10.0;
        power++;
    }
    while (value < 1.0) {
        value *= 10.0;
        power--;
    }

    double best = E12_VALUES[0];
    double best_diff = (value - E12_VALUES[0]);
    if (best_diff < 0) best_diff = -best_diff;

    for (int i = 1; i < 12; i++) {
        double diff = value - E12_VALUES[i];
        if (diff < 0) diff = -diff;
        if (diff < best_diff) {
            best_diff = diff;
            best = E12_VALUES[i];
        }
    }

    while (power > 0) {
        best *= 10.0;
        power--;
    }
    while (power < 0) {
        best /= 10.0;
        power++;
    }

    return best;
}

// Compute equivalent resistance for series

double series_R(double a, double b) {
    return a + b;
}

// Compute equivalent resistance for parallel

double parallel_R(double a, double b) {
    return 1.0 / (1.0 / a + 1.0 / b);
}

// Given a target R, try to approximate it with two E12 resistors in series

double best_series(double target, double *out_R1, double *out_R2) {
    double best_err = 1e9;
    double best_r1 = 0;
    double best_r2 = 0;

    for (int p1 = -2; p1 <= 5; p1++) {
        for (int i = 0; i < 12; i++) {
            double R1 = E12_VALUES[i];
            for (int x = 0; x < p1; x++) R1 *= 10;
            for (int x = 0; x > p1; x--) R1 /= 10;

            for (int p2 = -2; p2 <= 5; p2++) {
                for (int j = 0; j < 12; j++) {
                    double R2 = E12_VALUES[j];
                    for (int x = 0; x < p2; x++) R2 *= 10;
                    for (int x = 0; x > p2; x--) R2 /= 10;

                    double eq = series_R(R1, R2);
                    double err = eq - target;
                    if (err < 0) err = -err;

                    if (err < best_err) {
                        best_err = err;
                        best_r1 = R1;
                        best_r2 = R2;
                    }
                }
            }
        }
    }

    *out_R1 = best_r1;
    *out_R2 = best_r2;
    return best_err;
}

// Same but for parallel

double best_parallel(double target, double *out_R1, double *out_R2) {
    double best_err = 1e9;
    double best_r1 = 0;
    double best_r2 = 0;

    for (int p1 = -2; p1 <= 5; p1++) {
        for (int i = 0; i < 12; i++) {
            double R1 = E12_VALUES[i];
            for (int x = 0; x < p1; x++) R1 *= 10;
            for (int x = 0; x > p1; x--) R1 /= 10;

            for (int p2 = -2; p2 <= 5; p2++) {
                for (int j = 0; j < 12; j++) {
                    double R2 = E12_VALUES[j];
                    for (int x = 0; x < p2; x++) R2 *= 10;
                    for (int x = 0; x > p2; x--) R2 /= 10;

                    double eq = parallel_R(R1, R2);
                    double err = eq - target;
                    if (err < 0) err = -err;

                    if (err < best_err) {
                        best_err = err;
                        best_r1 = R1;
                        best_r2 = R2;
                    }
                }
            }
        }
    }

    *out_R1 = best_r1;
    *out_R2 = best_r2;
    return best_err;
}

int main() {
    double R = 3450; // example

    printf("Closest E12 to %.2f = %.2f\n", R, closest_E12(R));

    double r1, r2;
    best_series(R, &r1, &r2);
    printf("Best series approx: R1=%.2f  R2=%.2f  => %.2f\n", r1, r2, r1+r2);

    best_parallel(R, &r1, &r2);
    printf("Best parallel approx: R1=%.2f  R2=%.2f  => %.2f\n", r1, r2, 1.0/(1.0/r1 + 1.0/r2));

    return 0;
}
