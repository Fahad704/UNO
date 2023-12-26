#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
int draw = 0;
int indexofplayed;
int phasplayedd4;
int phasplayedd2;
int indexofplayedC;
int cardontable;
int game = 1;
int randomC;
int pcardn = 0;
int ccardn = 0;
int initcard = 7;
struct player
{
    int turn;
};
struct status
{
    int gcount;
    int ycount;
    int rcount;
    int bcount;
    int d2count;
    int hasd2;
    int haspnum;
    int hasd4;
    int haswild;
    int haspact;
    int wildcount;
    int d4count;
    int pnumcount;
    int pactcount;
    int indexd2[20];
    int indexpnum[20];
    int indexpact[20];
    int indexwild[20];
    int indexd4[20];
};
struct cards
{
    char colour;
    int number;
    char action;
    int indeck;
    int isp4;
    int index;
};
struct cards card[112];
struct cards playerC[54];
struct cards compC[54];
struct player player;
struct player comp;

char findMaxcol(int green, int yellow, int red, int blue);
void evaluatePlayer();
void evaluateComp();
void AddCards()
{

    for (int i = 0; i < 25; i++)
    {
        card[i].isp4 = 0;
        card[i].indeck = 1;
        card[0].number = 0;
        card[0].action = 'n';
        card[i].colour = 'y';
        card[i].index = i;
        if (i >= 1 && i <= 9)
        {
            card[i].number = i;
            card[i].action = 'n';
        }
        else if (i >= 10 && i <= 18)
        {
            card[i].number = i - 9;
            card[i].action = 'n';
        }
        else if (i == 19 || i == 20)
        {
            card[i].number = -1;
            card[i].action = 's';
        }
        else if (i == 21 || i == 22)
        {
            card[i].number = -1;
            card[i].action = 'r';
        }
        else if (i == 23 || i == 24)
        {
            card[i].number = -1;
            card[i].action = '2';
        }
    }
    for (int i = 25; i < 50; i++)
    {
        card[i].isp4 = 0;
        card[i].indeck = 1;
        card[25].number = 0;
        card[25].action = 'n';
        card[i].colour = 'b';
        card[i].index = i;
        if (i >= 26 && i <= 34)
        {
            card[i].number = i - 25;
            card[i].action = 'n';
        }
        else if (i >= 35 && i <= 43)
        {
            card[i].number = i - 34;
            card[i].action = 'n';
        }
        else if (i == 44 || i == 45)
        {
            card[i].number = -1;
            card[i].action = 's';
        }
        else if (i == 46 || i == 47)
        {
            card[i].number = -1;
            card[i].action = 'r';
        }
        else if (i == 48 || i == 49)
        {
            card[i].number = -1;
            card[i].action = '2';
        }
    }
    for (int i = 50; i < 75; i++)
    {
        card[i].isp4 = 0;
        card[i].indeck = 1;
        card[50].number = 0;
        card[50].action = 'n';
        card[i].colour = 'r';
        card[i].index = i;
        if (i >= 51 && i <= 59)
        {
            card[i].number = i - 50;
            card[i].action = 'n';
        }
        else if (i >= 60 && i <= 68)
        {
            card[i].number = i - 59;
            card[i].action = 'n';
        }
        else if (i == 69 || i == 70)
        {
            card[i].number = -1;
            card[i].action = 's';
        }
        else if (i == 71 || i == 72)
        {
            card[i].number = -1;
            card[i].action = 'r';
        }
        else if (i == 73 || i == 74)
        {
            card[i].number = -1;
            card[i].action = '2';
        }
    }
    for (int i = 75; i < 100; i++)
    {
        card[i].isp4 = 0;
        card[i].indeck = 1;
        card[75].number = 0;
        card[75].action = 'n';
        card[i].colour = 'g';
        card[i].index = i;
        if (i >= 76 && i <= 84)
        {
            card[i].number = i - 75;
            card[i].action = 'n';
        }
        else if (i >= 85 && i <= 93)
        {
            card[i].number = i - 84;
            card[i].action = 'n';
        }
        else if (i == 94 || i == 95)
        {
            card[i].number = -1;
            card[i].action = 's';
        }
        else if (i == 96 || i == 97)
        {
            card[i].number = -1;
            card[i].action = 'r';
        }
        else if (i == 98 || i == 99)
        {
            card[i].number = -1;
            card[i].action = '2';
        }
    }
    for (int i = 100; i < 108; i++)
    {
        card[i].number = -1;
        card[i].action = '4';
        card[i].isp4 = 1;
        card[i].indeck = 1;
        card[i].colour = 'n';
        card[i].index = i;
        if (i >= 104 && i <= 107)
        {
            card[i].action = 'w';
            card[i].isp4 = 0;
        }
    }
    card[108].colour = 'y';
    card[108].action = 'c';
    card[108].number = -1;
    card[108].indeck = 0;
    card[108].index = 108;
    card[108].isp4 = 0;
    card[109].colour = 'r';
    card[109].action = 'c';
    card[109].number = -1;
    card[109].indeck = 0;
    card[109].index = 109;
    card[109].isp4 = 0;
    card[110].colour = 'g';
    card[110].action = 'c';
    card[110].number = -1;
    card[110].index = 110;
    card[110].isp4 = 0;
    card[110].indeck = 0;
    card[111].colour = 'b';
    card[111].action = 'c';
    card[111].number = -1;
    card[111].indeck = 0;
    card[111].isp4 = 0;
    card[111].index = 111;
}
void drawcard(int b, char a)
{
    if (a == 'p')
    {
        indexofplayed = -1;
    }
    else if (a == 'c')
    {
        indexofplayedC = -1;
    }

    for (int i = 1; i <= b; i++)
    {
        while (1)
        {
            randomC = rand() % 108;
            if (card[randomC].indeck == 1)
            {
                break;
            }
        }

        card[randomC].indeck = 0;
        if (a == 'p')
        {
            playerC[pcardn] = card[randomC];

            pcardn++;
        }

        if (a == 'c')
        {
            compC[ccardn] = card[randomC];
            ccardn++;
        }
    }
}
void sayname(int a, char b) // a is index where 0 is 1st element
{
    if (b == 'I')
    {
        char action[20];
        if (card[a].action == 's')
        {
            strcpy(action, "Skip");
        }
        else if (card[a].action == 'r')
        {
            strcpy(action, "Reverse");
        }
        else if (card[a].action == '2')
        {
            strcpy(action, "Draw 2");
        }
        else if (card[a].action == '4')
        {
            strcpy(action, "Draw 4");
        }
        else if (card[a].action == 'w')
        {
            strcpy(action, "Wild");
        }
        else if (card[a].action == 'c')
        {
            strcpy(action, "Wild colour");
        }
        if (card[a].number != -1)
        {
            if (card[a].colour == 'g')
            {
                printf("\033[1;32mNumber %d\n\033[0m", card[a].number);
                return;
            }
            else if (card[a].colour == 'r')
            {
                printf("\033[1;31mNumber %d\n\033[0m", card[a].number);
                return;
            }
            else if (card[a].colour == 'y')
            {
                printf("\033[1;33mNumber %d\n\033[0m", card[a].number);
                return;
            }
            else if (card[a].colour == 'b')
            {
                printf("\033[1;34mNumber %d\n\033[0m", card[a].number);
                return;
            }
        }
        else if (card[a].action != 'n')
        {
            if (card[a].colour == 'g')
            {
                printf("\033[1;32m%s\n\033[0m", action);
                return;
            }
            else if (card[a].colour == 'r')
            {
                printf("\033[1;31m%s\n\033[0m", action);
                return;
            }
            else if (card[a].colour == 'y')
            {
                printf("\033[1;33m%s\n\033[0m", action);
                return;
            }
            else if (card[a].colour == 'b')
            {
                printf("\033[1;34m%s\n\033[0m", action);
                return;
            }
            else if (card[a].action == '4' || card[a].action == 'w')
            {
                printf("\x1b[1;90m%s\n\x1b[0m", action);
                return;
            }
        }
    }
    else if (b == 'p')
    {
        char action[20];
        if (playerC[a].action == 's')
        {
            strcpy(action, "Skip");
        }
        else if (playerC[a].action == 'r')
        {
            strcpy(action, "Reverse");
        }
        else if (playerC[a].action == '2')
        {
            strcpy(action, "Draw 2");
        }
        else if (playerC[a].action == '4')
        {
            strcpy(action, "Draw 4");
        }
        else if (playerC[a].action == 'w')
        {
            strcpy(action, "Wild");
        }
        if (playerC[a].number != -1)
        {

            if (playerC[a].colour == 'g')
            {
                printf("\033[1;32mNumber %d\n\033[0m", playerC[a].number);
                return;
            }
            else if (playerC[a].colour == 'r')
            {
                printf("\033[1;31mNumber %d\n\033[0m", playerC[a].number);
                return;
            }
            else if (playerC[a].colour == 'y')
            {
                printf("\033[1;33mNumber %d\n\033[0m", playerC[a].number);
                return;
            }
            else if (playerC[a].colour == 'b')
            {
                printf("\033[1;34mNumber %d\n\033[0m", playerC[a].number);
                return;
            }
        }
        else if (playerC[a].action != 'n')
        {
            if (playerC[a].colour == 'g')
            {
                printf("\033[1;32m%s\n\033[0m", action);
                return;
            }
            else if (playerC[a].colour == 'r')
            {
                printf("\033[1;31m%s\n\033[0m", action);
                return;
            }
            else if (playerC[a].colour == 'y')
            {
                printf("\033[1;33m%s\n\033[0m", action);
                return;
            }
            else if (playerC[a].colour == 'b')
            {
                printf("\033[1;34m%s\n\033[0m", action);
                return;
            }
            else
            {
                printf("\x1b[1;90m%s\n\x1b[0m", action);
                return;
            }
        }
    }
    else if (b == 'c')
    {
        char action[20];
        if (compC[a].action == 's')
        {
            strcpy(action, "Skip");
        }
        else if (compC[a].action == 'r')
        {
            strcpy(action, "Reverse");
        }
        else if (compC[a].action == '2')
        {
            strcpy(action, "Draw 2");
        }
        else if (compC[a].action == '4')
        {
            strcpy(action, "Draw 4");
        }
        else if (compC[a].action == 'w')
        {
            strcpy(action, "Wild");
        }
        if (compC[a].number != -1)
        {

            if (compC[a].colour == 'g')
            {
                printf("\033[1;32mNumber %d\n\033[0m", compC[a].number);
                return;
            }
            else if (compC[a].colour == 'r')
            {
                printf("\033[1;31mNumber %d\n\033[0m", compC[a].number);
                return;
            }
            else if (compC[a].colour == 'y')
            {
                printf("\033[1;33mNumber %d\n\033[0m", compC[a].number);
                return;
            }
            else if (compC[a].colour == 'b')
            {
                printf("\033[1;34mNumber %d\n\033[0m", compC[a].number);
                return;
            }
        }
        else if (compC[a].action != 'n')
        {
            if (compC[a].colour == 'g')
            {
                printf("\033[1;32m%s\n\033[0m", action);
                return;
            }
            else if (compC[a].colour == 'r')
            {
                printf("\033[1;31m%s\n\033[0m", action);
                return;
            }
            else if (compC[a].colour == 'y')
            {
                printf("\033[1;33m%s\n\033[0m", action);
                return;
            }
            else if (compC[a].colour == 'b')
            {
                printf("\033[1;34m%s\n\033[0m", action);
                return;
            }
            else
            {
                printf("\x1b[1;90m%s\n\x1b[0m", action);
                return;
            }
        }
    }
}
void randomcardont()
{
    while (1)
    {
        int a = rand() % 108;
        if (card[a].number != -1)
        {
            cardontable = a;
            card[cardontable].indeck = 0;
            break;
        }
    }
}
void playcard(int b, char a) // b is index where 1 is 1st element
{
    int inp;
    int played = b - 1;
    indexofplayed = playerC[played].index;
    if (a == 'p')
    {
        if (b > pcardn)
        {
            printf("You dont have that many cards.\n");
            return;
        }

        if (card[cardontable].action == 'n')
        {
            if (card[cardontable].colour != playerC[played].colour)
            {
                if (card[cardontable].number != playerC[played].number)
                {
                    if (playerC[played].isp4 == 0 && playerC[played].action != 'w')
                    {
                        printf("This card can't be played\n");
                        return;
                    }
                }
            }
        }
        else if (card[cardontable].action != 'n')
        {
            if (card[cardontable].colour != playerC[played].colour)
            {
                if (card[cardontable].action != playerC[played].action)
                {
                    if (playerC[played].isp4 == 0 && playerC[played].action != 'w')
                    {
                        printf("This card can't be played\n");
                        return;
                    }
                }
            }
        }
        cardontable = playerC[played].index;
        if (playerC[played].action == '2')
        {
            draw += 2;
        }
        if (playerC[played].action == '4' || playerC[played].action == 'w')
        {
            if (playerC[played].action == '4')
            {
                draw += 4;
            }
        start:
            printf("Color changes to...?\n");
            printf("1.Red\t");
            printf("2.Yellow\t");
            printf("3.Blue\t");
            printf("4.Green\t\n");
            scanf("%d", &inp);
            getchar();
            if (inp == 1)
            {
                cardontable = 109;
            }
            else if (inp == 2)
            {
                cardontable = 108;
            }
            else if (inp == 3)
            {
                cardontable = 111;
            }
            else if (inp == 4)
            {
                cardontable = 110;
            }
            else
            {
                printf("Invalid input\n");
                goto start;
            }
        }
        if (playerC[played].action == 's' || playerC[played].action == 'r')
        {
            player.turn = 1;
        }
        else
        {
            player.turn = 0;
        }
        printf("You played ");
        sayname(played, 'p');
        
        if (playerC[played].action == '2')
        {
            phasplayedd2 = 1;
            evaluateComp();
            phasplayedd2 = 0;
        }
        else if (playerC[played].action == '4')
        {
            phasplayedd4 = 1;
            evaluateComp();
            phasplayedd4 = 0;
        }
        int j = played;
        for (int i = 1; i <= (pcardn - played); i++)
        {
            playerC[j] = playerC[j + 1];
            j++;
        }

        pcardn--;
        return;
    }
    else if (a == 'c')
    {
        cardontable = compC[played].index;
        int j = played;
        for (int i = 1; i <= (ccardn - played); i++)
        {
            compC[j] = compC[j + 1];
            j++;
        }
        ccardn--;
        return;
    }
}
void evaluateComp()
{
    if (player.turn == 1 || pcardn == 0 || ccardn == 0)
    {
        if (player.turn == 1)
        {
            printf("Computer's turn skipped\n");
        }
        return;
    }

    struct status cstatus;
    comp.turn = 0;
    cstatus.gcount = 0;
    cstatus.ycount = 0;
    cstatus.rcount = 0;
    cstatus.bcount = 0;
    cstatus.haswild = 0;
    cstatus.hasd4 = 0;
    cstatus.haspnum = 0;
    cstatus.haspact = 0;
    cstatus.wildcount = 0;
    cstatus.d4count = 0;
    cstatus.pnumcount = 0;
    cstatus.pactcount = 0;
    cstatus.d2count = 0;
    cstatus.hasd2 = 0;

    for (int i = 0; i < ccardn; i++)
    {
        if (compC[i].colour == 'g')
        {
            cstatus.gcount++;
        }
        else if (compC[i].colour == 'y')
        {
            cstatus.ycount++;
        }
        else if (compC[i].colour == 'r')
        {
            cstatus.rcount++;
        }
        else if (compC[i].colour == 'b')
        {
            cstatus.bcount++;
        }
        if (compC[i].number != -1)
        {
            if (compC[i].number == card[cardontable].number ||
                compC[i].colour == card[cardontable].colour)
            {
                cstatus.indexpnum[cstatus.pnumcount] = i;
                cstatus.haspnum = 1;
                cstatus.pnumcount++;
            }
        }
        else if (compC[i].action != 'n')
        {
            if (compC[i].action == 'w')
            {
                cstatus.indexwild[cstatus.wildcount] = i;
                cstatus.haswild = 1;
                cstatus.wildcount++;
            }
            else if (compC[i].action == '4')
            {
                cstatus.indexd4[cstatus.d4count] = i;
                cstatus.hasd4 = 1;
                cstatus.d4count++;
            }
            else if (compC[i].action == '2')
            {
                cstatus.indexd2[cstatus.d2count] = i;
                cstatus.hasd2 = 1;
                cstatus.d2count++;
            }
            else if (compC[i].action == card[cardontable].action ||
                     compC[i].colour == card[cardontable].colour)
            {
                cstatus.indexpact[cstatus.pactcount] = i;
                cstatus.haspact = 1;
                cstatus.pactcount++;
            }
        }
    }
    if (card[indexofplayed].action == '2' && phasplayedd2)
    {
        if (cstatus.hasd2 == 1)
        {
            indexofplayedC = compC[cstatus.indexd2[0]].index;
            printf("Computer played ");
            sayname(cstatus.indexd2[0], 'c');
            playcard(cstatus.indexd2[0] + 1, 'c');
            draw += 2;
            evaluatePlayer();
            return;
        }
        else
        {
            drawcard(draw, 'c');
            printf("Computer drew %d cards\n", draw);
            draw = 0;
            indexofplayedC = -1;
            return;
        }
    }
    if (card[indexofplayed].action == '4' && phasplayedd4)
    {
        if (cstatus.hasd4 == 0)
        {
            drawcard(draw, 'c');
            printf("Computer drew %d cards\n", draw);
            draw = 0;
            return;
        }
        else
        {
            indexofplayedC = compC[cstatus.indexd4[0]].index;
            playcard(cstatus.indexd4[0] + 1, 'c');
            printf("Computer played ");
            sayname(cstatus.indexd4[0], 'c');
            draw += 4;
            char color;
            color = findMaxcol(cstatus.gcount, cstatus.ycount, cstatus.rcount, cstatus.bcount);
            if (color == 'g')
            {
                cardontable = 110;
            }
            else if (color == 'y')
            {
                cardontable = 108;
            }
            else if (color == 'r')
            {
                cardontable = 109;
            }
            else if (color == 'b')
            {
                cardontable = 111;
            }
            evaluatePlayer();
            return;
        }
    }
    if (cstatus.haspnum == 1)
    {
        indexofplayedC = compC[cstatus.indexpnum[0]].index;
        printf("Computer played ");
        sayname(cstatus.indexpnum[0], 'c');
        playcard((cstatus.indexpnum[0] + 1), 'c');
        return;
    }
    else if (cstatus.haspact == 1)
    {
        if (compC[cstatus.indexpact[0]].action == 's' || compC[cstatus.indexpact[0]].action == 'r')
        {
            comp.turn = 1;
        }
        indexofplayedC = compC[cstatus.indexpact[0]].index;
        printf("Computer played ");
        sayname(cstatus.indexpact[0], 'c');
        playcard(cstatus.indexpact[0] + 1, 'c');
        return;
    }
    else if (cstatus.haswild)
    {
        indexofplayedC = compC[cstatus.indexwild[0]].index;
        printf("Computer played ");
        sayname(cstatus.indexwild[0], 'c');
        playcard(cstatus.indexwild[0] + 1, 'c');
        char color = findMaxcol(cstatus.gcount, cstatus.ycount, cstatus.rcount, cstatus.bcount);
        if (color == 'g')
        {
            cardontable = 110;
        }
        else if (color == 'y')
        {
            cardontable = 108;
        }
        else if (color == 'r')
        {
            cardontable = 109;
        }
        else if (color == 'b')
        {
            cardontable = 111;
        }
        return;
    }
    else if (cstatus.hasd2 == 1)
    {
        for (int i = 0; i < cstatus.d2count; i++)
        {
            if (compC[cstatus.indexd2[i]].colour == card[cardontable].colour)
            {
                draw += 2;
                indexofplayedC = compC[cstatus.indexd2[i]].index;
                printf("Computer played ");
                sayname(cstatus.indexd2[i], 'c');
                playcard(cstatus.indexd2[i] + 1, 'c');
                evaluatePlayer();
                return;
            }
        }
    }
    
    if (cstatus.haspact == 0 && cstatus.haspnum == 0)
    {
        if (ccardn == 1 || cstatus.d4count > 1)
        {
            if (cstatus.hasd4 == 1)
            {
                indexofplayedC = compC[cstatus.indexd4[0]].index;
                draw += 4;
                printf("Computer played Draw 4\n");
                playcard(cstatus.indexd4[0], 'c');
                char color = findMaxcol(cstatus.gcount, cstatus.ycount, cstatus.rcount, cstatus.bcount);
                if (color == 'g')
                {
                    cardontable = 110;
                }
                else if (color == 'y')
                {
                    cardontable = 108;
                }
                else if (color == 'r')
                {
                    cardontable = 109;
                }
                else if (color == 'b')
                {
                    cardontable = 111;
                }
                evaluatePlayer();
                return;
            }
            else if (cstatus.hasd4 == 0)
            {
                drawcard(1, 'c');
                printf("Computer drew 1 card\n");
                indexofplayedC = -1;
                return;
            }
        }
        else
        {
            drawcard(1, 'c');
            printf("Computer drew 1 card\n");
            return;
        }
    }
}
void evaluatePlayer()
{
    if (comp.turn == 1 || ccardn == 0 || pcardn == 0)
    {
        if (ccardn == 0)
        {
            return;
        }
        else if (pcardn == 0)
        {
            return;
        }
        printf("Your turn was skipped\n");
        return;
    }
    struct status pstatus;
    player.turn = 1;
    pstatus.hasd4 = 0;
    pstatus.d4count = 0;
    pstatus.d2count = 0;
    pstatus.hasd2 = 0;
    for (int i = 0; i < pcardn; i++)
    {

        if (playerC[i].action == '4')
        {
            pstatus.indexd4[pstatus.d4count] = i;
            pstatus.hasd4 = 1;
            pstatus.d4count++;
        }
        else if (playerC[i].action == '2')
        {
            pstatus.indexd2[pstatus.d2count] = i;
            pstatus.hasd2 = 1;
            pstatus.d2count++;
        }
    }
    if (card[indexofplayedC].action == '4')
    {
        int inpdrw;
        if (pstatus.hasd4 == 1)
        {
            while (1)
            {
                printf("Play draw 4 or draw %d cards\n", draw);
                printf("1.Play draw 4\t2.Draw %d cards\n", draw);
                scanf("%d", &inpdrw);
                getchar();

                if (inpdrw == 1)
                {
                    indexofplayed = playerC[pstatus.indexd4[0]].index;
                    playcard(pstatus.indexd4[0] + 1, 'p');
                    player.turn = 0;
                    return;
                }
                else if (inpdrw == 2)
                {
                    drawcard(draw, 'p');
                    player.turn = 0;
                    draw = 0;
                    printf("You drew %d cards\n", draw);
                    return;
                }
                else
                {
                    printf("Invalid input\n");
                    continue;
                }
            }
        }
        else if (pstatus.hasd4 == 0)
        {
            drawcard(draw, 'p');
            printf("You had to draw %d cards\n", draw);
            player.turn = 0;
            draw = 0;
            return;
        }
    }
    if (card[indexofplayedC].action == '2')
    {
        int inpdrw;
        if (pstatus.hasd2 == 1)
        {
            while (1)
            {
                printf("Play draw 2 or draw %d cards\n", draw);
                printf("1.Play draw 2\t2.Draw %d cards\n", draw);
                scanf("%d", &inpdrw);
                getchar();

                if (inpdrw == 1)
                {
                    indexofplayed = playerC[pstatus.indexd2[0]].index;
                    playcard(pstatus.indexd2[0] + 1, 'p');
                    player.turn = 0;
                    return;
                }
                else if (inpdrw == 2)
                {
                    drawcard(draw, 'p');
                    player.turn = 0;
                    draw = 0;
                    printf("You drew %d cards\n", draw);
                    return;
                }
                else
                {
                    printf("Invalid input\n");
                    continue;
                }
            }
        }
        else if (pstatus.hasd2 == 0)
        {
            if (pstatus.hasd4 == 1)
            {
                while (1)
                {
                    printf("Play draw 4 or draw %d cards\n", draw);
                    printf("1.Play draw 4\t2.Draw %d cards\n", draw);
                    scanf("%d", &inpdrw);
                    getchar();

                    if (inpdrw == 1)
                    {
                        indexofplayed = playerC[pstatus.indexd4[0]].index;
                        playcard(pstatus.indexd4[0] + 1, 'p');
                        player.turn = 0;
                        return;
                    }
                    else if (inpdrw == 2)
                    {
                        drawcard(draw, 'p');
                        player.turn = 0;
                        draw = 0;
                        printf("You drew %d cards\n", draw);
                        return;
                    }
                    else
                    {
                        printf("Invalid input\n");
                        continue;
                    }
                }
            }
            else
            {
                drawcard(draw, 'p');
                printf("You had to draw %d cards\n", draw);
                player.turn = 0;
                draw = 0;
                return;
            }
        }
    }
    return;
}
char findMaxcol(int green, int yellow, int red, int blue)
{
    char max;
    if (green > yellow && green > red && green > blue)
    {
        max = 'g';
        return max;
    }
    else if (yellow > green && yellow > red && yellow > blue)
    {
        max = 'y';
        return max;
    }
    else if (red > green && red > yellow && red > blue)
    {
        max = 'r';
        return max;
    }
    else if (blue > green && blue > yellow && blue > red)
    {
        max = 'b';
        return max;
    }
    else if (green == yellow && yellow == red && red == blue)
    {
        int randcol = rand() % 4;
        if (randcol == 0)
        {
            max = 'g';
        }
        else if (randcol == 1)
        {
            max = 'y';
        }
        else if (randcol == 2)
        {
            max = 'r';
        }
        else if (randcol == 3)
        {
            max = 'b';
        }
    }
    else if (green == yellow || green == red || green == blue || yellow == red || yellow == blue || red == blue)
    {
        if (green == yellow)
        {
            int randcol = rand() % 2;
            if (randcol == 0)
            {
                max = 'g';
            }
            else
            {
                max = 'y';
            }
        }
        else if (green == red)
        {
            int randcol = rand() % 2;
            if (randcol == 0)
            {
                max = 'g';
            }
            else
            {
                max = 'r';
            }
        }
        else if (green == blue)
        {
            int randcol = rand() % 2;
            if (randcol == 0)
            {
                max = 'g';
            }
            else
            {
                max = 'b';
            }
        }
        else if (yellow == red)
        {
            int randcol = rand() % 2;
            if (randcol == 0)
            {
                max = 'y';
            }
            else
            {
                max = 'r';
            }
        }
        else if (yellow == blue)
        {
            int randcol = rand() % 2;
            if (randcol == 0)
            {
                max = 'y';
            }
            else
            {
                max = 'b';
            }
        }
        else if (red == blue)
        {
            int randcol = rand() % 2;
            if (randcol == 0)
            {
                max = 'r';
            }
            else
            {
                max = 'b';
            }
        }
    }
    return max;
}
