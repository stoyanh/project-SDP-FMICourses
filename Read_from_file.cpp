#include "Read_from_file.h"
#include "Course.h"
#include <iostream>

void ReadDataFromFile(vector<Disc*>& v, const char* filename)
{
    ifstream file(filename);
    if(!file)
    {
        cout << "Cannot open file !" << endl;
        return;
    }

    while(file.good())
    {
        Disc* disc = new Disc;
        /// проверка дали е достигнат края на файла
        char tmp = file.peek();
        if(tmp == EOF)
            break;

        ReadDiscFromFile(disc,file);
        v.push_back(disc);
    }
    file.close();
}

void ReadDiscFromFile(Disc* disc, ifstream& file)
{
    ReadIdent(disc,file);
    ReadName(disc,file);
    ReadReq(disc,file);
    ReadSpecs(disc,file);
    ReadCourseNumb(disc,file);
    ReadECTK(disc,file);
    ReadDiscsToHavePassed(disc,file);
}

void ReadIdent(Disc* disc, ifstream& file)
{
    file >> disc->ident;
}

void ReadName(Disc* disc, ifstream& file)
{
    file.get(); /// изчистване на символа за табулация
    char letter;

    while(file.get(letter) && letter != '\t')
    {
        disc->name += letter;
    }
}

void ReadReq(Disc* disc, ifstream& file)
{
    string req;
    char letter;

    while(file.get(letter) && letter != '\n')
    {
        req += letter;
    }
    if(req.compare("I") == 0)
        disc->req = NO;
    else if(req.compare("Z") == 0)
        disc->req = YES;
}

void ReadSpecs(Disc* disc, ifstream& file)
{
    char letter;
    while(1)
    {
        string str;
        while(file.get(letter) && letter != ',' && letter != '\n')
        {
            str += letter;
        }
        disc->specs.push_back(str);
        if(letter == '\n')
            break;
        if(letter == ',')
            file.get(letter);
    }
}

void ReadCourseNumb(Disc* disc, ifstream& file)
{
    file >> disc->courseNumb;
}

void ReadECTK(Disc* disc, ifstream& file)
{
    file >> disc->ECTK;
}

void ReadDiscsToHavePassed(Disc* disc, ifstream& file)
{
    using std::cout;
    file.get(); /// изчистване на символа за нов ред

    char separator = 'a';

    /// проверка дали редът не е празен
    char tmp = file.peek();
    if(tmp == '\n')
    {
        file.get();

        //disc->discsToHavePassed.push_back(0);
        return;
    }

    /// четене на реда
    size_t numb;

    while(1)
    {
        file >> numb;
        disc->discsToHavePassed.push_back(numb);
        if(file.eof())
            break;
        file.get(separator);
        if(separator == ',')
            continue;//file.get();
        if(separator == '\n')
            break;
    }
}
