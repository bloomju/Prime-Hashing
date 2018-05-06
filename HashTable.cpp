#include "HashTable.h"
#include <iostream>

HashTable::HashTable(unsigned int sz)
{
    hashSize = sz;
    primes = primeSeq();
    std::cout << sz << " terms of prime sequence initialized" << std::endl;
    bits = bitSeq();
    std:: cout << "Bits initialized" << std::endl;
}

HashTable::~HashTable()
{
    delete [] primes;
    std::cout << "prime sequence deleted" << std::endl;
    delete [] bits;
    std::cout << "Bit Sequence deleted" << std::endl;
}

bool HashTable::isPrime (int pp)
{
    for(int ii = 2; ii < pp; ii++)
    {
        if (pp % ii == 0)
            return pp == 2;
    }
    return pp > 1;
}

int* HashTable::primeSeq()
{
    if (hashSize <= 0)
        return nullptr;
    int * result = new int[hashSize];
    int count = 0;
    int ii = 2;
    while (count < hashSize)
    {
        if(isPrime(ii))
        {
            result[count] = ii;
            count++;
        }
        ii++;
    }
    return result;
}

unsigned int HashTable::halfHash(unsigned int input)
{
    if(hashSize < 34)
        return -1;
    unsigned int result = 0;
    int mul = 1;
    for(int ii = 0; ii < 32; ii++) 
    {
        result+= (mul*bits[(input+ii)%(3*hashSize-5)]);
        mul *= 2;
    }
    return result;
}

unsigned int HashTable::hash(unsigned int input)
{
    return halfHash(halfHash(input));
}

unsigned int HashTable::dhash(unsigned int input)
{
    return hash(hash(input));
}

unsigned int HashTable::nhash(unsigned int input, unsigned int comps)
{
    unsigned int result = input;
    for(int ii=comps; ii > 0; ii--)
    {
        result = dhash(result);
    }
}

bool* HashTable::bitSeq()
{
    bool* result = new bool[3*hashSize-5];

    int next = 0;  
    for(int ii = 2; ii < hashSize; ii++ )
    {
        result[next] = ((primes[ii] % 3) == 1);
        next++;
    }
    for(int ii = 1; ii < hashSize; ii++ )
    {
        result[next] = ((primes[ii] % 4) == 1);
        next++;
    }
    for(int ii = 2; ii < hashSize; ii++ )
    {
        result[next] = ((primes[ii] % 6) == 1);
        next++;
    }

    return result;
}