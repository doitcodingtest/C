#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    vector<pair<int, int>> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i].first;
        A[i].second = i;
    }

    sort(A.begin(), A.end()); //A배열 정렬 O(nlogn)시간 복잡도

    int Max = 0;
    for (int i = 0; i < N; i++) {
        if (Max < A[i].second - i) //정렬 전 index - 정렬 후 index 계산 값의 최대 값을 찾아 저장
            Max = A[i].second - i;
    }
    cout << Max + 1;
}