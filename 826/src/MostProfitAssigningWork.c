#include <stdio.h>
#include <stdlib.h>

// estrutura para armazenar dificuldade e lucro dos trabalhos
// tentei fazer algo que deixasse mais organizado
typedef struct {
    int dificuldade;
    int lucro;
} Trabalho;

// funcao para comparar os trabalhos pela dificuldade
// precisei disso pra ordenar os trabalhos e facilitar a busca
int compararTrabalho(const void *a, const void *b) {
    Trabalho *trabalhoA = (Trabalho *)a;
    Trabalho *trabalhoB = (Trabalho *)b;
    return trabalhoA->dificuldade - trabalhoB->dificuldade;
}

// funcao pra comparar os trabalhadores pela habilidade
// queria ordenar os trabalhadores tambem pra ajudar na busca
int compararInt(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int maxProfitAssignment(int* dificuldade, int tamanhoDificuldade, int* lucro, int tamanhoLucro, int* trabalhador, int tamanhoTrabalhador) {
    Trabalho trabalhos[tamanhoDificuldade];
    for (int i = 0; i < tamanhoDificuldade; i++) {
        trabalhos[i].dificuldade = dificuldade[i];
        trabalhos[i].lucro = lucro[i];
    }

    // ordena os trabalhos e os trabalhadores
    qsort(trabalhos, tamanhoDificuldade, sizeof(Trabalho), compararTrabalho);
    qsort(trabalhador, tamanhoTrabalhador, sizeof(int), compararInt);

    int maxLucro = 0, totalLucro = 0, i = 0;
    for (int j = 0; j < tamanhoTrabalhador; j++) {
        // aqui to percorrendo os trabalhos que o trabalhador consegue fazer
        while (i < tamanhoDificuldade && trabalhador[j] >= trabalhos[i].dificuldade) {
            if (trabalhos[i].lucro > maxLucro) {
                maxLucro = trabalhos[i].lucro;
            }
            i++;
        }
        // adiciono o maior lucro que o trabalhador pode conseguir
        totalLucro += maxLucro;
    }

    return totalLucro;
}

int main() {
    int dificuldade[] = {2, 4, 6, 8, 10};
    int lucro[] = {10, 20, 30, 40, 50};
    int trabalhador[] = {4, 5, 6, 7};

    // testando a funcao pra ver se ta certa
    int resultado = maxProfitAssignment(dificuldade, 5, lucro, 5, trabalhador, 4);
    printf("Lucro máximo: %d\n", resultado);

    return 0;
}