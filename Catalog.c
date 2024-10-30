#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct {
    int base;
    char value[100];
} Root;


long long decode_value(int base, const char *value) {
    long long result = 0;
    int len = strlen(value);
    for (int i = 0; i < len; i++) {
        if (value[i] >= '0' && value[i] <= '9') {
            result = result * base + (value[i] - '0');
        } else {
            result = result * base + (value[i] - 'a' + 10);
        }
    }
    return result;
}

double lagrange_interpolation(int n, double x_vals[], double y_vals[]) {
    double result = 0.0;
    for (int i = 0; i < n; i++) {
        double term = y_vals[i];
        for (int j = 0; j < n; j++) {
            if (i != j) {
                term *= (0 - x_vals[j]) / (x_vals[i] - x_vals[j]);
            }
        }
        result += term;
    }
    return result;
}

int main() {
    
    int n1 = 4, k1 = 3;
    Root roots1[] = {
        {10, "4"},
        {2, "111"},  
        {10, "12"},
        {4, "213"}   
    };

   
    double x_vals1[] = {1, 2, 3};
    double y_vals1[4];
    for (int i = 0; i < n1; i++) {
        y_vals1[i] = (double)decode_value(roots1[i].base, roots1[i].value);
    }

   
    double constant1 = lagrange_interpolation(k1, x_vals1, y_vals1);
    printf("Constant term for Test Case 1: %.0f\n", constant1);

   
    int n2 = 10, k2 = 7;
    Root roots2[] = {
        {6, "13444211440455345511"},
        {15, "aed7015a346d63"},
        {15, "6aeeb69631c227c"},
        {16, "e1b5e05623d881f"},
        {8, "316034514573652620673"},
        {3, "2122212201122002221120200210011020220200"},
        {3, "20120221122211000100210021102001201112121"},
        {6, "20220554335330240002224253"},
        {12, "45153788322a1255483"},
        {7, "1101613130313526312514143"}
    };

  
    double x_vals2[10];
    double y_vals2[10];
    for (int i = 0; i < n2; i++) {
        x_vals2[i] = (double)(i + 1);
        y_vals2[i] = (double)decode_value(roots2[i].base, roots2[i].value);
    }

    double constant2 = lagrange_interpolation(k2, x_vals2, y_vals2);
    printf("Constant term for Test Case 2: %.0f\n", constant2);

    return 0;
}
