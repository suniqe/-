 #include "visitor.h"
using namespace std; 
int main() 
{
    Identity* identity = new Identity("合格");
    Urine* urine = new Urine("合格");
    Health* health = new Health("合格");
    Sporter* Sheep = new Sporter(identity, urine, health);
 
    Detector1* Tiger = new Detector1("Detector1 老虎");
    Detector2* Wolf = new Detector2("Detector2 狼");
 
    cout << "\n1: 老虎检察员正在对羊运动员进行检查" << endl;
    Sheep->Accept(Tiger);
    cout << "\n2: 狼检察员正在对羊运动员进行检查" << endl;
    Sheep->Accept(Wolf);
 
    return 0;
}
