#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    sort(A.begin(), A.end()); //A배열 정렬 O(nlogn)시간 복잡도

    cin >> M;
    for (int i = 0; i < M; i++) {
        bool find = false;
        int target;
        cin >> target;
        // 이진 탐색 시작
        int start = 0;
        int end = A.size() - 1;
        while (start <= end) {
            int midi = (start + end) / 2;
            int midV = A[midi];
            if (midV > target) {
                end = midi - 1;
            }
            else if (midV < target) {
                start = midi + 1;
            }
            else {
                find = true;
                break;
            }
        }
        if (find) {
            cout << 1 << "\n";
        }
        else {
            cout << 0 << "\n";
        }
    }
}