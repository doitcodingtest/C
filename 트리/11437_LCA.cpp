#include <iostream>
#include <vector>
#include <queue>
using namespace std;

static int N, M;
static vector < vector <int> > tree;
static vector<int> depth;
static vector<int> parent;
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
    depth.resize(N + 1);
    parent.resize(N + 1);
    visited.resize(N + 1);
    for (int i = 0; i < N - 1; i++) { // A인접리스트에 그래프 데이터 저장
        int s, e;
        cin >> s >> e;
        tree[s].push_back(e);
        tree[e].push_back(s);
    }
    BFS(1); // depth를 BFS를 통하여 구하기
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
    if (depth[a] < depth[b]) {
        int temp = a;
        a = b;
        b = temp;
    }
    while (depth[a] != depth[b]) { // 두 노드의 Depth 맞춰주기
        a = parent[a];
    }
    while (a != b) { // 같은 조상이 나올 때까지 한칸씩 올려주기
        a = parent[a];
        b = parent[b];
    }
    return a;
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
                parent[next] = now_node;  //부모 노드 저장
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