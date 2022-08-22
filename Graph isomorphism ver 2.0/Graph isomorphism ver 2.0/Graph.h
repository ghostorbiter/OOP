#pragma once
#include <list>

// @ Defining maximum to equal to 20
// @ It will be used when declaring maximum size of 2 dimensional array - matrix
// @ Therefore Graph can have maximum 20 vertices
// @ Can be changed for higher numbers 
// @ 20 is used as a base and for easy implementation
#define MAX 20

using namespace std;

class Vertex
{
	// @ Class Vertex represents vertex that takes integer numbers as name of vertex
	// @ and it also contains degree which is integer number
	int vertex;
	int degree = 0;

public:

	// @ Simple constructor which assigns integer number given by user to vertex name
	Vertex(int i) { vertex = i; }

	// @ Method to increase degree of
	// @ We need it in future, when will iterate through list of edges in Graph class
	void add_degree() { degree++; }

	// @ Simple getter method
	// @ We need it when implementing methods in Graph class
	// @ Returns vertex name (integer value)
	int get() const { return vertex; }

	// @ Another simple getter method
	// @ We need it for sorting algorithm
	// @ Returns degree (integer value)
	int get_degree() const { return degree; }
};

class Graph
{
	// @ Class Graph represents a graph with vertices and edges
	// @ Class Graph contains list of vertices and list of pairs of edges (two integer values)
	// @ Moreover each graph contains matrix representation of itself
	// @ Matrix is two dimensional array where columns and rows are vertices
	// @ Matrix is boolean (is true when two vertices have edge connecting them and false otherwise)
	list<Vertex> vertex;
	list<pair<int, int>> edges;

	bool matrix[MAX][MAX];

public:

	// @ Default Constructor, so that we can use Graph
	// @ Constructor does not assign anything and does not contain any user input
	Graph() {}

	// @ Method add_vertex adds given vertex to the list using push_back
	// @ Moreover, add_vertex checks if given vertex already exists in the list
	// @ It does not add existing vertex to the list
	void add_vertex(Vertex i);

	// @ Method add_edge adds two integers (represents edge between two vertices) _
	// @ _ to the list of edges using push_back and make_pair
	// @ It also checks if given edge already exists in the list
	// @ It does not add existing edge to the list
	void add_edge(int i, int j);

	// @ Method change_degree is used to increase degree of each vertex _
	// @ _ with the help of add_degree method described in Vertex class
	// @ Will iterate through list of vertices and edges checking for similar _
	// @ _ vertex names (will increase by one if it finds such vertex)
	void change_degree();

	// @ Method sorting sorts list of vertices by their degree in ascending order
	// @ If degrees of vertices are same, comparator uses their names as comparison _
	// @ _ it is used for more precise comparison 
	// @ Moreover, sorting method also sorts list of edges for more precise sorting _
	// @ _ and correct output, i.e. in Peterson's Graph
	// @ Uses build-in method in STL list sort
	// @ For comparison lambda expression is used
	void sorting();

	// @ Method fill_matrix will fill matrix with true or false
	// @ Matrix is two dimensional array where columns and rows are vertices
	// @ Matrix is boolean (is true when two vertices have edge connecting them and false otherwise)
	void fill_matrix();

	// @ Boolean operator == will check if two graphs are isomorphic
	// @ Initially it checks if two graps have same number of vertices and edges
	// @ Then it checks if matrix representation of these graphs are identical
	// @ Identical here means if they have similar boolean values at the same coordinates
	friend bool operator== (Graph& g1, Graph& g2);
};