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
    
    void bfs(T src)
    {
        map<T, int> dist;
        queue<T> q;
        
        
        for(auto node_pair: mp)
        {
            T node = node_pair.first;
            dist[node] = INT_MAX;
        }
        q.push(src);
        dist[src] = 0;
        
        
        while(!q.empty())
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
        }
    }
};
