#include <string>
#include <sstream>
using namespace std;

string snow(int n,int length)
{
    if(n==0)
    {
        ostringstream oss;
        oss << "(FD 1/" << length << ") ";
        return oss.str();
    }
    else
    {
        return snow(n-1,length*3)
               +"(LT 60) "+snow(n-1,length*3)+"(RT 120) "+snow(n-1,length*3)
               +"(LT 60) "+snow(n-1,length*3);
    }
}
