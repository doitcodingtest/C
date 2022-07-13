#include <iostream>
#include <queue>
using namespace std;

void munion(int a, int b);
int find(int a);

static vector<int> parent;
typedef struct Edge 	// 에지정보 struct 생성, 가중치 값 기준 오름차순 정렬로 설정
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

    int N, M;
    cin >> N >> M;
    priority_queue<Edge, vector<Edge>, greater<Edge>> pq;   // 오름차순 정렬
    parent.resize(N + 1);
    for (int i = 0; i <= N; i++) {
        parent[i] = i;
    }
    for (int i = 0; i < M; i++) {
        int s, e, v;
        cin >> s >> e >> v;
        pq.push(Edge{ s, e, v });
    }
    int useEdge = 0;
    int result = 0;
    while (useEdge < N - 1) {
        Edge now = pq.top();
        pq.pop();
        if (find(now.s) != find(now.e)) // 같은 부모가 아니라면 -> 연결해도 사이클이 생기지 않는다면
        {
            munion(now.s, now.e);
            result = result + now.v;
            useEdge++;
        }
    }
    cout << result;

}

void munion(int a, int b) { 	// union 연산 : 대표 노드끼리 연결하여 줌
    a = find(a);
    b = find(b);
    if (a != b) {
        parent[b] = a;
    }
}
int find(int a) { 	// find 연산
    if (a == parent[a])
        return a;
    else
        return parent[a] = find(parent[a]); 	// 재귀함수의 형태로 구현 -> 경로 압축 부분
}
