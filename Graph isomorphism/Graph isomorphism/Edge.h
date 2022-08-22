#pragma once
#include "Vertex.h"

class Edge
{
private:
	Vertex ver1;
	Vertex ver2;
public:
	Edge(char a, char b) : ver1(a), ver2(b) {}
	char get_ver1() const { return ver1.get_vertex(); }
	char get_ver2() const { return ver2.get_vertex(); }
};