#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

static int N;
static int DP[1001][1001];
static string A, B;
static vector<char> Path;
void getText(int r, int c);

int main()
{
    cin >> A >> B;
    for (int i = 1; i <= A.size(); i++) {
        for (int j = 1; j <= B.size(); j++) {
            if (A[i - 1] == B[j - 1]) {
                DP[i][j] = DP[i - 1][j - 1] + 1; // 같은 문자열일 경우 왼쪽 대각선 값 +1
            }
            else {
                DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]); // 다르면 왼쪽과 위의 값 중 큰수
            }
        }
    }

    cout << DP[A.size()][B.size()] << "\n";
    getText(A.size(), B.size());
    for (int i = Path.size() - 1; i >= 0; i--) {
        cout<< Path[i];
    }
    cout << "\n";
}

void getText(int r, int c) { // LCS 출력함수
    if (r == 0 || c == 0) return;
    if (A[r - 1] == B[c - 1]) { // 같으면 LCS에 기록하고 왼쪽 위로 이동
        Path.push_back(A[r - 1]);
        getText(r - 1, c - 1);
    }
    else {
        if (DP[r - 1][c] > DP[r][c - 1]) // 다르면 왼쪽과 윗쪽 중 큰 수로 이동
            getText(r - 1, c);
        else
            getText(r, c - 1);
    }
}