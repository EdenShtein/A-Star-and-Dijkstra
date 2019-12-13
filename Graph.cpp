//Made by: Eden Shtein 311396592 and Or Levi 311323034
#include "Graph.h"

// method to simply add a new node to the graph

void Graph::addNode(Vertex * nodeToAdd)
{
	list<Vertex*>::iterator it = this->nodes.begin();
	while (it != this->nodes.end())
	{
		if (nodeToAdd == *it)
		{
			cout << "The node is already exists in the Graph! \n";
			return;
		}
		it++;
	}

	this->nodes.push_back(nodeToAdd);
}

// method to register a new edge in the graph, must initially recieve a source and a destination node to be connected to

void Graph::addEdge(Vertex* pie, Vertex* dest,double weight)
{
	list<Vertex*>::iterator it = pie->getAdj()->begin();
	if (pie == dest)
	{
		cout << "Cannot connect the same vertex to itself \n";
		return;
	}
	while (it != pie->getAdj()->end())
	{
		if ((*it) == dest)
		{
			cout << "There is already an edge between father and child node in the graph \n";
			return;
		}
		it++;
	}

	// Using flags while checking each node in the graph in order to detect if the source & destination nodes exits 

	int flag1 = 0, flag2 = 0;
	it = this->nodes.begin();
	while (it != this->nodes.end())
	{
		if ((*it) == pie)
		{
			flag1 = 1;
		}
		if ((*it) == dest)
		{
			flag2 = 2;
		}
		it++;
	}

	// if the flags return true we register the destination node as a new neighbor to the source node

	if (flag1 == 1 && flag2 == 2)
	{
		pie->addAdj(dest);
		dest->setPie(pie);
		this->edges.push_back(new Edge(pie, dest, weight));
	}
	

}


void Graph::printVertices(list<Vertex*> v)
{
	list<Vertex*>::iterator it_1 = v.begin();

	while (it_1 != v.end())
	{
		cout << "Vertex " << (*it_1)->getData() << ":\t ";
		cout << "Distance: " << (*it_1)->getDistance() << "\t";
		if (!(*it_1)->getPie())
			cout << "Previous: NULL" << "\t";
		else
			cout << "Previous: " << (*it_1)->getPie()->getData() << "\t";
		cout << "Adj: ";
		list<Vertex*>::iterator it_2 = (*it_1)->getAdj()->begin();
		while (it_2 != (*it_1)->getAdj()->end())
		{
			cout << (*it_2)->getData() << ", ";
			it_2++;
		}
		cout << "\n";
		it_1++;
	}

}


void Graph::initialSingleSource(Vertex * source)
{
	list<Vertex*>Vertices = this->getListOfVertices();
	list<Vertex*>::iterator it = Vertices.begin();

	for (; it != Vertices.end(); it++)
	{
		(*it)->setPie(NULL);
		(*it)->setDistance(INT_MAX);
	}
	source->setDistance(0);
}

void Graph::relaxD(Edge * e)
{
	Vertex* source = e->getSource();
	Vertex* destination = e->getDestination();
	if (destination->getDistance() > (source->getDistance() + e->getWeight()))
	{
		destination->setPie(source);
		destination->setDistance(source->getDistance() + e->getWeight());
	}
}

void Graph::Dijkstra(Vertex * source)
{
	this->initialSingleSource(source);
	priority_queue<Vertex*, vector<Vertex*>, Predicat> dijpq;
	list<Vertex*> listOfVertices = this->getListOfVertices();
	list<Vertex*>::iterator it1 = listOfVertices.begin();
	for (; it1 != listOfVertices.end(); it1++)
	{
		dijpq.push(*it1);
	}
	list<Edge*>::iterator it2;
	while (!(dijpq.empty()))
	{
		Vertex * x = dijpq.top();
		it2 = x->getListEdges()->begin();
		while ( it2 != x->getListEdges()->end())
		{
			relaxD(*it2);
			it2++;
		}
		dijpq.pop();
	}
	this->printVertices(this->getListOfVertices());
}
void Graph::initialHeuristic(Vertex * source,Vertex * destination)
{
	list<Vertex*>Vertices = this->getListOfVertices();
	list<Vertex*>::iterator it = Vertices.begin();
	for (; it != Vertices.end(); it++)
	{
		list<Edge*>::iterator itE = source->getListEdges()->begin();
		int sumEdgeW = 0;
		for (; itE != source->getListEdges()->end(); itE++) {
			sumEdgeW += 1;
		}
		(*it)->setHeuristic(sumEdgeW );
	}
	source->setHeuristic(0);
	destination->setHeuristic(0);
}



void Graph::relaxA(Edge * e)
{
	Vertex* source = e->getSource();
	Vertex* destination = e->getDestination();
	if ((destination->getDistance()+destination->getHeuristic()) > (source->getDistance()+source->getHeuristic() + e->getWeight()))
	{
		destination->setPie(source);
		destination->setDistance(source->getDistance() + e->getWeight());
	}
}

void Graph::A_Star(Vertex * source, Vertex * destination)
{
	this->initialSingleSource(source);
	this->initialHeuristic(source,destination);
	priority_queue<Vertex*, vector<Vertex*>, Predicat2> dijpq;
	list<Vertex*> listOfVertices = this->getListOfVertices();
	list<Vertex*>::iterator it1 = listOfVertices.begin();
	for (; it1 != listOfVertices.end(); it1++)
	{
		dijpq.push(*it1);
	}
	list <Vertex*> out;
	list<Edge*>::iterator it2;
	while (!(dijpq.empty()))
	{
		Vertex * x = dijpq.top();
		it2 = x->getListEdges()->begin();
		while (it2 != x->getListEdges()->end())
		{
			relaxA(*it2);
			it2++;
		}
		out.push_back(dijpq.top());
		if (dijpq.top() == destination)
		{
			out.push_back(dijpq.top());
			this->PrintAstar(out);
			break;
		}
		dijpq.pop();

	}
		
}
void Graph::PrintAstar(list<Vertex*> v)
{
		list<Vertex*>::iterator it_1 = v.begin();
		cout << "Source: " << (*it_1)->getData() << "\t ";
		int n = v.size();
		while (n!=1)
		{
			it_1++;
			n--;
		}
		cout << "Distance: " << (*it_1)->getDistance() << "\t";
		if (!(*it_1)->getPie())
			cout << "Previous: NULL" << "\t";
		else
			cout << "Previous: " << (*it_1)->getPie()->getData() << "\t";
		cout << "Destination:" << (*it_1)->getData();
		cout << "\n";

}




