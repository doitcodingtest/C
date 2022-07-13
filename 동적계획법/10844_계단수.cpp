#include <iostream>
using namespace std;

static int N;
static long D[101][11];
static long mod = 1000000000;

int main()
{
    cin >> N;

    for (int i = 1; i <= 9; i++) { // 0으로 숫자가 시작 할 수 없으므로 D[0][1]은 0으로 초기화
        D[1][i] = 1;
    }

    for (int i = 2; i <= N; i++) {
        D[i][0] = D[i - 1][1];
        D[i][9] = D[i - 1][8];
        for (int j = 1; j <= 8; j++) {
            D[i][j] = (D[i - 1][j - 1] + D[i - 1][j + 1]) % mod;
        }
    }

    long sum = 0;
    for (int i = 0; i < 10; i++) {
        sum = (sum + D[N][i]) % mod; // 정답 값을 더해 줄 때도 %연산 수행
    }

    cout << sum;
}
