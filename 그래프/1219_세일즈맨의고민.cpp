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
    std::fill(mdistance.begin(), mdistance.end(), LONG_MIN); // 최단거리 배열 초기화

    for (int i = 0; i < M; i++) { // 에지 리스트에 데이터 저장하기
        int start, end, price;
        cin >> start >> end >> price;
        edges.push_back(make_tuple(start, end, price));
    }

    for (int i = 0; i < N; i++) {
        cin >> cityMoney[i];
    }

    
    mdistance[sCity] = cityMoney[sCity]; // 변형된 벨만포드 알고리즘 수행
    for (int i = 0; i <= N + 100; i++) { // 양수싸이클이 전파되도록 충분히 큰 수로 반복하기
        for (int j = 0; j < M; j++) {
            int start = get<0>(edges[j]);
            int end = get<1>(edges[j]);
            int price = get<2>(edges[j]);
            if (mdistance[start] == LONG_MIN) continue; // 시작노드가 미방문 노드이면 continue
            // 시작 노드가 양수사이클에 연결된 노드라면 종료 노드도 연결 노드로 갱신
            else if (mdistance[start] == LONG_MAX)
                mdistance[end] = LONG_MAX;
            // 더 많은 돈을 벌수 있는 새로운 경로가 발견된 경우 새로운 경로 값으로 갱신
            else if (mdistance[end] < mdistance[start] + cityMoney[end] - price) {
                mdistance[end] = mdistance[start] + cityMoney[end] - price;
                // N-1 반복 이후 갱신되는 종료 노드는 양수사이클 연결 노드로 변경
                if (i >= N - 1)
                    mdistance[end] = LONG_MAX;
            }
        }
    }
    if (mdistance[eCity] == LONG_MIN) cout << "gg"<< "\n"; // 도착 불가능
    else if (mdistance[eCity] == LONG_MAX) cout << "Gee" << "\n"; // 양수사이클 연결
    else cout << mdistance[eCity] << "\n"; //그 이외의 경우
}
