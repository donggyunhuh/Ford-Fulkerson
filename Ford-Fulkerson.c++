#include <bits/stdc++.h> // ������� ����

constexpr int MAX = 10 + 1;
constexpr int INF = 999999999;

std::vector<int> adj[MAX];
int c[MAX][MAX], f[MAX][MAX];

void makeGraph(int a, int b, int capacity)
{ //�׷����� �Է� �� �迭�� ����
    adj[a].push_back(b);
    adj[b].push_back(a);
    c[a][b] = capacity;
    c[b][a] = 0;
}
int FordFulkerson(int start, int end)
{ // ���� ����, ���� ���� �Է� (S, T)
    int result = 0;

    while (true)
    { // queue �� �̿��Ͽ� ���� Ž��
        std::vector<int> dist(MAX, -1);
        std::queue<int> q;
        q.push(start); // ù��° ����

        while (!q.empty())
        {
            int current = q.front();
            q.pop();

            for (int i = 0; i < adj[current].size(); ++i)
            {
                int next = adj[current][i];

                if (c[current][next] - f[current][next] > 0 && dist[next] == -1) //�ܿ� ������ �ִ� ���
                {
                    dist[next] = current; // queue�� ���� ���� ����
                    q.push(next);
                    if (next == end) // �� Ž�� �� �� ����
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
            f[dist[i]][i] += flow; //������ + ����
            f[i][dist[i]] -= flow; //������ - ����
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

    std::cout << FordFulkerson(1, 4); // ���
}