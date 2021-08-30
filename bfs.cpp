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
        map<T, bool> visited;
        queue<T> q;
        
        q.push(src);
        visited[src] = true;
        
        while(!q.empty())
        {
            T node = q.front();
            q.pop();
            cout<<node<<"->"<<" ";
            
            for(T nbr: mp[node])
            {
                if(!visited[node])
                {
                    q.push(nbr);
                    visited[nbr] = true;
                }
            }
        }
    }
};
