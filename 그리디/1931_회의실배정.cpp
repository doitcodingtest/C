#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    vector<pair<int, int>> A(N);

    for (int i = 0; i < N; i++) {   // ���� �ð� ���� �켱�� ���� ���� ���� first�� ����
        cin >> A[i].second;
        cin >> A[i].first;
    }
    
    sort(A.begin(), A.end());

    int count = 0;
    int end = -1;
    for (int i = 0; i < N; i++) {
        if (A[i].second >= end) { // ��ġ�� �ʴ� ���� ȸ�ǰ� ���°��
            end = A[i].first; // ����ð� ������Ʈ
            count++;
        }
    }
    cout << count << "\n";
}
