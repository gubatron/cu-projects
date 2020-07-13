#include <iostream>
#include <vector>
#include "Graph.hpp"

using namespace std;


int main() {
	
    Graph g1;
    g1.addVertex("Amsterdam");
    g1.addVertex("Broomfield");
    g1.addVertex("Calcutta");
    g1.addVertex("Dallas");
    g1.addVertex("Fabens");
    g1.addEdge("Amsterdam", "Broomfield",10);
    g1.addEdge("Amsterdam", "Calcutta", 30);
    g1.addEdge("Broomfield", "Calcutta", 10);
    g1.addEdge("Calcutta","Dallas", 5);
    g1.addEdge("Dallas","Fabens", 5);
    g1.addEdge("Broomfield", "Fabens", 50);

    cout << "Displaying edges along with their distances:" << endl;
    g1.displayEdges();
    g1._grader_setAllVerticesUnvisited();
    g1.dijkstraTraverse("Amsterdam");
    cout << "Dijkstra's Shortest distance from Amsterdam: " << endl;
    g1._grader_print_shortest_distance("Broomfield");
    g1._grader_print_shortest_distance("Calcutta");
    g1._grader_print_shortest_distance("Dallas");
    g1._grader_print_shortest_distance("Fabens");
    
    g1._grader_setAllVerticesUnvisited();
    g1.dijkstraTraverse("Broomfield");
    cout << endl << "Dijkstra's Shortest distance from Broomfield: " << endl;
    g1._grader_print_shortest_distance("Calcutta");
    g1._grader_print_shortest_distance("Dallas");
    g1._grader_print_shortest_distance("Fabens");

    g1._grader_setAllVerticesUnvisited();
    g1.dijkstraTraverse("Calcutta");
    cout << endl << "Dijkstra's Shortest distance from Calcutta: " << endl;
    g1._grader_print_shortest_distance("Dallas");
    g1._grader_print_shortest_distance("Fabens");

    g1._grader_setAllVerticesUnvisited();
    g1.dijkstraTraverse("Dallas");
    cout << endl << "Dijkstra's Shortest distance from Dallas: " << endl;
    g1._grader_print_shortest_distance("Fabens");

    return 0;
}
