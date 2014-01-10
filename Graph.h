#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED
#include <list>
#include <vector>
#include "Course.h"
#include <iostream>

using namespace std;

struct Node
{
    size_t index;
    vector<size_t> indexes;
    Disc* disc;
    Node()
    {
        this->index = 0;
        this->disc = NULL;
    }
};

class Graph
{
public:
    Graph(const vector<Disc*>&);

    bool TopSort(list<Disc*>&)const;
    void printNodes()const;
private:
    vector<Node> nodes;

    size_t findIndex(size_t,const vector<Disc*>&)const;
    bool isInReqiuredDiscs(size_t,const Node&)const;
};

#endif // GRAPH_H_INCLUDED
