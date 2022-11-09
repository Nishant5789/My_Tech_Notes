#include<bits/stdc++.h>
using namespace std;

// problem set - https://www.hackerearth.com/challenges/competitive/code-monk-disjoint-set-union/problems/

// code link - https://www.hackerearth.com/practice/data-structures/disjoint-data-strutures/basics-of-disjoint-data-structures/practice-problems/algorithm/city-and-flood-1/
void makeset(vector<int> &parent, int n, vector<int> size)
void makeset(vector<int> &parent, int n)
{
    for(int i=0; i<n; i++)
    {
        parent[i]=i;
//         size[i]=1;
    }
}

int findparent(vector<int> &parent, int node)
{
    if(parent[node]== node)
        return node;
    // for compress the path
    return  parent[node] = findparent(parent,  parent[node]);
}
// void unionset(int u, int v, vector<int> &parent, vector<int> size)
void unionset(int u, int v, vector<int> &parent)
{
    u = findparent (parent, u);
    v = findparent (parent, v);
    parent[v]=u;
    if(u!=v)
        size[u]+=size[v];
}

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<vector<int>> edges(n);
    vector<int> parent(n);
    makeset(parent, n);
    for(int i=0; i<k; i++)
    {
        int temp1, temp2;
        cin >> temp1 >> temp2;
        unionset(temp1-1, temp2-1 , parent);
    }
    int ct=0;
    for(int i=0; i<n; i++)
    {
        if(parent[i]==i)
        ct++;
    }
    cout << ct << endl;
}
int main(){
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
