#include <iostream>
#include <queue>
using namespace std;

static int dx[] = {0, 1, 0, -1};
static int dy[] = {1, 0, -1, 0};
static int A[101][101];
static bool visited[101][101] = { false };
static int N, M;
void BFS(int i, int j);
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < M; j++) {
            A[i][j] = s[j] - '0';
        }
    }

    BFS(0,0);
    cout << A[N-1][M-1] << "\n";
}

void BFS(int i, int j) {  // BFS구현
    queue<pair<int, int>> myqueue;
    myqueue.push(make_pair(i, j));
    while (!myqueue.empty()) {
        int now[2];
        now[0] = myqueue.front().first;
        now[1] = myqueue.front().second;
        myqueue.pop();
        visited[i][j] = true;
        for (int k = 0; k < 4; k++) {
            int x = now[0] + dx[k];
            int y = now[1] + dy[k];
            if (x >= 0 && y >= 0 && x < N && y < M) { // 좌표 유효성 검사
                if (A[x][y] != 0 && !visited[x][y]) { // 미방문 정점 검사
                    visited[x][y] = true;
                    A[x][y] = A[now[0]][now[1]] + 1; // depth update
                    myqueue.push(make_pair(x, y));
                }
            }
        }
    }
}