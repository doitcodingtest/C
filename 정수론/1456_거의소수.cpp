#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long Min, Max;
    cin >> Min >> Max;
    long A[10000001];

    for (int i = 2; i < 10000001; i++) {
        A[i] = i;
    }
    for (int i = 2; i <=  sqrt(10000001); i++) { // 제곱근 까지만 수행
        if (A[i] == 0) {
            continue;
        }
        for (int j = i + i; j < 10000001; j = j + i) { // 배수 지우기
            A[j] = 0;
        }
    }
    int count = 0;
    for (int i = 2; i < 10000001; i++) {
        if (A[i] != 0) {
            long temp = A[i];
            while ((double)A[i] <= (double)Max / (double)temp) {
                if ((double)A[i] >= (double)Min / (double)temp) {
                    count++;
                }
                temp = temp * A[i];
            }
        }
    }
    cout << count << "\n";
}
