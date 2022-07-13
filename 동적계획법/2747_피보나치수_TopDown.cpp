#include <iostream>
#include <vector>
using namespace std;

static int N;
static vector<int> D;
int fibo(int n);

int main()
{
    cin >> N;
    D.resize(N + 1);

    for (int i = 0; i <= N; i++) {
        D[i] = -1;
    }
    D[0] = 0;
    D[1] = 1;
    fibo(N);

    cout << D[N];
}

int fibo(int n) {
    if (D[n] != -1) //기존에 계산한 적이 있는 부분 문제는 다시 계산하지 않고 리턴한다.
        return D[n];
    return D[n] = fibo(n - 2) + fibo(n - 1); //메모이제이션 부분
}