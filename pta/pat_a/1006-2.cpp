#include <algorithm>
#include <iostream>

using namespace std;

struct Record {
    string id;
    string in, out;
};

int main() {
    int n;
    cin >> n;
    Record records[n];
    for (int i = 0; i < n; i++) {
        Record _r;
        cin >> _r.id >> _r.in >> _r.out;
        records[i] = _r;
    }
    auto comp = [](Record a, Record b) -> bool {
        return a.in.compare(b.in) < 0;
    };
    Record *first = min_element(records, records + n, comp);
    Record *last = max_element(records, records + n, comp);
    
    cout << first->id << " " << last->id << endl;
}