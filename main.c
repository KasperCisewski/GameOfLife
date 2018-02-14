#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define n 22
#define m 62



int main()
{

    char tab[n][m];
    srand(time(0));
    menu(tab);

    return 0;

}
void generateBoard(char tab[n][m])
{
    int i,j;
    for( i=0;i<n;i++)
        for( j=0;j<m;j++)
        tab[i][j]=(char)32;

        for(i=0;i<m;i++)
        {
            tab[0][i]='-';
            tab[21][i]='-';
        }
        for(i=0;i<n;i++)
        {
            tab[i][0]='|';
            tab[i][61]='|';
        }



    setup(tab);
}


void setup(char tab[n][m])
{
    printf("Give the probality to appear a cell between 0 to 100  \n");
    int chance, i,j;
    scanf("%d",&chance);
    for(i=1;i<n-1;i++)
        for(j=1;j<m-1;j++)
    {
        int number=rand()%100;
        if(number<chance)
            tab[i][j]='o';

    }

        draw(tab);
        int counter;
        do
        {
           counter=simulation(tab);
        }while(counter==0);


}

int simulation(char tab[n][m])
{
 printf("\n To continue simulation, press key \n to leave press 0 \n");
 int choice, counter=0;
 char newTab[n][m];
 int i,j;
 int temperature;
 for(i=0;i<n;i++)
    for(j=0;j<m;j++)
 newTab[i][j]=tab[i][j];

 scanf("%d",&choice);
 switch(choice)
 {
 case 0:
     counter++;
    return counter;
    break;
 default:
{
 int i,j;
 for(i=1;i<n-1;i++)
    for(j=1;j<m-1;j++)
    {
    if(tab[i][j]=='o')
    {
        int sum =0;
        sum=count(tab,i,j);
        switch(sum)
        {
       case 2:
        case 3:
            break;
        default:
            newTab[i][j]=(char)32;
            break;
        }
    }
    else
    {
        int sum=0;
        sum=count(tab,i,j);
       if(sum==3)
            newTab[i][j]='o';
    }


    }

    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
        tab[i][j]=newTab[i][j];

    for(i=1;i<n-1;i++)
        for(j=1;j<m-1;j++)
    {
        if(tab[i][j]=='o')
        {

        }
        else
        {
            temperature=rand()%10000;
            if(temperature<1)
                tab[i][j]='o';
        }
    }
    draw(tab);
    return counter;
 break;
}

 }
}


int count(char tab[n][m],int l,int k)
{
    int count=0,i,j;

    for( i=-1;i<2;i++)
        for(j=-1;j<2;j++)
    {
        if(i==0&&j==0)
           {

            }
        else
        {
            if(tab[l+i][k+j]=='o')
            count++;
        }
    }

    return count;

}

void draw(char tab[n][m])
{
    int i,j;
    for( i=0;i<n;i++)
        {
            printf("\n");
            for( j=0;j<m;j++)
            {
                printf("%c",tab[i][j]);
            }
        }
}


void menu(char tab[n][m])
{
    int choice;

    printf("Menu:\n 1.Start\n 0.Exit\n");

    scanf("%d",&choice);

    switch(choice)
    {
        case 1:
            generateBoard(tab);;
            break;
        case 0:
            //exit();
            break;
        default:
            break;

    }
}
