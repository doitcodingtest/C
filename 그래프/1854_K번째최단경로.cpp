#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

typedef pair<int, int> Node;
static int N, M, K;
static int W[1001][1001];
static priority_queue<int> distQueue[1001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> K;

    for (int i = 0; i < M; i++) { // 가중치가 있는 인접 리스트 초기화
        int a, b, c;
        cin >> a >> b >> c;
        W[a][b] = c;
    }
    priority_queue<Node, vector<Node>, greater<Node>> pq;
    pq.push(make_pair(0, 1));
    distQueue[1].push(0);

    while (!pq.empty()) {
        Node u = pq.top();
        pq.pop();
        for (int adjNode = 1; adjNode <= N; adjNode++) {
            // 연결된 모든 노드에 대하여 검색하기 
            if (W[u.second][adjNode] != 0) {
                // 저장된 경로가 K개가 안될 경우 그냥 추가한다.
                if (distQueue[adjNode].size() < K) {
                    distQueue[adjNode].push(u.first + W[u.second][adjNode]);
                    pq.push(make_pair(u.first + W[u.second][adjNode], adjNode));
                }
                // 저장된 경로가 K개이고, 현재 가장 큰 값보다 작을때만 추가한다.
                else if (distQueue[adjNode].top() > u.first + W[u.second][adjNode]) {
                    distQueue[adjNode].pop(); // 기존 큐에서 Max값 삭제먼저 해주어야함
                    distQueue[adjNode].push(u.first + W[u.second][adjNode]);
                    pq.push(make_pair(u.first + W[u.second][adjNode], adjNode));
                }
            }
        }
    }
    for (int i = 1; i <= N; i++) { // K번째 경로 출력
        if (distQueue[i].size() == K) {
           cout << distQueue[i].top() << "\n";
        }
        else {
            cout << -1 << "\n";
        }
    }
}