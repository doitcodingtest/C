#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

static vector < vector <int> > A;
static vector<bool> visited;
void DFS(int v);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;
    A.resize(N + 1);
    visited = vector<bool>(N + 1, false);


    for (int i = 0; i < M; i++) {
        int s, e;
        cin >> s >> e ;
        A[s].push_back(e);
        A[e].push_back(s);
    }

    int count = 0;
    for (int i = 1; i < N + 1; i++) {
        if (!visited[i]) { // �� �湮�� ��尡 ���� ������ �ݺ�
            count++;
            DFS(i);
        }
    }
    cout << count << "\n";
}

void DFS(int v) {
    if (visited[v]) {
        return;
    }
    visited[v] = true;
    for (int i : A[v]) {
        if (visited[i] == false) { // ���� ���� �� �湮���� �ʾҴ� ��常 Ž����
            DFS(i);
        }
    }
}