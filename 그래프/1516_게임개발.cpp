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

    int N;
    cin >> N;

    vector < vector <int> > A;
    vector <int>  indegree;     // 진입차수배열
    vector <int>  selfBuild;
    A.resize(N + 1);
    indegree.resize(N + 1);
    selfBuild.resize(N + 1);

    for (int i = 1; i <= N; i++) {
        cin >> selfBuild[i]; // 해당 건물을 짓기 위한 시간
        while (true) { // 인접리스트 데이터 저장
            int preTemp;
            cin >> preTemp;
            if(preTemp == -1)
                break;
            A[preTemp].push_back(i);
            indegree[i]++; // 진입차수 데이터 저장
        }
    }

    queue<int> queue;  // 위상 정렬 수행
    for (int i = 1; i <= N; i++) {
        if (indegree[i] == 0) {
            queue.push(i);
        }
    }
    vector <int>  result;
    result.resize(N + 1);

    while (!queue.empty()) {
        int now = queue.front();
        queue.pop();
        for (int next : A[now]) {
            indegree[next]--;
            result[next] = max(result[next], result[now] + selfBuild[now]);
            if (indegree[next] == 0) {
                queue.push(next);
            }
        }
    }

    for (int i = 1; i <= N; i++) {
       cout << result[i] + selfBuild[i] << "\n";
    }
}