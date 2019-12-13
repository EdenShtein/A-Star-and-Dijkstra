//Made by: Eden Shtein 311396592 and Or Levi 311323034
#include "Vertex.h"

void Vertex::addAdj(Vertex* neighbor)
{
	list<Vertex*>::iterator it = this->adj.begin();

	while (it != this->adj.end())
	{
		if (neighbor != (*it))
			it++;
		else
		{
			cout << "The neighbor already exists in the list!";
			return;
		}
	}
	this->adj.push_back(neighbor);
}

void Vertex::addEdge(Edge * e)
{
	list <Edge*>::iterator it = this->edge.begin();
	while (it != this->edge.end())
	{
		if (e != (*it))
			it++;
		else
		{
			cout << "The edge already exists in the list!";
			return;
		}
	}
	this->edge.push_back(e);
}


