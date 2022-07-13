#include <iostream>
#include <queue>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    queue <int> myQueue;
    int N;
    cin >> N;
    for (int i = 1; i <= N; i++) { // ī�带 ť�� �����ϱ�
        myQueue.push(i);
    }
    while (myQueue.size() > 1) { // ī�尡 1�� ���� ������
        myQueue.pop(); // �� ���� ī�带 ����
        myQueue.push(myQueue.front()); // �� ���� ī�带 ���� �Ʒ� ī�� ������ �̵�
        myQueue.pop();
    }
    cout << myQueue.front();
}