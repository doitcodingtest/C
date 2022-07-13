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
    for (int i = 1; i <= N; i++) { // 카드를 큐에 저장하기
        myQueue.push(i);
    }
    while (myQueue.size() > 1) { // 카드가 1장 남을 때까지
        myQueue.pop(); // 맨 위의 카드를 버림
        myQueue.push(myQueue.front()); // 맨 위의 카드를 가장 아래 카드 밑으로 이동
        myQueue.pop();
    }
    cout << myQueue.front();
}