#pragma once

#include <deque>
#include <iostream>
#include <list>
#include <string>

class PmergeMe {
	public:
		PmergeMe(int ac, char **arg); 
		PmergeMe(const PmergeMe& other); 
		PmergeMe& operator=(const PmergeMe& other); 
		~PmergeMe(); 

		void printList(std::list<int> list);

		std::list<int> doFusion(std::list<int> list1, std::list<int> list2);
		std::list<int> mergeSort(std::list<int> list);
		std::deque<int> doFusion(std::deque<int> deque1, std::deque<int> deque2);
		std::deque<int> mergeSort(std::deque<int> deque);
		
		void doMerge();

	private:
		std::list<int> _list;
		std::deque<int> _deque;
};