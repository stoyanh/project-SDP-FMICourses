#include "Graph.h"
#include <queue>
Graph::Graph(const vector<Disc*>& discs)
{
    for(size_t i = 0 ; i < discs.size() ; ++i)
    {
        Node node;
        node.index = i;
        node.disc = discs[i];
        node.indexes.resize(node.disc->discsToHavePassed.size());

        for(size_t j = 0 ; j < node.indexes.size() ; ++j)
        {
            node.indexes[j] = findIndex(discs[i]->discsToHavePassed[j],discs);
        }
        this->nodes.push_back(node);
    }

}
/// за подаден индентификатор намира индекса на съответната дисциплина във вектора
size_t Graph::findIndex(size_t ident, const vector<Disc*>& discs)const
{
    for(size_t i = 0 ; i < discs.size() ; ++i)
    {
        if(ident == discs[i]->ident)
            return i;
    }
}

/// за всеки node проверява дали в масива от индекси на дисциплини,които трябва да си минал се съдържа дисциплината
/// с дадения индекс
bool Graph::isInReqiuredDiscs(size_t index, const Node& node)const
{
    for(size_t i = 0 ; i < node.indexes.size() ; ++i)
        if(node.indexes[i] == index)
            return true;

    return false;
}

bool Graph::TopSort(list<Disc*>& sorted)const
{
    /// създаване на опашка за индексите на дисциплините и вектор за броя на ребрата влизащи във върха със съответния индекс
    queue<size_t> q;
    vector<size_t> incoming;
    incoming.resize(nodes.size());

    for(size_t i = 0 ; i < nodes.size() ; ++i)
    {
        incoming[i] = nodes[i].disc->discsToHavePassed.size();
    }

    for(size_t i = 0 ; i < incoming.size() ; ++i)
    {
        if(incoming[i] == 0)
            q.push(i);
    }
    if(q.empty())
        return false;
    while(!q.empty())
    {
        size_t numb = q.front();
        q.pop();

        sorted.push_back( nodes[numb].disc );

        for(size_t i = 0 ; i < nodes.size() ; ++i)
        {
            /// тъй като проверяваме всички node-ове,включително и тези,които са в опашката
            /// (а ни трябват само тези,които не са), проверяваме дали сме на node,който вече е в опашката
            if(incoming[i] == 0)
                continue;
            if( isInReqiuredDiscs(numb, nodes[i]) )
                --incoming[i];
            if(incoming[i] == 0)
                q.push(i);
        }
    }
    return sorted.size() == nodes.size();
}

void Graph::printNodes()const
{
    for(size_t i = 0 ; i < nodes.size() ; ++i)
    {
        cout << nodes[i].index << endl;
        for(size_t j = 0 ; j < nodes[i].indexes.size() ; ++j)
            cout << nodes[i].indexes[j] << " ";
        cout << endl ;
    }
}
