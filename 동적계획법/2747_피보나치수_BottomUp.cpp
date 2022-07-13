#include <iostream>
#include <vector>
using namespace std;

static int N;
static vector<int> D;

int main()
{
    cin >> N;
    D.resize(N + 1);

    for (int i = 0; i <= N; i++) {
        D[i] = -1;
    }
    D[0] = 0;
    D[1] = 1;
    for (int i = 2; i <= N; i++) {
        D[i] = D[i - 1] + D[i - 2];
    }

    cout << D[N];
}
