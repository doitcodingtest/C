#include <iostream>
#include <queue>
using namespace std;

void munion(int a, int b);
int find(int a);
void BFS(int i, int j);

static int dr[] = { -1, 0, 1, 0 };
static int dc[] = { 0, 1, 0, -1 };
static int map[101][101];
static bool visited[101][101] = { false, };
static vector<int> parent;
static int N, M, sNum;
static vector < vector <pair<int, int>> > sumlist;
static vector <pair<int, int>>  mlist;

typedef struct Edge 	// 에지정보 struct 생성, 가중치 값 기준 오름차순 정렬로 설정
{
    int s, e, v;
    bool operator> (const Edge& temp) const {
        return v > temp.v;
    }
}Edge;

static priority_queue<Edge, vector<Edge>, greater<Edge>> pq;   // 오름차순 정렬

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j]; 	// 맵 정보 저장
        }
    }
    sNum = 1;

    for (int i = 0; i < N; i++) { 	// 각 자리에서 BFS 탐색을 이용하여 섬들을 분리하여 줍니다.
        for (int j = 0; j < M; j++) {
            if (map[i][j] != 0 && visited[i][j] != true) {
                BFS(i, j);
                sNum++;
                sumlist.push_back(mlist);
            }
        }
    }

    for (int i = 0; i < sumlist.size(); i++) {	 // 섬의 각 지점에서 만들 수 있는 모든 간선을 저장
        vector<pair<int, int>> now = sumlist[i];
        for (int j = 0; j < now.size(); j++) {
            int r = now[j].first;
            int c = now[j].second;
            int now_S = map[r][c];
            for (int d = 0; d < 4; d++) { 	// 4방향 검색
                int tempR = dr[d];
                int tempC = dc[d];
                int blenght = 0;
                while (r + tempR >= 0 && r + tempR < N && c + tempC >= 0 && c + tempC < M) {
                    if (map[r + tempR][c + tempC] == now_S) 	// 같은 섬이면 간선을 만들 수 없음
                        break;
                    else if (map[r + tempR][c + tempC] != 0) { 	//같은 섬이 아니고 바다가 아니면 
                        if (blenght > 1) 	// 다른 섬 -> 길이가 1이상일때 간선으로 더해줍니다.
                            pq.push(Edge{ now_S, map[r + tempR][c + tempC], blenght });
                        break;
                    }
                    else 	//바다이면 다리의 길이를 연장하여 줍니다.
                        blenght++;
                    if (tempR < 0)tempR--;
                    else if (tempR > 0)tempR++;
                    else if (tempC < 0)tempC--;
                    else if (tempC > 0)tempC++;
                }
            }
        }
    }

    parent.resize(sNum);
    for (int i = 0; i < parent.size(); i++) {
        parent[i] = i;
    }
    int useEdge = 0;
    int result = 0;
    while (!pq.empty()) {  	// 최소 신장 트리 알고리즘을 수행하여 줍니다.
        Edge now = pq.top();
        pq.pop();
        if (find(now.s) != find(now.e)) 	// 같은 부모가 아니라면 -> 연결 가능
        {
            munion(now.s, now.e);
            result = result + now.v;
            useEdge++;
        }
    }
    // 배열에서 쉬운 index 처리를 위해 sNum을 1부터 시작하였으므로 현재 sNum의 값이 섬의 개수보다 1 많은 상태임 때문에 1작은 수가 아닌 2작은 수와 사용 에지를 비교하여 줍니다. 
    if (useEdge == sNum - 2) {
        cout << result << "\n";
    }
    else {
        cout << -1 << "\n";
    }

}

void munion(int a, int b) { 		// union 연산 : 대표 노드끼리 연결하여 줌
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

void BFS(int i, int j) {	 // BFS를 통하여 연결된 섬을 찾아줍니다.
    queue<pair<int, int>> myqueue;
    mlist.clear();
    myqueue.push(make_pair(i, j));
    mlist.push_back(make_pair(i, j));
    visited[i][j] = true;
    map[i][j] = sNum;
    while (!myqueue.empty()) {
        int r = myqueue.front().first;
        int c = myqueue.front().second;
        myqueue.pop();
        for (int d = 0; d < 4; d++) { 	//4방향 검색
            int tempR = dr[d];
            int tempC = dc[d];
            while (r + tempR >= 0 && r + tempR < N && c + tempC >= 0 && c + tempC < M) {
                //현재 방문한 적이 없고 바다가 아니면 같은 섬으로 취급
                if (visited[r + tempR][c + tempC] == false && map[r + tempR][c + tempC] != 0) {
                    int now_i = r + tempR;
                    int now_j = c + tempC;
                    map[now_i][now_j] = sNum;
                    visited[now_i][now_j] = true;
                    mlist.push_back(make_pair(now_i, now_j));
                    myqueue.push(make_pair(now_i, now_j));
                }
                else break;
                if (tempR < 0)tempR--;
                else if (tempR > 0)tempR++;
                else if (tempC < 0)tempC--;
                else if (tempC > 0)tempC++;
            }
        }
    }
}
