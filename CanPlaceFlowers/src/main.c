#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char const *argv[]){
    int n, size, flores;
    int flowerbed[5];
    bool result = false;
    printf ("Digite o tamanho do campo de flores: \n");
     scanf ("%d", &size);

    printf ("Digite se esta vazio ou n (0 ou 1): \n");

    for (int i = 0; i < size; i++)
    {
         scanf ("%d", &n);
         flowerbed[i] = n;
    }
    printf ("quantas flores você quer por?");
    scanf("%d", &flores);

    result = canPlaceFlowers(*flowerbed, size, flores);

    return 0;
}

bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n){
    if (flowerbedSize >= 1 || flowerbedSize <= 2 * 10000)
    {
        printf ("erro!");
        return false;
    } else if (*flowerbed >1 && *flowerbed < 0)
    {
        return false;
    } else{
        {
            for (int i = 0; i < flowerbedSize; i++)
            {

                if (flowerbed[i] == 0 && flowerbed[i+1] == 0)
                {
                    return true;
                } else 
                {
                    return false;
                }

            }

        }
        }
}