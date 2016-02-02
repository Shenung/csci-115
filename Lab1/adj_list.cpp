#include <cstdlib>
#include <iostream>
#include <vector>
#include "graph.h"

using namespace std;

vector<graph*> adj_list; // one dimensional vector; each position in the vector stores a pointer to the head of a linked list


void graph::init(int num_of_vertices){
	for (int i = 1; i <= num_of_vertices; i++){
		graph* list = new graph;
		list->head = NULL;
		adj_list.push_back(list);
	}
	cout << endl << endl << endl;
}

void graph::insert_edge(int vertex1, int vertex2){
	graph* nodeA = adj_list[vertex1]->head;
	graph* nodeB = new graph;
	nodeB->next = NULL;
	nodeB->prev = NULL;
	nodeB->edge = vertex2;
	if (nodeA == NULL){
		adj_list[vertex1]->head = nodeB;
	}
	else
	{
		for (; nodeA->next != NULL; nodeA = nodeA->next){}
		nodeA->next = nodeB;
		nodeB->prev = nodeA;
	}
	cout << endl << endl << endl;
}

void graph::list_all_edges(int num_of_vertices){
	for (int i = 1; i < num_of_vertices; i++){
		for (graph *to = adj_list[i]->head; to != NULL; to = to->next)
			cout << i << "->" << to->edge << endl;
	}
	//implement this function
	cout << endl << endl << endl;
}

void graph::list_all_neighbors(int vertex1, int num_of_vertices){
	for (graph *nodeA = adj_list[vertex1]->head; nodeA != NULL; nodeA = nodeA->next){
		cout << vertex1 << " -> " << nodeA->edge << endl;
	}
	//implement this function
	cout << endl << endl << endl;
}

void graph::no_incoming(int num_of_vertices){
	bool* nodeA = new bool[num_of_vertices];
	for (int i = 1; i <= num_of_vertices; i++){
		nodeA[i] = true;
	}
	for (int i = 1; i <= num_of_vertices; i++){
		for (graph* current = adj_list[i]->head; current != NULL; current = current->next){
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
