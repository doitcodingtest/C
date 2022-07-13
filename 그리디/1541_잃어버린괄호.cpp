#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;
vector<string> split(string input, char delimiter);
int mySum(string a);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int answer = 0;
    string example;
    cin >> example;
    vector<string> str = split(example, '-');
    for (int i = 0; i < str.size(); i++) {
        int temp = mySum(str[i]);
        if (i == 0)
            answer = answer + temp; // 제일 앞에 것만 더해주고
        else
            answer = answer - temp; // 뒤에 부분은 더한 값들을 빼줌
    }

    cout << answer << "\n";
}

//문자열 특정 구분자로 잘라 벡터에 저장하는 함수 
vector<string> split(string input, char delimiter) {
    vector<string> result;
    stringstream mystream(input);
    string splitdata;

    while (getline(mystream, splitdata, delimiter)) {
        result.push_back(splitdata);
    }

    return result;
}

int mySum(string a) { // 나눠진 그룹의 더하기 연산 수행 함수
    int sum = 0;
    vector<string> temp = split(a, '+');
    for (int i = 0; i < temp.size(); i++) {
        sum += stoi(temp[i]);
    }
    return sum;
}