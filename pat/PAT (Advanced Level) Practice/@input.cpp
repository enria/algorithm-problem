#include <iostream>

using namespace std;

int main() {
    #if 0
    {
        //GET int 32位，1个符号位
        //GET 输出long，使用%d，最后结果是输出后32位，应该是使用的小端存储
        long long a;
        cin >> a;
        printf("%d\n", a);
    }
    #endif

    #if 1
    {
        char a[8];
        scanf("%s",a);
        printf("%s\n",a);
    }
    #endif

    return 0;
}