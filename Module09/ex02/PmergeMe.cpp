#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : _cmpVector(0), _cmpDeque(0) {}

PmergeMe::PmergeMe(int ac, char **av): _vector(), _deque(), _cmpVector(0), _cmpDeque(0) {
	if (ac < 2)
		throw std::invalid_argument("");
	
	for(int i = 1; i < ac; i++) {
		std::string perse = av[i];
		if (perse.empty()) {
			throw std::invalid_argument("");
		}
		for (size_t j = 0; j < perse.size(); j++) {
			if (!std::isdigit(perse[j])) {
				throw std::invalid_argument("");
			}
			if (perse[0] == '0' && perse.size() > 1) {
				throw std::invalid_argument("");
			}
		}
		long value = std::strtol(perse.c_str(), NULL, 10);
		if (value < 0 || value > INT_MAX) {
			throw std::invalid_argument("");
		}
		this->_vector.push_back(static_cast<int>(value));
		this->_deque.push_back(static_cast<int>(value));
	}
}

PmergeMe::PmergeMe(const PmergeMe &other)
{
	if (this != &other) {
		_vector = other._vector;
		_deque = other._deque;
		_cmpVector = other._cmpVector;
		_cmpDeque = other._cmpDeque;
	}
}


PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
	{
		_vector = other._vector;
		_deque = other._deque;
		_cmpVector = other._cmpVector;
		_cmpDeque = other._cmpDeque;
	}
	return *this;
}

PmergeMe::~PmergeMe() {}

// Suite de Jacobsthal : J(0)=0, J(1)=1, J(n)=J(n-1)+2*J(n-2)
// Retourne tous les termes <= n
std::vector<size_t> PmergeMe::generatorJacob(size_t n)
{
	std::vector<size_t> jacob;

	if (n == 0)
		return jacob;

	jacob.push_back(0);
	if (n == 1)
	{
		jacob.push_back(1);
		return jacob;
	}
	jacob.push_back(1);

	size_t i = 2;
	while (true)
	{
		size_t next = jacob[i - 1] + 2 * jacob[i - 2];
		if (next > n)
			break;
		jacob.push_back(next);
		i++;
	}
	return jacob;
}

size_t PmergeMe::binarySearchVector(std::vector<int> &vec, int value, size_t end)
{
	size_t low = 0;
	size_t high = end;
	while (low < high)
	{
		size_t mid = low + (high - low) / 2;
		_cmpVector++;
		if (vec[mid] < value)
			low = mid + 1;
		else
			high = mid;
	}
	return low;
}

size_t PmergeMe::binarySearchDeque(std::deque<int> &deq, int value, size_t end)
{
	size_t low = 0;
	size_t high = end;
	while (low < high)
	{
		size_t mid = low + (high - low) / 2;
		_cmpDeque++;
		if (deq[mid] < value)
			low = mid + 1;
		else
			high = mid;
	}
	return low;
}

void PmergeMe::mergePairsVector(std::vector<std::pair<int, int> > &pairs)
{
	if (pairs.size() <= 1)
		return;

	std::vector<int> larges;
	for (size_t i = 0; i < pairs.size(); i++)
		larges.push_back(pairs[i].first);

	fordJohnsonSortVector(larges);

	std::vector<std::pair<int, int> > sorted;
	std::vector<bool> used(pairs.size(), false);
	for (size_t i = 0; i < larges.size(); i++)
	{
		for (size_t j = 0; j < pairs.size(); j++)
		{
			if (!used[j] && pairs[j].first == larges[i])
			{
				sorted.push_back(pairs[j]);
				used[j] = true;
				break;
			}
		}
	}
	pairs = sorted;
}

