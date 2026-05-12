#ifndef PMERGEME_HPP
#define PMERGE_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <vector>
#include <deque>
#include <stdexcept>
#include <climits>

class PmergeMe
{
	private:
		std::vector<int> _vector;
		std::deque<int> _deque;
		size_t _cmpVector;
		size_t _cmpDeque;

		// suite de jacobsthal
		std::vector<size_t> generatorJacob(size_t n);

		// insertion binaire
		size_t binarySearchVector(std::vector<int> &vec, int value,size_t end);
		size_t binarySearchDeque(std::deque<int> &deq, int value, size_t end);

		// algo Ford-Johnson vector
		void fordJohnsonSortVector(std::vector<int> &vec);
	    void mergePairsVector(std::vector<std::pair<int, int> > &pairs);

		// algo Ford-Johnson deque
		void fordJohnsonSortDeque(std::deque<int> &vec);
		void mergePairsDeque(std::deque<std::pair<int, int> > &pairs);

	public:
		PmergeMe();
		PmergeMe(int ac, char **av);
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);
		~PmergeMe();

		void sortVector();
		void sortDeque();

		// Affichage
		void displayBefore() const;
		void displayAfter() const;

		// Getters
		const std::vector<int> &getVector() const;
		const std::deque<int> &getDeque() const;
		size_t getCmpVector() const;
		size_t getCmpDeque() const;
};

#endif