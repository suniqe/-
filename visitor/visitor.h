#ifndef VISITOR_H
#define VISITOR_H
 
#include <iostream>
#include <string>
#include <vector>
using namespace std;
 
class Element;
class Identity;
class Urine;
class Health;
 
class Visitor 
{
public:
    Visitor(string name) 
	{
        visitorName = name;
    }
    virtual void visitIdentity( Identity* identity ) {};
    virtual void visitUrine( Urine* urine ) {};
    virtual void visitHealth( Health* health ) {};
 
 
    string getName() 
	{
        return this->visitorName;
    };
private:
    string visitorName;
};
 
 
class Element 
{
public:
    Element( string name ) 
	{
        eleName = name;
    }
    virtual void accept( Visitor* visitor ) {};
 
    virtual string getName() 
	{
        return this->eleName;
    }
private:
    string eleName;
};
 
/*----------- Elements -------------*/
 
class Identity : public Element 
{
public:
    Identity(string name) : Element(name) {}
 
    void accept(Visitor* visitor) 
	{
        visitor->visitIdentity(this);
    }
};
 
class Urine : public Element 
{
public:
    Urine(string name) : Element(name) {}
 
    void accept(Visitor* visitor) 
	{
        visitor->visitUrine(this);
    }
};
 
class Health : public Element {
public:
    Health(string name) : Element(name) {}
      
    void accept(Visitor* visitor) 
	{
        visitor->visitHealth(this);
    }
};
 
/*----------- ConcreteVisitor -------------*/
 
class Detector1 : public Visitor 
{
public:
    Detector1(string name) : Visitor(name) {}
 
    // checking identity
    void visitIdentity( Identity* identity ) 
	{
        cout << Visitor::getName() << " 正在检查羊的身份——身份证件，" << identity->getName() << endl;
    }
 
    // checking urine
    void visitUrine( Urine* urine ) 
	{
        cout << Visitor::getName() << " 正在检查羊的尿液样本——化验A，" << urine->getName() << endl;
    }
 
    // checking health
    void visitHealth( Health* health ) 
	{
        cout << Visitor::getName() << " 正在检查羊的健康状况——体温测量，" << health->getName() << endl;
    }
 
};
 
class Detector2 : public Visitor 
{
public:
    Detector2(string name) : Visitor(name) {}
    virtual void visitIdentity( Identity* identity ) 
	{
        cout << Visitor::getName() << " 正在检查羊的身份——参赛证明，" << identity->getName() << endl;
    }
 
    // checking urine
    void visitUrine( Urine* urine ) 
	{
        cout << Visitor::getName() << " 正在检查羊的尿液样本——化验B，" << urine->getName() << endl;
    }
 
    // checking health
    void visitHealth( Health* health ) 
	{
        cout << Visitor::getName() << " 正在检查羊的健康状况——核酸检测，" << health->getName() << endl;
    }
};
 
class Sporter 
{
public:
    Sporter(Identity* identity,
            Urine* urine,
            Health* health) 
			{
        		elementList.push_back(identity);
        		elementList.push_back(urine);
        		elementList.push_back(health);
    		};
    void Accept(Visitor* visitor) 
	{
        for(vector<Element*>::iterator i = elementList.begin(); i != elementList.end(); i++ )
        {
            (*i)->accept(visitor);
        }
    }; 
private:
    vector<Element*> elementList;
};
 
 
#endif
