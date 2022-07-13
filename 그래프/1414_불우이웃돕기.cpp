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

    int N, sum = 0;
    cin >> N;
    priority_queue<Edge, vector<Edge>, greater<Edge>> pq;   // 오름차순 정렬

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
            sum = sum + temp; 	// 총 랜선의 길의 저장
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
        if (find(now.s) != find(now.e))	 // 같은 부모가 아니라면 -> 연결해도 사이클이 생기지 않는다면
        {
            munion(now.s, now.e);
            result = result + now.v;
            useEdge++;
        }
    }
    if (useEdge == N - 1) cout << sum - result << "\n";
    else cout << -1 << "\n";

}

void munion(int a, int b) { 	// union 연산 : 대표 노드끼리 연결하여 줌
    a = find(a);
    b = find(b);
    if (a != b) {
        parent[b] = a;
    }
}
int find(int a) {	 // find 연산 : 대표 노드 리턴
    if (a == parent[a])
        return a;
    else
        return parent[a] = find(parent[a]); 	// 재귀함수의 형태로 구현 -> 경로 압축 부분
}
