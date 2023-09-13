#include <stdio.h>
#include <sys/time.h>
#include <time.h>

void countingSort(int aux[], int n) {

    int maximo = aux[0];
    int saida[n];

    //verifica qual numero é o valor maximo a partir da posição 1, visto que o valor maximo inicial é o
    //valor da posição 0
    for (int i = 1; i < n; i++) {
        if (aux[i] > maximo)
            maximo = aux[i];
    }
    int count[maximo+1];
    //coloca 0 em todas as posições dos vetores
    for (int i = 0; i <=  maximo; ++i) {
        count[i] = 0;
    }
    //coloca quantas vezes cada valor se repete nos devidos lugares
    for (int i = 0; i < n; i++) {
        count[aux[i]]++;
    }
    //faz o somatorio com o valor anterior
    for (int i = 1; i <= maximo; i++) {
        count[i] += count[i - 1];
    }
    //organiza os valores no vetor de saída
    for (int i = n - 1; i >= 0; i--) {
        saida[count[aux[i]] - 1] = aux[i];
        count[aux[i]]--;
    }
    //atribui os valores do vetor saída ao vetor aux
    for (int i = 0; i < n; i++) {
        aux[i] = saida[i];
    }
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

    //cria o vetor
    int array[] = { 7,5,3,7,4,1,6,6,2, 3, 1,
                    6,3,3, 9,1,2,8,8,4,6,
                    7,4,3,7};
    //verifica o tamanho do vetor
    int n = sizeof(array) / sizeof(array[0]);

    //inicia a contagem do tempo
    gettimeofday(&inicio, 0);
    start = clock();

    //chama a função ordenação por contagem
    countingSort(array, n);

    //imprimi o array ordenado
        for (int i = 0; i < n; ++i){
        printf("%d  ", array[i]);
        }

    printf("\n");

    //função que finaliza a contagem do tempo
    tempo(start,inicio);

    return 0;
}