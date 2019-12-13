
#pragma once

#include "Edge.h"
#include <queue>
#include <vector>
#include <limits>
#include <ctime>



#ifndef GRAPH_H
#define GRAPH_H
class Graph
{
private:
	list <Vertex*> nodes;
	list <Edge*> edges;
	
public:
	Graph()
	{
		this->nodes.clear();
		this->edges.clear();
	}

	list<Vertex*> getListOfVertices () const { return this->nodes; }
	list<Edge*> getListOfEdge() const { return this->edges; }

	void addNode(Vertex * nodeToAdd);
	void addEdge(Vertex* pie, Vertex* dest, double weight);
	void printVertices(list<Vertex*> v);

	//Dijkstra
	void initialSingleSource(Vertex* source);
	void relaxD(Edge* edge);
	void relaxA(Edge* edge);
	void Dijkstra(Vertex* source);
	void A_Star(Vertex* source, Vertex* destination);
	void initialHeuristic(Vertex* source, Vertex * destination);
	void PrintAstar(list<Vertex*> v);

	~Graph()
	{
		this->nodes.clear();
		this->edges.clear();
	}

};
struct Predicat
{
	bool operator()(Vertex* u, Vertex* v) const { return u->getDistance() > v->getDistance(); }

};

struct Predicat2
{
	bool operator()(Vertex* u, Vertex* v) const { return (u->getDistance() + u->getHeuristic()) > (v->getDistance() + v->getHeuristic()); }

};
#endif
