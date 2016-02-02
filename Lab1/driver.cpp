#include <cstdlib>
#include <iostream>
#include "graph.h"

using namespace std;

int main()
{
  int num_of_vertices, num_of_edges, vertex1, vertex2, function;
  Graph *g = new Graph();

  while (1) {
    cout << "1 - initialize graph" << endl;
    cout << "2 - insert an edge to the graph" << endl;
    cout << "3 - list all edges in the graph" << endl;
    cout << "4 - list all neighbors for a particular vertex" << endl;
    cout << "5 - list all vertices with no incoming edges" << endl;
    cout << "6 - quit" << endl << endl;
    cout << "Choose a function (1 - 6): ";
    cin >> function;
    cout << endl << endl;

    switch (function) {
    case 1:
      cout << "Enter the number of vertices in the graph: ";
      cin >> num_of_vertices;
      cout << endl << endl;
      g->init(num_of_vertices);
      break;

    case 2:
      cout << "Enter the vertices, separated by a space" << endl;
      cin >> vertex1 >> vertex2;
      cout << endl << endl;
      g->insert_edge(vertex1, vertex2);
      break;

    case 3:
      g->list_all_edges();
      break;

    case 4:
      cout << "Enter the vertex to list all of the neighbors for: ";
      cin >> vertex1;
      cout << endl << endl;
      g->list_all_neighbors(vertex1);
      break;

    case 5:
      g->no_incoming();
      break;

    case 6:
      return 0;

    } //end switch
  }  //end while

}
