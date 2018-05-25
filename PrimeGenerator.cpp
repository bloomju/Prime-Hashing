#include <iostream>

#include "PrimeGenerator.h"

using std::cout;
using std::endl;

PrimeGenerator::PrimeGenerator(int max)
{
    listSize = 0;
    initialize_primes(max);
}

PrimeGenerator::~PrimeGenerator()
{
    node* nextUp = primeListHead->next;
    while(nextUp != primeListTail)
    {
        delete nextUp->prev;
        nextUp = nextUp->next;
    }
    delete nextUp->next;
    delete nextUp;
    delete [] primes;
}

unsigned int* PrimeGenerator::getPrimes()
{
    return primes;
}

unsigned int PrimeGenerator::getSize()
{
    return listSize;
}

void PrimeGenerator::initialize_sentinels()
{
    primeListHead = new node;
    primeListTail = new node;
    primeListHead->prev = nullptr;
    primeListHead->next = primeListTail;
    primeListTail->prev = primeListHead;
    primeListTail->next = nullptr;
    primeListHead->val = 0;
    primeListTail->val = 0;
}

void PrimeGenerator::initialize_natural(unsigned int max)
{
    initialize_sentinels();
    node* prevNat = primeListHead;
    for(unsigned int ii=2; ii <= max; ii++)
    {
        push(ii);
    }

}

void PrimeGenerator::initialize_primes(unsigned int max)
{
    initialize_natural(max);
    node* nextUp = primeListHead->next;
    while(nextUp->val < max / 2)
    {
        refine(nextUp->val);
        nextUp = nextUp->next;
    }
    primes = new unsigned int[listSize]; 
    int ii=0;
    nextUp = primeListHead->next;
    while(nextUp != primeListTail)
    {

        primes[ii] = nextUp->val;
        nextUp = nextUp->next;
        ii++;
    }
}

void PrimeGenerator::push(unsigned int val)
{
    node* newEnd = new node;
    newEnd->val = val;
    node* oldEnd = primeListTail->prev;
    primeListTail->prev = newEnd;
    newEnd->next = primeListTail;
    newEnd->prev = oldEnd;
    oldEnd->next = newEnd;
    listSize++;
}

void PrimeGenerator::pop(node* toPop)
{
    if(toPop == primeListHead || toPop == primeListTail)
        return;
    toPop->next->prev = toPop->prev;
    toPop->prev->next = toPop->next;
    delete toPop;
    listSize--;
}

void PrimeGenerator::printVals()
{
    node* nextUp = primeListHead;
    while(nextUp != nullptr)
    {
        cout << nextUp->val << ",";
        nextUp = nextUp->next;
    }
    cout << endl << endl;
}

void PrimeGenerator::refine(unsigned int mod)
{
    if(mod < 2 || mod > primeListTail->prev->val)
        return;
    node* nextUp = primeListHead->next;
    while(nextUp->val != 0)
    {
        if(nextUp->val != mod && nextUp->val % mod == 0)
        {
            nextUp = nextUp->next;
            pop(nextUp->prev);
        }
        else
            nextUp = nextUp->next;
    }
    
}
