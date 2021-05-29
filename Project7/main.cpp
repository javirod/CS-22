/*
CS 22, Prof Tahir Aziz 
Name: Javier Rodriguez
Assignment: Project 7
Due Date: 30 MAY 2021
*/
// Problem 2: Write a program that outputs the nodes 
// of a graph in a breadth first traversal.

#include<iostream>
#include<fstream>
#include<list>
// #include<queue>
using namespace std;

class Graph
{
	int V;
	list<int>* adj;
	void DFTUtil(int v, bool visited[]);
	void BFTUtil(int v, bool visited[]);

public:
	Graph(int V);
	void addEdge(int v, int w);
	void addEdgeWeight(int v, int w);
	void DFT(int v);
	void BFT();
    void createGraph();
};

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w);
}

void Graph::DFTUtil(int v, bool visited[])
{
	visited[v] = true;
	cout << v << " ";
	list<int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i)
	{
		if (!visited[*i])
		{
			DFTUtil(*i, visited);
		}
	}
}

void Graph::DFT(int v)
{
	bool* visited = new bool[V];
	for (int i = 0; i < V; i++)
	{
		visited[i] = false;
	}
	DFTUtil(v, visited);
}

void Graph::BFT()
{
    list<int> queueList;
    bool* visited = new bool[V];
    for(int i = 0; i < V; i++)
    {
        visited[i] = false;
    }

    list<int>::iterator i;

    for(int index = 0; index < V; index++)
    {
        if(!visited[index])
        {
            queueList.push_back(index);
            visited[index] = true;
            // cout << " " << index << " ";

            while(!queueList.empty())
            {
                int u = queueList.front();
                cout << u << " ";
                queueList.pop_front();
                for (i = adj[u].begin(); i != adj[u].end(); ++i)
	            {
                    int w = *i;
                    if (!visited[w])
                    {
                        queueList.push_back(w);
                        visited[w] = true;
                        // cout << " " << u << " ";
                    }
                }
            }
        }
    }

}
void Graph::createGraph()
{
    int gSize;  //current number of vertices
    int index;
    int vertex;
    int adjacentVertex;

    ifstream infile;
    infile.open("data.txt");

    if(!infile)
    {
        cout << "Cannot open input file." << endl;
        return;
    }

    infile >> gSize;    //get the number of vertices
    cout << "Number of vertices: " << gSize << endl;

    for(index = 0; index < gSize; index++)
    {
        infile >> vertex;
        infile >> adjacentVertex;

        cout << "Vertex: " << vertex << "\t";
        if (adjacentVertex != -999)
        {
            cout << "Adjacent Vertex: " << adjacentVertex << " ";
        }
        else{
            cout << "Adjacent Vertex: N/A" << " ";
        }
        
        while(adjacentVertex != -999)
        {
            addEdge(vertex, adjacentVertex);
            infile >> adjacentVertex;
            if (adjacentVertex != -999)
                cout << adjacentVertex << " ";
        }
        cout << endl;
    }
}

int main()
{
	Graph g(10);
    int adjWeights[10][10] ={
                                {0, 1, 0, 2, 0, 0, 0, 0, 0, 0},
                                {0, 0, 0, 0, 3, 0, 0, 0, 0, 0},
                                {0, 0, 0, 0, 0, 5, 0, 0, 0, 0},
                                {0, 0, 4, 0, 0, 0, 0, 0, 0, 0},
                                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                {0, 0, 0, 0, 0, 0, 0, 6, 7, 0},
                                {0, 0, 0, 0, 8, 0, 0, 9, 0, 0},
                                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                {0, 0, 0, 0, 0, 0, 0, 10, 11, 0}};
    g.createGraph();

	cout << "\nFollowing is Breadth First Traversal:\n\n";
	// g.DFT(0);
    g.BFT();
	cout << endl << endl;
    cout << "0 -> 1 -> 4" << endl;
    int total1 = adjWeights[0][1] + adjWeights[1][4];
    cout << "Total Path Weight: " << total1 << endl << endl;

    cout << "0 -> 3 -> 2 -> 5 -> 7" << endl;
    int total2 = adjWeights[0][3] + adjWeights[3][2] + adjWeights[2][5] + adjWeights[5][7];
    cout << "Total Path Weight: " << total2 << endl << endl;

    cout << "0 -> 3 -> 2 -> 5 -> 8" << endl;
    int total3 = adjWeights[0][3] + adjWeights[3][2] + adjWeights[2][5] + adjWeights[5][8];
    cout << "Total Path Weight: " << total3 << endl << endl;

    cout << "6 -> 4" << endl;
    int total4 = adjWeights[6][4];
    cout << "Total Path Weight: " << total4 << endl << endl;

    cout << "6 -> 7" << endl;
    int total5 = adjWeights[6][7];
    cout << "Total Path Weight: " << total5 << endl << endl;

    cout << "9 -> 7" << endl;
    int total6 = adjWeights[9][7];
    cout << "Total Path Weight: " << total6 << endl << endl;

    cout << "9 -> 8" << endl;
    int total7 = adjWeights[9][8];
    cout << "Total Path Weight: " << total7 << endl << endl;

	system("pause");
}