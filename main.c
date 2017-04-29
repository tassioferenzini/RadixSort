/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: tassio
 *
 * Created on 1 de Abril de 2017, 18:26
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int a[], tamanho;

void radixSort(int vetor[], int tamanho) {
    int i;
    int *b;
    int maior = vetor[0];
    int exp = 1;

    b = (int *) calloc(tamanho, sizeof (int));

    for (i = 0; i < tamanho; i++) {
        if (vetor[i] > maior)
            maior = vetor[i];
    }

    while (maior / exp > 0) {
        int bucket[10] = {0};
        for (i = 0; i < tamanho; i++)
            bucket[(vetor[i] / exp) % 10]++;
        for (i = 1; i < 10; i++)
            bucket[i] += bucket[i - 1];
        for (i = tamanho - 1; i >= 0; i--)
            b[--bucket[(vetor[i] / exp) % 10]] = vetor[i];
        for (i = 0; i < tamanho; i++)
            vetor[i] = b[i];
        exp *= 10;
    }

    free(b);
}

int main(int argc, char** argv) {

    srand(time(NULL));
    for (int t = 0; t < 10; t++) {
        a[t] = rand() % 10;
    }

    printf("Entrada  = ");
    for (int t = 0; t < 10; t++) {
        printf("%d ", a[t]);
    }

    tamanho = 11;

    printf("\nOdenação = ");
    radixSort(a, tamanho);
    for (int t = 0; t < 10; t++) {
        printf("%d ", a[t]);
    }

    return (EXIT_SUCCESS);
}



