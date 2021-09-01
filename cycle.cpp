bool cycle_helper(int node, bool *visited, int parent)
{
    visited[node] = true;
    for(auto nbr: mp[node])
    {
        if(!visited[nbr])
        {
            bool got = cycle_helper(nbr, visited, node);
            if(got) return true;
        }
        else if(nbr!=parent)
        {
            return true;
        }
        
        return false;
    }
}

bool contain_cycle()
{
    bool *visited = new bool[V];
    for(int i=0; i<V; i++)
    {
        visisted[i] = false;
    }
    
    cycle_helper(0, visited, -1);
}
