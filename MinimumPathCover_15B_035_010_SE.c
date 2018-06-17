    #include<stdio.h>
    #include<conio.h>
     
    void Dijkstra(int Graph[20][20],int vertice_count,int start_vertice);
     
    int main()
    {
        int Graph[20][20]; //Graph[] makes a matrix for graph
        int row;
        int col;
        int vertice_count;//vertice_count was the number of vertices in a graph
        int start_vertice; //start_vertice is the starting node
    													  
        printf("Please enter max number of vertices:");
        scanf("%d",&vertice_count);	//	input for max number of vertices.	
    	
        printf("\nPlease enter the matrix:\n");    
        for(row=0;row<vertice_count;row++)
    	{		
            for(col=0;col<vertice_count;col++)
    		{
                scanf("%d",&Graph[row][col]);
    		}
    	}//a matrix was formed from user input
        printf("\nStarting node of the graph:");
        scanf("%d",&start_vertice);//start node of the graph traversal
        Dijkstra(Graph,vertice_count,start_vertice);// the input was provided to the function as parameters   
        getch(); 
        return 0;
    }
     
    void Dijkstra(int Graph[20][20],int vertice_count,int start_vertice)
    {
     
        int cost[20][20];//create cost i.e. given distances and infinite distance if not given
        int dist[20];//total distance of vertex from source node
        int pred[20];//pred[] stores the predecessor of each node
        int visited[20];// add the visited node for path tracing
        int count;//count gives the number of nodes seen so far
        int min_dist;// minimum distance
        int next_vertice;//next node to tbe traversed
        int row;
        int col;
        
        
        
        
        for(row=0;row<vertice_count;row++)
    	{
            for(col=0;col<vertice_count;col++)
    		{
                if(Graph[row][col]!=0)
    			{
                   cost[row][col]=Graph[row][col]; // if the distance is given, fine
                    
    			}
                else
    			{
                    cost[row][col]=999;// else assign distance infinity
    			}
    		}
        }//cost matrix created here
        
        
    	
        for(row=0;row<vertice_count;row++)
        {
            dist[row]=cost[start_vertice][row];//calculate dist 
            pred[row]=start_vertice;	// predecessor of each vertex
            visited[row]=0;	//first visit
        }
        
        dist[start_vertice]=0;
        visited[start_vertice]=1;
        count=1;
        
        while(count<vertice_count-1)//till all vertices traversed
        {
            min_dist=999;
            
            //nextnode gives the node at minimum dist
            for(row=0;row<vertice_count;row++)
    		{
                if(dist[row]<min_dist&&!visited[row])//if dist is less than min_dist and the node is not visited
                {
                    min_dist=dist[row];
                    next_vertice=row;
                }
            } 
                //checks whether a smaller path exists via nextnode            
                visited[next_vertice]=1;
                for(row=0;row<vertice_count;row++)
    			{
                    if(!visited[row])//if vertex is not visited
                        if(min_dist+cost[next_vertice][row]<dist[row]) //and min_distance and cost is lower than current distance, update
                        {
                            dist[row]=min_dist+cost[next_vertice][row];
                            pred[row]=next_vertice;
                        }
    			}
    		
            count++; //increment the counter of nodes seen
        }
     
        //print path and distance of each vertex
        for(row=0;row<vertice_count;row++)
    	{
            if(row!=start_vertice)
            {
                printf("\nDistance of vertex %d is %d",row,dist[row]);
                printf("\nTraversing path =%d",row);                
                col=row;
                do
                {
                    col=pred[col];//get and print each predecessor
                    printf("<-%d",col);
                }
    			while(col!=start_vertice);//till start_vertice reached
            
            }
    	}
    }
