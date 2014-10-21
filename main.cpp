/* 
 * File:   main.cpp
 * Author: Gowtham
 *
 * Created on October 21, 2014, 5:09 PM
 */

#include <cstdlib>
#include <iostream>
#include <chrono>
#include <time.h>
#include <cmath>
#include <limits>

using namespace std;

/*
 * 
 */

class BinTree {
public:

	struct node {
		node* left;
		node* right;
		unsigned int value;

		node(unsigned int value) : value(value) {
			left = NULL;
			right = NULL;
		}

		~node() {
			delete left;
			delete right;
		}
	};

	void insert(unsigned int value) {
		findNear(value);
		if (ref == NULL) {
			ref = new node(value);
		} else if (value < ref->value) {
			ref->left = new node(value);
		} else if (value > ref->value) {
			ref->right = new node(value);
		}
	}

	bool find(unsigned int value) {
		findNear(value);
		if (ref != NULL) {
			return false;
		} else {
			return true;
		}
	}

	BinTree() {
		ref = NULL;
	}

	~BinTree() {
		delete ref;
	}

private:
	node* ref;

	void findNear(unsigned int value) {
		if (ref) {
			if (value < ref->value) {
				if (ref->left != NULL) {
					ref = ref->left;
					findNear(value);
				}
			} else if (value > ref->value) {
				if (ref->right != NULL) {
					ref = ref->right;
					findNear(value);
				}
			}
		}
	}
};

void insert_find_n_no(unsigned int n) {
	BinTree myBinTree;
	int i = 0;
	int trials = 100;
	srand(time(NULL));
	auto start = std::chrono::high_resolution_clock::now();
	auto finish = start;
	auto diff = std::chrono::duration_cast<std::chrono::nanoseconds>
			(finish - start).count();
	std::cout.precision(3);
	while (trials > 0) {
		start = std::chrono::high_resolution_clock::now();
		while (i < n) {
			myBinTree.insert(rand() % 100000000);
			i++;
		}
		finish = std::chrono::high_resolution_clock::now();
		diff += std::chrono::duration_cast<std::chrono::nanoseconds>
				(finish - start).count();
		trials--;
	}
	diff /= 100;
	std::cout << "n=" << n << " insert: " <<
			std::fixed << (((double) diff) / 1000000) << "ms; ";
	i = 0;
	trials = 100;
	diff = 0;
	while (trials > 0) {
		start = std::chrono::high_resolution_clock::now();
		while (i < 10000) {
			myBinTree.find(rand() % 100000000);
			i++;
		}
		finish = std::chrono::high_resolution_clock::now();
		diff += std::chrono::duration_cast<std::chrono::nanoseconds>
				(finish - start).count();
		trials--;
	}
	diff /= 100;
	std::cout << "find: " <<
			std::fixed << (((double) diff) / 1000000) << "ms\n";
}

int main(int argc, char** argv) {
	insert_find_n_no(50);
	insert_find_n_no(10000);
	insert_find_n_no(10000000);
	return 0;
}

