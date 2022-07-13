#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

typedef pair<int, int> edge;
static vector < vector <edge> > A;
static vector<bool> visited;
static vector<int> m_distance;
void BFS(int node);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    A.resize(N + 1);

    for (int i = 0; i < N; i++) {
        int S;
        cin >> S;
        while (true)
        {
            int E, V;
            cin >> E;
            if (E == -1)break;
            cin >> V;
            A[S].push_back(edge(E, V));
        }
    }

    m_distance = vector<int>(N + 1, 0);
    visited = vector<bool>(N+1, false);
    BFS(1);
    int Max = 1;
    for (int i = 2; i <= N; i++) {
        if (m_distance[Max] < m_distance[i])
            Max = i;
    }
    fill(m_distance.begin(), m_distance.end(), 0); // 거리 배열 초기화
    fill(visited.begin(), visited.end(), false); // 방문 배열 초기화
    BFS(Max);
    sort(m_distance.begin(), m_distance.end());
    cout << m_distance[N] << "\n";
}


void BFS(int index) {  // BFS구현
    queue<int> myqueue;
    myqueue.push(index);
    visited[index] = true;

    while (!myqueue.empty()) {
        int now_node = myqueue.front();
        myqueue.pop();
        for (edge i : A[now_node]) {
            if (!visited[i.first]) {
                visited[i.first] = true;
                myqueue.push(i.first);
                m_distance[i.first] = m_distance[now_node] + i.second;
            }
        }
    }
}