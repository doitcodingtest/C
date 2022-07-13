#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

void BFS();
static int Sender[] = {0, 0, 1, 1, 2, 2};
static int Receiver[] = {1, 2, 0, 2, 0, 1};
static bool visited[201][201];  //A B의 무게만 있으면 C의 무게가 고정되므로 2개로만 체크 가능
static bool answer[201];
static int now[3]; // A B C 물의 양을 저장하는 배열

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> now[0] >> now[1] >> now[2]; 
    BFS();
    
    for (int i = 0; i < 201; i++) {
        if (answer[i]) cout << i << " ";
    }
}

void BFS() {
    queue<pair<int,int>> queue;
    queue.push(make_pair(0,0));
    visited[0][0] = true;
    answer[now[2]] = true;
    while (!queue.empty()) {
        pair <int, int> p = queue.front();
        queue.pop();
        int A = p.first;
        int B = p.second;
        int C = now[2] - A - B; // C는 전체 물의 양에서 A와 B를 빼준 것
        for (int k = 0; k < 6; k++) { // A->B, A->C, B->A, B->C, C->A, C->B 6개의 케이스로 이동
            int next[] = { A, B, C };
            next[Receiver[k]] += next[Sender[k]];
            next[Sender[k]] = 0;
            if (next[Receiver[k]] > now[Receiver[k]]) { // 대상 물통의 용량보다 물이 많아 넘칠 때
                // 초과하는 만큼 다시 이전 물통에 넣어줌
                next[Sender[k]] = next[Receiver[k]] - now[Receiver[k]];
                next[Receiver[k]] = now[Receiver[k]]; // 대상 물통은 최대로 채워줌
            }
            if (!visited[next[0]][next[1]]) { // A와 B의 물의 양을 통하여 방문 배열 체크
                visited[next[0]][next[1]] = true;
                queue.push(make_pair(next[0], next[1]));
                if (next[0] == 0) {  // A의 물의 양이 0일때 C의 물의 무게를 정답 변수에 저장
                    answer[next[2]] = true;
                }
            }
        }
    }
}