#include <iostream>
using namespace std;

void DFS(int number, int jarisu);
bool isPrime(int num);
static int N;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    DFS(2, 1);
    DFS(3, 1);
    DFS(5, 1);
    DFS(7, 1);
}

void DFS(int number, int jarisu) {
    if (jarisu == N) {
        if (isPrime(number)) {
            cout << number << "\n";
        }
        return;
    }
    for (int i = 1; i < 10; i++) {
        if (i % 2 == 0) { // 짝수이면 더 이상 탐색할 필요가 없음
            continue;
        }
        if (isPrime(number * 10 + i)) { // 소수이면 재귀로 자리수를 늘려갑니다.
            DFS(number * 10 + i, jarisu + 1);
        }
    }
}

bool isPrime(int num) {
    for (int i = 2; i <= num / 2; i++)
        if (num % i == 0)
            return false;
    return true;
}