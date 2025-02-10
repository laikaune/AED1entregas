// laila kauane, 23103141
// fiz as variáveis em português para melhor entedimento meu, pois não domino tanto a lingua
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    double ganho;  // Quanto a aprovação aumenta ao adicionar um aluno
    int aprovados;
    int total;
} Turma;

// Prototipos:
double calcularGanho(int aprovados, int total);
int comparar(const void *a, const void *b);
double maximoMediaAprovacao(int** turmas, int tamanho, int* colunas, int alunosExtras);
double maximoMediaAprovacao(int** turmas, int tamanho, int* colunas, int alunosExtras);

// função para calcular o aumento na taxa de aprovação ao adicionar um aluno
double calcularGanho(int aprovados, int total) {
    return ((double)(aprovados + 1) / (total + 1)) - ((double)aprovados / total);
}

// função de comparação para ordenar do maior ganho para o menor
int comparar(const void *a, const void *b) {
    double dif = ((Turma*)b)->ganho - ((Turma*)a)->ganho;
    return (dif > 0) - (dif < 0); 
}

double maximoMediaAprovacao(int** turmas, int tamanho, int* colunas, int alunosExtras) {
    Turma *lista = (Turma*) malloc(tamanho * sizeof(Turma));

    for (int i = 0; i < tamanho; i++) {
        lista[i].aprovados = turmas[i][0];
        lista[i].total = turmas[i][1];
        lista[i].ganho = calcularGanho(lista[i].aprovados, lista[i].total);
    }

    qsort(lista, tamanho, sizeof(Turma), comparar);


    for (int i = 0; i < alunosExtras; i++) {
        lista[0].aprovados++; 
        lista[0].total++;
        lista[0].ganho = calcularGanho(lista[0].aprovados, lista[0].total);
    }
    double somaRazao = 0.0;
    for (int i = 0; i < tamanho; i++) {
        somaRazao += (double) lista[i].aprovados / lista[i].total;
    }

    free(lista);
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

