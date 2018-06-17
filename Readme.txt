MINIMUM PATH COVER

Dijkstra calculation is likewise called single source minimum path cover algorithm. It depends on Greedy technique. The algorithm keeps up a rundown visited[ ] of vertices, whose minimum path from the source is already known.

1. Enter the Matrix M[ ][ ]. In matrix M[row][col] is the cost of going from vertex 'row' to vertex 'col'. In the event that there is no edge between vertices 'row' and 'col' at that point C[row][col] is infinity. 
 
2. Array visited[ ] is instated to zero. 
               for(row=0;row<n;row++)
                              visited[row]=0;
 
3. In the event that the vertex 0 is the source vertex then visited[0] is set apart as 1. 
 
4. Make the path matrix, by putting away the cost of vertices from vertex no. 0 to n-1 from the source vertex 0. 
               for(row=1;row<n;row++)
                              path[row]=cost[0][row];

At first, separation of source vertex is taken as 0. i.e. path[0]=0; 
 
5. for(row=1;row<n;row++)


– Choose a vertex a, with the end goal that path[a] is least and visited[a] is 0. Mark visited[a] as 1. 
– Recalculate the minimum path of remaining vertices from the source.
– Only, the vertices not set apart as 1 in array visited[ ] ought to be considered for recalculation of way. i.e. for every vertex b 
          if(visited[b]==0)
                              path[b]=min(path[b],
                              path[a]+cost[a][b])

Time Complexity

The program contains two nested loops each of which has a complexity of O(n). n is number of vertices. So the complexity of algorithm is O(V^2).


GROUP MEMBERS:

AREEBA ASIF 15B-035-SE
HIBA KHALID 15B-010-SE