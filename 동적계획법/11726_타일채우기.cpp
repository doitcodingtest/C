#include <iostream>
using namespace std;

static int N;
static long D[1001];
static long mod = 10007;

int main()
{
    cin >> N;
    D[1] = 1;  //길이가 2*1일때 타일 경우의 수
    D[2] = 2;  //길이가 2*2일때 타일 경우의 수
    
    for (int i = 3; i <= N; i++) {
        D[i] = (D[i - 1] + D[i - 2]) % mod;
    }

    cout << D[N];
}
