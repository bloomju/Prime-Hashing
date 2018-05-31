# Prime-Hashing
This is a demonstration for my personal research in number theory. I've been using the prime sequence in order to generate random bits, which are in turn used for a hashing function.
## Instructions:
When compiled, an executable named "hash" will appear. 
* Typing the command "hash write n" (where n is a positive integer) will use a slow algorithm to write the first n prime numbers to the file "primes.dat".  
* Typing the command "hash link n" (where n is a positive integer) will use a more advanced algorithm to write all prime numbers less than n to the file "primes.dat". You will find that this algorithm takes about half as long as hash write.
* Typing the command "hash read n" (where n is a positive integer) will use the prime numbers stored in prime.dat in order to generate n pseudorandom numbers. It will tally these numbers based on which interval they fall in, and you will be able to see the distribution of all of these numbers per each interval.  
* Typing the command "hash demo n" (where n is a positive integer) will display a small demonstration of the actual pseudorandom numbers being generated.  
* Typing the command "hash compare n" (where n is a positive integer) will display a comparison to built in random number generators libraries, by generating n pseudorandom numbers and displaying the distribution of all these numbers per each interval. You are guaranteed to find a nearly uniform distribution, unlike with the hash read procedure, which you will find to have biases depending on how many prime numbers are in primes.dat.
