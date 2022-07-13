#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    vector<int> A(N, 0);
    vector<int> ans(N, 0);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    stack <int> myStack;
    myStack.push(0);
    for (int i = 1; i < N; i++) {
        //���� ������� �ʰ� ���� ������ ���� TOP�ε��� ����Ű�� �������� ũ��
        while (!myStack.empty() && A[myStack.top()] < A[i]) {
            ans[myStack.top()] = A[i];  //���� �迭�� ��ū���� ���� ������ �����ϱ�
            myStack.pop();
        }
        myStack.push(i); //�űԵ����� push  
    }
    while (!myStack.empty()) {
        // �ݺ����� �� ���� ���Դµ� ������ ������� �ʴٸ� �� �� ����
        ans[myStack.top()] = -1;
        myStack.pop();
    };
    for (int i = 0; i < N; i++) {   // ���
        cout << ans[i] << " ";
    }
}