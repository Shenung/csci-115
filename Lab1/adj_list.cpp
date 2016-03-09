#include <cstdlib>
#include <iostream>
#include <vector>
#include "Graph.h"

using namespace std;

vector<Graph*> adj_list; // one dimensional vector; each position in the vector stores a pointer to the head of a linked list


void Graph::init(int n){
	for (int i = 1; i <= n; i++){
		Graph* list = new Graph;
		list->head = NULL;
		adj_list.push_back(list);
	}
	cout << endl << endl << endl;
}

void Graph::insert_edge(int v1, int v2){
	Graph* nodeA = adj_list[v1]->head;
	Graph* nodeB = new Graph;
	nodeB->next = NULL;
	nodeB->prev = NULL;
	nodeB->edge = v2;
	if (nodeA == NULL){
		adj_list[v1]->head = nodeB;
	}
	else
	{
		for (; nodeA->next != NULL; nodeA = nodeA->next){}
		nodeA->next = nodeB;
		nodeB->prev = nodeA;
	}
	cout << endl << endl << endl;
}

void Graph::list_all_edges(int n){
	for (int i = 1; i < n; i++){
		for (Graph *to = adj_list[i]->head; to != NULL; to = to->next)
			cout << i << "->" << to->edge << endl;
	}
	//implement this function
	cout << endl << endl << endl;
}

void Graph::list_all_neighbors(int vertex1){
	for (Graph *nodeA = adj_list[vertex1]->head; nodeA != NULL; nodeA = nodeA->next){
		cout << vertex1 << " -> " << nodeA->edge << endl;
	}
	//implement this function
	cout << endl << endl << endl;
}

void Graph::no_incoming(int num_of_vertices){
	bool* nodeA = new bool[num_of_vertices];
	for (int i = 1; i <= num_of_vertices; i++){
		nodeA[i] = true;
	}
	for (int i = 1; i <= num_of_vertices; i++){
		for (Graph* current = adj_list[i]->head; current != NULL; current = current->next){
			nodeA[current->edge] = false;
		}
	}
	for (int i = 1; i <= num_of_vertices; i++){
		if (nodeA[i] == true)
			cout << i << endl;
	}
	delete[] nodeA;
	//implement this function

	cout << endl << endl << endl;
}
