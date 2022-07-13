#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void merget_sort(int s, int e);
static vector<int> A;
static vector<int> tmp;
static long result;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    A = vector<int>(N + 1, 0);
    tmp = vector<int>(N + 1, 0);
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }
    result = 0;
    merget_sort(1, N); // �������� �����ϱ�
    
    cout << result << "\n";
}

void merget_sort(int s, int e) {
    if (e - s < 1)
        return;
    int m = s + (e - s) / 2;
    // ����Լ� ���·� ����
    merget_sort(s, m);
    merget_sort(m + 1, e);
    for (int i = s; i <= e; i++) {
        tmp[i] = A[i];
    }
    int k = s;
    int index1 = s;
    int index2 = m + 1;
    while (index1 <= m && index2 <= e) { // �� �׷��� Merge ���ִ� ����
        if (tmp[index1] > tmp[index2]) {
            A[k] = tmp[index2];
            result = result + index2 - k; // ���� ������ ���� �۾� ���õǴ� ��� ��� �� ������Ʈ
            k++;
            index2++;
        }
        else {
            A[k] = tmp[index1];
            k++;
            index1++;
        }
    }
    // ���� �׷��� ��� ���õ� �� �����ִ� �� �����ϱ�
    while (index1 <= m) {
        A[k] = tmp[index1];
        k++;
        index1++;
    }
    while (index2 <= e) {
        A[k] = tmp[index2];
        k++;
        index2++;
    }

}