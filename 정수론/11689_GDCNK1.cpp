#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long n;
    cin >> n;
    long result = n;
    for (long p = 2; p <= sqrt(n); p++) { // �����ٱ����� ����
        if (n % p == 0) { // p�� ���μ����� Ȯ��
            result = result - result / p; // ��� �� ������Ʈ
            while (n % p == 0) { // �ش� ���μ��� ������ 2^7*11�̶�� 2^7�� ���ְ� 11�� ����
                n /= p;
            }
        }
    }
    if (n > 1) { // ���� ���μ� ������ �����ִ� ���
        //(�ݺ������� �����ٱ����� Ž���߱� ������ 1���� ���μ��� �����Ǵ� ���̽�)
        result = result - result / n;
    }
    cout << result << "\n";
}
