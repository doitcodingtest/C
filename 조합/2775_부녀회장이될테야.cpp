#include <iostream>
using namespace std;

static int T, N, K;
static int D[15][15];

int main()
{
    for (int i = 0; i < 15; i++) { //�ʱ�ȭ
        D[i][1] = 1;
        D[0][i] = i;
    }
    for (int i = 1; i < 15; i++) {
        for (int j = 2; j < 15; j++) {
            D[i][j] = D[i][j - 1] + D[i - 1][j];  // ��ȭ��
        }
    }
    cin >> T;
    for (int i = 0; i < T; i++) // D�迭�� ��� ���س��� �� ���� ���
    {
        cin >> K >> N;
        cout << D[K][N] << "\n";
    }
}
