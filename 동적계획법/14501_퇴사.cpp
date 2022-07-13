#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

static int N;
static vector<int> D, T, P;

int main()
{
    cin >> N;
    D.resize(N + 2);
    T.resize(N + 1);
    P.resize(N + 1);

    for (int i = 1; i <= N; i++)
    {
        cin >> T[i] >> P[i];
    }

    for (int i = N; i > 0; i--) {
        if (i + T[i] > N + 1) {
            D[i] = D[i + 1];
        }
        else {
            D[i] = max(D[i + 1], P[i] + D[i + T[i]]);
        }
    }

    cout << D[1];
}
