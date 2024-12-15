# Trabalho: CanPlaceFlowers
Nome: Laila Kauane Carvalho da Silva  Matricula: 23103141
## Descrição do Projeto
Este programa, implementado em linguagem C, verifica se é possível plantar um número específico de flores em um canteiro, respeitando a regra de que duas flores não podem ser plantadas em posições adjacentes.

O programa utiliza a função `canPlaceFlowers` para realizar a verificação e permite ao usuário fornecer as configurações do canteiro e o número de flores desejado.

---

## Casos Testados com Sucesso
1. **Caso 1:**
   - **Entrada:** `[0, 0, 1, 0, 0]`  
   - **Flores:** `1`  
   - **Resultado esperado:** É possível plantar 1 flor.  
   - **Resultado obtido:** **Sucesso.**

2. **Caso 2:**
   - **Entrada:** `[1, 0, 0, 0, 1]`  
   - **Flores:** `2`  
   - **Resultado esperado:** Não é possível plantar 2 flores.  
   - **Resultado obtido:** **Sucesso.**

3. **Caso 3:**
   - **Entrada:** `[0, 0, 0, 0, 0]`  
   - **Flores:** `3`  
   - **Resultado esperado:** É possível plantar 3 flores.  
   - **Resultado obtido:** **Sucesso.**

---

## O que Funciona
- A lógica de verificação para plantar flores funciona corretamente.
- Trata entradas inválidas como valores fora de `[0, 1]`.
- Gera a saída esperada para todos os casos testados.

---

## O que Não Funciona
- Não há tratamento para entradas não numéricas (por exemplo, letras ou caracteres especiais).  
- Não foi testado para valores muito grandes ou negativos de flores.
---

## Como Rodar o Programa
1. Certifique-se de ter o compilador GCC instalado.
2. Compile o programa:
   ```bash
   gcc -o CanPlaceFlowers CanPlaceFlowers.c
