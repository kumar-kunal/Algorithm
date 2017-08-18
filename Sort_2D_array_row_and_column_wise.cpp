
#include <stdio.h>
#include <stdlib.h>

void print_matrix(int **matrix, int rows, int cols) {
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void swap(int *a, int *b) {
    int buf = *a;
    *a = *b;
    *b = buf;
}

int partition(int **a, int l, int r, int c) {
    int i;
    // Left pivot
    int pivot_val = a[l/c][l%c];
    // Move pivot to end
    swap(&a[l/c][l%c], &a[r/c][r%c]);

    // If <= to the pivot value, swap
    int j = l;
    for (i = l; i < r; i++) {
        if (a[i/c][i%c] <= pivot_val) {
            swap(&a[i/c][i%c], &a[j/c][j%c]);
            j++;
        }
    }

    // Move pivot to its place.
    swap(&a[j/c][j%c], &a[r/c][r%c]);

    return j;
}

void quicksort_r(int **a, int l, int r, int c) {
    if (l < r) {
        int pivot = partition(a, l, r, c);
        quicksort_r(a, l, pivot-1, c);
        quicksort_r(a, pivot+1, r, c);
    }
}

void quicksort(int **a, int rows, int cols) {
    quicksort_r(a, 0, rows * cols - 1, cols);
}

int main() {
    int i, j;
    int rows = 5;
    int cols = 4;
    int **matrix = (int**)malloc(sizeof(int*) * rows);

    // Init of a 2D array with random numbers:
    for (i = 0; i < rows; i++) {
        matrix[i] =(int*) malloc(sizeof(int) * cols);
        for (j = 0; j < cols; j++) {
            matrix[i][j] = random() % 10;
        }
    }

    // Before:
    printf("Before:\n");
    print_matrix(matrix, rows, cols);

    quicksort(matrix, rows, cols);

    // After:
    printf("After:\n");
    print_matrix(matrix, rows, cols);

    return 0;
}