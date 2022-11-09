que link - https://www.codechef.com/problems/SNSOCIAL

more que - https://leetcode.com/problems/rotting-oranges/submissions/
https://codeforces.com/contest/1283/problem/D
https://codeforces.com/contest/1272/problem/E

#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> v = {{+1, +1}, {+1, -1}, {-1, +1}, {-1, -1}, {0, +1}, {0, -1}, {+1, 0}, {-1, 0}};

bool check(int x, int y, int n, int m)
{
    if(x>=0 && x<n && y>=0 && y<m) return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);    

    int t;
    cin>>t;
    while(t--)
    {
        int n, m, maxA = INT_MIN;
        cin>>n>>m;

        int a[n][m];

        vector<vector<int>> level;
        level.resize(n+1, vector<int> (m+1, INT_MAX));

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
                maxA = max(maxA, a[i][j]);
            }
        }

        queue<pair<int,int>> q;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(a[i][j]==maxA)
                {
                    q.push({i,j});
                    level[i][j] = 0;
                }
            }
        }

        while(q.size()!=0)
        {
            pair<int,int> front = q.front();
            int x = front.first, y = front.second;
            q.pop();

            for(auto value: v)
            {
                int x1 = x + value.first, y1 = y + value.second;
                if(check(x1,y1,n,m)==0) continue;

                if(level[x][y]+1 < level[x1][y1])
                {
                    level[x1][y1] = level[x][y]+1;
                    q.push({x1,y1});
                }
            }
        }

        maxA = INT_MIN;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                maxA = max(maxA, level[i][j]);
            }
        }

        cout<<maxA<<endl;
    }
}
