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
    if (D[n] != -1) //������ ����� ���� �ִ� �κ� ������ �ٽ� ������� �ʰ� �����Ѵ�.
        return D[n];
    return D[n] = fibo(n - 2) + fibo(n - 1); //�޸������̼� �κ�
}