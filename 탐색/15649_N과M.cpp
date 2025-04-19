#include <iostream>
using namespace std;

static int N, M;
static bool V[8]; // 숫자 사용 여부 저장하기
static int S[8]; // 수열 정보 저장하기

void backtracking(int length);
int main() {
    cin >> N >> M;
    backtracking(0);
}

void backtracking(int length) {
    if (length == M) { // 길이가 M인 수열이 만들어진 경우
        for (int i = 0; i < M; ++i) {
            cout << S[i] + 1 << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = 0; i < N; ++i) {
        if (!V[i]) {
            V[i] = true;    // 수 사용 저장하기
            S[length] = i;  // 수열에 수 사용하기
            backtracking(length + 1);
            V[i] = false;  // 수 반납 저장하기
        }
    }
}
