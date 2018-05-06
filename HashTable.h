#ifndef HASHTABLE_H
#define HASHTABLE_H

class HashTable
{
public:
    /**
     * Constructor takes in an int for the size of the prime sequence
     */
    HashTable(const unsigned int sz);
    ~HashTable();

    /**
     * Takes single integer input
     * Determines if int is prime
     */
    static bool isPrime(int);

    /**
     * Returns primes sequence with hashSize terms
     */
    int* primeSeq();

    /**
     * takes single positive integer
     * returns number based on prime modulo sequence
     */ 
    unsigned int halfHash(unsigned int);
    /*
     * takes single positive integer
     * returns very unpredictable number
     */
    unsigned int hash(unsigned int);
    /*
     * takes single positive integer
     * returns like a super hard to predict number
     */
    unsigned int dhash(unsigned int);
    /*
     * takes two positive integers
     * first parameter is starting condition
     * second number is the number of iterative compositions
     * returns an unreasonably hard to predict number
     */
    unsigned int nhash(unsigned int, unsigned int);

private:
    /*************************************
     * Package for prime hashing process *
     ************************************/
     int hashSize;
     int* primes;
     bool* bits;
     bool* bitSeq();
     
    /*********************
     * Package for table *
     ********************/

};
#endif
