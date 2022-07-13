#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

static int N;
static  vector <pair<int, int>> M;
static long D[502][502];
int excute(int s, int e);

int main()
{
    cin >> N;
    M.resize(N + 1);
    for (int i = 0; i < N + 1; i++) {
        for (int j = 0; j < N + 1; j++) {
            D[i][j] = -1;
        }
    }

    for (int i = 1; i <= N; i++) {
        int y, x;
        cin >> y >> x;
        M[i] = make_pair(y, x);
    }
    cout << excute(1, N) << "\n";
}

int excute(int s, int e) {
    int result = INT_MAX;
    if (D[s][e] != -1) // �̹� ����� ���� �ִ� �κ��̸� �ٽ� ������� �ʴ´� -> �޸������̼�
        return D[s][e];
    if (s == e) // ��� �� ���� ���� ������ ��
        return 0;
    if (s + 1 == e) // ��� �� ���� ���� ������ ��
        return M[s].first * M[s].second * M[e].second;
    for (int i = s; i < e; i++) // ����� 3�� �̻��� ��� ��������� -> ��ȭ�� ó��
        result = min(result, M[s].first * M[i].second * M[e].second + excute(s, i) + excute(i + 1, e));
    return D[s][e] = result;
}