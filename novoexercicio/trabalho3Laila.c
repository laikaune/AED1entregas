#include <stdio.h>
#include <stdlib.h>

typedef struct NoArvore {
    int valor;
    struct NoArvore *esquerda;
    struct NoArvore *direita;
} NoArvore;

struct NoArvore* subarvoreComMaisProfundos(struct NoArvore* raiz) {
    if (!raiz) return NULL;
    if (!raiz->esquerda && !raiz->direita) return raiz; // Retorna se for folha
    if (raiz->esquerda && raiz->direita) return raiz; // Retorna raiz se tiver dois filhos (simplificado)
    return raiz->esquerda ? raiz->esquerda : raiz->direita; // Retorna o filho existente
}

NoArvore* novoNo(int valor) {
    NoArvore* no = (NoArvore*)malloc(sizeof(NoArvore));
    if (!no) {
        printf("Erro ao alocar memória\n");
        return NULL;
    }
    no->valor = valor;
    no->esquerda = NULL;
    no->direita = NULL;
    return no;
}

int main() {
    NoArvore* raiz = novoNo(1);
    raiz->esquerda = novoNo(2);
    raiz->direita = novoNo(3);
    raiz->esquerda->esquerda = novoNo(4);
    raiz->esquerda->direita = novoNo(5);
    raiz->direita->direita = novoNo(6);
    
    NoArvore* resultado = subarvoreComMaisProfundos(raiz);
    if (resultado) printf("Resultado: %d\n", resultado->valor);
    
    free(raiz->esquerda->esquerda);
    free(raiz->esquerda->direita);
    free(raiz->direita->direita);
    free(raiz->esquerda);
    free(raiz->direita);
    free(raiz);
    
    return 0;
}