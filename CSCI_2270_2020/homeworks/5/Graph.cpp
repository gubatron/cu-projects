#include "Graph.hpp"
#include <vector>
#include <queue>
#include <iostream>
#include <limits> // to get the maximum value of an int

#define INFINITY std::numeric_limits<int>::max()

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
        //vertices[i]->distance = 0; //don't do more than you need to
    }
}

vertex *searchVertex(string start, vector<vertex *> &vertices)
{
    vertex *vStart;
    for (unsigned int i = 0; i < vertices.size(); i++)
    {
        if (vertices[i]->name == start)
            return vStart = vertices[i];
    }
    return NULL;
}

bool haveAllNodesBeenVisited(vector<vertex*> vertices) {
  for (auto v : vertices) {
    if (!v->visited) {
      return false;
    }
  }
  return true;
}

vertex* getUnvisitedVertexWithMinimumDistance(vector<vertex*> vertices) {
  vertex* result = NULL;
  for (int i=0; i < vertices.size(); i++) {
    vertex* v = vertices[i];

    // skip visited, we're only interested in unvisited
    if (v->visited) {
      continue;
    }
    if (result == NULL) {
      result = v;
    }
    if (v->distance < result->distance) {
      result = v;
    }
  }
  return result;
}

/**
 * Sets distance INFINITY for all vertices.
 */
void setDistancesToInfinity(vector<vertex*> vertices) {
  for (auto v : vertices) {
    v->distance = INFINITY;
  }
}

void setPredecesorsToNull(vector<vertex*> vertices) {
  for (auto v : vertices) {
    v->pred = NULL;
  }
}

//
// My C++ adaption to the python implementation at
// https://dev.to/mxl/dijkstras-algorithm-in-python-algorithms-for-beginners-dkc
//
void Graph::dijkstraTraverse(string start)
{
  // Find the corresponding start vertex
  vertex *vStart;        
  vStart = searchVertex(start, this->vertices);
  if (vStart == NULL) {
    cout << "ERROR dijkstraTraverse: cannot traverse from non-existent node '"<< start << "'" << endl;
    return;
  }
  // Mark all vertices unvisited
  // Set distance to start as infinity on all vertices
  // Set predecesors to null
  _grader_setAllVerticesUnvisited();
  setDistancesToInfinity(this->vertices);
  setPredecesorsToNull(this->vertices);

  // Starting node should have distance 0 to itself.
  vStart->distance = 0;

  while (!haveAllNodesBeenVisited(this->vertices)) {
    // Select the unvisited vertex with the smallest distance to the start
    // as the current vertex.
    auto current_vertex = getUnvisitedVertexWithMinimumDistance(this->vertices);

    // Abort if something went wrong
    if (current_vertex == NULL) {
     cout << "dijkstraTraverse: check your logic, getVertexWithMinimumDistance == NULL" << endl;
     return;
    }

    // Find unvisited neighbors to current_vertex
    // and calculate their distances through the current_vertex
    // Neighbors are stored as vertex->adj (vector<adjVertex>)
    for (auto neighbor : current_vertex->adj) {
      if (neighbor.v->visited) {
	// unvisited neighbors only
	continue;
      }

      // Compare newly calculate route cost with the neighbors current distance
      // Update it if the new route through current_vertex is smaller
      int alternative_route_cost = current_vertex->distance + neighbor.weight;
      if (alternative_route_cost < neighbor.v->distance) {
	neighbor.v->distance = alternative_route_cost;
	neighbor.v->pred = current_vertex;
      }
    }
    // Now mark the current vertex as visited
   current_vertex->visited = true;
 }
}
