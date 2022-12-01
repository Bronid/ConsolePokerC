#include <stdio.h>
#include <stdbool.h>
#include "poker.h"

int main()
{
    struct karta talia[52] = {
        {2, 1}, {3, 1}, {4, 1}, {5, 1}, {6, 1}, {7, 1}, {8, 1}, {9, 1}, {10, 1}, {11, 1}, {12, 1}, {13, 1}, {14, 1},
        {2, 2}, {3, 2}, {4, 2}, {5, 2}, {6, 2}, {7, 2}, {8, 2}, {9, 2}, {10, 2}, {11, 2}, {12, 2}, {13, 2}, {14, 2},
        {2, 3}, {3, 3}, {4, 3}, {5, 3}, {6, 3}, {7, 3}, {8, 3}, {9, 3}, {10, 3}, {11, 3}, {12, 3}, {13, 3}, {14, 3},
        {2, 4}, {3, 4}, {4, 4}, {5, 4}, {6, 4}, {7, 4}, {8, 4}, {9, 4}, {10, 4}, {11, 4}, {12, 4}, {13, 4}, {14, 4}
    };
    
    struct karta firsthand[5] = { {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0} };
    struct karta secondhand[5] = { {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0} };
    
    int liczba_elementow1 = sizeof(firsthand) / sizeof(*firsthand);
    int liczba_elementow2 = sizeof(secondhand) / sizeof(*secondhand);
    
    giveCards(talia, firsthand, liczba_elementow1);
    giveCards(talia, secondhand, liczba_elementow2);
 
    sort(firsthand, liczba_elementow1);
    sort(secondhand, liczba_elementow2);
    
    printPlayerCards(firsthand, liczba_elementow1);
    printPlayerCards(secondhand, liczba_elementow2);
    
    if (GetCombinationValue(firsthand, liczba_elementow1) > GetCombinationValue(secondhand, liczba_elementow2)) printf("Player 1 wins!\n");
    else if (GetCombinationValue(firsthand, liczba_elementow1) < GetCombinationValue(secondhand, liczba_elementow2)) printf("Player 2 wins!\n");
    else printf("Draw!\n");

    return 0;
}