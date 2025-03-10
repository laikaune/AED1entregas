#include <stdio.h>
#include <stdlib.h>

// definicao da estrutura do no da arvore
typedef struct no_arvore {
    int valor;
    struct no_arvore *esquerda;
    struct no_arvore *direita;
} no_arvore;

// funcao auxiliar para calcular a profundidade de um no
int profundidade(no_arvore* raiz) {
    if (!raiz) return 0;
    int prof_esquerda = profundidade(raiz->esquerda);
    int prof_direita = profundidade(raiz->direita);
    return (prof_esquerda > prof_direita ? prof_esquerda : prof_direita) + 1;
}

// funcao para encontrar a menor subarvore contendo os nos mais profundos
no_arvore* subarvore_com_mais_profundos(no_arvore* raiz) {
    if (!raiz) return NULL;
    
    int prof_esquerda = profundidade(raiz->esquerda);
    int prof_direita = profundidade(raiz->direita);
    
    // se ambas as subarvores tem a mesma profundidade, a raiz contem os nos mais profundos
    if (prof_esquerda == prof_direita) return raiz;
    
    // se a subarvore esquerda for mais profunda, buscamos nela
    return prof_esquerda > prof_direita ? subarvore_com_mais_profundos(raiz->esquerda) : subarvore_com_mais_profundos(raiz->direita);
}

// funcao auxiliar para criar um novo no
no_arvore* novo_no(int valor) {
    no_arvore* no = (no_arvore*)malloc(sizeof(no_arvore));
    if (!no) {
        printf("erro ao alocar memoria\n");
        exit(1);
    }
    no->valor = valor;
    no->esquerda = NULL;
    no->direita = NULL;
    return no;
}

int main() {
    // criando uma arvore de exemplo
    no_arvore* raiz = novo_no(1);
    raiz->esquerda = novo_no(2);
    raiz->direita = novo_no(3);
    raiz->esquerda->esquerda = novo_no(4);
    raiz->esquerda->direita = novo_no(5);
    raiz->direita->direita = novo_no(6);
    raiz->esquerda->direita->esquerda = novo_no(7);
    raiz->esquerda->direita->direita = novo_no(8);
    
    // encontrando a menor subarvore que contem todos os nos mais profundos
    no_arvore* resultado = subarvore_com_mais_profundos(raiz);
    if (resultado) printf("resultado: %d\n", resultado->valor);
    
    // liberacao de memoria
    free(raiz->esquerda->esquerda);
    free(raiz->esquerda->direita->esquerda);
    free(raiz->esquerda->direita->direita);
    free(raiz->esquerda->direita);
    free(raiz->direita->direita);
    free(raiz->esquerda);
    free(raiz->direita);
    free(raiz);
    
    return 0;
}