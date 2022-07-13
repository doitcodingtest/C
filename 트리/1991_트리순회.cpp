#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

static int n;
static int tree[26][2];
void preOrder(int now);
void inOrder(int now);
void postOrder(int now);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++) {
        char node_char, left, right;
        cin >> node_char >> left >> right;

        int node = node_char - 'A'; 	// index�� ��ȯ�� ���� A���� ���ֱ�

        // �ڽ� ��尡 ���� ��� -1�� ����
        if (left == '.') {
            tree[node][0] = -1;
        }
        else {
            tree[node][0] = left - 'A';
        }
        if (right == '.') {
            tree[node][1] = -1;
        }
        else {
            tree[node][1] = right - 'A';
        }
    }
    preOrder(0);
    cout << "\n";
    inOrder(0);
    cout << "\n";
    postOrder(0);
    cout << "\n";
}

void preOrder(int now) {
    if (now == -1)
        return;
    cout << (char)(now + 'A');  // 1.���� ���
    preOrder(tree[now][0]);     // 2.���� Ž��
    preOrder(tree[now][1]);     // 3.������ Ž��
}
void inOrder(int now) {
    if (now == -1)
        return;
    inOrder(tree[now][0]);       // 1.���� Ž��
    cout << (char)(now + 'A'); // 2.���� ���
    inOrder(tree[now][1]);       // 3.������ Ž��
}
void postOrder(int now) {
    if (now == -1)
        return;
    postOrder(tree[now][0]);    // 1.���� Ž��
    postOrder(tree[now][1]);    // 2.������ Ž��
    cout << (char)(now + 'A');  // 3.���� ���
}
