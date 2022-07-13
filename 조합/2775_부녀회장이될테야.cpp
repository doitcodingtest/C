#include <iostream>
using namespace std;

static int T, N, K;
static int D[15][15];

int main()
{
    for (int i = 0; i < 15; i++) { //초기화
        D[i][1] = 1;
        D[0][i] = i;
    }
    for (int i = 1; i < 15; i++) {
        for (int j = 2; j < 15; j++) {
            D[i][j] = D[i][j - 1] + D[i - 1][j];  // 점화식
        }
    }
    cin >> T;
    for (int i = 0; i < T; i++) // D배열을 모두 구해놓은 후 질의 출력
    {
        cin >> K >> N;
        cout << D[K][N] << "\n";
    }
}
