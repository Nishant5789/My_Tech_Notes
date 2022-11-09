#include<bits/stdc++.h>
using namespace std;
// void dfs(int vertex, int parent, vector<vector<int>> graph){
//     // Take action on vertex after   
//     // entering the vertex
//     for(auto child: graph[vertex])
//     {
//         // Take action on child before   
//         // entering the child node
//         if(child==parent) continue;
//         dfs(child, vertex)
//         // Take action on child after   
//         // exiting the child node
//     }
//     // Take action on vertex after   
//     // exitting the vertex
// }
void dfs(int vertex, int parent, vector<vector<int>> graph
,vector<int> &deapth, vector<int> &height){

    for(auto child: graph[vertex])
    {
        if(child==parent) continue;
        deapth[child]=deapth[vertex]+1;
        dfs(child, vertex, graph, deapth, height);
        height[vertex]=max(height[vertex], height[child]+1);
    }
}
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
        // graph[temp2].push_back(temp1);
    }
    dfs(0,-1,graph, deapth, height);
    for(int i=0; i<v;i++)
    {
        cout << i <<" 's height is "<< height[i] << endl; 
    }
    for(int i=0; i<v;i++)
    {
        cout << i <<" 's deapth is "<< deapth[i] << endl; 
    }
}
int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0), cout.tie(0);
   
   int t=1;
//    cin >> t;
   while(t--){
     solve();
   }
   // solve();
   return 0;
}