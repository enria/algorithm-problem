#include <iostream>

using namespace std;

struct Student {
    int gender = -1;
    string id, name;
} grades[101];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        char id[11], name[11], gender[2];
        int grade;
        scanf("%s %s %s %d", name, gender, id, &grade);
        grades[grade].id = id, grades[grade].name = name;
        grades[grade].gender = gender[0] == 'M' ? 1 : 0;
    }

    int mindex = -1, findex = -1;

    for (int i = 0; i <= 100; i++) {
        if (grades[i].gender == 1) {
            mindex = i;
            break;
        }
    }
    for (int i = 100; i >= 0; i--) {
        if (grades[i].gender == 0) {
            findex = i;
            break;
        }
    }
    if (findex == -1) {
        printf("Absent\n");
    } else {
        printf("%s %s\n", grades[findex].name.c_str(),
               grades[findex].id.c_str());
    }
    
    if (mindex == -1) {
        printf("Absent\n");
    } else {
        printf("%s %s\n", grades[mindex].name.c_str(),
               grades[mindex].id.c_str());
    }

    if (mindex == -1 || findex == -1) {
        printf("NA\n");
    } else {
        printf("%d\n", findex - mindex);
    }

    return 0;
}