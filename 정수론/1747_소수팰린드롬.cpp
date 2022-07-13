#include <iostream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;
bool isPalindrome(int target);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long N;
    cin >> N;
    long A[10000001];

    for (int i = 2; i < 10000001; i++) {
        A[i] = i;
    }
    for (int i = 2; i <= sqrt(10000001); i++) { // 제곱근 까지만 수행
        if (A[i] == 0) {
            continue;
        }
        for (int j = i + i; j < 10000001; j = j + i) { // 배수 지우기
            A[j] = 0;
        }
    }
    int i = N;
    while (true) { // N부터 1씩 증가시켜가면서 소수와 펠린드롬 수가 맞는지 확인
        if (A[i] != 0) {
            int result = A[i];
            if (isPalindrome(result)) {
                cout << result << "\n";
                break;
            }
        }
        i++;
    }
}

bool isPalindrome(int target) // 펠린드롬수 판별 함수
{

    string temp_str = to_string(target); //converting number to a string
    char const* temp = temp_str.c_str(); //converting string to char Array
    int s = 0;
    int e = temp_str.size() - 1;
    while (s < e) {
        if (temp[s] != temp[e])
            return false;
        s++;
        e--;
    }
    return true;
}
