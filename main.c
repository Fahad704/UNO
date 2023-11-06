#include "deck.h"
int initcard = 7;
int main()
{
    srand(time(NULL));
    AddCards();
    while(1){
        int n;
        char play;
        printf("1.Start Game\t");
        printf("2.Edit initial card draw\t");
        printf("3.Quit\t\n");
        printf("Enter: ");
        scanf("%d",&n);
        if(n==3){
            return 0;
        }else if(n==2){
            printf("Enter new initial card draw: ");
            scanf("%d",&initcard);
            if(initcard>10){
                initcard = 7;
                printf("Initial card draw can't be more than 10\n");
                printf("Initial card set to default(7)\n");
            }

        }else if(n<1||n>3){
            printf("Invalid Input\n");
            continue;
        }
        drawcard(initcard,'p');
        drawcard(initcard,'c');
        randomcardont();
        while(game!=0){
        printf("\tYour cards: \n");
        for(int i=0;i<pcardn;i++){
            printf("%d.",i+1);
            sayname(i,'p');
        }
        printf("\tCard on table:\n");
        sayname(cardontable,'I');
        printf("b.Back\t");
        printf("d.Draw\t\n");
        printf("Enter: ");
        scanf(" %c",&play);
        if(play=='d'){
            drawcard(1,'p');
            continue;
        }else if(play=='b'){
            pcardn = 0;
            ccardn = 0;
            break;
        }
        if(pcardn==0||ccardn==0){
            game = 0;
        }
        }
    }
    
    return 0;
   
}