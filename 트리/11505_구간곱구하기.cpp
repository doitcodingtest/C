#include <iostream>
#include <vector>
#include<cmath>
using namespace std;


static vector<long> tree;
static int MOD = 1000000007;
long getMul(int s, int e);
void changeVal(int index, long val);
void setTree(int i);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, K;
    cin >> N >> M >> K; // 수의 개수, 변경이 일어나는 횟수, 구간 곱 구하는 횟수

    int treeHeight = 0;
    int lenght = N;
    while (lenght != 0) {
        lenght /= 2;
        treeHeight++;
    }
    int treeSize = int(pow(2, treeHeight + 1));
    int leftNodeStartIndex = treeSize / 2 - 1;
    tree.resize(treeSize + 1);
    fill(tree.begin(), tree.end(), 1);

    // 데이터를 리프노드에 입력 받기
    for (int i = leftNodeStartIndex + 1; i <= leftNodeStartIndex + N; i++) {
        cin >> tree[i];
    }
    setTree(treeSize - 1); // tree 만들기

    for (int i = 0; i < M + K; i++) {
        long a, s, e;
        cin >> a >> s >> e;

        if (a == 1) { // 변경
            changeVal(leftNodeStartIndex + s, e);
        }
        else if (a == 2) { // 구간 곱
            s = s + leftNodeStartIndex;
            e = e + leftNodeStartIndex;
            cout << getMul(s, e) << "\n";
        }
    }
}

// 곱셈이 발생할때 마다 MOD연산 수행
long getMul(int s, int e) {
    long partMul = 1;
    while (s <= e) {
        if (s % 2 == 1) {
            partMul = partMul * tree[s] % MOD;
            s++;
        }
        if (e % 2 == 0) {
            partMul = partMul * tree[e] % MOD;
            e--;
        }
        s = s / 2;
        e = e / 2;
    }
    return partMul;
}

void changeVal(int index, long val) {
    tree[index] = val;
    while (index > 1) { //현재 노드의 양쪽 자식 노드를 찾아 곱해주는 로직
        index = index / 2;
        tree[index] = tree[index * 2] % MOD * tree[index * 2 + 1] % MOD;
    }
}

void setTree(int i) {
    while (i != 1) {
        tree[i / 2] = tree[i / 2] * tree[i] % MOD;
        i--;
    }

}