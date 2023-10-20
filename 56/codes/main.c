#include <stdio.h>
#include <math.h>

// Function to calculate the factorial of a number
double factorial(int n) {
    if (n == 0 || n == 1)
        return 1.0;
    else
        return n * factorial(n - 1);
}

double powerOfTwo(int x) {
    double result = 1.0;

    if (x >= 0) {
        for (int i = 0; i <x; i++) {
            result *= 2.0;
        }
    } else {
        for (int i = 0; i < -x; i++) {
            result /= 2.0;
        }
    }

    return result;
}

int main() {
    FILE *dataFile;
    dataFile = fopen("out.dat", "w"); // Open a file for writing

    if (dataFile == NULL) {
        printf("Unable to open the file.\n");
        return 1;
    }

    int x, y;
    double e = 2.71828; // Approximation of e
    
    for (x = 1; x <= 100000; x++) {
        fprintf(dataFile, "x = %d\n", x);
    }

    // Loop to calculate and write the values to the file
    for (x = 1; x <= 100000; x++) {
        double p_x = exp(-1.0) / factorial(x);
        fprintf(dataFile, "p_X(%d) = %lf\n", x, p_x);
    }
    
    for (y = 1; y <= 100000; y++) {
        fprintf(dataFile, "y = %d\n", y);
    }
    
    for (y = 1; y <= 100000; y++) {
        double p_y = powerOfTwo(y) * (exp(-2)/ factorial(y));
        fprintf(dataFile, "p_Y(%d) = %lf\n", y, p_y);
    }

    fclose(dataFile); // Close the file
    printf("Data has been written to out.dat.\n");

    return 0;
}

