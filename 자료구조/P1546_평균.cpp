#include <iostream>
using namespace std;
int main()
{
	int N = 0;
	int A[1000];
	cin >> N;
	for (int i = 0; i < N; i++){
		cin >> A[i];
	}
	
	long sum = 0;
	long max = 0;
	for (int i = 0; i < N; i++) {
		if (A[i] > max) {
			max = A[i];
		}
		sum = sum + A[i];
	}
	// 한 과목과 관련된 수식을 총합한 후 관련된 수식으로 변환해 로직이 간단해짐
	double result = sum * 100.0 / max / N;	
	cout << result << "\n";
}
