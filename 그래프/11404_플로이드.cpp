#include <iostream>
#include <vector>
#include <limits.h>
#include <tuple>
using namespace std;
static int N, M;
static long mdistance[101][101];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for (int i = 1; i <= N; i++) { // ���� ��� �ʱ�ȭ
        for (int j = 1; j <= N; j++) {
            if (i == j)
                mdistance[i][j] = 0;
            else
                mdistance[i][j] = 10000001; // ����� ū���� ����
        }
    }

    for (int i = 0; i < M; i++) {
        int s, e, v;
        cin >> s >> e >> v;
        if (mdistance[s][e] > v) mdistance[s][e] = v;
    }
    for (int k = 1; k <= N; k++) { // �÷��̵� ���� �˰��� ����
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (mdistance[i][j] > mdistance[i][k] + mdistance[k][j])
                    mdistance[i][j] = mdistance[i][k] + mdistance[k][j];
            }
        }
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (mdistance[i][j] == 10000001) cout << "0 ";
            else cout << mdistance[i][j] << " ";
        }
        cout << "\n";
    }
}