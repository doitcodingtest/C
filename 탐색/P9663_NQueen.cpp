#include <iostream>
#include <cmath>
using namespace std;

static int A[15];      // 퀸 배치 정보 
static int N;          // 체스판 크기
static int cnt = 0;    // 정답 수 저장
void backtracking(int row);
bool check(int row);

int main() {
    cin >> N;
    backtracking(0);
    cout << cnt << '\n';
}

void backtracking(int row) {
    if (row == N) {    // 퀸 N개를 모두 배치한 경우
        cnt++;
        return;
    }

    for (int i = 0; i < N; ++i) {
        A[row] = i;
        if (check(row)) {   // 배치한 퀸이 이전 퀸들과 서로 공격할 수 없는지 체크하기
            backtracking(row + 1);
        }
    }
}

bool check(int row) {
    for (int i = 0; i < row; ++i) {
        if (A[i] == A[row]) return false;  // 같은 열
        if (abs(row - i) == abs(A[i] - A[row])) return false; // 같은 대각선
    }
    return true;
}
