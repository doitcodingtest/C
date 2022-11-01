#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
static int INF = 1000000 * 16 + 1;
static int N;
static int W[16][16];
static int D[16][(1 << 16)];
int tsp(int c, int v);
int main()
{
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> W[i][j];
		}
	}
	cout << tsp(0, 1) << "\n";
}
int tsp(int c, int v) { // 모든 경우의 수에 대한 완전 탐색, 재귀 구현
	if (v == (1 << N) - 1) { // 모든 노드를 방문한 경우
		return W[c][0] == 0 ? INF : W[c][0];
	}
	// 이미 방문한 노드인 경우 → 이미 계산한 경우 바로 반환(메모이제이션)
	if (D[c][v] != 0) {
		return D[c][v];
	}
	int min_val = INF;
	for (int i = 0; i < N; i++) {
		// 방문한 적이 없고 갈 수 있는 도시인 경우
		if ((v & (1 << i)) == 0 && W[c][i] != 0) {
			min_val = min(min_val, tsp(i, (v | (1 << i))) + W[c][i]);
		}
	}
	D[c][v] = min_val;
	return D[c][v];
}
