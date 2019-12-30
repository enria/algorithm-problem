#include <iostream>
#include <vector>

using namespace std;

class Contact {
   public:
    string name, birth, gender, phone, cell;
};

int main1(int argc, char const* argv[]) {
    Contact c;
    cin >> c.name;
    cin >> c.birth;
    cout << c.birth;
    cout << c.name;
    return 0;
}

int main() {
    int n;
    cin >> n;
    vector<Contact> contacts(n);
    for (int i = 0; i < n; i++) {
        Contact c;
        cin >> c.name;
        cin >> c.birth;
        cin >> c.gender;
        cin >> c.phone;
        cin >> c.cell;
        contacts[i] = c;
    }
    int n2;
    cin >> n2;
    int si[n2];
    for (int i = 0; i < n2; i++) {
        cin >> si[i];
    }
    for (int i = 0; i < n2; i++) {
        if (si[i] < 0 || si[i] >= n) {
            cout << "Not Found" << endl;
        } else {
            Contact c = contacts[si[i]];
            cout << c.name << " " << c.phone << " " << c.cell << " " << c.gender
                 << " " << c.birth << endl;
        }
    }
    return 0;
}