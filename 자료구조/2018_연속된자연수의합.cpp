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
        if (sum == N) {         //  ���� ã�� ���
            count++;
            end_index++;
            sum = sum + end_index;
        }
        else if (sum > N) {   // ���� ���� �亸�� ū ���
            sum = sum - start_index;
            start_index++;
        }
        else {                // ���� ���� �亸�� ���� ���
            end_index++;
            sum = sum + end_index;
        }
    }
	cout << count << "\n";
}