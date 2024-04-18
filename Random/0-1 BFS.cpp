#include <bits/stdc++.h>

using namespace std;

struct node_n_distance
{
    int node;
    int distance;
    node_n_distance(int node, int distance) : node(node), distance(distance) {}
};

vector<int> bfs(int &vertices, vector<vector<int>> &adj, int &source)
{
    // vector<int> ans(vertices, INT_MAX);
    vector<int> dist(vertices, INT_MAX);
    deque<node_n_distance> dq;
    dq.push_back(node_n_distance(source, 0));

    while (!dq.empty())
    {
        node_n_distance cur = dq.front();
        dq.pop_front();
        // ans[cur.node] = cur.distance;

        for (int i = 0; i < vertices; i++)
        {
            // if (ans[i] != INT_MAX)
            //     continue;
            if (adj[cur.node][i] == 0 && dist[i] > cur.distance)
            {
                dq.push_front(node_n_distance(i, cur.distance));
                dist[i] = cur.distance;
            }
            if (adj[cur.node][i] == 1 && dist[i] > cur.distance + 1)
            {
                dq.push_front(node_n_distance(i, cur.distance + 1));
                dist[i] = cur.distance + 1;
            }
        }
    }
    return dist;
}

int main()
{
    int vertices;
    cin >> vertices;
    vector<vector<int>> adj(vertices, vector<int>(vertices, INT_MAX));
    int edges;
    cin >> edges;
    while (edges--)
    {
        int a;
        cin >> a;
        int b;
        cin >> b;
        int c;
        cin >> c;
        if (adj[a][b] < c)
            continue;
        adj[a][b] = c;
        adj[b][a] = c;
    }
    int source;
    cin >> source;

    vector<int> ans = bfs(vertices, adj, source);
    for (int i = 0; i < ans.size(); i++)
        cout << i << " : " << ans[i] << endl;

    return 0;
}
