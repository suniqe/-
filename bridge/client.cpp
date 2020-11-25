//client
#include <iostream>

#include "match.h"
#include "gym.h"

using namespace std;

#ifndef DELETE_OBJECT
#define DELETE_OBJECT(p) {if(NULL != (p)){delete (p); (p) = NULL;}}
#endif

int main()
{
    Match* pSolo400 = new Solo400();
    Gym* gymsolo1 = new SoloGym(pSolo400);
    gymsolo1->SetMatch();

    Match* pSolo800 = new Solo800();
    Gym* gymsolo2 = new SoloGym(pSolo800);
    gymsolo2->SetMatch();

    Match* pTeam400 = new Team400();
    Gym* gymteam1 = new TeamGym(pTeam400);
    gymteam1->SetMatch();

    Match* pTeam800 = new Team800();
    Gym* gymteam2 = new TeamGym(pTeam800);
    gymteam2->SetMatch();

    DELETE_OBJECT(gymsolo1);
    DELETE_OBJECT(gymsolo2);
    DELETE_OBJECT(gymteam1);
    DELETE_OBJECT(gymteam2);

    return 0;
}
