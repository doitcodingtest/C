#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int count = 0;
    for (int i = N - 1; i >= 0; i--) {
        if (A[i] <= K) {    // ���� ������ ��ġ�� K���� �۰ų� ������ ������ �߰�.
            count += (K / A[i]);
            K = K % A[i];   // K�� ���� ������ ����ϰ� ���� �ݾ����� ������Ʈ ��
        }
    }

    cout << count << "\n";
}
