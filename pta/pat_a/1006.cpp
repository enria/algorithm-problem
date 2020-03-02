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
    string minid, mint;
    string maxid, maxt;
    for (int i = 0; i < n; i++) {
        string id, in, out;
        cin >> id >> in >> out;
        if (i == 0) {
            minid=id;mint=in;
            maxid=id;maxt=out;
        }
        if (in.compare(mint) < 0) {
            minid = id;
            mint = in;
        }
        if (out.compare(maxt) > 0) {
            maxid = id;
            maxt = out;
        }
        Record _r;
        _r.id = id;
        _r.in = in;
        _r.out = out;
        records[i] = _r;
    }

    auto comp = [](Record a, Record b) -> bool {
        return a.in.compare(b.in) < 0;
    };
    Record *first = min_element(records, records + n, comp);
    Record *last = max_element(records, records + n, comp);
    if(last->id!=maxid){
        return 1;
    }
    cout << minid << " " << maxid << endl;
}