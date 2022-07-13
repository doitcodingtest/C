#include <iostream>
#include <vector>
#include <limits.h>
#include <tuple>
using namespace std;


typedef tuple<int, int, int> edge;
static int N, M;
static vector<long> mdistance;
static vector <edge> edges;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    mdistance.resize(N + 1);
    std::fill(mdistance.begin(), mdistance.end(), LONG_MAX); // 최단거리 배열 초기화

    for (int i = 0; i < M; i++) { // 간선 리스트에 데이터 저장하기
        int start, end, time;
        cin >> start >> end >> time;
        edges.push_back(make_tuple(start, end, time));
    }

    // 벨만포드 알고리즘 수행
    mdistance[1] = 0;
    for (int i = 1; i < N; i++) {  //N보다 하나 적은 수만큼 반복
        for (int j = 0; j < M; j++) {
            edge medge = edges[j];
            int start = get<0>(medge);
            int end = get<1>(medge);
            int time = get<2>(medge);
            // 더 작은 최단거리 가 있는 경우 갱신
            if (mdistance[start] != LONG_MAX && mdistance[end] > mdistance[start] + time) {
                mdistance[end] = mdistance[start] + time;
            }
        }
    }
    bool mCycle = false;
    for (int i = 0; i < M; i++) { // 음수 cycle 확인
        edge medge = edges[i];
        int start = get<0>(medge);
        int end = get<1>(medge);
        int time = get<2>(medge);
        if (mdistance[start] != LONG_MAX && mdistance[end] > mdistance[start] + time) {
            mCycle = true;
        }
    }
    if (!mCycle) { // 음의 cycle이 없는 경우
        for (int i = 2; i <= N; i++) {
            if (mdistance[i] == LONG_MAX)
                cout << -1 << "\n";
            else
                cout << mdistance[i] << "\n";
        }
    }
    else { // 음의 cycle이 있는 경우
        cout << -1 << "\n";
    }
}