#include "PmergeMe.hpp"
#include <sys/time.h>
#include <cstddef>
#include <cstdlib>

PmergeMe::PmergeMe(int ac, char **arg) {
	for (int i = 1; i < ac; i++) {
		int nb = std::atoi(arg[i]);
		_list.push_back(nb);
		_deque.push_back(nb);
	}
}

PmergeMe::PmergeMe(const PmergeMe& other) {
	_deque = other._deque;
	_list = other._list;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
	if (this == &other)
		return *this;
	_deque = other._deque;
	_list = other._list;
	return *this;
}

PmergeMe::~PmergeMe() {

}

void PmergeMe::printList(std::list<int> list) {
	for (std::list<int>::iterator it = list.begin(); it != list.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

std::list<int> PmergeMe::doFusion(std::list<int> list1, std::list<int> list2) {
	std::list<int> listTotal;

	while (list1.size() && list2.size()) {
		if (list1.front() < list2.front()) {
			listTotal.push_back(list1.front());
			list1.pop_front();
		}
		else {
			listTotal.push_back(list2.front());
			list2.pop_front();
		}
	}
	while (list1.size()) {
		listTotal.push_back(list1.front());
		list1.pop_front();
	}
	while (list2.size()) {
		listTotal.push_back(list2.front());
		list2.pop_front();
	}
	return listTotal;
}

std::list<int> PmergeMe::mergeSort(std::list<int> list) {
	if (list.size() <= 1)
		return list;

	size_t middle = list.size() / 2;
	std::list<int> list1;
	std::list<int> list2;
	while (list.size() != middle) {
		list1.push_back(list.front());
		list.pop_front();
	}
	while (list.size()) {
		list2.push_back(list.front());
		list.pop_front();
	}
	return doFusion(mergeSort(list1), mergeSort(list2));
}

std::deque<int> PmergeMe::doFusion(std::deque<int> deque1, std::deque<int> deque2) {
	std::deque<int> dequeTotal;

	while (deque1.size() && deque2.size()) {
		if (deque1.front() < deque2.front()) {
			dequeTotal.push_back(deque1.front());
			deque1.pop_front();
		}
		else {
			dequeTotal.push_back(deque2.front());
			deque2.pop_front();
		}
	}
	while (deque1.size()) {
		dequeTotal.push_back(deque1.front());
		deque1.pop_front();
	}
	while (deque2.size()) {
		dequeTotal.push_back(deque2.front());
		deque2.pop_front();
	}
	return dequeTotal;
}

std::deque<int> PmergeMe::mergeSort(std::deque<int> deque) {
	if (deque.size() <= 1)
		return deque;

	size_t middle = deque.size() / 2;
	std::deque<int> deque1;
	std::deque<int> deque2;
	while (deque.size() != middle) {
		deque1.push_back(deque.front());
		deque.pop_front();
	}
	while (deque.size()) {
		deque2.push_back(deque.front());
		deque.pop_front();
	}
	return doFusion(mergeSort(deque1), mergeSort(deque2));
}

void PmergeMe::doMerge() {
	struct timeval start, end;
	{
		printList(_list);
		gettimeofday(&start, NULL);
		_list = mergeSort(_list);
		gettimeofday(&end, NULL);
		printList(_list);
		unsigned long timeToExec = (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_usec - start.tv_usec);
		std::cout << "Time to process a range of " << _list.size() << " elements with std::list : " << timeToExec << " us" << std::endl;
	}
	{
		gettimeofday(&start, NULL);
		_deque = mergeSort(_deque);
		gettimeofday(&end, NULL);
		unsigned long timeToExec = (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_usec - start.tv_usec);
		std::cout << "Time to process a range of " << _deque.size() << " elements with std::deque : " << timeToExec << " us" << std::endl;
	}

}