#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long N, K;
    cin >> N >> K;
    long start = 1, end = K;
    long ans = 0;
    // �̺� Ž�� ����
    while (start <= end) {
        long middle = (start + end) / 2;
        long cnt = 0;
        // �߾� ������ ���� ���� �� ������ ���.
        for (int i = 1; i <= N; i++) {
            cnt += min(middle/i, N);  // ���� ���� ī��Ʈ�ϴ� �ٽɷ���
        }
        if (cnt < K) {
            start = middle + 1;
        }
        else {
            ans = middle;  // ���� �ܰ��� �߾� ���� ���� ������ ����
            end = middle - 1;
        }
    }
    cout << ans << "\n";
}