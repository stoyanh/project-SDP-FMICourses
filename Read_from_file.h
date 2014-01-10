#ifndef READ_FROM_FILE_H_INCLUDED
#define READ_FROM_FILE_H_INCLUDED

#include <fstream>
#include <vector>
#include "Course.h"

using namespace std;

void ReadDataFromFile(vector<Disc*>& , const char* );

void ReadDiscFromFile(Disc* , ifstream& );

void ReadIdent(Disc* , ifstream& );

void ReadName(Disc* , ifstream& );

void ReadReq(Disc* , ifstream& );

void ReadSpecs(Disc* , ifstream& );

void ReadCourseNumb(Disc* , ifstream& );

void ReadECTK(Disc* , ifstream& );

void ReadDiscsToHavePassed(Disc* , ifstream& );

#endif // READ_FROM_FILE_H_INCLUDED
