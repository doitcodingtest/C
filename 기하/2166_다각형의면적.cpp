#include <iostream>
using namespace std;

static int N;
static long x[10001], y[10001];

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> x[i];
        cin >> y[i];
    }
    x[N] = x[0]; // 마지막과 처음점도 CCW 계산에 포함해주어야함
    y[N] = y[0];
    double result = 0;
    for (int i = 0; i < N; i++) {
        result += (x[i] * y[i + 1]) - (x[i + 1] * y[i]);
    }
    cout << fixed;
    cout.precision(1); //소수점 자리수 설정
    cout << abs(result) / 2.0;
}
