#include <stdio.h>

using namespace std;

int main() {
    int c, q = 1;
    //TODO 这边的输入，和换行有什么关系？
    while ((c = getchar()) != EOF) {
        if (c == '"') {
            printf("%s", q ? "``" : "''");
            q = !q;
        } else {
            printf("%c", c);
        }
    }
    return 0;
}