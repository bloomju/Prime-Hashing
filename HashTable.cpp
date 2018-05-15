#include "HashTable.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

HashTable::HashTable()
{
    //initializes primes and hashSize
    readPrimes();
    bits = bitSeq();
    std::cout << "Bits initialized" << std::endl;
}

HashTable::HashTable(unsigned int sz)
{
    hashSize = sz;
    writePrimes();
    bits = bitSeq();
    std::cout << "Bits initialized" << std::endl;
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
    int* result = new int[hashSize];
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
    std::cout << hashSize << " terms of prime sequence initialized" << std::endl;
    return result;
}

int HashTable::getPrime(int ii)
{
    return primes[ii];
}

unsigned int HashTable::halfHash(unsigned int input)
{
    if(hashSize < 34)
        return -1;
    unsigned int result = 0;
    int mul = 1;
    for(int ii = 0; ii < 32; ii++) 
    {
        //result+= (mul*bits[(input+ii)%(3*hashSize-5)]);
        result += (mul*bits[(input+ii)%(hashSize-2)]);
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
    //bool* result = new bool[3*hashSize-5];

    bool* result = new bool[hashSize-2];
    
    int next = 0;  
    /*
    for(unsigned int ii = 2; ii < hashSize; ii++ )
    {
        result[next] = ((primes[ii] % 3) == 1);
        next++;
    }
    */
    for(unsigned int ii = 1; ii < hashSize; ii++ )
    {
        result[next] = ((primes[ii] % 4) == 1);
        next++;
    }
    /*
    
    for(unsigned int ii = 2; ii < hashSize; ii++ )
    {
        result[next] = ((primes[ii] % 6) == 1);
        next++;
    }
    */
    return result;
}

bool HashTable::getBit(int ii)
{
    return bits[ii];
}

void HashTable::writePrimes()
{
    std::ofstream file;
    file.open("prime.dat", std::ofstream::binary);
    unsigned int feeder[2];
    feeder[1] = 0; //null terminator for when location is cast to char*
    if(file.is_open())
    {
        std::cout << "prime.dat opened for writing" << std::endl;
        primes = primeSeq();
        for(unsigned int ii = 0; ii < hashSize; ii++)
        {
            *feeder = primes[ii];
            file.write((char*)feeder, sizeof(int));
        }
        *feeder = 0;
        file.write((char*)feeder, sizeof(int));
        file.close();
        std::cout << "prime.dat closed for writing" << std::endl;
    }
}

void HashTable::readPrimes()
{
   std::ifstream file;
   file.open("prime.dat", std::ifstream::binary);
   if(file.is_open())
   {
       std::cout << "prime.dat opened for reading" << std::endl;
       std::stringstream strStream;
       strStream << file.rdbuf();
       std::string strPrimes = strStream.str();
       hashSize = ( strPrimes.length() / (sizeof(int) / sizeof(char)) ) - 1;
       
       std::cout << hashSize << " prime numbers read from prime.dat" << std::endl;
       
       primes = new int[hashSize];
       
       const char* bitWisePrimes = strPrimes.c_str();
       int* fromFile = (int*)bitWisePrimes;
       
       for(int ii = 0; ii < hashSize; ii++)
       {
           primes[ii] = fromFile[ii];
       }
       
       file.close();
       std::cout << "prime.dat closed for reading" << std::endl;
   }
}
