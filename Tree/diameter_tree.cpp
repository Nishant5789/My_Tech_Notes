#include<bits/stdc++.h>
using namespace std;


void dfs(int v, int parent,vector<vector<int>> graph,
vector<int> &depth)
{
    for(auto child: graph[v])
    {
        if(child==parent) continue;
        depth[child]=depth[v]+1;
        dfs(child, v, graph, depth);
    }
}

void solve()
{
    int v;
    cin >> v;
    vector<vector<int>> graph(v);
    vector<int> depth(v,0);
    for(int i=0; i<v-1; i++)
    {
        int temp1,temp2;
        cin >> temp1 >> temp2;
        graph[temp1-1].push_back(temp2-1);
        graph[temp2-1].push_back(temp1-1);
    }
    dfs(0,-2, graph, depth);
    // int k=1;
    // for(auto i: depth)
    // {
    //     cout << k++ << "- "<< i <<endl;
    // }
    int maxi_depth=-1,pre_depth=-1,maxi_v=-1;
    for(int i=0; i<v; i++)
    {  
        maxi_depth=max(maxi_depth, depth[i]);
        if(maxi_depth!=pre_depth)
        {
            maxi_v=i;
            pre_depth=maxi_depth;
        }
        depth[i]=0;
    }
    // cout << maxi_v << " ";
    dfs(maxi_v, -1, graph, depth);

    maxi_depth=-1;
    for(int i=0; i<v; i++)
    {  
        maxi_depth=max(maxi_depth, depth[i]);
    }  
    cout << maxi_depth << endl;
}

int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0), cout.tie(0);
   
   solve();
   return 0;
}