#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long Min, Max;
    cin >> Min >> Max;
    // �ִ񰪰� �ּڰ��� ���� ��ŭ �迭 ����
    vector<bool> Check(Max - Min + 1);
    // 2�� �������� 4���� max���� �۰ų� ���� ���� �ݺ�
    for (long i = 2; i * i <= Max; i++) {
        long pow = i * i; // ������
        long start_index = Min / pow;
        if (Min % pow != 0)
            start_index++; // �������� ������ 1�� �����־�� Min���� ū ������ ���� ���۵�
        for (long j = start_index; pow * j <= Max; j++) { // �������� true�� ����
            Check[(int)((j * pow) - Min)] = true;
        }
    }
    int count = 0;
    for (int i = 0; i <= Max - Min; i++) {
        if (!Check[i]) {
            count++;
        }
    }
    cout << count << "\n";
}
