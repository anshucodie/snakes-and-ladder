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

void layout()
{
    for (int i = 100; i >= 99; i--)
    {
        printf("%d    ", i);
    }

    for (int i = 98; i >= 91; i--)
    {
        printf(" %d    ", i);
    }

    printf("\n");
    printf("\n");
    printf("\n");

    for (int i = 9; i >= 2; i--)
    {
        if (i % 2 == 0)
        {
            for (int j = 10 * i; j >= 10 * i - 9; j--)
            {
                printf("%d     ", j);
            }
            printf("\n");
            printf("\n");
            printf("\n");
        }

        else
        {
            for (int k = 10 * i - 9; k <= 10 * i; k++)
            {
                printf("%d     ", k);
            }
            printf("\n");
            printf("\n");
            printf("\n");
        }
    }

    for (int i = 1; i <= 10; i++)
    {
        printf("%d      ", i);
    }
}

int main()
{
    int n;
    printf("=================================================\n");
    printf("To start press 1, to exit press 0\n");
    printf("Enter your choice: ");
    scanf("%d", &n);
    switch (n)
    {
    case 0:
        printf("Program is ending!");
        break;

    case 1:
        layout();
    }

    return 0;
}
