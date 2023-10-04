// /*

//  */
// #include <bits/stdc++.h>
// using namespace std;

// void solve(vector<int> adj[], int source, bool visited[])
// {
//     visited[source] = true;
//     cout << source << endl;

//     for (int u : adj[source])
//         if (visited[u] == false)
//             solve(adj, u, visited);
// }

// void dfs(vector<int> adj[], int v, int source)
// {
//     bool visited[v];
//     for (int i = 0; i < v; i++)
//     {
//         visited[i] == false;
//     }
//     solve(adj, source, visited);
// }

// int main()
// {
//     solve();
//     return 0;
// }

// // To detect cycle using the dfs in a graph we say that we will check if the same vertex is repeated again from the  visited array, if it is the same vertex then it is called to have a cycle present in it.
// // and also we have to see that it is the same parent or not.

// function(vector<int> adj[], int source, bool visited[], int parent)
// {
//     visited[source] = true;
//     for
//         every adjacent u in source
//         {
//             if (visited[u] == false)
//             {
//                 if (dfsrec(adj, u, source, visited) == true)
//                     return true;
//                 else if (u != parent)
//                     return true;
//             }
//         }
//     return false;
// }
