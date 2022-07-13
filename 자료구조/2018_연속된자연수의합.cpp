#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
    int count = 1;
    int start_index = 1;
    int end_index = 1;
    int sum = 1;
    while (end_index != N) {
        if (sum == N) {         //  답을 찾은 경우
            count++;
            end_index++;
            sum = sum + end_index;
        }
        else if (sum > N) {   // 현재 합이 답보다 큰 경우
            sum = sum - start_index;
            start_index++;
        }
        else {                // 현재 합이 답보다 작은 경우
            end_index++;
            sum = sum + end_index;
        }
    }
	cout << count << "\n";
}