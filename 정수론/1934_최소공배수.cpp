#include <iostream>
#include <cmath>
using namespace std;

int gcd(int a, int b);
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int a, b;
        cin >> a >> b;
        int result = a * b / gcd(a, b);
        cout << result << "\n";
    }
}

int gcd(int a, int b) {
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);   // 재귀함수 형태로 구현
}