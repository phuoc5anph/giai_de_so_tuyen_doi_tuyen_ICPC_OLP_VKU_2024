#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int value;
    int index;
} IndexedValue;


int compare_by_value(const void *a, const void *b) {
    return ((*(IndexedValue*)b).value - (*(IndexedValue*)a).value);
}


int compare_by_index(const void *a, const void *b) {
    return ((*(IndexedValue*)a).index - (*(IndexedValue*)b).index);
}


int find_divisors(IndexedValue *sorted_indexed_B, int k, int p) {

    IndexedValue *part_to_sort = (IndexedValue *)malloc(k * sizeof(IndexedValue));


    for (int i = 0; i < k; i++) {
        part_to_sort[i] = sorted_indexed_B[i];
    }


    qsort(part_to_sort, k, sizeof(IndexedValue), compare_by_index);

    int result = part_to_sort[p - 1].value;
    free(part_to_sort);
    return result;
}

int main() {
    int N;
    scanf("%d", &N);

    IndexedValue *indexed_B = (IndexedValue *)malloc(N * sizeof(IndexedValue));
    for (int i = 0; i < N; i++) {
        scanf("%d", &indexed_B[i].value);
        indexed_B[i].index = i;
    }

    int M;
    scanf("%d", &M);

    int **C = (int **)malloc(M * sizeof(int *));
    for (int i = 0; i < M; i++) {
        C[i] = (int *)malloc(2 * sizeof(int));
        scanf("%d %d", &C[i][0], &C[i][1]);
    }


    qsort(indexed_B, N, sizeof(IndexedValue), compare_by_value);


    for (int i = 0; i < M; i++) {
        int result = find_divisors(indexed_B, C[i][0], C[i][1]);
        printf("%d\n", result);
    }

    // Free allocated memory
    free(indexed_B);
    for (int i = 0; i < M; i++) {
        free(C[i]);
    }
    free(C);

    return 0;
}
