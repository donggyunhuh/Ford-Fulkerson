#include <bits/stdc++.h> // 헤더파일 모음

constexpr int MAX = 10 + 1;
constexpr int INF = 999999999;

std::vector<int> adj[MAX];
int c[MAX][MAX], f[MAX][MAX];

void makeGraph(int a, int b, int capacity)
{ //그래프를 입력 후 배열로 저장
    adj[a].push_back(b);
    adj[b].push_back(a);
    c[a][b] = capacity;
    c[b][a] = 0;
}
int FordFulkerson(int start, int end)
{ // 시작 정점, 도착 정점 입력 (S, T)
    int result = 0;

    while (true)
    { // queue 를 이용하여 정점 탐색
        std::vector<int> dist(MAX, -1);
        std::queue<int> q;
        q.push(start); // 첫번째 정점

        while (!q.empty())
        {
            int current = q.front();
            q.pop();

            for (int i = 0; i < adj[current].size(); ++i)
            {
                int next = adj[current][i];

                if (c[current][next] - f[current][next] > 0 && dist[next] == -1) //잔여 유량이 있는 경우
                {
                    dist[next] = current; // queue에 다음 정점 넣음
                    q.push(next);
                    if (next == end) // 다 탐색 할 때 까지
                        break;
                }
            }
        }

        if (dist[end] == -1)
            break;

        int flow = INF;
        for (int i = end; i != start; i = dist[i])
            flow = std::min(flow, c[dist[i]][i] - f[dist[i]][i]);

        for (int i = end; i != start; i = dist[i])
        {
            f[dist[i]][i] += flow; //정방향 + 유량
            f[i][dist[i]] -= flow; //역방향 - 유량
        }

        result += flow;
    }

    return result;
}
int main()
{
    makeGraph(1, 2, 2);
    makeGraph(1, 3, 2);
    makeGraph(2, 4, 3);
    makeGraph(3, 4, 1);
    makeGraph(2, 3, 2);

    std::cout << FordFulkerson(1, 4); // 출력
}