#include <iostream>
using namespace std;

int main()
{
	int N = 0;
	string numbers;
	cin >> N;
	cin >> numbers;

	int sum = 0;;
	for (int i = 0; i < numbers.length(); i++){
		sum += numbers[i] - '0';	 // numbers[i]를 정수 값으로 계산하여 sum에 더하여 누적하기
	}
	cout << sum << "\n";
}