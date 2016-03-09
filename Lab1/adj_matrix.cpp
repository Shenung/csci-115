#include <cstdlib>
#include <iostream>
#include <vector>
#include "graph.h"

using namespace std;

vector< vector<int> > adj_matrix;

void Graph::init(int n){
  for (int i = 0; i < n; i++){
		vector<int> row;
    for(int j = 0; j < n; j++){
		    row.push_back(0);
    }
    adj_matrix.push_back(row)
	}
}
int  Graph::num_vertices(){
  int v = 0;
  for(iterator it = adj_matrix.begin(); it != adj_matrix.end(); it++){
    v++;
  }
  return v;
}
int  Graph::num_edges();
void Graph::insert_edge(int v1, int v2){

}
void Graph::list_all_edges();
void Graph::list_all_neighbors(int v);
void Graph::no_incoming();
