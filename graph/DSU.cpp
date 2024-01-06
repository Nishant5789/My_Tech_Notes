#include <bits/stdc++.h>
using namespace std;
const int N = 1000;

// 5 3
// 1 0
// 1 2
// 3 4

void make(int v)
{
    parent[v] = v;
    size[v] = 1;
}

int find(int v)
{
    if (parent[v] == v)
        return v;
    parent[v] = find(parent[v]);
}

void Union(int a, int b)
{
    a = find(a);
    b = find(b);

    if (a != b)
    {
        if (size[b] > size[a])
            swap(a, b);
        parent[b] = a;
        size[a] += size[b];
    }
}

void solve()
{
    int v, e;
    cin >> v >> e;
    for (int i = 0; i < v; i++)
    {
        make(i);
    }

    for (int i = 1; i <= e; i++)
    {
        int a, b;
        cin >> a >> b;
        Union(a, b);
    }

    int connected_com = 0;
    for (int i = 0; i < v; i++)
    {
        if (parent[i] == i)
            connected_com++;
    }
    cout << connected_com;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    //    int t;
    //    cin >> t;
    //    while(t--){
    //      solve();
    //    }
    solve();
    return 0;
}