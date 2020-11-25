#include "visitor.h"
using namespace std; 
int main() 
{
    Identity* identity = new Identity("ºÏ¸ñ");
    Urine* urine = new Urine("ºÏ¸ñ");
    Health* health = new Health("ºÏ¸ñ");
    Sporter* Sheep = new Sporter(identity, urine, health);
 
    Detector1* Tiger = new Detector1("Detector1 ÀÏ»¢");
    Detector2* Wolf = new Detector2("Detector2 ÀÇ");
 
    cout << "\n1: ÀÏ»¢¼ì²ìÔ±ÕýÔÚ¶ÔÑòÔË¶¯Ô±½øÐÐ¼ì²é" << endl;
    Sheep->Accept(Tiger);
    cout << "\n2: ÀÇ¼ì²ìÔ±ÕýÔÚ¶ÔÑòÔË¶¯Ô±½øÐÐ¼ì²é" << endl;
    Sheep->Accept(Wolf);
 
    return 0;
}
