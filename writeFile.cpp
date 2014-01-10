#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ofstream write("proben_file.txt");
    if(!write)
    {
        cout << "Cannot open file !" << endl;
        return -1;
    }

    write << "12\t3D grafiki i trasirane na luchi\tI" << endl;
   //write << "12\t3Д графики и трасиране на лъчи\tИ" << endl;
   write << "I, IS, KN, M" << endl;
   //write << "И, ИС, КН, М, СИ" << endl;
   write << "2" << endl;
   write << "9.5" << endl;
   write << "9, 8, 11" << endl;

   write << "9\tBqsni algoritmi\tI" << endl;
   //write << "13\tБясни алгоритми\tИ" << endl;
  // write << "И, ИС, КН, М, ПМ, СИ" << endl;
   write << "I, IS, KN, M, PM, SI" << endl;
   write << "4" << endl;
   write << "10" << endl;
   write << "10, 8" << endl;

   write << "10\tDiferencialno i integralno smqtane purva chast\tZ" << endl;
   //write << "9\tДиференциално и интегрално смятане първа част\tЗ" << endl;
   write << "I, KN, PM, SI" << endl;
   //write << "И, КН, ПМ, СИ" << endl;
   write << "1" << endl;
   write << "7" << endl;
   write << "\n";

   write << "8\tAlgebra\tZ" << endl;
   write << "I, KN, PM, SI, Stat, M, IS" << endl;
   write << "1" << endl;
   write << "6.5" << endl;
   write << "11" << endl;

   write << "11\tDiskretni strukturi\tI" << endl;
   write << "I, KN, PM, SI, M, IS" << endl;
   write << "1" << endl;
   write << "10" << endl;
   write << "\n";
   write.close();
}
