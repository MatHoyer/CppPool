#include "PmergeMe.hpp"
#include <algorithm>
#include <bits/types/clock_t.h>
#include <cstddef>
#include <cstdlib>
#include <iterator>
#include <list>
#include <utility>
#include <vector>

PmergeMe::PmergeMe(int ac, char **arg) {
	for (int i = 1; i < ac; i++) {
		int nb = std::atoi(arg[i]);
		_list.push_back(nb);
		_vector.push_back(nb);
	}
}

PmergeMe::PmergeMe(const PmergeMe& other) {
	_vector = other._vector;
	_list = other._list;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
	if (this == &other)
		return *this;
	_vector = other._vector;
	_list = other._list;
	return *this;
}

PmergeMe::~PmergeMe() {

}

void PmergeMe::printVector(std::vector<int> vec) {
	for (size_t i = 0; i < vec.size(); i++) {
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl;
}

void PmergeMe::printList(std::list<int> lst) {
	for (size_t i = 0; i < lst.size(); i++) {
		std::cout << lst.front() << " ";
		lst.pop_front();
	}
	std::cout << std::endl;
}

int jacobsthal(int n) {
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return jacobsthal(n - 1) + 2 * jacobsthal(n - 2);
}

// ========================================== VECTOR ==============================================
std::vector<std::pair<int, int> > sortPair(std::vector<std::pair<int, int> > S) {
	std::vector<std::pair<int, int> > sortedS;
	int min[2];
	std::vector<std::pair<int, int> >::iterator itMem;
	while (!S.empty()) {
		min[0] = 0;
		min[1] = 2147483647;
		for (std::vector<std::pair<int, int> >::iterator it = S.begin(); it != S.end(); it++) {
			if (it->second < min[1]) {
				min[0] = it->first; 
				min[1] = it->second;
				itMem = it;
			}
		}
		S.erase(itMem);
		sortedS.push_back(std::make_pair(min[0], min[1]));
	}
	return sortedS;
}

void insertJacob(std::vector<std::pair<int, int> > S, std::vector<int>& vector) {
	int indJacob = 0;
	while (indJacob != -1) {
		int start = jacobsthal(indJacob);
		if ((size_t)start > vector.size())
			break;
		std::vector<std::pair<int, int> >::iterator it = S.begin();
		std::advance(it, start);
		while (!S.empty()) {
			std::vector<int>::iterator insertIt = std::upper_bound(vector.begin(), vector.end(), it->first);
			vector.insert(insertIt, it->first);
			S.erase(it);
			if (it != S.begin())
				it--;
		}
		++indJacob;
	}
}

std::vector<int> PmergeMe::sortVec() {
	if (_vector.empty() || _vector.size() == 1)
		return _vector;
	std::vector<std::pair<int, int> > S;
	for (std::vector<int>::iterator it = _vector.begin(); it != _vector.end(); it++) {
		std::vector<int>::iterator itNext = it;
		++itNext;
		if (itNext != _vector.end()) {
			S.push_back(std::make_pair(*it, *itNext));
			it++;
		}
		else
			S.push_back(std::make_pair(*it, -1));
	}
	for (std::vector<std::pair<int, int> >::iterator it = S.begin(); it != S.end(); it++) {
		if (it->first > it->second) {
			int tmp = it->first;
			it->first = it->second;
			it->second = tmp;
		}
	}
	S = sortPair(S);
	std::vector<int> newVector;
	for (std::vector<std::pair<int, int> >::iterator it = S.begin(); it != S.end(); it++)
		newVector.push_back(it->second);
	insertJacob(S, newVector);
	while (newVector.front() == -1)
		newVector.erase(newVector.begin());
	return newVector;
}

// ========================================== LIST ==============================================
std::list<std::pair<int, int> > sortPair(std::list<std::pair<int, int> > S) {
	std::list<std::pair<int, int> > sortedS;
	int min[2];
	std::list<std::pair<int, int> >::iterator itMem;
	while (!S.empty()) {
		min[0] = 0;
		min[1] = 2147483647;
		for (std::list<std::pair<int, int> >::iterator it = S.begin(); it != S.end(); it++) {
			if (it->second < min[1]) {
				min[0] = it->first; 
				min[1] = it->second;
				itMem = it;
			}
		}
		S.erase(itMem);
		sortedS.push_back(std::make_pair(min[0], min[1]));
	}
	return sortedS;
}

void insertJacob(std::list<std::pair<int, int> > S, std::list<int>& list) {
	int indJacob = 0;
	while (indJacob != -1) {
		int start = jacobsthal(indJacob);
		if ((size_t)start > list.size())
			break;
		std::list<std::pair<int, int> >::iterator it = S.begin();
		std::advance(it, start);
		while (!S.empty()) {
			std::list<int>::iterator insertIt = std::upper_bound(list.begin(), list.end(), it->first);
			list.insert(insertIt, it->first);
			S.erase(it);
			if (it != S.begin())
				it--;
		}
		++indJacob;
	}
}

std::list<int> PmergeMe::sortList() {
	if (_list.empty() || _list.size() == 1)
		return _list;
	std::list<std::pair<int, int> > S;
	for (std::list<int>::iterator it = _list.begin(); it != _list.end(); it++) {
		std::list<int>::iterator itNext = it;
		++itNext;
		if (itNext != _list.end()) {
			S.push_back(std::make_pair(*it, *itNext));
			it++;
		}
		else
			S.push_back(std::make_pair(*it, -1));
	}
	for (std::list<std::pair<int, int> >::iterator it = S.begin(); it != S.end(); it++) {
		if (it->first > it->second) {
			int tmp = it->first;
			it->first = it->second;
			it->second = tmp;
		}
	}
	S = sortPair(S);
	std::list<int> newList;
	for (std::list<std::pair<int, int> >::iterator it = S.begin(); it != S.end(); it++)
		newList.push_back(it->second);
	insertJacob(S, newList);
	while (newList.front() == -1)
		newList.erase(newList.begin());
	return newList;
}

void PmergeMe::doMerge() {
	{
		printVector(_vector);
		clock_t start = clock();
		_vector = sortVec();
		clock_t end = clock();
		printVector(_vector);
		std::cout << "Time to process a range of " << _vector.size() << " elements with std::vector : " << static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000 << " us" << std::endl;
	}
	{
		clock_t start = clock();
		_list = sortList();
		clock_t end = clock();
		std::cout << "Time to process a range of " << _list.size() << " elements with std::list : " << static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000 << " us" << std::endl;
	}
}