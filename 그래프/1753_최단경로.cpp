#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

typedef pair<int, int> edge;
static int V, E, K;
static vector<int> mdistance;
static vector<bool> visited;
static vector < vector <edge> > mlist;
static priority_queue<edge, vector<edge>, greater<edge>> q;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> V >> E >> K;

    mdistance.resize(V + 1);
    std::fill(mdistance.begin(), mdistance.end(), INT_MAX);

    visited.resize(V + 1);
    std::fill(visited.begin(), visited.end(), false);
    mlist.resize(V + 1);

    for (int i = 0; i < E; i++) { // 가중치가 있는 인접 리스트 초기화
        int u, v, w;
        cin >> u >> v >> w;
        mlist[u].push_back(make_pair(v, w));
    }

    q.push(make_pair(0, K));
    mdistance[K] = 0;
    while (!q.empty()) {
        edge current = q.top();
        q.pop();
        int c_v = current.second;
        if (visited[c_v]) continue; // 기 방문 노드는 다시 큐에 넣지 않습니다.
        visited[c_v] = true;
        for (int i = 0; i < mlist[c_v].size(); i++) {
            edge tmp = mlist[c_v][i];
            int next = tmp.first;
            int value = tmp.second;
            if (mdistance[next] > mdistance[c_v] + value) { // 최소 거리로 업데이트
                mdistance[next] = value + mdistance[c_v];
                q.push(make_pair(mdistance[next], next));
            }
        }
    }
    for (int i = 1; i <= V; i++) { // 거리 배열 출력
        if (visited[i])
            cout << mdistance[i] << "\n";
        else
            cout << "INF" << "\n";
    }
}