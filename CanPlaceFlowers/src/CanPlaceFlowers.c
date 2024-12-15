#include <stdio.h>
#include <stdbool.h>

// Função que verifica se é possível plantar 'n' flores no canteiro
bool CanPlaceFlowers(int* flowerbed, int flowerbedSize, int flowersToPlant) {
    int plantedCount = 0;

    for (int i = 0; i < flowerbedSize; i++) {
        if (flowerbed[i] == 0) {
            bool leftIsEmpty = (i == 0) || (flowerbed[i - 1] == 0);
            bool rightIsEmpty = (i == flowerbedSize - 1) || (flowerbed[i + 1] == 0);

            if (leftIsEmpty && rightIsEmpty) {
                flowerbed[i] = 1;  // Planta a flor
                plantedCount++;

                // Se já plantamos flores suficientes, saímos cedo
                if (plantedCount >= flowersToPlant) {
                    return true;
                }
            }
        }
    }

    // Retorna se conseguimos plantar a quantidade desejada
    return plantedCount >= flowersToPlant;
}

int main() {
    int flowerbedSize;
    int flowersToPlant;

    // Entrada: tamanho do canteiro
    printf("Digite o tamanho do campo de flores: ");
    scanf("%d", &flowerbedSize);

    if (flowerbedSize <= 0) {
        printf("Tamanho inválido.\n");
        return 1;
    }

    // Cria o canteiro
    int flowerbed[flowerbedSize];

    // Entrada: estado inicial do canteiro
    printf("Digite se cada posição está vazia ou não (0 ou 1):\n");
    for (int i = 0; i < flowerbedSize; i++) {
        scanf("%d", &flowerbed[i]);

        if (flowerbed[i] != 0 && flowerbed[i] != 1) {
            printf("Valor inválido! Apenas 0 ou 1 são permitidos.\n");
            return 1;
        }
    }

    // Entrada: número de flores a plantar
    printf("Quantas flores você quer plantar? ");
    scanf("%d", &flowersToPlant);

    if (flowersToPlant < 0) {
        printf("Número inválido de flores.\n");
        return 1;
    }

    // Verifica se é possível plantar as flores
    bool result = CanPlaceFlowers(flowerbed, flowerbedSize, flowersToPlant);

    // Exibe o resultado
    if (result) {
        printf("É possível plantar %d flores.\n", flowersToPlant);
    } else {
        printf("Não é possível plantar %d flores.\n", flowersToPlant);
    }

    return 0;
}

