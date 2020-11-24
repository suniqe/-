 #include "visitor.h"
using namespace std; 
int main() 
{
    Identity* identity = new Identity("�ϸ�");
    Urine* urine = new Urine("�ϸ�");
    Health* health = new Health("�ϸ�");
    Sporter* Sheep = new Sporter(identity, urine, health);
 
    Detector1* Tiger = new Detector1("Detector1 �ϻ�");
    Detector2* Wolf = new Detector2("Detector2 ��");
 
    cout << "\n1: �ϻ����Ա���ڶ����˶�Ա���м��" << endl;
    Sheep->Accept(Tiger);
    cout << "\n2: �Ǽ��Ա���ڶ����˶�Ա���м��" << endl;
    Sheep->Accept(Wolf);
 
    return 0;
}
