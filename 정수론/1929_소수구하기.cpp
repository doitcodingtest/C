#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int M, N;
    cin >> M  >> N;
    vector<int> A(N+1);

    for (int i = 2; i <= N; i++) {
        A[i] = i;
    }
    for (int i = 2; i <= sqrt(N); i++) { // 제곱근 까지만 수행
        if (A[i] == 0) {
            continue;
        }
        for (int j = i + i; j <= N; j = j + i) { // 배수 지우기
            A[j] = 0;
        }
    }
    for (int i = M; i <= N; i++) {
        if (A[i] != 0) {
            cout << A[i] << "\n";
        }
    }
}
