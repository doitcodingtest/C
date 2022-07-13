#include <iostream>
using namespace std;

static int N, M, K;
static long D[202][202];

int main()
{
    cin >> N >> M >> K;
    for (int i = 0; i <= 200; i++) { // ���� ���̺� �ʱ�ȭ
        for (int j = 0; j <= i; j++) {
            if (j == 0 || j == i)
                D[i][j] = 1;
            else {
                D[i][j] = D[i - 1][j - 1] + D[i - 1][j];
                if (D[i][j] > 1000000000) D[i][j] = 1000000001; // K ������ �Ѿ�� ���� �ִ� �� ����
            }
        }
    }
    if (D[N + M][M] < K) // �־��� �ڸ����� ���� �� ���� K��° ���̸�
        cout << "-1";
    else {
        while (!(N == 0 && M == 0)) {
            // a�� �����Ͽ����� ���� ���ڷ� ���� �� �ִ� ��� ����� ���� K���� ũ��
            if (D[N - 1 + M][M] >= K) {
                cout << "a";
                N--;
            }
            else { // ��� ����� ���� K���� ������
                cout << "z";
                K = K - D[N - 1 + M][M]; //K�� ������Ʈ
                M--;
            }
        }
    }
}