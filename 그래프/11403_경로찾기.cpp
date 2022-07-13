#include <iostream>
#include <vector>
#include <limits.h>
#include <tuple>
using namespace std;
static int N;
static long mdistance[101][101];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++) { // ���� ��� �ʱ�ȭ
        for (int j = 0; j < N; j++) {
            cin >> mdistance[i][j];
        }
    }

    
    for (int k = 0; k < N; k++) { // �÷��̵� ���� �˰��� ����
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (mdistance[i][k] == 1 && mdistance[k][j] == 1) mdistance[i][j] = 1;
            }
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << mdistance[i][j] << " ";
        }
        cout << "\n";
    }
}