#include <iostream>
#include <queue>
using namespace std;

void munion(int a, int b);
int find(int a);

static vector<int> parent;
typedef struct Edge 	// �������� struct ����, ����ġ �� ���� �������� ���ķ� ����
{
    int s, e, v;
    bool operator> (const Edge& temp) const {
        return v > temp.v;
    }
}Edge;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, sum = 0;
    cin >> N;
    priority_queue<Edge, vector<Edge>, greater<Edge>> pq;   // �������� ����

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            char tempc = cin.get();
            if (tempc == '\n') {
                tempc = cin.get();
            }
            int temp = 0;
            if (tempc >= 'a' && tempc <= 'z') {
                temp = tempc - 'a' + 1;
            }
            else if (tempc >= 'A' && tempc <= 'Z') {
                temp = tempc - 'A' + 27;
            }
            sum = sum + temp; 	// �� ������ ���� ����
            if (i != j && temp != 0) {
                pq.push(Edge{ i, j, temp });
            }
        }
    }

    parent.resize(N);
    for (int i = 0; i < N; i++) {
        parent[i] = i;
    }

    int useEdge = 0;
    int result = 0;
    while (!pq.empty()) {
        Edge now = pq.top();
        pq.pop();
        if (find(now.s) != find(now.e))	 // ���� �θ� �ƴ϶�� -> �����ص� ����Ŭ�� ������ �ʴ´ٸ�
        {
            munion(now.s, now.e);
            result = result + now.v;
            useEdge++;
        }
    }
    if (useEdge == N - 1) cout << sum - result << "\n";
    else cout << -1 << "\n";

}

void munion(int a, int b) { 	// union ���� : ��ǥ ��峢�� �����Ͽ� ��
    a = find(a);
    b = find(b);
    if (a != b) {
        parent[b] = a;
    }
}
int find(int a) {	 // find ���� : ��ǥ ��� ����
    if (a == parent[a])
        return a;
    else
        return parent[a] = find(parent[a]); 	// ����Լ��� ���·� ���� -> ��� ���� �κ�
}
