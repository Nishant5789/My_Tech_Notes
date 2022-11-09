#include<bits/stdc++.h>
using namespace std;

// solution - https://github.com/SuryankDixit/Problem-Solving/blob/master/GRAPH/CSES/08-shortest-route-1.cpp


    void dijkstra(int n, int source, vector<pair<int,int>> graph[])
    {
        vector<int> distance(n+1,INT_MAX);
        vector<bool>visited(n+1,false);
        set<pair<int,int>> st;
        st.insert({0,source});
        distance[source]=0;
        while(st.size()>0)
        {
            auto node = *st.begin();
            int v=node.second, dist = node.first;
            st.erase(st.begin());
            
            if(visited[v]) continue;
            visited[v]=true;
            for(auto child : graph[v])
            {
                int wt=child.second, child_v = child.first;
                // cout << wt << " " << child_v<< endl;
                if(distance[v]+wt < distance[child_v])
                {
                    distance[child_v]=distance[v]+wt;
                    st.insert({distance[child_v],child_v});
                }
            }
        }
        for(int i=1;i<=n; i++)
        {
            cout << distance[i] << " ";
        }
    }
void solve(){
    int n, k; 
    cin >> n >> k;
    vector<pair<int,int>> graph[n+1];
    
    for(int i=0; i<k; i++)
    {
        int x, y, wt;
        cin >> x >> y >> wt;
        graph[x].push_back({y,wt});
    }
    dijkstra(n, 1, graph);
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
