#include <iostream>
using namespace std;

static int N, Q;
static long F[21], S[21];
static bool visited[21] = {false};

int main()
{
    cin >> N >> Q;
    F[0] = 1;
    for (int i = 1; i <= N; i++) { // 팩토리얼 초기화 -> 각 자리수에서 만들수 있는 경우의 수
        F[i] = F[i - 1] * i;
    }
    if (Q == 1) {
        long K;
        cin >> K;
        for (int i = 1; i <= N; i++) {
            for (int j = 1, cnt = 1; j <= N; j++) {
                if (visited[j])
                    continue; // 이미 사용한 숫자는 사용할 수 없음
                if (K <= cnt * F[N - i]) { // 주어진 K에 따라 각 자리에 들어갈 수 있는 수 찾기
                    K -= ((cnt - 1) * F[N - i]);
                    S[i] = j;
                    visited[j] = true;
                    break;
                }
                cnt++;
            }
        }
        for (int i = 1; i <= N; i++) {
            cout << S[i] << " ";
        }
    }
    else {
        long K = 1;
        for (int i = 1; i <= N; i++) {
            cin >> S[i];
            long cnt = 0;
            for (int j = 1; j < S[i]; j++) {
                if (visited[j] == false) {
                    cnt++; // 미사용 숫자 개수만큼 카운트
                }
            }
            K += cnt * F[N - i]; // 자리수 개수에 따라 순서 더해주기
            visited[S[i]] = true;
        }
        cout << K << "\n";
    }
}