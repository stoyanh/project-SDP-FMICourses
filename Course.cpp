#include "Course.h"
#include <cstring>
Disc::Disc()
{
    this->ident = 0;
    this->courseNumb = 0;
    this->ECTK = 0;
}
ostream& operator << (ostream& os, const Disc& disc)
{
    os << disc.ident << "\t";
    os << disc.name << "\t";

    if(disc.req == YES)
        os << "Z" << endl;
    else if(disc.req == NO)
        os << "I" << endl;

    for(int i = 0 ; i < disc.specs.size() ; ++i)
    {
        if(i == disc.specs.size() - 1)
            os << disc.specs[i] << endl;
        else os << disc.specs[i] << ", ";
    }

    os << disc.courseNumb << endl;
    os << disc.ECTK << endl;

    if(!disc.discsToHavePassed.size())
    {
        cout << "No indentificators !" << endl;
        return os;
    }
    for(int i = 0 ; i < disc.discsToHavePassed.size() ; ++i)
    {
        if(i == disc.discsToHavePassed.size() - 1)
            os << disc.discsToHavePassed[i] << endl;
        else os << disc.discsToHavePassed[i] << ", ";
    }
    return os;
}
