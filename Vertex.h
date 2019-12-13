//Made by: Eden Shtein 311396592 and Or Levi 311323034
#ifndef VERTEX_H
#define VERTEX_H
#include <list>
#include <iostream>
#include <string>

using namespace std;
class Edge;
class Vertex
{
private:
	list <Edge*> edge;
	list <Vertex*> adj;
	Vertex* pie;
	string data;
	double distance;
	double heuristic;
	

public:
	Vertex(string name) {
		this->adj.clear();
		this->edge.clear();
		this->pie = NULL;
		this->data =name;
		this->distance = 0;
	}

	//setters and getters
	void setPie(Vertex* pie) { this->pie = pie; }
	void setDistance(double distance) { this->distance = distance; }
	void setData(char data) { this->data = data; }
	void setHeuristic(double h) { this->heuristic = h; }
	
	list<Edge*>* getListEdges() { return &(this->edge); }
	list<Vertex*>* getAdj() { return &(this->adj); }
	Vertex* getPie() const { return this->pie; }
	int getDistance() const { return this->distance; }
	string getData() const { return this->data; }
	double getHeuristic()const{ return this->heuristic; }

	// method to register a new neighbor to the vertex neighbor list
	void addAdj(Vertex* neighbor);
	void addEdge(Edge* e);


	~Vertex() {
		this->adj.clear();
		this->edge.clear();
		delete this->pie;
	}

};
#endif