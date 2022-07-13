#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
long gcd(long a, long b);
vector<long> Excute(long a, long b);
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long a, b, c;
    cin >> a >> b >> c;
    long tgcd = gcd(a, b);
    if (c % tgcd != 0) {
        cout << -1 << "\n";
    }
    else {
        int mok = (int)(c / tgcd);
        vector<long> ret = Excute(a, b);
        cout << ret[0] * mok << " " << ret[1] * mok;
    }
}

vector<long> Excute(long a, long b) {
    vector<long> ret(2);
    if (b == 0) {
        ret[0] = 1;
        ret[1] = 0;
        return ret;
    }
    long q = a / b;
    vector<long> v = Excute(b, a % b); 	// 재귀 형태로 호제법 수행
    ret[0] = v[1];  		// 역으로 올라오면서 X Y값을 계산해주는 로직
    ret[1] = v[0] - v[1] * q;
    return ret;
}

long gcd(long a, long b) {
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}
