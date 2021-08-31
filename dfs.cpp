#include <iostream>
#include <map>
#include <queue>
using namespace std;

template <typename T>

class Graph
{
    map<T, list<T>> mp;   // key is node and list are its neighbours
    
    public:
    void addEdge(T x, T y)
    {
        mp[x].push_back(y);
        mp[y].push_back(x);
    }
    
    void dfs_helper(T src, map<T, bool>&visited )
    {
       cout<<src<<" ";
       visited[src] = true;
       for(T nbr: mp[src])
       {
           if(!visited[nbr])
           {
               dfs_helper(nbr, visited);
           }
       }
    }
    
    void dfs(T src)
    {
        map<T, int> visited;
        queue<T> q;
        
        
        for(auto node_pair: mp)
        {
            T node = node_pair.first;
            visited[node] = false;
        }
        dfs_helper(src, visited);
        
        /*while(!q.empty())
        {
            T node = q.front();
            q.pop();
            cout<<node<<"->"<<" ";
            
            for(T nbr: mp[node])
            {
                if(dist[node] == INT_MAX)
                {
                    q.push(nbr);
                    dist[nbr] = dist[node]+1;
                }
            }
        }*/
    }
};
