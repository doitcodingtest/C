#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
static  vector<int> parent;

void unionfunc(int a, int b);
int find(int a);
bool checkSame(int a, int b);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;
    parent.resize(N + 1);

    for (int i = 0; i <= N; i++) { 	// 대표 노드를 자기 자신으로 초기화 하기
        parent[i] = i;
    }

    for (int i = 0; i < M; i++) {
        int question, a, b;
        cin >> question >> a >> b;
        if (question == 0) { 	// 집합 합치기
            unionfunc(a, b);
        }
        else {	 // 같은 집합의 원소인지 확인하기
            if (checkSame(a, b)) {
                cout << "YES" << "\n";
            }
            else {
                cout << "NO" << "\n";
            }
        }
    }
}
void unionfunc(int a, int b) { 	// union 연산 : 바로 연결이 아닌 대표 노드끼리 연결하여 줌
    a = find(a);
    b = find(b);
    if (a != b) {
        parent[b] = a;
    }
}
int find(int a) {	 // find 연산 : 대표 노드를 찾아서 리턴
    if (a == parent[a])
        return a;
    else
        return parent[a] = find(parent[a]);	 // 재귀함수의 형태로 구현
}
bool checkSame(int a, int b) { // 두 원소가 같은 집합인지 확인
    a = find(a);
    b = find(b);
    if (a == b) {
        return true;
    }
    return false;
}
