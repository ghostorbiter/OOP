#include <iostream>
#include "Graph.h"

using namespace std;

int main()
{
	cout << "**********CHECKING 2 ISOMORPHIC GRAPHS**********" << endl << endl;

	Graph g1, g2;
	for (int i = 1; i <= 6; i++) {
		g1.add_vertex(Vertex(i));
		g2.add_vertex(Vertex(i));
	}

	g1.add_edge(1, 2);
	g1.add_edge(2, 3);
	g1.add_edge(3, 4);
	g1.add_edge(4, 5);
	g1.add_edge(5, 6);
	g1.add_edge(6, 3);
	g1.add_edge(4, 1);
	g1.add_edge(6, 1);

	g2.add_edge(1, 2);
	g2.add_edge(2, 3);
	g2.add_edge(3, 4);
	g2.add_edge(4, 5);
	g2.add_edge(5, 6);
	g2.add_edge(6, 3);
	g2.add_edge(4, 1);
	g2.add_edge(6, 1);

	if (g1 == g2)
		cout << "G1 and G2 are isomorphic" << endl;
	else
		cout << "G1 and G2 are not isomorphic" << endl;

	Graph h1, h2;
	h1.add_vertex(Vertex(1));
	h1.add_vertex(Vertex(3));
	h1.add_vertex(Vertex(4));
	h1.add_vertex(Vertex(2));
	h1.add_vertex(Vertex(6));
	h1.add_vertex(Vertex(5));


	h2.add_vertex(Vertex(2));
	h2.add_vertex(Vertex(6));
	h2.add_vertex(Vertex(5));
	h2.add_vertex(Vertex(4));
	h2.add_vertex(Vertex(1));
	h2.add_vertex(Vertex(3));

	h1.add_edge(1, 2);
	h1.add_edge(2, 3);
	h1.add_edge(3, 4);
	h1.add_edge(4, 5);
	h1.add_edge(5, 6);
	h1.add_edge(6, 3);
	h1.add_edge(4, 1);
	h1.add_edge(6, 1);

	h2.add_edge(1, 2);
	h2.add_edge(2, 3);
	h2.add_edge(3, 4);
	h2.add_edge(4, 5);
	h2.add_edge(5, 6);
	h2.add_edge(6, 3);
	h2.add_edge(4, 1);
	h2.add_edge(6, 1);

	if (h1 == h2)
		cout << "H1 and H2 are isomorphic" << endl;
	else
		cout << "H1 and H2 are not isomorphic" << endl;

	cout << endl << endl << "**********CHECKING 2 NON-ISOMORPHIC GRAPHS**********" << endl << endl;

	Graph g3, g4;
	for (int i = 1; i <= 5; i++) {
		g3.add_vertex(Vertex(i));
		g4.add_vertex(Vertex(i));
	}

	g3.add_edge(1, 2);
	g3.add_edge(2, 3);
	g3.add_edge(3, 4);
	g3.add_edge(4, 5);
	g3.add_edge(5, 2);
	g3.add_edge(4, 1);

	g3.add_edge(1, 2);
	g3.add_edge(2, 3);
	g3.add_edge(3, 4);
	g3.add_edge(4, 5);
	g3.add_edge(3, 5);
	g3.add_edge(5, 1);
	
	if (g3 == g4)
		cout << "G3 and G4 are isomorphic" << endl;
	else
		cout << "G3 and G4 are not isomorphic" << endl;

	cout << endl << endl << "**********CHECKING 2 NON-ISOMORPHIC CYCLIC GRAPHS**********" << endl << endl;

	Graph g5, g6;
	for (int i = 1; i <= 6; i++) {
		g5.add_vertex(Vertex(i));
		g6.add_vertex(Vertex(i));
	}

	g5.add_edge(1, 2);
	g5.add_edge(5, 6);
	g5.add_edge(6, 4);
	g5.add_edge(2, 3);
	g5.add_edge(3, 1);
	g5.add_edge(4, 5);

	g6.add_edge(5, 6);
	g6.add_edge(1, 2);
	g6.add_edge(2, 4);
	g6.add_edge(6, 3);
	g6.add_edge(3, 1);
	g6.add_edge(4, 5);

	if (g5 == g6)
		cout << "G5 and G6 are isomorphic" << endl;
	else
		cout << "G5 and G6 are not isomorphic" << endl;

	Graph g7, g8;
	for (int i = 1; i <= 8; i++) {
		g7.add_vertex(Vertex(i));
		g8.add_vertex(Vertex(i));
	}

	g7.add_edge(1, 2);
	g7.add_edge(2, 3);
	g7.add_edge(3, 4);
	g7.add_edge(4, 5);
	g7.add_edge(5, 6);
	g7.add_edge(6, 7);
	g7.add_edge(7, 8);
	g7.add_edge(1, 8);

	g8.add_edge(1, 2);
	g8.add_edge(2, 3);
	g8.add_edge(3, 4);
	g8.add_edge(1, 4);
	g8.add_edge(5, 6);
	g8.add_edge(6, 7);
	g8.add_edge(7, 8);
	g8.add_edge(5, 8);

	if (g7 == g8)
		cout << "G7 and G8 are isomorphic" << endl;
	else
		cout << "G7 and G8 are not isomorphic" << endl;

	cout << endl << endl << "**********CHECKING 2 ISOMORPHIC GRAPHS**********" << endl << endl;

	Graph g9, g10;
	for (int i = 1; i <= 6; i++) {
		g9.add_vertex(Vertex(i));
		g10.add_vertex(Vertex(i));
	}

	g9.add_edge(1, 2);
	g9.add_edge(1, 6);
	g9.add_edge(1, 4);
	g9.add_edge(3, 2);
	g9.add_edge(3, 4);
	g9.add_edge(3, 6);
	g9.add_edge(5, 2);
	g9.add_edge(5, 4);
	g9.add_edge(5, 6);

	g10.add_edge(1, 2);
	g10.add_edge(1, 6);
	g10.add_edge(1, 4);
	g10.add_edge(3, 2);
	g10.add_edge(3, 4);
	g10.add_edge(3, 6);
	g10.add_edge(5, 2);
	g10.add_edge(5, 4);
	g10.add_edge(5, 6);

	//g9.add_edge(1, 4);
	//g9.add_edge(1, 5);
	//g9.add_edge(1, 6);
	//g9.add_edge(2, 4);
	//g9.add_edge(2, 5);
	//g9.add_edge(2, 6);
	//g9.add_edge(3, 4);
	//g9.add_edge(3, 5);
	//g9.add_edge(3, 6);

	//g10.add_edge(1, 2);
	//g10.add_edge(1, 4);
	//g10.add_edge(1, 6);
	//g10.add_edge(2, 3);
	//g10.add_edge(2, 5);
	//g10.add_edge(3, 4);
	//g10.add_edge(3, 6);
	//g10.add_edge(4, 5);
	//g10.add_edge(5, 6);

	if (g9 == g10)
		cout << "G9 and G10 are isomorphic" << endl;
	else
		cout << "G9 and G10 are not isomorphic" << endl;

	cout << endl << endl << "**********CHECKING 3 REGULAR NON-ISOMORPHIC GRAPHS**********" << endl << endl;

	Graph g11, g12;
	for (int i = 1; i <= 6; i++) {
		g11.add_vertex(Vertex(i));
		g12.add_vertex(Vertex(i));
	}

	g11.add_edge(1, 2);
	g11.add_edge(1, 6);
	g11.add_edge(1, 4);
	g11.add_edge(3, 2);
	g11.add_edge(3, 4);
	g11.add_edge(3, 6);
	g11.add_edge(5, 2);
	g11.add_edge(5, 4);
	g11.add_edge(5, 6);

	g12.add_edge(1, 2);
	g12.add_edge(1, 6);
	g12.add_edge(1, 5);
	g12.add_edge(3, 2);
	g12.add_edge(3, 4);
	g12.add_edge(3, 6);
	g12.add_edge(2, 4);
	g12.add_edge(5, 4);
	g12.add_edge(5, 6);

	if (g11 == g12)
		cout << "G11 and G12 are isomorphic" << endl;
	else
		cout << "G11 and G12 are not isomorphic" << endl;

	cout << endl << endl << "**********CHECKING 2 PETERSON'S ISOMORPHIC GRAPHS**********" << endl << endl;

	Graph g13, g14;
	for (int i = 1; i <= 10; i++) {
		g13.add_vertex(Vertex(i));
		g14.add_vertex(Vertex(i));
	}

	g13.add_edge(1, 2);
	g13.add_edge(1, 10);
	g13.add_edge(1, 6);
	g13.add_edge(2, 7);
	g13.add_edge(2, 3);
	g13.add_edge(3, 8);
	g13.add_edge(3, 4);
	g13.add_edge(4, 9);
	g13.add_edge(4, 10);
	g13.add_edge(10, 5);
	g13.add_edge(6, 8);
	g13.add_edge(6, 9);
	g13.add_edge(5, 8);
	g13.add_edge(5, 7);
	g13.add_edge(7, 9);	

	g14.add_edge(1, 2);
	g14.add_edge(2, 3);
	g14.add_edge(3, 4);
	g14.add_edge(4, 9);
	g14.add_edge(9, 6);
	g14.add_edge(6, 8);
	g14.add_edge(8, 5);
	g14.add_edge(5, 10);
	g14.add_edge(1, 10);
	g14.add_edge(4, 10);
	g14.add_edge(9, 7);
	g14.add_edge(2, 7);
	g14.add_edge(5, 7);
	g14.add_edge(1, 6);
	g14.add_edge(3, 8);

	if (g13 == g14)
		cout << "G13 and G14 are isomorphic" << endl;
	else
		cout << "G13 and G14 are not isomorphic" << endl;

	return 0;
}