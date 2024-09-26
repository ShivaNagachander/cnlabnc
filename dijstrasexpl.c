#include <stdio.h>
#define INFINITY 9999  // Define a large value to represent unreachable nodes
#define MAX 10         // Maximum number of vertices allowed

// Dijkstra's algorithm function prototype
void dijkstra(int G[MAX][MAX], int n, int startnode);

int main() {
    int G[MAX][MAX], i, j, n, u;  // G is the graph (adjacency matrix), n is the number of vertices, u is the starting node
    printf("\nEnter the number of vertices: ");
    scanf("%d", &n);  // Input the number of vertices

    printf("\nEnter the adjacency matrix:\n");
    for (i = 0; i < n; i++) {  // Loop to input the adjacency matrix
        for (j = 0; j < n; j++) {
            scanf("%d", &G[i][j]);  // Adjacency matrix input, where G[i][j] represents the weight of the edge from i to j
        }
    }

    printf("\nEnter the starting node: ");
    scanf("%d", &u);  // Input the starting node for the algorithm
    dijkstra(G, n, u);  // Call the Dijkstra function
    return 0;
}

void dijkstra(int G[MAX][MAX], int n, int startnode) {
    int cost[MAX][MAX], distance[MAX], pred[MAX];  // Cost matrix, distance array, and predecessor array
    int visited[MAX], count, mindistance, nextnode, i, j;  // Arrays and variables for tracking nodes and distances

    // Create the cost matrix from the adjacency matrix
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (G[i][j] == 0) {
                cost[i][j] = INFINITY;  // If no edge exists, set cost to INFINITY
            } else {
                cost[i][j] = G[i][j];  // Otherwise, use the actual edge weight
            }
        }
    }

    // Initialize the distance, predecessor, and visited arrays
    for (i = 0; i < n; i++) {
        distance[i] = cost[startnode][i];  // Distance from the start node to itself is 0
        pred[i] = startnode;  // Initially set all predecessors to the start node
        visited[i] = 0;  // Mark all nodes as unvisited
    }

    distance[startnode] = 0;  // Distance from start node to itself is 0
    visited[startnode] = 1;  // Mark the start node as visited
    count = 1;  // Initialize the count of visited nodes

    // Main loop runs until all nodes are visited
    while (count < n - 1) {
        mindistance = INFINITY;  // Reset mindistance for finding the next closest node

        // Find the next node with the minimum distance
        for (i = 0; i < n; i++) {
            if (distance[i] < mindistance && !visited[i]) {
                mindistance = distance[i];  // Update the mindistance
                nextnode = i;  // Set the nextnode as the node with the smallest distance
            }
        }

        visited[nextnode] = 1;  // Mark the nextnode as visited

        // Update distances for the neighboring nodes of the nextnode
        for (i = 0; i < n; i++) {
            if (!visited[i]) {  // Only consider unvisited nodes
                if (mindistance + cost[nextnode][i] < distance[i]) {
                    distance[i] = mindistance + cost[nextnode][i];  // Update the shortest distance
                    pred[i] = nextnode;  // Set the predecessor for node i
                }
            }
        }
        count++;  // Increment the count of visited nodes
    }

    // Print the results: distances and paths from the startnode to every other node
    for (i = 0; i < n; i++) {
        if (i != startnode) {
            printf("\nDistance of node %d = %d", i, distance[i]);  // Display the distance to node i
            printf("\nPath = %d", i);  // Display the path to node i
            j = i;
            do {
                j = pred[j];  // Trace back the path using the predecessor array
                printf(" <- %d", j);
            } while (j != startnode);  // Repeat until reaching the startnode
        }
    }
}
