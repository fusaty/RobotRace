#include <stdio.h>
#include "robot_race.h"
#include "robot_race.c"


int skuska()
{
  for(int i =0; i<sirka;i++)
        {

            if (pole[vyska-1][i]==ROBOTa)
            {
                printf("\n\nRobot A vyhral\n\n");
                return 0;
            }
            else if (pole[vyska-1][i]==ROBOTb)
            {
                printf("\n\nRobot B vyhral\n\n");
                return 0;
            }
            else if (pole[vyska-1][i]==ROBOTc)
            {

                printf("\n\nRobot C vyhral\n\n");
                return 0;

            }
            else if (pole[vyska-1][i]==ROBOTd)
            {

                printf("\n\nRobot D vyhral\n\n");
                return 0;

            }
            else if (pole[vyska-1][i]==ROBOTe)
            {

                printf("\n\nRobot E vyhral\n\n");
                return 0;
            }
}

return 1;
}




int main(int argc, char* argv[])
{
    int a=0;


    initRobots();
    initTrack();


        while(skuska()==1)
        {
            updateRobotPosition();
                initTrack();
                SLEEP(200);





        }
        }








