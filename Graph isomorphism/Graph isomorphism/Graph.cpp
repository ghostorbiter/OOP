#include <list>
#include <algorithm>
#include "Graph.h"

using namespace std;

void Graph::AddVertexes(Vertex ver)
{
	for (auto it = vertexes.begin(); it != vertexes.end(); it++) {
		if (it->get_vertex() == ver.get_vertex())
			return;
	}

	vertexes.push_back(ver);
}

void Graph::AddEdges(Edge edge)
{
	for (auto it = edges.begin(); it != edges.end(); it++) {
		if (it->get_ver1() == edge.get_ver1() && it->get_ver2() == edge.get_ver2() || (edge.get_ver1() == edge.get_ver2()))
			return;
	}

	edges.push_back(edge);
}

void Graph::ChangeDegree()
{
	for (auto it = vertexes.begin(); it != vertexes.end(); it++) {
		for (auto deg = edges.begin(); deg != edges.end(); deg++) {
			if (it->get_vertex() == deg->get_ver1() || it->get_vertex() == deg->get_ver2()) {
				it->add_degree();
			}
		}
	}
}

bool Graph::samevertexes(const Graph& g) const
{
	return vertexes.size() == g.vertexes.size();
}

bool Graph::sameedges(const Graph& g) const
{
	return edges.size() == g.edges.size();
}

bool Graph::samedegrees(const Graph& g) const
{
	list<Vertex> newver1 = vertexes;
	list<Vertex> newver2 = g.vertexes;

	for (auto it = newver1.begin(); it != newver1.end(); it++) {
		for (auto deg = newver2.begin(); deg != newver2.end(); ) {
			if (newver1.begin()->get_degree() == deg->get_degree()) {
				auto deg1 = deg;
				deg++;
				newver2.erase(deg1);
				break;
			}
			deg++;
		}
	}

	if (newver2.size() == 0)
		return true;
	return false;
}

void Graph::sorting() const
{
	auto lambda = [](const Vertex& ver1, const Vertex& ver2) {
		return ver1.get_degree() < ver2.get_degree();
	};

	sort(vertexes.begin(), vertexes.end(), lambda);
	ChangeDegree();
}

bool operator==(const Graph& g1, const Graph& g2)
{
	if (!(g1.samevertexes(g2)))
		return false;
	if (!(g1.sameedges(g2)))
		return false;
	if (!(g1.samedegrees(g2)))
		return false;
	g1.sorting();
	g2.sorting();

	for (int i = 0; i < g1.vertexes.size(); i++) {

	}

	return true;
}	