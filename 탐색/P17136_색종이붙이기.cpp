#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

static int M[10][10];
static int S[6] = { 0, 5, 5, 5, 5, 5 }; // 색종이 남은 개수 (1~5 크기)
static int result = INT_MAX; // 최소 사용 개수
void backtracking(int xy, int useCnt);
bool check(int x, int y, int size);
void fill(int x, int y, int size, int num);

int main() {
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; ++j) {
			cin >> M[i][j];
		}
	}
	// 1이 적힌 모든 칸을 붙이는 색종이를 사용한 경우의 수를 백트래킹으로 탐색
	backtracking(0, 0);

	if (result == INT_MAX)
		cout << -1 << '\n';
	else
		cout << result << '\n';
}

void backtracking(int xy, int useCnt) {
	if (xy == 100) {  // 1이 적힌 모든 칸을 붙였을 때(x, y 좌표를 끝까지 탐색한 경우) 탐색 종료
		result = min(result, useCnt);
		return;
	}

	int x = xy % 10;
	int y = xy / 10;

	// 가지치기: 이전에 최소로 사용한 색종이 수보다 현재 사용한 색종이가 많으면 탐색 중단
	if (result <= useCnt) return;

	if (M[y][x] == 1) {
		for (int i = 5; i >= 1; --i) {
			if (S[i] > 0 && check(x, y, i)) {
				S[i]--;		// 종이 사용하기
				fill(x, y, i, 0);	// 종이 붙이기: 종이로 덮이는 부분 1 → 0으로 변경
				backtracking(xy + 1, useCnt + 1);
				S[i]++;		// 사용한 종이 다시 채우기
				fill(x, y, i, 1);	// 종이 떼어 내기: 기존에 덮인 부분 0 → 1로 변경
			}
		}
	}
	else {
		backtracking(xy + 1, useCnt);	// 현재 좌표의 값이 0이면 바로 다음 칸 이동
	}
}

bool check(int x, int y, int size) {
	if (x + size > 10 || y + size > 10) return false;
	for (int i = y; i < y + size; ++i) {
		for (int j = x; j < x + size; ++j) {
			if (M[i][j] != 1) return false;
		}
	}
	return true;
}

void fill(int x, int y, int size, int num) {
	for (int i = y; i < y + size; ++i) {
		for (int j = x; j < x + size; ++j) {
			M[i][j] = num;
		}
	}
}
