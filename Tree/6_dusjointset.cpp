#include<bits/stdc++.h>
using namespace std;


// que link- 
void makeset(vector<int> &parent,vector<int> &size,multiset<int> &ans, int n)
{
    for(int i=0; i<n; i++)
    {
        parent[i]=i;
        size[i]=1;
        ans.insert(1);
    }
}
int findparent(vector<int> &parent, int node)
{
    if(parent[node]== node)
        return node;
    // for compress the path
    return  parent[node] = findparent(parent,  parent[node]);
}
void merge(int u, int v, vector<int> &size, multiset<int>& ans)
{
    ans.erase(ans.find(size[u]));
    ans.erase(ans.find(size[v]));
    ans.insert(size[u]+size[v]);
}
void unionset(int u, int v, vector<int> &parent, vector<int> &size, multiset<int> &ans)
{
    u = findparent(parent, u);
    v = findparent(parent, v);
    merge(u, v, size, ans);
    if(u!=v)
    {
        if(size[u]<size[v])
            swap(u,v);
        parent[v]=u;
        size[u]+=size[v];
    }
}
int main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0), cout.tie(0);

    int n, k;
    cin >> n >> k;
    vector<int> parent(n);
    vector<int> size(n);
    multiset<int> ans;
    makeset(parent, size, ans, n);
    
    for(int i=0; i<k; i++)
    {
        int temp1, temp2;
        cin >> temp1 >> temp2;
        unionset(temp1-1, temp2-1, parent, size, ans);
        int start = *ans.begin(), end = *(--ans.end());
        if(ans.size()==1)
        {
            cout << 0 << endl;
        }
        else
        {
            cout << end-start << endl;
        }
    }

   return 0;
}