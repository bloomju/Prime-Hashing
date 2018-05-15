#include <iostream>
#include <string>
#include "HashTable.h"

using std::cout;
using std::endl;
using std::string;


void readProc(int);
void demoProc(int);

int main (int argc, char** argv)
{

    if (argc != 3)
    {
        cout << "invalid inputs" << endl;
        return 1;
    }
    
    string arg1 = argv[1];
    
    string arg2 = argv[2];
    int input2 = std::stoi(arg2);
    if(arg1 == "write")
    {
        HashTable* ht = new HashTable(input2);
        delete ht;
    }
    else if (arg1 == "read")
    {
        readProc(input2);
    }
    else if(arg1 == "demo")
    {
        demoProc(input2);
    }
    else
    {
        cout << "invalid inputs" << endl;
        return 1;
    }

    return 0;
}

void readProc(int num)
{
    HashTable* ht = new HashTable();
    int* intervalCounts = new int[10];
    for(int ii=0; ii < 10; ii++)
        intervalCounts[ii] = 0;
    
    cout << "Preparing to count proportions in intervals of length 0.1\n" << endl;

    for(int ii = 0; ii < num; ii++)
    {
        unsigned int usMax = 0;
        //unsigned integer max value
        usMax--;

        unsigned int rand = ht->dhash(ii);
        for(int jj = 0; jj < 10; jj++)
        {
            if(rand >= (0.1*jj)*usMax && rand <= (0.1*(jj+1))*usMax)
                intervalCounts[jj]++;
            
        }
    }

    cout << "The distribution of prime modulus is approximately: " << endl;
    for(int ii = 0; ii < 10; ii++)
    {
        cout << "[" << 0.1*ii << "," << 0.1*(ii+1) << "]: "
            << ((double)intervalCounts[ii]) / num << endl;
    }

    delete [] intervalCounts;
    delete ht;
}

void demoProc(int num)
{
    HashTable* ht = new HashTable();

    cout << "The first " << num << " numbers above 3 are:" << endl;

    for(int ii=0; ii < num; ii++)
        cout << ht->getPrime(ii+2) << ", ";
    cout << "\n\nThe first " << num  << " bits from prime sequence are:\nmod 4: ";
    for(int ii=0; ii < num; ii++)
        cout << ht->getBit(ii) << ((ii%4 == 3) ? " " : "");
    cout << "\nmod 3: ";
    for(int ii=0; ii < num; ii++)
        cout <<( (ht->getPrime(ii+2) % 3) == 1 ) << ((ii%4 == 3) ? " " : "");
    cout << "\nmod 6: ";
    for(int ii=0; ii < num; ii++)
        cout <<( (ht->getPrime(ii+2) % 6) == 1 ) << ((ii%4 == 3) ? " " : "");

    cout << "\n\nThe first " << num-31 << " half-hashed numbers are: ";
    for(int ii=0; ii < num - 31; ii++)
        cout << ht->halfHash(ii) << ", ";
    cout << endl;
    
    delete ht;
}