void PmergeMe::fordJohnsonSortVector(std::vector<int> &vec)
{
	if (vec.size() <= 1)
		return;

	// Isoler le straggler si nombre impair
	bool hasStraggler = (vec.size() % 2 != 0);
	int straggler = hasStraggler ? vec.back() : 0;

	// Créer des paires (max, min) — 1 comparaison par paire
	std::vector<std::pair<int, int> > pairs;
	size_t limit = vec.size() - (hasStraggler ? 1 : 0);
	for (size_t i = 0; i < limit; i += 2)
	{
		_cmpVector++;
		if (vec[i] >= vec[i + 1])
			pairs.push_back(std::make_pair(vec[i], vec[i + 1]));
		else
			pairs.push_back(std::make_pair(vec[i + 1], vec[i]));
	}

	// Trier recursivement les paires par leur plus grand element
	mergePairsVector(pairs);

	// Construire la chaine principale : [b1, a1, a2, ..., an]
	std::vector<int> mainChain;
	mainChain.push_back(pairs[0].second);
	for (size_t i = 0; i < pairs.size(); i++)
		mainChain.push_back(pairs[i].first);

	// pend = [b2, b3, ..., bn]
	std::vector<int> pend;
	for (size_t i = 1; i < pairs.size(); i++)
		pend.push_back(pairs[i].second);

	if (!pend.empty())
	{
		// Suivi des positions des grands elements dans mainChain.
		// aPos[i] = position courante de pairs[i].first (a_{i+1}) dans mainChain.
		// Initialement : a_1 en pos 1, a_2 en pos 2, ..., a_n en pos n.
		// Cela evite une deuxieme recherche binaire pour trouver la borne.
		std::vector<size_t> aPos(pairs.size());
		for (size_t i = 0; i < pairs.size(); i++)
			aPos[i] = i + 1;

		// Suite de Jacobsthal pour l'ordre d'insertion : 1, 3, 5, 11, 21, ...
		// Chaque terme definit la fin d'un groupe a inserer en ordre decroissant.
		std::vector<size_t> jacob;
		jacob.push_back(1);
		jacob.push_back(3);
		while (jacob.back() < pend.size())
		{
			size_t n = jacob.size();
			jacob.push_back(jacob[n - 1] + 2 * jacob[n - 2]);
		}

		std::vector<bool> inserted(pend.size(), false);
		size_t prevJacob = 0;

		for (size_t k = 0; k < jacob.size(); k++)
		{
			size_t curr = (jacob[k] <= pend.size()) ? jacob[k] : pend.size();

			// Inserer de curr-1 a prevJacob (0-based), en ordre decroissant
			for (size_t idx = curr; idx > prevJacob; idx--)
			{
				size_t realIdx = idx - 1;
				if (!inserted[realIdx])
				{
					// La borne est directement aPos[realIdx+1] : position de a_{realIdx+2}.
					// On sait que pend[realIdx] <= pairs[realIdx+1].first, donc on
					// cherche uniquement dans [0, aPos[realIdx+1][.
					size_t bound = aPos[realIdx + 1];
					size_t pos = binarySearchVector(mainChain, pend[realIdx], bound);
					mainChain.insert(mainChain.begin() + pos, pend[realIdx]);
					inserted[realIdx] = true;
					// Mettre a jour les positions des grands elements decales par l'insertion
					for (size_t j = 0; j < aPos.size(); j++)
						if (aPos[j] >= pos)
							aPos[j]++;
				}
			}
			prevJacob = jacob[k];
			if (prevJacob >= pend.size())
				break;
		}

		// Inserer les elements restants non encore inseres
		for (size_t i = 0; i < pend.size(); i++)
		{
			if (!inserted[i])
			{
				size_t bound = aPos[i + 1];
				size_t pos = binarySearchVector(mainChain, pend[i], bound);
				mainChain.insert(mainChain.begin() + pos, pend[i]);
				for (size_t j = 0; j < aPos.size(); j++)
					if (aPos[j] >= pos)
						aPos[j]++;
			}
		}
	}

	// Inserer le straggler
	if (hasStraggler)
	{
		size_t pos = binarySearchVector(mainChain, straggler, mainChain.size());
		mainChain.insert(mainChain.begin() + pos, straggler);
	}

	vec = mainChain;
}

void PmergeMe::mergePairsDeque(std::deque<std::pair<int, int> > &pairs)
{
	if (pairs.size() <= 1)
		return;

	std::deque<int> larges;
	for (size_t i = 0; i < pairs.size(); i++)
		larges.push_back(pairs[i].first);

	fordJohnsonSortDeque(larges);

	std::deque<std::pair<int, int> > sorted;
	std::deque<bool> used(pairs.size(), false);
	for (size_t i = 0; i < larges.size(); i++)
	{
		for (size_t j = 0; j < pairs.size(); j++)
		{
			if (!used[j] && pairs[j].first == larges[i])
			{
				sorted.push_back(pairs[j]);
				used[j] = true;
				break;
			}
		}
	}
	pairs = sorted;
}

