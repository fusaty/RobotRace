#include <stdio.h>
#include "robot_race.h"
//#include <time.h>


#define prekazka '*'
#define volne ''

#define ROBOTa 'a'
#define ROBOTb 'b'
#define ROBOTc 'c'
#define ROBOTd 'd'
#define ROBOTe 'e'


#define vyska 30
#define sirka 25
#define pocet_prekazok 5
#define hraci 4



int pole[vyska][sirka];


 typedef struct
{
    int x;
    int y;
    int preksirka;
    int prekvyska;
} OBSTACLE;

int obX()
{
   int obstX=(rand()% (sirka + 1 - 1) + 1);
   int const x=obstX;
   return (x) ;
}

int obY()
{
   int obstY=(rand()% (vyska + 1 - 1) + 1);
   int const y=obstY;
   return (y) ;
}

void initTrack(){
    CLEAR_SCREEN();

    //srand( time( 0 ) );
    int obstX=obX();
    int obstY=obY();

    OBSTACLE obstacles[pocet_prekazok];
    obstacles[0].x=sirka/4;
    obstacles[0].y=vyska/4;
    obstacles[0].preksirka=6;
    obstacles[0].prekvyska=3;

    obstacles[1].x=sirka/3;
    obstacles[1].y=vyska/3;
    obstacles[1].preksirka=6;
    obstacles[1].prekvyska=3;

    obstacles[2].x=6;
    obstacles[2].y=17;
    obstacles[2].preksirka=sirka/3;
    obstacles[2].prekvyska=3;

    obstacles[3].x=20;
    obstacles[3].y=13;
    obstacles[3].preksirka=7;
    obstacles[3].prekvyska=vyska/3;

    obstacles[4].x=2;
    obstacles[4].y=20;
    obstacles[4].preksirka=6;
    obstacles[4].prekvyska=8;

   for (int r=0; r<vyska;r++)
   {
        printf("          ");

       for(int c=0;c<sirka;c++)
       {




            if (c==0)
            {
                printf("|");
            }


         printf("%c",(pole[r][c]));


            if (c==sirka-1)
            {
                printf("|");
            }





       }
       printf("\n");
   }



int r=0;

while(r<pocet_prekazok)
{
int p=0;
int k=0;

while (p<obstacles[r].preksirka+1)
{
pole[obstacles[r].y][obstacles[r].x+p]=prekazka;
pole[obstacles[r].y+obstacles[r].prekvyska][obstacles[r].x+p]=prekazka;
p++;
}

while (k<obstacles[r].prekvyska+1)
{
pole[obstacles[r].y+k][obstacles[r].x]=prekazka;
pole[obstacles[r].y+k][obstacles[r].x+obstacles[r].preksirka]=prekazka;
k++;
}

r++;
}
}





void initRobots()
{

if (hraci==1)
{


    for(int i=1; i<vyska;i++)
    {
        for(int j =1; j<sirka;j++)
        {
            pole[0][sirka/2-7]=ROBOTa;
            //pole[0][sirka/2]=ROBOTb;
            //pole[0][sirka/2+7]=ROBOTc;
        }
    }

}





if (hraci==2)
{


    for(int i=1; i<vyska;i++)
    {
        for(int j =1; j<sirka;j++)
        {
            pole[0][sirka/2-7]=ROBOTa;
            pole[0][sirka/2]=ROBOTb;
            //pole[0][sirka/2+7]=ROBOTc;
        }
    }

}



if (hraci==3)
{


    for(int i=1; i<vyska;i++)
    {
        for(int j =1; j<sirka;j++)
        {
            pole[0][sirka/2-7]=ROBOTa;
            pole[0][sirka/2]=ROBOTb;
            pole[0][sirka/2+7]=ROBOTc;
        }
    }

}



if (hraci==4)
{


    for(int i=1; i<vyska;i++)
    {
        for(int j =1; j<sirka;j++)
        {
            pole[0][2]=ROBOTa;
            pole[0][8]=ROBOTb;
            pole[0][12]=ROBOTc;
            pole[0][16]=ROBOTd;
        }
    }

}

if (hraci==5)
{


    for(int i=1; i<vyska;i++)
    {
        for(int j =1; j<sirka;j++)
        {
            pole[0][2]=ROBOTa;
            pole[0][8]=ROBOTb;
            pole[0][12]=ROBOTc;
            pole[0][16]=ROBOTd;
            pole[0][22]=ROBOTe;
        }
    }

}
}



int rychlost()
{
    int rychlost;
    printf("Rychlost robotov: ");
    scanf("%i",&rychlost);
    return(rychlost);
}



void updateRobotPosition()
{
    int skok=1;

    for(int j=0; j<sirka;j++)
    {
        for(int i =0; i<vyska;i++)
        {
            // prvy robot
            if(pole[i][j]==ROBOTa && pole[i+skok][j]!=prekazka)
            {
                pole[i+skok][j]=ROBOTa;
                pole[i][j]='.';

                break;
            }
            else if(pole[i][j]==ROBOTa && pole[i+skok][j]==prekazka)
            {
                pole[i][j-skok]=ROBOTa;
                pole[i][j]='.';

                break;
            }
            // druhy robot
            if(pole[i][j]==ROBOTb && pole[i+1][j]!=prekazka)
            {
                pole[i+1][j]=ROBOTb;
                pole[i][j]='.';

                break;
            }
            else if(pole[i][j]==ROBOTb && pole[i+skok][j]==prekazka)
            {
                pole[i][j+skok]=ROBOTb;
                pole[i][j]='.';

                break;
            }
            // treti robot
            if(pole[i][j]==ROBOTc && pole[i+skok][j]!=prekazka)
            {
                pole[i+skok][j]=ROBOTc;
                pole[i][j]='.';

                break;
            }
            else if(pole[i][j]==ROBOTc && pole[i+skok][j]==prekazka)
            {
                pole[i][j-skok]=ROBOTc;
                pole[i][j]='.';

                break;
            }


            // stvrty robot
            if(pole[i][j]==ROBOTd && pole[i+skok][j]!=prekazka)
            {
                pole[i+skok][j]=ROBOTd;
                pole[i][j]='.';

                break;
            }
            else if(pole[i][j]==ROBOTd && pole[i+skok][j]==prekazka)
            {
                pole[i][j+skok]=ROBOTd;
                pole[i][j]='.';

                break;
            }

            // piaty robot
            if(pole[i][j]==ROBOTe && pole[i+skok][j]!=prekazka)
            {
                pole[i+skok][j]=ROBOTe;
                pole[i][j]='.';

                break;
            }
            else if(pole[i][j]==ROBOTe && pole[i+skok][j]==prekazka)
            {
                pole[i][j+skok]=ROBOTe;
                pole[i][j]='.';

                break;
            }

        }
    }
}


