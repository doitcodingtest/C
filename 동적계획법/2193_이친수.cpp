#include <iostream>
using namespace std;

static int N;
static long D[91][2];

int main()
{
    cin >> N;
 
    D[1][1] = 1;
    D[1][0] = 0;
    for (int i = 2; i <= N; i++) {
        D[i][0] = D[i - 1][1] + D[i - 1][0];
        D[i][1] = D[i - 1][0];
    }
    cout << D[N][0] + D[N][1];
}