void PmergeMe::fordJohnsonSortDeque(std::deque<int> &deq)
{
	if (deq.size() <= 1)
		return;

	bool hasStraggler = (deq.size() % 2 != 0);
	int straggler = hasStraggler ? deq.back() : 0;

	std::deque<std::pair<int, int> > pairs;
	size_t limit = deq.size() - (hasStraggler ? 1 : 0);
	for (size_t i = 0; i < limit; i += 2)
	{
		_cmpDeque++;
		if (deq[i] >= deq[i + 1])
			pairs.push_back(std::make_pair(deq[i], deq[i + 1]));
		else
			pairs.push_back(std::make_pair(deq[i + 1], deq[i]));
	}

	mergePairsDeque(pairs);

	std::deque<int> mainChain;
	mainChain.push_back(pairs[0].second);
	for (size_t i = 0; i < pairs.size(); i++)
		mainChain.push_back(pairs[i].first);

	std::deque<int> pend;
	for (size_t i = 1; i < pairs.size(); i++)
		pend.push_back(pairs[i].second);

	if (!pend.empty())
	{
		std::vector<size_t> aPos(pairs.size());
		for (size_t i = 0; i < pairs.size(); i++)
			aPos[i] = i + 1;

		std::vector<size_t> jacob;
		jacob.push_back(1);
		jacob.push_back(3);
		while (jacob.back() < pend.size())
		{
			size_t n = jacob.size();
			jacob.push_back(jacob[n - 1] + 2 * jacob[n - 2]);
		}

		std::deque<bool> inserted(pend.size(), false);
		size_t prevJacob = 0;

		for (size_t k = 0; k < jacob.size(); k++)
		{
			size_t curr = (jacob[k] <= pend.size()) ? jacob[k] : pend.size();

			for (size_t idx = curr; idx > prevJacob; idx--)
			{
				size_t realIdx = idx - 1;
				if (!inserted[realIdx])
				{
					size_t bound = aPos[realIdx + 1];
					size_t pos = binarySearchDeque(mainChain, pend[realIdx], bound);
					mainChain.insert(mainChain.begin() + pos, pend[realIdx]);
					inserted[realIdx] = true;
					for (size_t j = 0; j < aPos.size(); j++)
						if (aPos[j] >= pos)
							aPos[j]++;
				}
			}
			prevJacob = jacob[k];
			if (prevJacob >= pend.size())
				break;
		}

		for (size_t i = 0; i < pend.size(); i++)
		{
			if (!inserted[i])
			{
				size_t bound = aPos[i + 1];
				size_t pos = binarySearchDeque(mainChain, pend[i], bound);
				mainChain.insert(mainChain.begin() + pos, pend[i]);
				for (size_t j = 0; j < aPos.size(); j++)
					if (aPos[j] >= pos)
						aPos[j]++;
			}
		}
	}

	if (hasStraggler)
	{
		size_t pos = binarySearchDeque(mainChain, straggler, mainChain.size());
		mainChain.insert(mainChain.begin() + pos, straggler);
	}

	deq = mainChain;
}

void PmergeMe::displayBefore() const
{
	std::cout << "Before: ";
	for (size_t i = 0; i < _vector.size(); i++)
	{
		std::cout << _vector[i];
		if (i < _vector.size() - 1)
			std::cout << " ";
	}
	std::cout << std::endl;
}

void PmergeMe::displayAfter() const
{
	std::cout << "After:  ";
	for (size_t i = 0; i < _vector.size(); i++)
	{
		std::cout << _vector[i];
		if (i < _vector.size() - 1)
			std::cout << " ";
	}
	std::cout << std::endl;
}

void PmergeMe::sortVector()
{
	fordJohnsonSortVector(_vector);
}

void PmergeMe::sortDeque()
{
	fordJohnsonSortDeque(_deque);
}

const std::vector<int> &PmergeMe::getVector() const { return _vector; }
const std::deque<int> &PmergeMe::getDeque() const { return _deque; }
size_t PmergeMe::getCmpVector() const { return _cmpVector; }
size_t PmergeMe::getCmpDeque() const { return _cmpDeque; }
