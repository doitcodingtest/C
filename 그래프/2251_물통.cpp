#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

void BFS();
static int Sender[] = {0, 0, 1, 1, 2, 2};
static int Receiver[] = {1, 2, 0, 2, 0, 1};
static bool visited[201][201];  //A B�� ���Ը� ������ C�� ���԰� �����ǹǷ� 2���θ� üũ ����
static bool answer[201];
static int now[3]; // A B C ���� ���� �����ϴ� �迭

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
        int C = now[2] - A - B; // C�� ��ü ���� �翡�� A�� B�� ���� ��
        for (int k = 0; k < 6; k++) { // A->B, A->C, B->A, B->C, C->A, C->B 6���� ���̽��� �̵�
            int next[] = { A, B, C };
            next[Receiver[k]] += next[Sender[k]];
            next[Sender[k]] = 0;
            if (next[Receiver[k]] > now[Receiver[k]]) { // ��� ������ �뷮���� ���� ���� ��ĥ ��
                // �ʰ��ϴ� ��ŭ �ٽ� ���� ���뿡 �־���
                next[Sender[k]] = next[Receiver[k]] - now[Receiver[k]];
                next[Receiver[k]] = now[Receiver[k]]; // ��� ������ �ִ�� ä����
            }
            if (!visited[next[0]][next[1]]) { // A�� B�� ���� ���� ���Ͽ� �湮 �迭 üũ
                visited[next[0]][next[1]] = true;
                queue.push(make_pair(next[0], next[1]));
                if (next[0] == 0) {  // A�� ���� ���� 0�϶� C�� ���� ���Ը� ���� ������ ����
                    answer[next[2]] = true;
                }
            }
        }
    }
}