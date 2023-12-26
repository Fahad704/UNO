#include "deck.h"
int main()
{
    srand(time(NULL));
    AddCards();
    while (1)
    {
        int n;
        char choose[20];
        player.turn = 0;
        game=1;
        printf("1.Start Game\t");
        printf("2.Edit initial card draw\t");
        printf("3.Quit\t\n");
        printf("Enter: ");
        scanf("%d", &n);
        getchar();
        if (n == 3)
        {
            return 0;
        }
        else if (n == 2)
        {
            printf("Enter new initial card draw: ");
            scanf("%d", &initcard);
            getchar();
            if (initcard > 10)
            {
                initcard = 7;
                printf("Initial card draw can't be more than 10\n");
                printf("Initial card draw set to default(7)\n");
            }
            continue;
        }
        else if (n < 1 || n > 3)
        {
            printf("Invalid Input\n");
            continue;
        }
        drawcard(initcard, 'p');
        drawcard(initcard, 'c');
        randomcardont();
        while (game != 0)
        {
            while (comp.turn == 1)
            {
                evaluateComp();
                if (ccardn == 0)
                {
                    printf("\n\nComputer Won!\n\n");
                    break;
                }
            }
            int num = -222;
            player.turn = 1;
            printf("\tYour cards: \n");
            for (int i = 0; i < pcardn; i++)
            {
                printf("%d.", i + 1);
                sayname(i, 'p');
            }
            printf("\tComputer's cards: \n");
            for (int i = 0; i < ccardn; i++)
            {
                printf("%d.", i + 1);
                sayname(i, 'c');
            }
            printf("\tCard on table:\n");
            sayname(cardontable, 'I');
            printf("b.Back\t");
            printf("d.Draw\t\n");
            printf("Computer Has %d Cards\n", ccardn);
            printf("Enter: ");
            fgets(choose, sizeof(choose), stdin);
            choose[strcspn(choose, "\n")] = '\0';
            sscanf(choose, "%d", &num);
            if (strcmp(choose, "d") == 0)
            {
                player.turn = 0;
                drawcard(1, 'p');
                printf("You drew a card\n");
                evaluateComp();
            }
            else if (strcmp(choose, "b") == 0)
            {
                pcardn = 0;
                ccardn = 0;
                break;
            }
            else if (num != -222)
            {
                if (num >= 1 && num <= pcardn)
                {
                    playcard(num, 'p');
                    evaluateComp();
                }
                else
                {
                    printf("Invalid input\n");
                }
            }
            else
            {
                printf("Invalid input\n");
            }

            if (pcardn == 0 || ccardn == 0)
            {
                game = 0;
                if (pcardn == 0)
                {
                    printf("\n\nYou won!\n\n");
                    game = 0;
                }
                else
                {
                    printf("\n\nComputer won!\n\n");
                    game = 0;
                }
            }
        }
    }

    return 0;
}
