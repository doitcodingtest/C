#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

void DFS(int node);

static vector < vector <int> > A;
static vector<int> check;
static vector<bool> visited;
static bool IsEven;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    for (int t = 0; t < N; t++) {
        int V, E;
        cin >> V >> E;
        A.resize(V + 1);
        visited.resize(V + 1);
        check.resize(V + 1);
        IsEven = true;
        for (int i = 0; i < E; i++) {
            int S, E;
            cin >> S >> E;
            A[S].push_back(E);
            A[E].push_back(S);
        }
        // 주어진 그래프가 하나로 연결되어 있다는 보장이 없으므로 모든 정점에서 수행
        for (int i = 1; i <= V; i++) {
            if (IsEven)
                DFS(i);
            else
                break;
        }
        if (IsEven)
            cout << "YES" << "\n";
        else
            cout << "NO" << "\n";

        for (int i = 0; i <= V; i++) {
            A[i].clear();
            visited[i] = false;
            check[i] = 0;
        }
    }
}


void DFS(int node) { 	// DFS구현
    visited[node] = true;
    for (int i : A[node]) {
        if (!visited[i]) {
            check[i] = (check[node] + 1) % 2; 	// 인접한 정점은 같은 집합이 아니므로 이전 정점과 다른 집합으로 처리
            DFS(i);
        }
        else if (check[node] == check[i]) { 	// 이미 방문한 정점이 현재 내 정점과 같은 집합이면 이분 그래프가 아님
            IsEven = false;
        }
    }
}
