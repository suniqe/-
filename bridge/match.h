#ifndef OS_H_
#define OS_H_

#include <iostream>
using namespace std;

class Match
{
	public:
    	virtual string GetMatch() = 0;
};

class Solo : public Match
{
	public:
    	virtual string GetMatch()
    	{
        	return "Solo Match";
    	}
};

class Team : public Match
{
	public:
    	virtual string GetMatch()
    	{
        	return "Team Match";
    	}
};

class Solo400 : public Solo
{
	public:
    	virtual string GetMatch()
    	{
        	return "Solo Match 400m";
    	}
};

class Solo800 : public Solo
{
	public:
    	virtual string GetMatch()
    	{
        	return "Solo Match 800m";
    	}
};

class Team400 : public Team
{
	public:
   		virtual string GetMatch()
    	{
        	return "Team Match 400m";
    	}
};

class Team800 : public Team
{
	public:
    	virtual string GetMatch()
    	{
        	return "Team Match 800m";
    	}
};

#endif
