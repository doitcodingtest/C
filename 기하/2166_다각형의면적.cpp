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
    x[N] = x[0]; // �������� ó������ CCW ��꿡 �������־����
    y[N] = y[0];
    double result = 0;
    for (int i = 0; i < N; i++) {
        result += (x[i] * y[i + 1]) - (x[i + 1] * y[i]);
    }
    cout << fixed;
    cout.precision(1); //�Ҽ��� �ڸ��� ����
    cout << abs(result) / 2.0;
}
