#include<stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#include<windows.h>
#include<time.h>

struct Node{
    int data;
    int x;
    int y;
    struct node *link;
}*f,*l,*n;

int score=0,LooseCounter=0;
//max score 100 and loose counter 10 to terminate game


COORD coord={0,0};
void gotoxy(int x,int y)
{
  	coord.X=x;
 	coord.Y=y;
 	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void Characters(int n)
{
    int randNum = 0;
    int x = 0 ;
    if(n==1) //for generating capital letters
    {
        while(1)
        {
            randNum = 65 + (rand() % (int)(90 - 65 + 1)); //formula for ASCII 65-90 to generate A to Z
            x = rand()%70;
            Sleep(700);
            insertNode(randNum,x,0);
            printChar();
    }

    }
    else if(n==2) //for generating small letters
    {
        while(1)
        {
            randNum = 97 + (rand() % (int)(122 - 97 + 1)); //formula for ASCII 97-122 to generate a to z
            x = rand()%70;
            Sleep(700);
            insertNode(randNum,x,0);
            printChar();
        }
    }
    else if(n==3) //for generating numbers
    {
        while(1)
        {
            randNum = 48 + (rand() % (int)(57 - 48 + 1)); //formula for ASCII 48-57 to generate 1-9
            x = rand()%70;
            Sleep(700);
            insertNode(randNum,x,0);
            printChar();
        }
    }
    else if(n==4) //for generating combination of capital and small letters
    {
        while(1)
        {
            randNum=48+(rand()%(int)(122-48+1));
            if((randNum>=65 && randNum<=90)||(randNum>=97 && randNum<=122))
            {
                x = rand()%70;
                Sleep(700);
                insertNode(randNum,x,0);
                printChar();
            }
        }
    }
    else if(n==5) //for generating combination numbers and small letters

    {
        while(1)
    {
        randNum=48+(rand()%(int)(122-48+1));
        if((randNum>=48 && randNum<=57)||(randNum>=97 && randNum<=122))
        {
            x = rand()%70;
            Sleep(700);
            insertNode(randNum,x,0);
            printChar();
        }


    }
    }

    else if(n==6) //for generating combination numbers, small and capital letters
    {
         while(1)
    {
        randNum=48+(rand()%(int)(122-48+1));
        if((randNum>=65 && randNum<=90)||(randNum>=97 && randNum<=122) || (randNum>47 && randNum<58))
        {
            x = rand()%70;
            Sleep(700);
            insertNode(randNum,x,0);
            printChar();
        }
    }
    }
    else if(n==7) //for generating combination numbers, small and capital letters
    {
         while(1)
    {
        randNum=48+(rand()%(int)(122-48+1));
        if((randNum>=65 && randNum<=90)||(randNum>=97 && randNum<=122) || (randNum>47 && randNum<58))
        {
            x = rand()%70;
            Sleep(100);
            insertNode(randNum,x,0);
            printChar();
        }
    }
    }

}
void insertNode(int data,int x,int y){
    char temp;
    if(kbhit())
    {
        temp=getch();
        if(temp==f->data) //comparing with start of linked list
        {
            DeleteNode();
            score++;
            Termination();
        }

    }
    if(f == NULL)
    {
        f = (struct Node*)malloc(sizeof(struct Node));
        f->data = data;
        f->x = x;
        f->y = y;
        f->link = NULL;
        l = f;
     }
     else
    {
       while(l->link!=NULL)
       l=l->link;
       n = (struct Node*)malloc(sizeof(struct Node));
       n->data = data;
       n->x = x;
       n->y = y;
       n->link = NULL;
       l->link = n;
       l = n;
     }

}
void printChar(){
   system("cls");
   l = f;
     while(l->link)
     {
         gotoxy(l->x,l->y++);
              printf("%c",l->data);
            if(l->y<=25) //
            {
                l =  l->link;
            }
     else //If missed then counter incremented
    {   LooseCounter++;
        DeleteNode();
        Termination();
        printChar();
    }
    }
       gotoxy(l->x,l->y++);
       printf("%c\n",l->data);
 gotoxy(1,25);
 printf("____________________________________________________________________________");
 gotoxy(1,27);
 printf("100 score needed to win");
 gotoxy(1,29);
 printf("Score : %d",score);
 gotoxy(60,27);
 printf("Total Chance = 10");
 gotoxy(60,29);
 printf("Loose : %d",LooseCounter);

}

 void DeleteNode(){
    f=f->link; //removing first node and making second first node



 }
 void Termination()
 {
     //Game ends if player has scored 100 or missed 10 characters
     if(LooseCounter==100)
     {
         gotoxy(50,10);
         printf("<--------Game End--------> \nYou Loose!\nYou have missed 10 characters :(");
         printf("");
         exit(0);

     }
    if(score==10)
     {
          gotoxy(50,10);
          printf("<--------Game End-------->\nYou Win!\nYou have scored 100:)");
          printf("");
          exit(0);


     }

 }


void main()
{
    srand(time(0));


    int o;
    printf("\t\t\t<--------Typing Tutor-------->\n");
    printf("\nEnter Any Game Mode From below\n 1. Game mode for Capital Letter \n 2. Game mode for small \n 3. Game mode for digits \n 4. Beginner mode combination of 1 and 2 \n 5. Learner mode combination of 2 and 3 \n 6. Expert mode combination of 1,2 and 3 \n 7.  Expert high level mode combination of 1,2 and 3 \n 8. Exit \n");
    scanf("%d",&o);
    switch(o)
    {
    case 1:
        {
            Characters(1);
            break;
        }
    case 2:
        {
            Characters(2);
            break;
        }
    case 3:
        {
            Characters(3);
            break;
        }
    case 4:
        {
            Characters(4);
        }
    case 5:
        {
            Characters(5);
        }
    case 6:
        {
            Characters(6);
        }
    case 7:
        {
            Characters(7);
        }
    default:
    {
        printf("Select any valid option");
    }

    }
}

