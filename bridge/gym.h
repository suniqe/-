#ifndef GYM_H_
#define GYM_H_

#include "match.h"

#ifndef DELETE_OBJECT
#define DELETE_OBJECT(p) {if(NULL != (p)){delete (p); (p) = NULL;}}
#endif

class Gym
{
	public:
    	virtual void SetMatch() = 0;
};

class SoloGym : public Gym
{
	public:
    	SoloGym(Match* match)
    	{
        	m_pMatch = match;
    	}
    	~SoloGym()
    	{
        	DELETE_OBJECT(m_pMatch);
    	}
    	virtual void SetMatch()
    	{
        	cout << "Set The Match: " << m_pMatch->GetMatch().c_str() << endl;
    	}
	private:
    	Match* m_pMatch;
};

class TeamGym : public Gym
{
	public:
    	TeamGym(Match* match)
    	{
        	m_pMatch = match;
    	}
    	~TeamGym()
    	{
        	DELETE_OBJECT(m_pMatch);
    	}

    	virtual void SetMatch()
    	{
        	cout << "Set The Match: " << m_pMatch->GetMatch().c_str() << endl;
    	}
	private:
    	Match* m_pMatch;
};
#endif
