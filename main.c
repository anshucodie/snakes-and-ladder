#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int p1 = 0, p2 = 0;
int c, turn;
int board[100];
char ch;
char p1name[100];
char p2name[100];

// Gives out a random number between 1 and 6, and acts like a virtual dice
int dice()
{
    static int initial = 0;
    if (!initial)
    {
        srand(time(NULL));
        initial = 1;
    }

    // Generate and return random number between 1 and 6
    return rand() % 6 + 1;
}

// Clears out the terminal each time the dice is rolled
void clearTerminal()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// Saves the game in save.txt file
void savegame()
{
    FILE *fptr;
    fptr = fopen("save.txt", "w");
    if (fptr == NULL)
    {
        printf("The file was unabble to open. Saving not done.");
        exit(0);
    }
    else
    {
        fprintf(fptr, "%s %s %d %d", p1name, p2name, p1, p2);
        fclose(fptr);
    }
}

// Loads the game from save.txt file in the same directory
void loadgame()
{
    FILE *fptr;
    fptr = fopen("save.txt", "r");
    printf("OK\n");
    if (fptr == NULL)
    {
        printf("The file was unabble to open. Loading not done.");
        exit(0);
    }
    else
    {
        fscanf(fptr, "%s %s %d %d", p1name, p2name, &p1, &p2);
        fclose(fptr);
    }
    printf("%s %s %d %d\n", p1name, p2name, p1, p2);
}

// Creates the layout for the game and also prints the position of Player 1 and Player 2 on the board
void layout(int a, int b)
{
    printf("\n");
    for (int i = 0; i < 100; i++)
    {
        board[i] = i + 1;
    }
    int j = 0;
    while (a == board[j])
    {
        int n = board[j];
        board[j] = a;
        j++;
    }

    for (int i = board[99]; i >= board[98]; i--)
    {

        if (i == a && i == b)
        {
            printf("#P12 ");
        }

        else if (i == a)
        {
            printf("#P1  ");
        }

        else if (i == b)
        {
            printf("#P2  ");
        }

        else
        {
            printf("%d    ", i);
        }
    }

    for (int i = board[97]; i >= board[90]; i--)
    {
        if (i == a && i == b)
        {
            printf(" #P12 ");
        }

        else if (i == a)
        {
            printf(" #P1  ");
        }
        else if (i == b)
        {
            printf(" #P2  ");
        }

        else if (i == 98 || i == 93)
        {
            printf(" (%d)  ", i);
        }

        else if (i == 91)
        {
            printf(" /%d/  ", i);
        }

        else
        {
            printf(" %d    ", i);
        }
    }

    printf("\n");
    printf("\n");
    printf("\n");

    for (int i = board[8]; i >= board[1]; i--)
    {
        if (i % 2 == 0)
        {
            for (int j = 10 * i; j >= 10 * i - 9; j--)
            {

                if (j == a && j == b)
                {
                    printf("#P12  ");
                }

                else if (j == a)
                {
                    printf("#P1   ");
                }
                else if (j == b)
                {
                    printf("#P2   ");
                }

                else if (j == 98 || j == 93 || j == 17)
                {
                    printf("(%d)   ", j);
                }

                else if (j == 73 || j == 39)
                {
                    printf("/%d/   ", j);
                }

                else if (j == 76 || j == 54 || j == 32)
                {
                    printf("|%d|   ", j);
                }

                else
                {
                    printf("%d     ", j);
                }
            }
            printf("\n");
            printf("\n");
            printf("\n");
        }

        else
        {
            for (int k = 10 * i - 9; k <= 10 * i; k++)
            {

                if (k == a && k == b)
                {
                    printf("#P12  ");
                }

                else if (k == a)
                {
                    printf("#P1   ");
                }
                else if (k == b)
                {
                    printf("#P2   ");
                }

                else if (k == 62 || k == 64 || k == 86)
                {
                    printf("(%d)   ", k);
                }

                else if (k == 89 || k == 43 || k == 21)
                {
                    printf("/%d/   ", k);
                }

                else if (k == 84 || k == 66 || k == 48)
                {
                    printf("|%d|   ", k);
                }

                else
                {
                    printf("%d     ", k);
                }
            }
            printf("\n");
            printf("\n");
            printf("\n");
        }
    }

    for (int i = board[0]; i <= board[9]; i++)
    {

        if (i == a && i == b)
        {
            printf("#P12   ");
        }
        else if (i == a)
        {
            printf("#P1    ");
        }
        else if (i == b)
        {
            printf("#P2    ");
        }

        else if (i == 7)
        {
            printf("(%d)    ", i);
        }

        else
        {
            printf("%d      ", i);
        }
    }
    printf("\n");
}

