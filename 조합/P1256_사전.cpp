#include <iostream>
using namespace std;

static int N, M, K;
static long D[202][202];

int main()
{
    cin >> N >> M >> K;
    for (int i = 0; i <= 200; i++) { // 조합 테이블 초기화
        for (int j = 0; j <= i; j++) {
            if (j == 0 || j == i)
                D[i][j] = 1;
            else {
                D[i][j] = D[i - 1][j - 1] + D[i - 1][j];
                if (D[i][j] > 1000000000) D[i][j] = 1000000001; // K 범위가 넘어가면 범위 최대 값 저장
            }
        }
    }
    if (D[N + M][M] < K) // 주어진 자리수로 만들 수 없는 K번째 수이면
        cout << "-1";
    else {
        while (!(N == 0 && M == 0)) {
            // a를 선택하였을때 남은 문자로 만들 수 있는 모든 경우의 수가 K보다 크면
            if (D[N - 1 + M][M] >= K) {
                cout << "a";
                N--;
            }
            else { // 모든 경우의 수가 K보다 작으면
                cout << "z";
                K = K - D[N - 1 + M][M]; //K값 업데이트
                M--;
            }
        }
    }
}
