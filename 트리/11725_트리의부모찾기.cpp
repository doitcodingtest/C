#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

static int N;
static vector<int> answer;
static vector<bool> visited;
static vector < vector <int> > tree;
void DFS(int number);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    visited.resize(N + 1);
    tree.resize(N + 1);
    answer.resize(N + 1);

    for (int i = 1; i < N; i++) {
        int n1, n2;
        cin >> n1 >> n2;
        tree[n1].push_back(n2);
        tree[n2].push_back(n1);
    }

    DFS(1);	// 루트 노드에서 DFS 실행
    for (int i = 2; i <= N; i++) {
        cout << answer[i] << "\n";
    }
}

void DFS(int number) {
    visited[number] = true;
    for (int i : tree[number]) {
        if (!visited[i]) {
            answer[i] = number;	// 부모노드를 정답 배열에 저장하기
            DFS(i);
        }
    }
}
