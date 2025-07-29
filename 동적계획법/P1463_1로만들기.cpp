#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

static int N;
static vector<int> D;

int main()
{
    cin >> N;
    D.resize(N + 1);

    D[1] = 0;
    for (int i = 2; i <= N; i++) {
        D[i] = D[i - 1] + 1;
        if (i % 2 == 0)D[i] = min(D[i], D[i / 2] + 1);
        if (i % 3 == 0)D[i] = min(D[i], D[i / 3] + 1);
    }
    cout << D[N];
}
