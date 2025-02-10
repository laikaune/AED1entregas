// laila kauane, 23103141
// fiz as variáveis em português para melhor entedimento meu, pois não domino tanto a lingua
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    double ganho;
    int aprovados;
    int total;
} Turma;

double calcularGanho(int aprovados, int total) {
    return ((double)(aprovados + 1) / (total + 1)) - ((double)aprovados / total);
}

// Troca duas turmas de lugar
void trocar(Turma *a, Turma *b) {
    Turma temp = *a;
    *a = *b;
    *b = temp;
}

// Organiza a heap
void ajustarHeap(Turma *heap, int n, int i) {
    int maior = i;
    int esq = 2 * i + 1;
    int dir = 2 * i + 2;

    if (esq < n && heap[esq].ganho > heap[maior].ganho)
        maior = esq;
    if (dir < n && heap[dir].ganho > heap[maior].ganho)
        maior = dir;
    if (maior != i) {
        trocar(&heap[i], &heap[maior]);
        ajustarHeap(heap, n, maior);
    }
}

// Constrói a heap máxima
void construirHeap(Turma *heap, int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        ajustarHeap(heap, n, i);
    }
}

double maximoMediaAprovacao(int** turmas, int tamanho, int* colunas, int alunosExtras) {
    Turma *heap = (Turma*) malloc(tamanho * sizeof(Turma));

    for (int i = 0; i < tamanho; i++) {
        heap[i].aprovados = turmas[i][0];
        heap[i].total = turmas[i][1];
        heap[i].ganho = calcularGanho(heap[i].aprovados, heap[i].total);
    }

    construirHeap(heap, tamanho);

    while (alunosExtras--) {
        heap[0].aprovados++;
        heap[0].total++;
        heap[0].ganho = calcularGanho(heap[0].aprovados, heap[0].total);
        ajustarHeap(heap, tamanho, 0);
    }

    double somaRazao = 0.0;
    for (int i = 0; i < tamanho; i++) {
        somaRazao += (double) heap[i].aprovados / heap[i].total;
    }

    free(heap);
    return somaRazao / tamanho;
}

int main() {
    int dados[][2] = {{1,2}, {3,5}, {2,2}};
    int tamanho = 3;
    int alunosExtras = 2;

    int **turmas = (int**) malloc(tamanho * sizeof(int*));
    for (int i = 0; i < tamanho; i++) {
        turmas[i] = (int*) malloc(2 * sizeof(int));
        turmas[i][0] = dados[i][0];
        turmas[i][1] = dados[i][1];
    }

    int colunas = 2;
    double resultado = maximoMediaAprovacao(turmas, tamanho, &colunas, alunosExtras);
    printf("Média final: %.5f\n", resultado);

    for (int i = 0; i < tamanho; i++) free(turmas[i]);
    free(turmas);

    return 0;
}


