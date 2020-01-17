#include <iostream>

using namespace std;

class Destroy {
  private:
    int a;

  public:
    Destroy(int aa);
    ~Destroy();
};

Destroy::Destroy(int aa) { a = aa; }

Destroy::~Destroy() { cout << "var has been destroyed\n"; }

int main() {
    Destroy c(123);
    return 0;
}