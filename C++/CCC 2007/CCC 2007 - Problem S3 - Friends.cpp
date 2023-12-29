#include <bits/stdc++.h>

using namespace std;

bool visited[10000] = { false };
bool dfs(int start, int end, vector<int> matrix[]) {
    stack<int> st;
    int count = 0;

    st.push(start);
    while (!st.empty()) {
        int s = st.top();
        st.pop();
        if (!visited[s]) {
            count++;
            for (auto k : matrix[s])
                st.push(k);
        }
    }
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    int x, y;

    cin >> n;
    vector<int> matrix[n + 1];
    for (int z = 0; z < n; z++) {
        cin >> x >> y;
        matrix[x].push_back(y);
    }

    cin >> x >> y;
    while (x != 0 || y != 0)
        dfs(x, y, matrix);

    return 0;
}