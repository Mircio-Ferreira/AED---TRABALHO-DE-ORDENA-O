#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define CASE1 1000
#define CASE2 5000
#define CASE3 10000
#define NUM_BUCKETS 100

void bucket_sort(int *array, int len, int *comparisons, int *swaps);
void fill_sorted(int *arr, int n);
void fill_reverse(int *arr, int n);
void fill_random(int *arr, int n);

int main(){
    srand(time(NULL));
    int array1[CASE1];
    int array2[CASE2];
    int array3[CASE3];
    int comp1=0,comp2=0,comp3=0,swap1=0,swap2=0,swap3=0;
    double start1, start2, start3;
    double end1,end2,end3;
    
    // 1) CASE 1000 ELEMENTOS
    printf("==== 1000 ELEMENTOS ====\n");
    // Ordenado
    fill_sorted(array1, CASE1);
    comp1 = swap1 = 0;
    start1 = clock();
    bucket_sort(array1, CASE1, &comp1, &swap1);
    end1 = clock();
    
    printf("Ordenado -> Comp: %d | Trocas: %d | Tempo: %.5f s\n",comp1, swap1, (end1 - start1) / CLOCKS_PER_SEC);
    
    // Inverso
    fill_reverse(array1, CASE1);
    comp1 = swap1 = 0;
    start1 = clock();
    bucket_sort(array1, CASE1, &comp1, &swap1);
    end1 = clock();
    printf("Reverso  -> Comp: %d | Trocas: %d | Tempo: %.5f s\n",
           comp1, swap1, (end1 - start1) / CLOCKS_PER_SEC);
    
    // Aleatório
    fill_random(array1, CASE1);
    comp1 = swap1 = 0;
    start1 = clock();
    bucket_sort(array1, CASE1, &comp1, &swap1);
    end1 = clock();
    printf("Aleatorio -> Comp: %d | Trocas: %d | Tempo: %.5f s\n\n",comp1, swap1, (end1 - start1) / CLOCKS_PER_SEC);
    
    // 2) CASE 5000 ELEMENTOS
    printf("==== 5000 ELEMENTOS ====\n");
    // Ordenado
    fill_sorted(array2, CASE2);
    comp2 = swap2 = 0;
    start2 = clock();
    bucket_sort(array2, CASE2, &comp2, &swap2);
    end2 = clock();
    
    printf("Ordenado -> Comp: %d | Trocas: %d | Tempo: %.5f s\n",comp2, swap2, (end2 - start2) / CLOCKS_PER_SEC);
    
    // Reverso
    fill_reverse(array2, CASE2);
    comp2 = swap2 = 0;
    start2 = clock();
    bucket_sort(array2, CASE2, &comp2, &swap2);
    end2 = clock();
    printf("Reverso  -> Comp: %d | Trocas: %d | Tempo: %.5f s\n",comp2, swap2, (end2 - start2) / CLOCKS_PER_SEC);
    
    // Aleatório
    fill_random(array2, CASE2);
    comp2 = swap2 = 0;
    start2 = clock();
    bucket_sort(array2, CASE2, &comp2, &swap2);
    end2 = clock();
    printf("Aleatorio -> Comp: %d | Trocas: %d | Tempo: %.5f s\n\n",comp2, swap2, (end2 - start2) / CLOCKS_PER_SEC);
    
    // 3) CASE 10000 ELEMENTOS
    printf("==== 10000 ELEMENTOS ====\n");
    // Ordenado
    fill_sorted(array3, CASE3);
    comp3 = swap3 = 0;
    start3 = clock();
    bucket_sort(array3, CASE3, &comp3, &swap3);
    end3 = clock();
    
    printf("Ordenado -> Comp: %d | Trocas: %d | Tempo: %.5f s\n",comp3, swap3, (end3 - start3) / CLOCKS_PER_SEC);
    
    // Reverso
    fill_reverse(array3, CASE3);
    comp3 = swap3 = 0;
    start3 = clock();
    bucket_sort(array3, CASE3, &comp3, &swap3);
    end3 = clock();
    printf("Reverso  -> Comp: %d | Trocas: %d | Tempo: %.5f s\n",comp3, swap3, (end3 - start3) / CLOCKS_PER_SEC);
    
    // Aleatório
    fill_random(array3, CASE3);
    comp3 = swap3 = 0;
    start3 = clock();
    bucket_sort(array3, CASE3, &comp3, &swap3);
    end3 = clock();
    printf("Aleatorio -> Comp: %d | Trocas: %d | Tempo: %.5f s\n\n",comp3, swap3, (end3 - start3) / CLOCKS_PER_SEC);
    
    return 0;
}

void bucket_sort(int *array, int len, int *comparisons, int *swaps){
    if(len <= 0) return;
    
    int min = array[0], max = array[0];
    for(int i = 1; i < len; i++){
        (*comparisons)++;
        if(array[i] < min) min = array[i];
        (*comparisons)++;
        if(array[i] > max) max = array[i];
    }
    
    if(min == max) return;
    
    int bucket_count = NUM_BUCKETS;
    int **buckets = (int**)malloc(bucket_count * sizeof(int*));
    int *bucket_sizes = (int*)calloc(bucket_count, sizeof(int));
    int *bucket_capacities = (int*)malloc(bucket_count * sizeof(int));
    
    for(int i = 0; i < bucket_count; i++){
        bucket_capacities[i] = 10;
        buckets[i] = (int*)malloc(bucket_capacities[i] * sizeof(int));
    }
    
    double range = (double)(max - min);
    for(int i = 0; i < len; i++){
        int bucket_idx = (int)((array[i] - min) / range * (bucket_count - 1));
        
        if(bucket_sizes[bucket_idx] >= bucket_capacities[bucket_idx]){
            bucket_capacities[bucket_idx] *= 2;
            buckets[bucket_idx] = (int*)realloc(buckets[bucket_idx], 
                                                bucket_capacities[bucket_idx] * sizeof(int));
        }
        
        buckets[bucket_idx][bucket_sizes[bucket_idx]++] = array[i];
    }
    
    int idx = 0;
    for(int i = 0; i < bucket_count; i++){
        for(int j = 1; j < bucket_sizes[i]; j++){
            int key = buckets[i][j];
            int k = j - 1;
            while(k >= 0){
                (*comparisons)++;
                if(buckets[i][k] > key){
                    buckets[i][k + 1] = buckets[i][k];
                    (*swaps)++;
                    k--;
                } else {
                    break;
                }
            }
            buckets[i][k + 1] = key;
        }
        
        for(int j = 0; j < bucket_sizes[i]; j++){
            array[idx++] = buckets[i][j];
        }
    }
    
    for(int i = 0; i < bucket_count; i++){
        free(buckets[i]);
    }
    free(buckets);
    free(bucket_sizes);
    free(bucket_capacities);
}

void fill_sorted(int *arr, int n) {
    for (int i = 0; i < n; i++) arr[i] = i;
}

void fill_reverse(int *arr, int n) {
    for (int i = 0; i < n; i++) arr[i] = n - i;
}

void fill_random(int *arr, int n) {
    for (int i = 0; i < n; i++) arr[i] = rand();
}
