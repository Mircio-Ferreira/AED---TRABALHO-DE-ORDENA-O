#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define CASE1 1000
#define CASE2 5000
#define CASE3 10000

void selection_sort(int *array,int len,int *comparisons,int *swaps);

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
    selection_sort(array1, CASE1, &comp1, &swap1);
    end1 = clock();
    
    printf("Ordenado -> Comp: %d | Trocas: %d | Tempo: %.5f s\n",comp1, swap1, (end1 - start1) / CLOCKS_PER_SEC);

    // Inverso
    fill_reverse(array1, CASE1);
    comp1 = swap1 = 0;
    start1 = clock();
    selection_sort(array1, CASE1, &comp1, &swap1);
    end1 = clock();

    printf("Reverso  -> Comp: %d | Trocas: %d | Tempo: %.5f s\n",
           comp1, swap1, (end1 - start1) / CLOCKS_PER_SEC);

    // Aleatório
    fill_random(array1, CASE1);
    comp1 = swap1 = 0;
    start1 = clock();
    selection_sort(array1, CASE1, &comp1, &swap1);
    end1 = clock();

    printf("Aleatorio -> Comp: %d | Trocas: %d | Tempo: %.5f s\n\n",comp1, swap1, (end1 - start1) / CLOCKS_PER_SEC);


    // 2) CASE 5000 ELEMENTOS


    printf("==== 5000 ELEMENTOS ====\n");

    // Ordenado
    fill_sorted(array2, CASE2);
    comp2 = swap2 = 0;
    start2 = clock();
    selection_sort(array2, CASE2, &comp2, &swap2);
    end2 = clock();
    
    printf("Ordenado -> Comp: %d | Trocas: %d | Tempo: %.5f s\n",comp2, swap2, (end2 - start2) / CLOCKS_PER_SEC);

    // Reverso
    fill_reverse(array2, CASE2);
    comp2 = swap2 = 0;
    start2 = clock();
    selection_sort(array2, CASE2, &comp2, &swap2);
    end2 = clock();

    printf("Reverso  -> Comp: %d | Trocas: %d | Tempo: %.5f s\n",comp2, swap2, (end2 - start2) / CLOCKS_PER_SEC);

    // Aleatório
    fill_random(array2, CASE2);
    comp2 = swap2 = 0;
    start2 = clock();
    selection_sort(array2, CASE2, &comp2, &swap2);
    end2 = clock();

    printf("Aleatorio -> Comp: %d | Trocas: %d | Tempo: %.5f s\n\n",comp2, swap2, (end2 - start2) / CLOCKS_PER_SEC);

    // 3) CASE 10000 ELEMENTOS

    printf("==== 10000 ELEMENTOS ====\n");

    // Ordenado
    fill_sorted(array3, CASE3);
    comp3 = swap3 = 0;
    start3 = clock();
    selection_sort(array3, CASE3, &comp3, &swap3);
    end3 = clock();
    
    printf("Ordenado -> Comp: %d | Trocas: %d | Tempo: %.5f s\n",comp3, swap3, (end3 - start3) / CLOCKS_PER_SEC);

    // Reverso
    fill_reverse(array3, CASE3);
    comp3 = swap3 = 0;
    start3 = clock();
    selection_sort(array3, CASE3, &comp3, &swap3);
    end3 = clock();

    printf("Reverso  -> Comp: %d | Trocas: %d | Tempo: %.5f s\n",comp3, swap3, (end3 - start3) / CLOCKS_PER_SEC);

    // Aleatório
    fill_random(array3, CASE3);
    comp3 = swap3 = 0;
    start3 = clock();
    selection_sort(array3, CASE3, &comp3, &swap3);
    end3 = clock();

    printf("Aleatorio -> Comp: %d | Trocas: %d | Tempo: %.5f s\n\n",comp3, swap3, (end3 - start3) / CLOCKS_PER_SEC);



    return 0;
}


void selection_sort(int *array,int len,int *comparisons,int *swaps){
    for(int i = 0;i<len-1;i++){
        int idx = i;
        for(int j=i+1;j<len;j++){
            (*comparisons)++;
            if(array[j]<array[idx]) idx=j;
        }
        if(idx!=i){
            int temp = array[i];
            array[i]=array[idx];
            array[idx]=temp;
            (*swaps)++;
        }
    }
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