// Processes how the Players act according to the dice and how they move
int maingame()
{
    while (p1 != 100 || p2 != 100)
    {
        layout(p1, p2);
        c = dice();
        printf("\nPress enter to roll the dice...\n");
        ch = getchar();
        if (ch == 10)
        {
            clearTerminal();
            if (turn % 2 != 0)
            {
                if (p1 + c > 100)
                {
                    turn++;
                }
                else if (p1 == 0)
                {
                    if (c == 6)
                    {
                        p1 = 1;
                    }
                    else
                    {
                        turn++;
                    }
                }
                else if (p1 + c == 100)
                {
                    return 1;
                    exit(0);
                }
                else
                {
                    turn++;
                    p1 += c;
                }
                printf("P1 rolled %d in the dice\n\n", c);
            }
            else
            {

                if (p2 + c > 100)
                {
                    turn++;
                }
                else if (p2 == 0)
                {
                    if (c == 6)
                    {
                        p2 = 1;
                    }
                    else
                    {
                        turn++;
                    }
                }
                else if (p2 + c == 100)
                {
                    return 2;
                    exit(0);
                }
                else
                {
                    turn++;
                    p2 += c;
                }
                printf("P2 rolled %d in the dice\n\n", c);
            }

            // Defines the snakes and ladders in the game
            switch (p1)
            {
                // Snakes
            case 17:
                p1 = 7;
                break;
            case 62:
                p1 = 19;
                break;
            case 86:
                p1 = 37;
                break;
            case 93:
                p1 = 69;
                break;
            case 98:
                p1 = 80;
                break;
                // Ladders
            case 21:
                p1 = 43;
                break;
            case 32:
                p1 = 84;
                break;
            case 73:
                p1 = 91;
                break;
            }
            switch (p2)
            {
                // Snakes
            case 17:
                p1 = 7;
                break;
            case 62:
                p1 = 19;
                break;
            case 86:
                p1 = 37;
                break;
            case 93:
                p1 = 69;
                break;
            case 98:
                p1 = 80;
                break;
                // Ladders
            case 21:
                p1 = 43;
                break;
            case 32:
                p1 = 84;
                break;
            case 73:
                p1 = 91;
                break;
            }
        }
        else if (ch == 57)
        {
            printf("SAVING...\n");
            savegame();
            printf("GAME SAVED.....EXITING THE GAME! BYE!!\n");
            break;
        }
    }
    return 0;
}

// Main function which you see in the start of the program
int main()
{
    int n;
    int c;
    // Inputs the name of the players
    printf("Enter the name of P1: ");
    scanf("%s", p1name);
    printf("Enter the name of P2: ");
    scanf("%s", p2name);
    printf("=================================================\n");
    printf("To enter the snake world enter 1\n");
    printf("To load a previous game enter 2\n");
    printf("To exit out enter 0\n");
    printf("=================================================\n");
    printf("Enter your choice: ");
    scanf("%d", &n);
    if (n == 0)
    {
        printf("Meet you again, BYE!!");
    }
    else if (n == 1)
    {
        c = maingame();
        if (c == 1)
        {
            printf("Congo! %s has won and reached the home!!", p1name);
        }
        else if (c == 2)
        {
            printf("Congo! %s has won and reached the home!!", p2name);
        }
    }
    else if (n == 2)
    {
        loadgame();
        c = maingame();
        if (c == 1)
        {
            printf("Congo! %s has won and reached the home!!", p1name);
        }
        else if (c == 2)
        {
            printf("Congo! %s has won and reached the home!!", p2name);
        }
    }

    return 0;
}
