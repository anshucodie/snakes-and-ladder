#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int p1 = 0, p2 = 0;
int c, turn;
int board[100];
char ch;

int dice() { 
    srand(time(NULL));
    return rand() % 6 + 1; 
}

void clearTerminal()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void layout(int a , int b){

    for(int i = 0 ; i < 100 ; i++){
        board[i] = i+1;
    }
    int j = 0;
    while(a == board[j]){
            int n = board[j];
            board[j] = a;
            j++;
        }

    for(int i = board[99] ; i >= board[98] ; i--){
            
            if(i == a && i == b){
                printf("#P12 ");
            }

            else if (i == a) { 
                printf("#P1  "); 
            } 
                
            else if (i == b) { 
                printf("#P2  "); 
            } 

            else{
                printf("%d    " , i);
            }
    }

    for(int i = board[97] ; i >= board[90] ; i--){
            if(i == a && i == b){
                printf(" #P12 ");
            }
            
            else if (i == a) { 
                printf(" #P1  "); 
            } 
            else if (i == b) { 
                printf(" #P2  "); 
            } 
        
            else{
            printf(" %d    " , i);
            }
    }

    printf("\n");
    printf("\n");
    printf("\n");

    for(int i = board[8] ; i >= board[1] ; i--){
        if(i%2 == 0){
            for(int j = 10*i ;j >= 10*i - 9 ; j--){

            if(j == a && j == b){
                printf("#P12  ");
            }
                
            else if (j == a) { 
                printf("#P1   "); 
            } 
            else if (j == b) { 
                printf("#P2   "); 
            } 
                
            else{
            printf("%d     " , j);
            }
        }
        printf("\n");
        printf("\n");
        printf("\n");
        }

        else{
            for(int k = 10*i - 9 ; k <= 10*i ; k++){

                if(k == a && k == b){
                printf("#P12  ");
                }

                else if (k == a) { 
                printf("#P1   "); 
                } 
                else if (k == b) { 
                printf("#P2   "); 
                } 
                else{
                printf("%d     " , k);
                }
        }
        printf("\n");
        printf("\n");
        printf("\n");
        }
    }

    for(int i = board[0] ; i <= board[9] ; i++){

            if(i == a && i == b){
                printf("#P12   ");
            }
            else if (i == a) { 
                printf("#P1    "); 
            } 
            else if (i == b) { 
                printf("#P2    "); 
            } 
            else{
            printf("%d      " , i);
            }
    }
    printf("\n");
}
void maingame()
{
    while (p1 != 100 || p2 != 100)
    {
        layout(p1, p2);
        c = dice();
        printf("\nPress enter to roll the dice...\n");
        ch = getchar();
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
                printf("P1 wins!");
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
                printf("P2 wins!");
                exit(0);
            }
            else
            {
                turn++;
                p2 += c;
            }
            printf("P2 rolled %d in the dice\n\n", c);
        }

        switch (p1)
        {
        case 6:
            p1 = 40;
            break;
        case 23:
            p1 = 13;
            break;
        case 45:
            p1 = 38;
            break;
        case 61:
            p1 = 43;
            break;
        case 65:
            p1 = 57;
            break;
        case 77:
            p1 = 82;
            break;
        case 98:
            p1 = 88;
            break;
        }
        switch (p2)
        {
        case 6:
            p2 = 40;
            break;
        case 23:
            p2 = 13;
            break;
        case 45:
            p2 = 38;
            break;
        case 61:
            p2 = 43;
            break;
        case 65:
            p2 = 57;
            break;
        case 77:
            p2 = 82;
            break;
        case 98:
            p2 = 88;
            break;
        }
    }
}

int main()
{
    int n;
    printf("=================================================\n");
    printf("To start press 1, to exit press 0\n");
    printf("Enter your choice: ");
    scanf("%d", &n);
    printf("=================================================\n");
    if (n == 0)
    {
        printf("Program is ending!");
    }
    else if (n == 1)
    {
        maingame();
    }

    return 0;
}
