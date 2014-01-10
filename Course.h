#ifndef COURSE_H_INCLUDED
#define COURSE_H_INCLUDED
#include <string>
#include <vector>
#include <iostream>
using namespace std;

enum Required { YES, NO };
using std::vector;
using std::string;

const int MAX = 100;

struct Disc
{
    friend ostream& operator << (ostream& , const Disc&);
    Disc();

    size_t ident; /// индентификатор
    string name; /// наименование на курса
    size_t courseNumb; /// курсът,за който е предназначена дисциплината
    float ECTK; /// брой кредити
    Required req; /// задължителен или избираем
    vector<string> specs; /// специалностите, за които е предназначен курсът
    vector<size_t> discsToHavePassed; /// индентификаторите на курсовете,които трябва да си изкарал,за да запишеш курса
};


#endif // COURSE_H_INCLUDED
