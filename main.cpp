//Made by: Eden Shtein 311396592 and Or Levi 311323034


#include "Graph.h"

using namespace std;

int main()
{
	
	Graph g;
	//Create Vertices
	Vertex* A = new Vertex("A");
	g.addNode(A);
	Vertex* B = new Vertex("B");
	g.addNode(B);
	Vertex* C = new Vertex("C");
	g.addNode(C);
	Vertex* D = new Vertex("D");
	g.addNode(D);
	Vertex* E = new Vertex("E");
	g.addNode(E);
	Vertex* F = new Vertex("F");
	g.addNode(F);
	Vertex* H = new Vertex("H");
	g.addNode(H);
	Vertex* S = new Vertex("S");
	g.addNode(S);

	
	g.addEdge(S, A, 33);
	g.addEdge(S, B, 8);
	g.addEdge(S, C, 10);
	g.addEdge(A, E, 11);
	g.addEdge(C, F, 9);
	g.addEdge(C, H, 13);
	g.addEdge(C, D, 6);
	g.addEdge(D, H, 5);
	g.addEdge(B, D, 12);
	g.addEdge(H, F, 6);
	g.addEdge(F, A, 3);
	g.addEdge(F, E, 25);

	Edge* S_A = new Edge(S, A, 33);
	Edge* S_B = new Edge(S, B, 8);
	Edge* S_C = new Edge(S, C, 10);
	Edge* A_E = new Edge(A, E, 11);
	Edge* B_D = new Edge(B, D, 12);
	Edge* C_D = new Edge(C, D, 6);
	Edge* C_H = new Edge(C, H, 13);
	Edge* C_F = new Edge(C, F, 9);
	Edge* D_H = new Edge(D, H, 5);
	Edge* F_A = new Edge(F, A, 3);
	Edge* F_E = new Edge(F, E, 25);
	Edge* H_F = new Edge(H, F, 6);

	S->addEdge(S_A);
	S->addEdge(S_B);
	S->addEdge(S_C);
	A->addEdge(A_E);
	B->addEdge(B_D);
	C->addEdge(C_D);
	C->addEdge(C_H);
	C->addEdge(C_F);
	D->addEdge(D_H);
	F->addEdge(F_A);
	F->addEdge(H_F);
	F->addEdge(F_E);

	cout << "The original graph:\n";
	g.printVertices(g.getListOfVertices());
	cout << "\n";
	cout << "-------------Dijkstra Algorithm:----------------------\n";
	g.Dijkstra(S);
	cout << "--------------------------------------------------------";
	cout << "\n";
	cout << "---------------------------A Star Algorithm-----------------------\n";
	g.A_Star(S, A);
	cout << "\n";
	g.A_Star(S, B);
	cout << "\n";
	g.A_Star(S, C);
	cout << "\n";
	g.A_Star(S, D);
	cout << "\n";
	g.A_Star(S, E);
	cout << "\n";
	g.A_Star(S, F);
	cout << "\n";
	g.A_Star(S, H);
	cout << "\n";
	

}

