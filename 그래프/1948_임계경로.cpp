#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector < vector <pair<int, int>> > A;
    vector < vector <pair<int, int>> > reverseA;
    vector <int> indegree;     // 진입차수배열
    A.resize(N + 1);
    reverseA.resize(N + 1);
    indegree.resize(N + 1);

    for (int i = 0; i < M; i++) {
        int S, E, V;
        cin >> S >> E >> V;
        A[S].push_back(make_pair(E, V));
        reverseA[E].push_back(make_pair(S, V));  // 역방향 간선 정보 저장
        indegree[E]++;	 // 진입 차수 배열 초기화
    }

    int startDosi, endDosi;
    cin >> startDosi >> endDosi;

    queue<int> mqueue;  	// 위상 정렬 수행
    mqueue.push(startDosi);
    vector <int> result;
    result.resize(N + 1);

    while (!mqueue.empty()) {
        int now = mqueue.front();
        mqueue.pop();
        for (pair<int, int> next : A[now]) {
            indegree[next.first]--;
            result[next.first] = max(result[next.first], result[now] + next.second);
            if (indegree[next.first] == 0) {
                mqueue.push(next.first);
            }
        }
    }
    // 위상 정렬 reverse
    int resultCount = 0;
    vector <bool> visited;
    visited.resize(N + 1);
    queue<int> rqueue;
    rqueue.push(endDosi);
    visited[endDosi] = true;
    while (!rqueue.empty()) {
        int now = rqueue.front();
        rqueue.pop();
        for (pair<int, int> next : reverseA[now]) {
            if (result[next.first] + next.second == result[now]) { 	// 1분도 쉬지 않는 도로 체크
                resultCount++;
                if (visited[next.first] == false) { 	// 중복 카운트 방지를 위해 기 방문 노드 제외
                    visited[next.first] = true;
                    rqueue.push(next.first);
                }
            }
        }
    }
    cout << result[endDosi] << "\n";
    cout << resultCount << "\n";
}
