#pragma once

#include <deque>
#include <iostream>
#include <list>
#include <vector>
#include <string>

class PmergeMe {
	public:
		PmergeMe(int ac, char **arg); 
		PmergeMe(const PmergeMe& other); 
		PmergeMe& operator=(const PmergeMe& other); 
		~PmergeMe(); 

		void printVector(std::vector<int> vec);
		void printList(std::list<int> lst);


		std::vector<int> sortVec();
		
		void doMerge();

	private:
		std::list<int> _list;
		std::vector<int> _vector;
};