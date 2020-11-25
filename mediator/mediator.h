#ifndef VISITOR_H
#define VISITOR_H

#include <iostream>
#include <string> 
#define SAFE_DELETE(p) if (p) { delete p; p = NULL; }

using namespace std;

class Terminal;

class Team
{
	public:
     	Team(Terminal *terminal) : priTerminal(terminal){}

     	virtual void Send(string message) = 0;

	protected:
     	Terminal *priTerminal;
};

class SwimTeam : public Team
{
	public:
     	SwimTeam(Terminal *terminal) : Team(terminal){}
     	void Send(string message);
     	void Notify(string message)
     	{
          	cout<<message<<endl;
     	}
};

class BikeTeam : public Team
{
public:
     BikeTeam(Terminal *terminal) : Team(terminal){}

     void Send(string message);

     void Notify(string message)
     {
          cout<<"BikeTeam is handling the message."<<endl;
          cout<<message<<endl;
     }
};

class RunTeam : public Team
{
	public:
     	RunTeam(Terminal *terminal) : Team(terminal){}
     	void Send(string message);
     	void Notify(string message)
     	{
          	cout<<"RunTeam is handling the message."<<endl;
          	cout<<message<<endl;
     	}
};

class Terminal
{
	public:
     	virtual void Sent(string message, Team *pColleague) = 0;
};

class TriathlonTerminal : public Terminal
{
	public:
     	// The mediator forward the message
     	void Sent(string message, Team *pTeam)
     	{
          	SwimTeam *pSwimTeam = dynamic_cast<SwimTeam *>(pTeam);
          	BikeTeam *pBikeTeam = dynamic_cast<BikeTeam *>(pTeam);
          	if (pSwimTeam)
          	{
               	cout<<"The message is from SwimTeam. Now mediator forward it to BikeTeam"<<endl;
               	if (priBikeTeam)
               	{
                    priBikeTeam->Notify(message);
               	}
          	}
          	else if (pBikeTeam)
          	{
                cout<<"The message is from BikeTeam. Now mediator forward it to RunTeam"<<endl;
               	if (priRunTeam)
               	{
                    priRunTeam->Notify(message);
               	}
          	}
     	}

     	void SetSwimTeam(Team *pTeam)
     	{
          	priSwimTeam = dynamic_cast<SwimTeam *>(pTeam);
     	}

     	void SetBikeTeam(Team *pTeam)
     	{
          	priBikeTeam = dynamic_cast<BikeTeam *>(pTeam);
     	}
     
     	void SetRunTeam(Team *pTeam)
     	{
          	priRunTeam = dynamic_cast<RunTeam *>(pTeam);
     	}

	private:
     	// The Terminal knows all the Team
     	SwimTeam *priSwimTeam;
     	BikeTeam *priBikeTeam;
     	RunTeam *priRunTeam;
};

#endif
