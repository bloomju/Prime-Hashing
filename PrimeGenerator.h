#ifndef PRIME_GENERATOR
#define PRIME_GENERATOR
/***************************************************
* Test class for generating primes more efficiently.
* Uses linked list method
* *************************************************/
struct node
{
    unsigned int val;
    node* next;
    node* prev;
};

class PrimeGenerator 
{
public:
    PrimeGenerator(int);
    ~PrimeGenerator();
    unsigned int* getPrimes();
    void printVals();
    unsigned int getSize();
private:
    node* primeListHead;
    node* primeListTail;
    unsigned int* primes;
    unsigned int listSize;
    /**************************
    * initializes head and tail
    * ************************/
    void initialize_sentinels();
    /***********************************************************
    * initializes prime sequence to natural numbers below input
    * *********************************************************/
    void initialize_natural(unsigned int);
    
    /********************************************************
     * initialized prime list  by refining natural numbers
     * stores vals directly to primes array
     * *****************************************************/
    void initialize_primes(unsigned int);

    /****************************
    * pushes input to end of list
    * ***************************/
    void push(unsigned int);
    
    /*************************************
     * pops a specific node frome the list
     * node can not be sentinel
     * ***********************************/
    void pop(node*);

    /************************************************
     * iterates through list, popping nodes with vals
     * which are divisible by input
     * *********************************************/
    void refine(unsigned int);
};
#endif
