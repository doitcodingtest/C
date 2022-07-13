#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

class Node 	//Ʈ���� �ڷ� ���� ����� Ŭ����
{
public:
    Node* next[26];
    bool isEnd;
    Node() : isEnd(false) {
        fill(next, next + 26, nullptr);
    }

    ~Node() {
        for (auto& child : next)
            delete child;
    }

    void insert(const char* key) {		// ���ڿ� ���� �Լ�
        if (*key == 0)
            isEnd = true;
        else {
            int next_index = *key - 'a';
            if (next[next_index] == nullptr)
                next[next_index] = new Node();

            next[next_index]->insert(key + 1);
        }
    }

    Node* find(const char* key) {		// ���ڿ� ã�� �Լ�
        if (*key == 0)
            return this;

        int next_index = *key - 'a';
        if (next[next_index] == nullptr)
            return nullptr;

        return next[next_index]->find(key + 1);
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    Node* root = new Node();

    while (n > 0) {  	// Ʈ���� �ڷᱸ�� �����ϱ�
        char text[501];
        cin >> text;
        root->insert(text);
        n--;
    }

    int count = 0;
    while (m > 0) {  	// Ʈ���� �ڷᱸ�� �˻��ϱ�
        char text[501];
        cin >> text;
        Node* result = root->find(text);
        if (result && result->isEnd) {
            count++; 	// S���տ� ���ԵǴ� ���ڿ�
        }
        m--;
    }
    cout << count << "\n";
}
