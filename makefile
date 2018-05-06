all: hash

hash: main.cpp HashTable.cpp
	g++ -std=c++11 main.cpp HashTable.cpp -o hash
