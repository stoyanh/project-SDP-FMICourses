#include <iostream>
#include <fstream>
#include <cstring>
#include "Read_from_file.h"
#include "Course.h"
#include "Graph.h"
#include <list>

using namespace std;




int main()
{
    vector<Disc*> v;
    ReadDataFromFile(v,"proben_file.txt");

    for(int i = 0 ; i < v.size() ; ++i)
    {
        cout << *v[i] << endl;
    }


    Graph graph(v);
    list<Disc*> sorted;
    if(graph.TopSort(sorted))
       {
           for(list<Disc*>::iterator it = sorted.begin(), end = sorted.end() ; it != end ; ++it)
            {
                cout << (*it)->ident << " ";
            }
            cout << endl;
       }
    else {
        cout << "slabo" << endl;
        return -1;
    }

    //graph.printNodes();




    int neededECTK;
    cout << "Enter the needed ECTK: ";
    cin >> neededECTK;



    /// изтриване на дисциплините
    for(int i = 0 ; i < v.size() ; ++i)
        delete v[i];
    return 0;
}
