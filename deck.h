#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
int cardontable;
int game=1;
int randomC;
int pcardn = 0;
int ccardn = 0;
struct cards
{
    char colour;
    int number;
    char action;
    int indeck;
    int isp4;
};
struct cards card[108];
struct cards playerC[54];
struct cards compC[54];
void AddCards()
{

    for (int i = 0; i < 25; i++)
    {
        card[i].isp4 = 0;
        card[i].indeck = 1;
        card[0].number = 0;
        card[0].action = 'n';
        card[i].colour = 'y';
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
        card[i].colour = 'N';
        if (i >= 104 && i <= 107)
        {
            card[i].action = 'w';
            card[i].isp4 = 0;
        }
    }
}
void drawcard(int b,char a)
{

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
            playerC[pcardn].number = card[randomC].number;
            playerC[pcardn].colour = card[randomC].colour;
            playerC[pcardn].isp4 = card[randomC].isp4;
            playerC[pcardn].action = card[randomC].action;

            pcardn++;
        }
        
        if (a == 'c')
        {
            compC[ccardn].number = card[randomC].number;
            compC[ccardn].colour = card[randomC].colour;
            compC[ccardn].isp4 = card[randomC].isp4;
            compC[ccardn].action = card[randomC].action;

            ccardn++;
        }
       
    }
}
void sayname(int a,char b){//a =  index of card,b=card of
if(b=='I'){
    char action[20];
    if(card[a].action=='s'){
        strcpy(action,"Skip");
    }
    else if(card[a].action=='r'){
        strcpy(action,"Reverse");
    }else if(card[a].action=='2'){
        strcpy(action,"Draw 2");
    }else if(card[a].action=='4'){
        strcpy(action,"Draw 4");
    }else if(card[a].action=='w'){
        strcpy(action,"Wild");
    }
    if(card[a].number!=-1){
    if(card[a].colour=='g'){
    printf("\033[1;32mNumber %d\n\033[0m",card[a].number);
    }
    else if(card[a].colour=='r'){
    printf("\033[1;31mNumber %d\n\033[0m",card[a].number);
    }
    else if(card[a].colour=='y'){
    printf("\033[1;33mNumber %d\n\033[0m",card[a].number);
    }
    else if(card[a].colour=='b'){
    printf("\033[1;34mNumber %d\n\033[0m",card[a].number);
    }
    }else if(card[a].action!='n'){
        if(card[a].colour=='g'){
    printf("\033[1;32m%s\n\033[0m",action);
    }
    else if(card[a].colour=='r'){
    printf("\033[1;31m%s\n\033[0m",action);
    }
    else if(card[a].colour=='y'){
    printf("\033[1;33m%s\n\033[0m",action);
    }
    else if(card[a].colour=='b'){
    printf("\033[1;34m%s\n\033[0m",action);
    }else{
        printf("\x1b[1;90m%s\n\x1b[0m",action);
    }
    }
}else if(b=='p'){
    char action[20];
    if(playerC[a].action=='s'){
        strcpy(action,"Skip");
    }
    else if(playerC[a].action=='r'){
        strcpy(action,"Reverse");
    }else if(playerC[a].action=='2'){
        strcpy(action,"Draw 2");
    }else if(playerC[a].action=='4'){
        strcpy(action,"Draw 4");
    }else if(playerC[a].action=='w'){
        strcpy(action,"Wild");
    }
    if(playerC[a].number!=-1){
    if(playerC[a].colour=='g'){
    printf("\033[1;32mNumber %d\n\033[0m",playerC[a].number);
    }
    else if(playerC[a].colour=='r'){
    printf("\033[1;31mNumber %d\n\033[0m",playerC[a].number);
    }
    else if(playerC[a].colour=='y'){
    printf("\033[1;33mNumber %d\n\033[0m",playerC[a].number);
    }
    else if(playerC[a].colour=='b'){
    printf("\033[1;34mNumber %d\n\033[0m",playerC[a].number);
    }
    }else if(playerC[a].action!='n'){
        if(playerC[a].colour=='g'){
    printf("\033[1;32m%s\n\033[0m",action);
    }
    else if(playerC[a].colour=='r'){
    printf("\033[1;31m%s\n\033[0m",action);
    }
    else if(playerC[a].colour=='y'){
    printf("\033[1;33m%s\n\033[0m",action);
    }
    else if(playerC[a].colour=='b'){
    printf("\033[1;34m%s\n\033[0m",action);
    }else{
        printf("\x1b[1;90m%s\n\x1b[0m",action);
    }
    }
}
     
}
void randomcardont(){
    while(1){
    int a = rand() % 108;
    if(card[a].number!=-1){
        cardontable = a;
        card[cardontable].indeck = 0;
        break;
    }
    }
}
// void putcard(int a,char b){

// }