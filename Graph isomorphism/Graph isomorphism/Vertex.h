#pragma once

class Vertex
{
private:
	char vertex;
	int degree = 0;
public:
	Vertex() : vertex('!') {}
	Vertex(char ver) : vertex(ver) {}
	char get_vertex() const { return vertex; }
	int get_degree() const { return degree; }
	void add_degree() { degree++; }

	friend bool operator== (const Vertex& ver1, const Vertex& ver2) {
		return ver1.vertex == ver2.vertex;
	}

	Vertex& operator=(const Vertex& ver) {
		if (this == &ver)
			return *this;

		vertex = ver.vertex;
		degree = ver.degree;
		return *this;
	}
};

//bool operator==(const Vertex& ver1, const Vertex& ver2)
//{
//	return ver1.vertex == ver2.vertex;
//}
//
//Vertex& Vertex::operator=(const Vertex& ver)
//{
//	if (this == &ver)
//		return *this;
//
//	vertex = ver.vertex;
//	degree = ver.degree;
//	return *this;
//}