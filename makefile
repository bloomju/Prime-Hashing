all: hash

hash: main.cpp HashTable.cpp
	g++ -std=c++11 main.cpp HashTable.cpp PrimeGenerator.cpp -o hash
clean:
	rm -rf hash
