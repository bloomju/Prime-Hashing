#include <iostream>
#include <string>
#include "HashTable.h"

using std::cout;
using std::endl;
using std::string;


int main (int argc, char** argv)
{

    if (argc != 2)
        return 1;
    string arg1 = argv[1];
    double input1 = std::stod(arg1);

/*
    string arg2 = argv[2];
    int input2 = std::stoi(arg2); 
    
    string arg3 = argv[3];
    int input3 = std::stoi(arg3);

    HashTable* ht = new HashTable(input1);
    for(int ii=1; ii <=input3; ii++)
        cout << ht->nhash(input2, ii) << std::endl;
    delete ht;
*/
    HashTable* ht = new HashTable(50000);
    double sum = 0;
    for(int jj = 1; jj < 50; jj++)
    {
        int count = 0;
        for(int ii = 0; ii < 10000; ii++)
        {
            unsigned int usMax = 0;
            // unsigned integer max value
            usMax--;
            
            //unsigned int rand1 = ht->nhash(ii, jj);
            //unsigned int rand2 = ht->nhash(ii+input1, jj); 
            //double xx = ( (double) rand1 ) / usMax;
            //double yy = ( (double) rand2 ) / usMax;

            //if ((xx*xx+yy*yy)<1)
              //count++;
            unsigned int rand1 = ht->nhash(ii, jj);
            if ( rand1 < input1 * usMax)
                count++;
        }
        sum += count / 10000.0;
        cout << count / 10000.0 << endl; 
    }
    cout << "mean: " << sum / 50 << endl;
    //cout << "pi approximately = " << 4*sum / 50 << endl;
    delete ht;
    return 0;
}
