#include <iostream>
#include <vector>
#include <limits.h>
#include <tuple>
using namespace std;


typedef tuple<int, int, int> edge;
static int N, M, sCity, eCity;
static vector<long> mdistance, cityMoney;
static vector <edge> edges;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> sCity >> eCity >> M;

    mdistance.resize(N);
    cityMoney.resize(N);
    std::fill(mdistance.begin(), mdistance.end(), LONG_MIN); // �ִܰŸ� �迭 �ʱ�ȭ

    for (int i = 0; i < M; i++) { // ���� ����Ʈ�� ������ �����ϱ�
        int start, end, price;
        cin >> start >> end >> price;
        edges.push_back(make_tuple(start, end, price));
    }

    for (int i = 0; i < N; i++) {
        cin >> cityMoney[i];
    }

    
    mdistance[sCity] = cityMoney[sCity]; // ������ �������� �˰��� ����
    for (int i = 0; i <= N + 100; i++) { // �������Ŭ�� ���ĵǵ��� ����� ū ���� �ݺ��ϱ�
        for (int j = 0; j < M; j++) {
            int start = get<0>(edges[j]);
            int end = get<1>(edges[j]);
            int price = get<2>(edges[j]);
            if (mdistance[start] == LONG_MIN) continue; // ���۳�尡 �̹湮 ����̸� continue
            // ���� ��尡 �������Ŭ�� ����� ����� ���� ��嵵 ���� ���� ����
            else if (mdistance[start] == LONG_MAX)
                mdistance[end] = LONG_MAX;
            // �� ���� ���� ���� �ִ� ���ο� ��ΰ� �߰ߵ� ��� ���ο� ��� ������ ����
            else if (mdistance[end] < mdistance[start] + cityMoney[end] - price) {
                mdistance[end] = mdistance[start] + cityMoney[end] - price;
                // N-1 �ݺ� ���� ���ŵǴ� ���� ���� �������Ŭ ���� ���� ����
                if (i >= N - 1)
                    mdistance[end] = LONG_MAX;
            }
        }
    }
    if (mdistance[eCity] == LONG_MIN) cout << "gg"<< "\n"; // ���� �Ұ���
    else if (mdistance[eCity] == LONG_MAX) cout << "Gee" << "\n"; // �������Ŭ ����
    else cout << mdistance[eCity] << "\n"; //�� �̿��� ���
}
