#pragma once
#include <list>
#include <map>
#include "Edge.h"


using namespace std;

class Graph
{
private:
	list<Vertex> vertexes;
	list<Edge> edges;

	int** adjacent_mat;
public:
	void AddVertexes(Vertex ver);
	void AddEdges(Edge edge);
	void ChangeDegree();

	bool samevertexes(const Graph& g) const;
	bool sameedges(const Graph& g) const;
	bool samedegrees(const Graph& g) const;

	void sorting() const;

	friend bool operator==(const Graph& g1, const Graph& g2);
};