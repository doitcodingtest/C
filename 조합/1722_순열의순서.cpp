#include <iostream>
using namespace std;

static int N, Q;
static long F[21], S[21];
static bool visited[21] = {false};

int main()
{
    cin >> N >> Q;
    F[0] = 1;
    for (int i = 1; i <= N; i++) { // ���丮�� �ʱ�ȭ -> �� �ڸ������� ����� �ִ� ����� ��
        F[i] = F[i - 1] * i;
    }
    if (Q == 1) {
        long K;
        cin >> K;
        for (int i = 1; i <= N; i++) {
            for (int j = 1, cnt = 1; j <= N; j++) {
                if (visited[j])
                    continue; // �̹� ����� ���ڴ� ����� �� ����
                if (K <= cnt * F[N - i]) { // �־��� K�� ���� �� �ڸ��� �� �� �ִ� �� ã��
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
                    cnt++; // �̻�� ���� ������ŭ ī��Ʈ
                }
            }
            K += cnt * F[N - i]; // �ڸ��� ������ ���� ���� �����ֱ�
            visited[S[i]] = true;
        }
        cout << K << "\n";
    }
}