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

    for (int i = 0; i < M; i++) { // ����ġ�� �ִ� ���� ����Ʈ �ʱ�ȭ
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
            // ����� ��� ��忡 ���Ͽ� �˻��ϱ� 
            if (W[u.second][adjNode] != 0) {
                // ����� ��ΰ� K���� �ȵ� ��� �׳� �߰��Ѵ�.
                if (distQueue[adjNode].size() < K) {
                    distQueue[adjNode].push(u.first + W[u.second][adjNode]);
                    pq.push(make_pair(u.first + W[u.second][adjNode], adjNode));
                }
                // ����� ��ΰ� K���̰�, ���� ���� ū ������ �������� �߰��Ѵ�.
                else if (distQueue[adjNode].top() > u.first + W[u.second][adjNode]) {
                    distQueue[adjNode].pop(); // ���� ť���� Max�� �������� ���־����
                    distQueue[adjNode].push(u.first + W[u.second][adjNode]);
                    pq.push(make_pair(u.first + W[u.second][adjNode], adjNode));
                }
            }
        }
    }
    for (int i = 1; i <= N; i++) { // K��° ��� ���
        if (distQueue[i].size() == K) {
           cout << distQueue[i].top() << "\n";
        }
        else {
            cout << -1 << "\n";
        }
    }
}