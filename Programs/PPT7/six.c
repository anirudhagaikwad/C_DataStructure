/*
C program for Kruskal’s Minimum Spanning Tree Algorithm.


*/
#include<stdio.h>
#include<stdlib.h>

int comparator(const void *p1,const void *p2)//used by qsort()
{
	const int (*x)[3]=p1;
	const int (*y)[3]=p2;

	return (*x)[2]-(*y)[2];
}

void makeSet(int parent[],int rank[],int n)
{
	for(int i=0;i<n;i++)
	{
		parent[i]=i;
		rank[i]=0;
	}
}

int findParent(int parent[],int component)
{
	if(parent[component]==component)
	return component;

	return parent[component]=findParent(parent,parent[component]);
}

void unionSet(int u,int v,int parent[],int rank[],int n)
{
	//this function unions two set on the basis of rank
	//as shown below
	u=findParent(parent,u);
	v=findParent(parent,v);

	if(rank[u]<rank[v])
	{
		parent[u]=v;
	}
	else if(rank[u]<rank[v])
	{
		parent[v]=u;
	}
	else
	{
		parent[v]=u;
		rank[u]++;//since the rank increases if the ranks of two sets are same
	}
}

void kruskalAlgo(int n,int edge[n][3])
{
	//First we sort the edge array in ascending order
	//so that we can access minimum distances/cost
	qsort(edge,n,sizeof(edge[0]),comparator);
	//inbuilt quick sort function comes with stdlib.h
	//go to https://www.geeksforgeeks.org/comparator-function-of-qsort-in-c/
	//if there is any doubt regarding the function

	int parent[n];
	int rank[n];
	makeSet(parent,rank,n);//function to initialize parent[] and rank[]

	int minCost=0;//to store the minimun cost

	printf("Following are the edges in the constructed MST\n");
	for(int i=0;i<n;i++)
	{
		int v1=findParent(parent,edge[i][0]);
		int v2=findParent(parent,edge[i][1]);
		int wt=edge[i][2];

		if(v1!=v2)//if the parents are different that means they are in
				//different sets so union them
		{
			unionSet(v1,v2,parent,rank,n);
			minCost+=wt;
			printf("%d -- %d == %d\n",edge[i][0],edge[i][1],wt);
		}
	}

	printf("Minimum Cost Spanning Tree: %d\n",minCost);
}

int main()
{

	/* Let us create following weighted graph
				10
			0--------1
			| \	 |
			6| 5\ |15
			|	 \ |
			2--------3
				4	 */

	//Here 5 is the number of edges, can be asked from the user
	//when making the graph through user input
	//3 represents the no of index positions for storing u --> v(adjacent vertices)
	//and its cost/distance;
	int edge[5][3]={{0,1,10},
					{0,2,6},
					{0,3,5},
					{1,3,15},
					{2,3,4}};

	kruskalAlgo(5,edge);
}

