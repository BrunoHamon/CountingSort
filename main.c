#include <stdio.h>
#include <sys/time.h>
#include <time.h>

void countingSort(int array[], int size) {

    int max = array[0];
    for (int i = 1; i < size; i++) {
        if (array[i] > max)
            max = array[i];
    }
    int output[max+1];
    int count[max+1];

    for (int i = 0; i <= max; ++i) {
        count[i] = 0;
    }

    for (int i = 0; i < size; i++) {
        count[array[i]]++;
    }

    for (int i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }

    for (int i = size - 1; i >= 0; i--) {
        output[count[array[i]] - 1] = array[i];
        count[array[i]]--;
    }

    for (int i = 0; i < size; i++) {
        array[i] = output[i];
    }
}

void printArray(int array[], int size) {
    for (int i = 0; i < size; ++i) {
        printf("%d  ", array[i]);
    }
    printf("\n");
}


void tempo(clock_t start,struct timeval inicio){
    clock_t end;
    struct timeval fim;
    double cpu_time_used;


    gettimeofday(&fim, 0);
    end = clock();


    long seg = fim.tv_sec - inicio.tv_sec;
    long mseg = fim.tv_usec - inicio.tv_usec;
    double tempo_total = seg + mseg * 1e-6;

    printf("Tempo gasto: %f segundos.\n", tempo_total);

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Tempo gasto de CPU: %f segundos.\n", cpu_time_used);

}
int main() {

    struct timeval inicio;
    clock_t start;

    int array[] = {5, 7, 18, 3, 2, 5, 8, 4, 5, 8};
    int n = sizeof(array) / sizeof(array[0]);


    gettimeofday(&inicio, 0);
    start = clock();

    countingSort(array, n);

    printArray(array, n);

    tempo(start,inicio);
}