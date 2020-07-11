#include "Graph.hpp"
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

void Graph::addEdge(string v1, string v2, int num)
{
    for (unsigned int i = 0; i < vertices.size(); i++)
    {
        if (vertices[i]->name == v1)
        {
            for (unsigned int j = 0; j < vertices.size(); j++)
            {
                if (vertices[j]->name == v2 && i != j)
                {
                    adjVertex av;
                    av.v = vertices[j];
                    av.weight = num;
                    vertices[i]->adj.push_back(av);
                    //another vertex for edge in other direction
                    adjVertex av2;
                    av2.v = vertices[i];
                    av2.weight = num;
                    vertices[j]->adj.push_back(av2);
                }
            }
        }
    }
}

void Graph::addVertex(string n)
{
    bool found = false;
    for (unsigned int i = 0; i < vertices.size(); i++)
    {
        if (vertices[i]->name == n)
        {
            found = true;
            cout << vertices[i]->name << " found." << endl;
        }
    }
    if (found == false)
    {
        vertex *v = new vertex;
        v->name = n;
        v->distance = 0;
        vertices.push_back(v);
    }
}

void Graph::displayEdges()
{
    //loop through all vertices and adjacent vertices
    // cout<<"here"<<vertices.size()<<endl;
    for (unsigned int i = 0; i < vertices.size(); i++)
    {

        cout << vertices[i]->name << ":" << endl;

        for (unsigned int j = 0; j < vertices[i]->adj.size(); j++)
        {
            cout << " --> " << vertices[i]->adj[j].v->name << " " << vertices[i]->adj[j].weight << endl;
        }

        cout << endl;
    }
}

void Graph::_grader_print_shortest_distance(string destination)
{
    for (unsigned int i = 0; i < vertices.size(); i++)
    {
        if (vertices[i]->name == destination)
        {
            cout << vertices[i]->name << " (" << vertices[i]->distance << ")" << endl;
        }
    }
}

// resets for when I use dijsktra's again
void Graph::_grader_setAllVerticesUnvisited()
{
    unsigned int i;
    for (i = 0; i < vertices.size(); i++)
    {
        vertices[i]->visited = false;
        vertices[i]->distance = 0;
    }
}

vertex *searchVertex(string start, vector<vertex *> &vertices)
{
    vertex *vStart;
    for (unsigned int i = 0; i < vertices.size(); i++)
    {
        if (vertices[i]->name == start)
            vStart = vertices[i];
    }
    return vStart;
}

void Graph::dijkstraTraverse(string start)
{
    // to be completed
    // must use searchVertex() for the source (see implementation above)
    vertex *vStart, *vEnd;
    
    start->visited = true;


}