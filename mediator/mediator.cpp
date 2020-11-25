#include <iostream>
#include <string>
#include "mediator.h"
using namespace std;

void SwimTeam::Send(string message)
{
    priTerminal->Sent(message, this);
}

void BikeTeam::Send(string message)
{
    priTerminal->Sent(message, this);
}

void RunTeam::Send(string message)
{
    priTerminal->Sent(message, this);
}

int main()
{
    Terminal *terminal = new TriathlonTerminal();

    Team *pSwimTeam = new SwimTeam(terminal);
    Team *pBikeTeam = new BikeTeam(terminal);
    Team *pRunTeam = new RunTeam(terminal);

    TriathlonTerminal *pTriathlonTerminal = dynamic_cast<TriathlonTerminal *>(terminal);
    pTriathlonTerminal->SetSwimTeam(pSwimTeam);
    pTriathlonTerminal->SetBikeTeam(pBikeTeam);
    pTriathlonTerminal->SetRunTeam(pRunTeam);

    string message= "Swim match is over.";
    pSwimTeam->Send(message);
    message = "Bike match is over.";
    pBikeTeam->Send(message);

    return 0;
}
