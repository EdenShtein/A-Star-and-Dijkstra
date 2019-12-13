
#pragma once

#ifndef EDGE_H
#define EDGE_H
class Vertex;

#include "Vertex.h"

class Edge
{
private:
	Vertex* source;
	Vertex* destination;
	double weight;
public:
	Edge()
	{
		this->source = NULL;
		this->destination = NULL;
		this->weight = 0;

	}
	Edge(Vertex* s, Vertex* d, double w)
	{
		this->setSource(s);
		this->setDestination(d);
		this->setWeight(w);
	}
	//Setters
	void setSource(Vertex* source) { this->source = source; }
	void setDestination(Vertex* destination) { this->destination = destination; }
	void setWeight(double weight) { this->weight = weight; }
	//Getters
	Vertex* getSource() { return this->source; }
	Vertex* getDestination() { return this->destination; }
	double getWeight() { return this->weight; }

};

#endif 
