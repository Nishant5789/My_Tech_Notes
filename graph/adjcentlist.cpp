#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;


// template is very usefull in industry
// template<typename T>

// test case
// 5 6
// 0 1
// 1 2
// 2 3
// 3 1
// 3 4
// 0 4
class graph{
public:
    unordered_map<int,list<int >> adj;
    
        // if we use int 
        // void addEdge(T u,T v,bool direction){
    void addEdge(int u,int v,bool direction){
        // direction=0->undirected
        // direction=1->directed graph
        // create an edge from u to v
        adj[u].push_back(v);
        if(direction == 0)
                adj[v].push_back(u);
    }

    void printadjlist()
    {
        for(auto i: adj)
        {
            cout << i.first << "-> ";
            for(auto j:i.second)
            {
                cout << j << " ";
            }
            cout << endl;
        }
    }
};

int main()
{

    int n;
    cout << "number of nodes" << endl;
    cin >> n;
    cout << "number of edges" << endl;
    int m;
    cin >> m;

    graph g;
    // if we use template;
    // graph<int> g;
    for(int i=0; i<m; i++)
    {
        int u, v;
        cin >> u >> v;
        g.addEdge(u,v,0);
    }
    g.printadjlist();
    return 0;
}
