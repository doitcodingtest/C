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

    for (int i = 0; i < N; i++) {   // 종료 시간 정렬 우선을 위해 종료 값을 first에 저장
        cin >> A[i].second;
        cin >> A[i].first;
    }
    
    sort(A.begin(), A.end());

    int count = 0;
    int end = -1;
    for (int i = 0; i < N; i++) {
        if (A[i].second >= end) { // 겹치지 않는 다음 회의가 나온경우
            end = A[i].first; // 종료시간 업데이트
            count++;
        }
    }
    cout << count << "\n";
}
