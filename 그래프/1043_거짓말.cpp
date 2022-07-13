#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
static  vector<int> parent;
static  vector<int> trueP;
static vector < vector <int> > party;
static int result;

void unionfunc(int a, int b);
int find(int a);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, T;
    cin >> N >> M >> T;
    trueP.resize(T);
    for (int i = 0; i < T; i++) { // ������ �ƴ� ��� ����
        cin >> trueP[i];
    }
    
    party.resize(M);

    for (int i = 0; i < M; i++) { // ��Ƽ ������ ����
        int party_size;
        cin >> party_size;
        for (int j = 0; j < party_size; j++) {
            int temp;
            cin >> temp;
            party[i].push_back(temp);
        }
    }

    parent.resize(N + 1);
    for (int i = 0; i <= N; i++) { // ��ǥ ��带 �ڱ� �ڽ����� �ʱ�ȭ �ϱ�
        parent[i] = i;
    }

    for (int i = 0; i < M; i++) { // �� ��Ƽ�� ������ ������� �ϳ��� �׷����� ����� -> union ����
        int firstPeople = party[i][0];
        for (int j = 1; j < party[i].size(); j++) {
            unionfunc(firstPeople, party[i][j]);
        }
    }
    for (int i = 0; i < M; i++) { // �� ��Ƽ���� ������ �ƴ� ����� ���� �׷쿡 �ִٸ� ���� �� �� ����
        bool isPossible = true;
        int cur = party[i][0];
        for (int j = 0; j < T; j++) {
            if (find(cur) == find(trueP[j])) {
                isPossible = false;
                break;
            }
        }
        if (isPossible)
            result++;
    }
    cout << result;
}
void unionfunc(int a, int b) { // union ���� : �ٷ� ������ �ƴ� ��ǥ ��峢�� �����Ͽ� ��
    a = find(a);
    b = find(b);
    if (a != b) {
        parent[b] = a;
    }
}
int find(int a) { // find ����
    if (a == parent[a])
        return a;
    else
        return parent[a] = find(parent[a]); // ����Լ��� ���·� ����
}
