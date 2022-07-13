#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
static  vector<int> parent;

void unionfunc(int a, int b);
int find(int a);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;
    int dosi[201][201];
    for (int i = 1; i <= N; i++) { 	// ���� ���� ������ ����
        for (int j = 1; j <= N; j++) {
            cin >> dosi[i][j];
        }
    }
    int route[1001];
    for (int i = 1; i <= M; i++) { 	//���� ���� ���� ����
        cin >> route[i];
    }
    parent.resize(N + 1);
    for (int i = 1; i <= N; i++) { 	// ��ǥ ��带 �ڱ� �ڽ����� �ʱ�ȭ
        parent[i] = i;
    }
    for (int i = 1; i <= N; i++) { 	// ������� Ž������ ���ð� ����Ǿ� ������ ���Ͽ� ����
        for (int j = 1; j <= N; j++) {
            if (dosi[i][j] == 1) unionfunc(i, j);
        }
    }

    // ���� ��ȹ ���õ��� �ϳ��� ��ǥ ���÷� ����Ǿ� �ִ��� Ȯ��
    int index = find(route[1]);
    bool connect = true;
    for (int i = 2; i <= M; i++) {
        if (index != find(route[i])) {
            cout << "NO" << "\n";
            connect = false;
            break;
        }
    }
    if (connect) cout << "YES" << "\n";
}
void unionfunc(int a, int b) {	 // union ���� : �ٷ� ������ �ƴ� ��ǥ ��峢�� �����Ͽ� ��
    a = find(a);
    b = find(b);
    if (a != b) {
        parent[b] = a;
    }
}
int find(int a) { 	// find ���� : ��ǥ ��带 ����
    if (a == parent[a])
        return a;
    else
        return parent[a] = find(parent[a]); 	// ����Լ��� ���·� ����
}
