# Menor Subárvore com Nós Mais Profundos

Este projeto implementa uma função para encontrar a menor subárvore que contém todos os nós mais profundos de uma árvore binária.

## 📌 Descrição

O código percorre a árvore para identificar os nós mais profundos e retorna a menor subárvore que contém todos eles.

## 🛠️ Funcionamento

O programa executa os seguintes passos:

1. **Calcula a profundidade** de cada nó da árvore.
2. **Busca o menor nó** que contém todos os nós mais profundos.
3. **Retorna a subárvore correspondente**.

## ⏳ Complexidade

A solução tem complexidade **O(n)**, pois percorre a árvore duas vezes:
- Uma para calcular as profundidades.
- Outra para encontrar o nó correto.

## 🏗️ Compilação e Execução

 Para compilar o código, use:

```sh
gcc -o trabalho3Laila trabalho3Laila.c -g

Para rodar o programa:

sh
./trabalho3Laila

# ⚠️ Dificuldades Encontradas
Compreender a necessidade da função de profundidade.
Implementar a lógica recursiva corretamente.
Garantir a liberação de memória para evitar vazamentos.

# ✅ Conclusão
O projeto foi útil para reforçar conceitos de árvores binárias e recursão. O código final encontra corretamente a subárvore desejada e não apresenta vazamento de memória.