

// given q queries
// in each auery given v,
// print subtree sum of number of even numbers
// in subtree v
#include<bits/stdc++.h>
using namespace std;

void solve(){
    int v;
    cin >> v;
    vector<vector<int>> graph(v);
    vector<int> deapth(v,0), height(v,0);

    for(int i=0; i<v-1; i++)
    {
        int temp1,temp2;
        cin >> temp1 >> temp2;
        graph[temp1].push_back(temp2);
    }
    int query;
    while(query--)
    {
        int v;
        cin >> v;
        // dfs(v);
        // dfs2(v)
    }
    
  
}
int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0), cout.tie(0);
 
   solve();
   return 0;
}