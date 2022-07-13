#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long N, K;
    cin >> N >> K;
    long start = 1, end = K;
    long ans = 0;
    // 이분 탐색 수행
    while (start <= end) {
        long middle = (start + end) / 2;
        long cnt = 0;
        // 중앙 값보다 작은 수는 몇 개인지 계산.
        for (int i = 1; i <= N; i++) {
            cnt += min(middle/i, N);  // 작은 수를 카운트하는 핵심로직
        }
        if (cnt < K) {
            start = middle + 1;
        }
        else {
            ans = middle;  // 현재 단계의 중앙 값을 정답 변수에 저장
            end = middle - 1;
        }
    }
    cout << ans << "\n";
}