#include <iostream>
#include <vector>
#include <queue>
#include<cmath>
using namespace std;

static int N, M;
static vector < vector <int> > tree;
static vector<int> depth;
static int kmax;
static int parent[21][100001];
static vector<bool> visited;
int excuteLCA(int a, int b);
void BFS(int node);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    tree.resize(N + 1);
    for (int i = 0; i < N - 1; i++) { // A인접리스트에 그래프 데이터 저장
        int s, e;
        cin >> s >> e;
        tree[s].push_back(e);
        tree[e].push_back(s);
    }

    depth.resize(N + 1);
    visited.resize(N + 1);
    int temp = 1;
    kmax = 0;
    while (temp <= N) { // 최대 가능 Depth 구하기
        temp <<= 1;
        kmax++;
    }

    BFS(1); // depth를 BFS를 통하여 구하기

    for (int k = 1; k <= kmax; k++) {   // 점화식을 이용한 parent 배열 채우기
        for (int n = 1; n <= N; n++) {
            parent[k][n] = parent[k - 1][parent[k - 1][n]];
        }
    }


    cin >> M;
    for (int i = 0; i < M; i++) {
        // 공통 조상을 구할 두 노드
        int a, b;

        cin >> a >> b;
        int LCA = excuteLCA(a, b);
        cout << LCA << "\n";
    }
}

int excuteLCA(int a, int b) {
    if (depth[a] > depth[b]) {//더 깊이가 깊은 depth가 b가 되도록 변경해주기
        int temp = a;
        a = b;
        b = temp;
    }
    for (int k = kmax; k >= 0; k--) {// depth 빠르게 맞춰주기
        if (pow(2, k) <= depth[b] - depth[a]) {
            if (depth[a] <= depth[parent[k][b]]) {
                b = parent[k][b];
            }
        }
    }
    for (int k = kmax; k >= 0 && a != b; k--) { // 조상 빠르게 찾기
        if (parent[k][a] != parent[k][b]) {
            a = parent[k][a];
            b = parent[k][b];
        }
    }
    int LCA = a;
    if (a != b)
        LCA = parent[0][LCA];
    return LCA;
}
// BFS구현
void BFS(int node) {
    queue<int> myqueue;
    myqueue.push(node);
    visited[node] = true;
    int level = 1;
    int now_size = 1;
    int count = 0;
    while (!myqueue.empty()) {
        int now_node = myqueue.front();
        myqueue.pop();
        for (int next : tree[now_node]) {
            if (!visited[next]) {
                visited[next] = true;
                myqueue.push(next);
                parent[0][next] = now_node; // 부모 노드 저장
                depth[next] = level; //노드 depth 저장
            }
        }
        count++;
        if (count == now_size) {
            count = 0;
            now_size = myqueue.size();
            level++;
        }
    }
}