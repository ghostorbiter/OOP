#include "Graph.h"
#include <algorithm>
#include <cmath>

using namespace std;

void Graph::add_vertex(Vertex i)
{
	for (auto it = vertex.begin(); it != vertex.end(); it++) {
		if (it->get() == i.get())
			return;
	}

	vertex.push_back(i);
}

void Graph::add_edge(int i, int j)
{
	int p = count(edges.begin(), edges.end(), make_pair(i, j));
	int k = count(edges.begin(), edges.end(), make_pair(j, i));
	if (!p && !k)
		edges.push_back(make_pair(i, j));
}

void Graph::change_degree()
{
	for (auto it = vertex.begin(); it != vertex.end(); it++) {
		for (auto gym = edges.begin(); gym != edges.end(); gym++) {
			if (it->get() == gym->first || it->get() == gym->second)
				it->add_degree();
		}
	}
}

void Graph::sorting()
{
	change_degree();

	auto lambdaV = [](const Vertex& i, const Vertex& j) {
		if (i.get_degree() != j.get_degree())
			return i.get_degree() < j.get_degree();
		else
			return i.get() < j.get();
	};

	auto lambdaE = [](const pair<int, int>& i, const pair<int, int>& j) {
		if (min(i.first, i.second) != min(j.first, j.second))
			return min(i.first, i.second) < min(j.first, j.second);
		else
			return max(i.first, i.second) < max(j.first, j.second);
	};

	vertex.sort(lambdaV);
	edges.sort(lambdaE);
	fill_matrix();
}

void Graph::fill_matrix()
{
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			matrix[i][j] = false;
		}
	}

	int i = 0, j = 0;
	for (auto it = vertex.begin(); it != vertex.end(); it++, i++) {
		for (auto gr = edges.begin(); gr != edges.end(); gr++, j++) {
			if (it->get() == gr->first || it->get() == gr->second)
				matrix[i][j] = true;
		}
		j = 0;
	}
}

bool operator== (Graph& g1, Graph& g2)
{
	if (g1.vertex.size() != g2.vertex.size())
		return false;
	if (g1.edges.size() != g2.edges.size())
		return false;

	g1.sorting();
	g2.sorting();

	for (int i = 0; i < g1.vertex.size(); i++) {
		for (int j = 0; j < g1.edges.size(); j++) {
			if (g1.matrix[i][j] != g2.matrix[i][j])
				return false;
		}
	}
	return true;
}