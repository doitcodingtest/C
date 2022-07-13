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
    for (int i = 1; i <= N; i++) { 	// 도시 연결 데이터 저장
        for (int j = 1; j <= N; j++) {
            cin >> dosi[i][j];
        }
    }
    int route[1001];
    for (int i = 1; i <= M; i++) { 	//여행 도시 정보 저장
        cin >> route[i];
    }
    parent.resize(N + 1);
    for (int i = 1; i <= N; i++) { 	// 대표 노드를 자기 자신으로 초기화
        parent[i] = i;
    }
    for (int i = 1; i <= N; i++) { 	// 인접행렬 탐색에서 도시가 연결되어 있으면 유니온 실행
        for (int j = 1; j <= N; j++) {
            if (dosi[i][j] == 1) unionfunc(i, j);
        }
    }

    // 여행 계획 도시들이 하나의 대표 도시로 연결되어 있는지 확인
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
void unionfunc(int a, int b) {	 // union 연산 : 바로 연결이 아닌 대표 노드끼리 연결하여 줌
    a = find(a);
    b = find(b);
    if (a != b) {
        parent[b] = a;
    }
}
int find(int a) { 	// find 연산 : 대표 노드를 리턴
    if (a == parent[a])
        return a;
    else
        return parent[a] = find(parent[a]); 	// 재귀함수의 형태로 구현
}
