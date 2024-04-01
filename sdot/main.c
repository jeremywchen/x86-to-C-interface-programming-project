#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

const int X = 3;
const int ITERATION = 30;

extern void dot_product_asm(float* A, float* B, int n, float* Sdot_asm);


void dot_product_c(float* A, float* B, int n, float* Sdot_c) {
    double sdot = 0;
    for (int i = 0; i < n; i++) {
        sdot += (double)A[i] * B[i];
    }
    *Sdot_c = (float)sdot;
}

double runCSolution(float* A, float* B, int n, double*Sdot_c){
    clock_t start_c = clock();
    // NOTE: actual function call
    dot_product_c(A, B, n, Sdot_c);
    clock_t end_c = clock();
    double time_c = ((double)(end_c - start_c)) / CLOCKS_PER_SEC;
    return time_c;
}


double runASMSolution(float* A, float* B, int n, double*Sdot_asm){
    clock_t start_asm = clock();
    // NOTE: actual function call
    dot_product_asm(A, B, n, Sdot_asm);
    clock_t end_asm = clock();
    double time_asm = ((double)(end_asm - start_asm)) / CLOCKS_PER_SEC;
    return time_asm;
}


void printResult(float Sdot_c, double time_c, float Sdot_asm, double time_asm, int isCorrect) {

    printf("| Method          | %-30s | Execution Time |\n", "Dot Product");
    printf("|-----------------|--------------------------------|----------------|\n");
    printf("| C               | %30.2f | %14.6f |\n", Sdot_c, time_c);
    printf("| Assembly        | %30.2f | %14.6f |\n", Sdot_asm, time_asm);

    if (isCorrect) {
        printf("| %-65s |\n", "[CORRECT] Results are correct and congruent.");
    }
    else {
        printf("| %-65s |\n", "[WRONG] Results do not match.");

    }


}


int main() {
    int sizes[] = {20, 25, 30};

    for(int i = 0; i < X; i++){

        int n = pow(2, sizes[i]);
        
        float* A = (float*)malloc(n * sizeof(float));
        float* B = (float*)malloc(n * sizeof(float));
        float Sdot_asm;
        float Sdot_c;

        double average_time_c = 0.0;
        double average_time_asm = 0.0;
        int isAllCorrect = 1;

        for (int j = 0; j < n; ++j) {
            A[j] =  1;
            B[j] =  1;
        }
        


        printf("\n[VECTOR SIZE] 2^%d = %d\n", sizes[i], n);

        

        for (int j = 0; j < ITERATION; j++) {
            int isCorrect = 1;
            double time_c = runCSolution(A, B, n, &Sdot_c);
            double time_asm = runASMSolution(A, B, n, &Sdot_asm);

            if (Sdot_c != Sdot_asm) {
                isCorrect = 0;
                isAllCorrect = 0;
            }

            printf("\n[%d]\n", j+1);
            printResult(Sdot_c, time_c, Sdot_asm, time_asm, isCorrect);

            average_time_c += time_c;
            average_time_asm += time_asm;
        }

        average_time_asm = average_time_asm / ITERATION;
        average_time_c = average_time_c / ITERATION;

        printf("\nAverage Time C: %lf\n", average_time_c);
        printf("Average Time ASM: %lf\n", average_time_asm);
        
        if (isAllCorrect) {
            printf("All Correct: True\n\n");
        } else {
            printf("All Correct: False\n\n");
        }
        
        
        free(A);
        free(B);
        
    }

    return 0;
}