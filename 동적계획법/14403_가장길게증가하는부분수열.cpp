#include <iostream>
using namespace std;

static int N, maxLength;
static int B[1000001];
static int A[1000001];
static int D[1000001];
static int ans[1000001];
int binarysearch(int l, int r, int now);

int main()
{
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }

    int index;
    B[++maxLength] = A[1];
    D[1] = 1;
    for (int i = 2; i <= N; i++) {
        if (B[maxLength] < A[i]) { //가장 마지막 수열보다 현재 수열이 큰 경우
            B[++maxLength] = A[i];
            D[i] = maxLength;
        }
        else {
            index = binarysearch(1, maxLength, A[i]);    // B배열에서 data[i]보다 처음으로 크거나 같아지는 원소의 index 찾기
            B[index] = A[i];
            D[i] = index;
        }
    }
    cout << maxLength << "\n"; //가장 긴 증가하는 부분 수열 길이 출력
    index = maxLength;
    int x = B[maxLength] + 1;
    for (int i = N; i >= 1; i--) { //뒤에서 부터 탐색하면서 정답 수열 저장하기
        if (D[i] == index && A[i] < x) {
            ans[index] = A[i];
            x = A[i];
            index--;
        }
    }
    for (int i = 1; i <= maxLength; i++)
        cout << ans[i] << " ";
}

// 현재 수열이 들어 갈 수 있는 위치를 빠르게 찾아주기 위한 바이너리 서치 구현
int binarysearch(int l, int r, int now) {
    int mid;
    while (l < r) {
        mid = (l + r) / 2;
        if (B[mid] < now)
            l = mid + 1;
        else
            r = mid;
    }
    return l;
}