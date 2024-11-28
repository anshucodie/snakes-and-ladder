#include <stdio.h>
#include <stdlib.h>

int dice() { return rand() % 6 + 1; }

int move(int currentPosition, int roll)
{
    int newPosition = currentPosition + roll;
    int snakesandladders[101];

    for (int i = 0; i <= 100; i++)
    {
        snakesandladders[i] = 0;
    }
    snakesandladders[6] = 40;
    snakesandladders[23] = -10;
    snakesandladders[45] = -7;
    snakesandladders[61] = -18;
    snakesandladders[65] = -8;
    snakesandladders[77] = 5;
    snakesandladders[98] = -10;

    int finalPosition = newPosition + snakesandladders[newPosition];

    if (finalPosition > 100)
    {
        printf("player cannot move!");
    }
    return finalPosition;
}

int main()
{
    int n;
    printf("===============================================");
    printf("To start press 1, to exit press 0");
    printf("Enter your choice: ");
    scanf("%d", &n);
    switch (n)
    {
    case 0:
        printf("Program is ending!");
        break;

    case 1:
    }

    return 0;
}
