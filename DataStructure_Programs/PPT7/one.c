/*
 C program for BFS traversal of graph.

The breadth-first search (BFS) algorithm is used to search a tree or graph data structure for a node that meets a set of criteria. It starts
at the tree�s root or graph and searches/visits all nodes at the current depth level before moving on to the nodes at the next depth level.
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 50

// This struct represents a directed graph using
// adjacency list representation
typedef struct Graph_t {
	int V; // No. of vertices
	bool adj[MAX_VERTICES][MAX_VERTICES];
} Graph;

// Constructor
Graph* Graph_create(int V)
{
	Graph* g = malloc(sizeof(Graph));
	g->V = V;

	for (int i = 0; i < V; i++) {
		for (int j = 0; j < V; j++) {
			g->adj[i][j] = false;
		}
	}

	return g;
}

// Destructor
void Graph_destroy(Graph* g) { free(g); }

// function to add an edge to graph
void Graph_addEdge(Graph* g, int v, int w)
{
	g->adj[v][w] = true; // Add w to v�s list.
}

// prints BFS traversal from a given source s
void Graph_BFS(Graph* g, int s)
{
	// Mark all the vertices as not visited
	bool visited[MAX_VERTICES];
	for (int i = 0; i < g->V; i++) {
		visited[i] = false;
	}

	// Create a queue for BFS
	int queue[MAX_VERTICES];
	int front = 0, rear = 0;

	// Mark the current node as visited and enqueue it
	visited[s] = true;
	queue[rear++] = s;

	while (front != rear) {
		// Dequeue a vertex from queue and print it
		s = queue[front++];
		printf("%d ", s);

		// Get all adjacent vertices of the dequeued
		// vertex s. If a adjacent has not been visited,
		// then mark it visited and enqueue it
		for (int adjecent = 0; adjecent < g->V;
			adjecent++) {
			if (g->adj[s][adjecent] && !visited[adjecent]) {
				visited[adjecent] = true;
				queue[rear++] = adjecent;
			}
		}
	}
}

int main()
{
	// Create a graph given in the above diagram
	Graph* g = Graph_create(4);
	Graph_addEdge(g, 0, 1);
	Graph_addEdge(g, 0, 2);
	Graph_addEdge(g, 1, 2);
	Graph_addEdge(g, 2, 0);
	Graph_addEdge(g, 2, 3);
	Graph_addEdge(g, 3, 3);

	printf("Following is Breadth First Traversal "
		"(starting from vertex 2) \n");
	Graph_BFS(g, 2);

	Graph_destroy(g);

	return 0;
}

