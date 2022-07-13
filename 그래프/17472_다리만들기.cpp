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

typedef struct Edge 	// �������� struct ����, ����ġ �� ���� �������� ���ķ� ����
{
    int s, e, v;
    bool operator> (const Edge& temp) const {
        return v > temp.v;
    }
}Edge;

static priority_queue<Edge, vector<Edge>, greater<Edge>> pq;   // �������� ����

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j]; 	// �� ���� ����
        }
    }
    sNum = 1;

    for (int i = 0; i < N; i++) { 	// �� �ڸ����� BFS Ž���� �̿��Ͽ� ������ �и��Ͽ� �ݴϴ�.
        for (int j = 0; j < M; j++) {
            if (map[i][j] != 0 && visited[i][j] != true) {
                BFS(i, j);
                sNum++;
                sumlist.push_back(mlist);
            }
        }
    }

    for (int i = 0; i < sumlist.size(); i++) {	 // ���� �� �������� ���� �� �ִ� ��� ������ ����
        vector<pair<int, int>> now = sumlist[i];
        for (int j = 0; j < now.size(); j++) {
            int r = now[j].first;
            int c = now[j].second;
            int now_S = map[r][c];
            for (int d = 0; d < 4; d++) { 	// 4���� �˻�
                int tempR = dr[d];
                int tempC = dc[d];
                int blenght = 0;
                while (r + tempR >= 0 && r + tempR < N && c + tempC >= 0 && c + tempC < M) {
                    if (map[r + tempR][c + tempC] == now_S) 	// ���� ���̸� ������ ���� �� ����
                        break;
                    else if (map[r + tempR][c + tempC] != 0) { 	//���� ���� �ƴϰ� �ٴٰ� �ƴϸ� 
                        if (blenght > 1) 	// �ٸ� �� -> ���̰� 1�̻��϶� �������� �����ݴϴ�.
                            pq.push(Edge{ now_S, map[r + tempR][c + tempC], blenght });
                        break;
                    }
                    else 	//�ٴ��̸� �ٸ��� ���̸� �����Ͽ� �ݴϴ�.
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
    while (!pq.empty()) {  	// �ּ� ���� Ʈ�� �˰����� �����Ͽ� �ݴϴ�.
        Edge now = pq.top();
        pq.pop();
        if (find(now.s) != find(now.e)) 	// ���� �θ� �ƴ϶�� -> ���� ����
        {
            munion(now.s, now.e);
            result = result + now.v;
            useEdge++;
        }
    }
    // �迭���� ���� index ó���� ���� sNum�� 1���� �����Ͽ����Ƿ� ���� sNum�� ���� ���� �������� 1 ���� ������ ������ 1���� ���� �ƴ� 2���� ���� ��� ������ ���Ͽ� �ݴϴ�. 
    if (useEdge == sNum - 2) {
        cout << result << "\n";
    }
    else {
        cout << -1 << "\n";
    }

}

void munion(int a, int b) { 		// union ���� : ��ǥ ��峢�� �����Ͽ� ��
    a = find(a);
    b = find(b);
    if (a != b) {
        parent[b] = a;
    }
}
int find(int a) { 	// find ����
    if (a == parent[a])
        return a;
    else
        return parent[a] = find(parent[a]); 	// ����Լ��� ���·� ���� -> ��� ���� �κ�
}

void BFS(int i, int j) {	 // BFS�� ���Ͽ� ����� ���� ã���ݴϴ�.
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
        for (int d = 0; d < 4; d++) { 	//4���� �˻�
            int tempR = dr[d];
            int tempC = dc[d];
            while (r + tempR >= 0 && r + tempR < N && c + tempC >= 0 && c + tempC < M) {
                //���� �湮�� ���� ���� �ٴٰ� �ƴϸ� ���� ������ ���
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
