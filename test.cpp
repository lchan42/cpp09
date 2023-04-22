#include <iostream>
#include <vector>

/* testing iterator insert and erase*/

int main (void)
{
	std::vector<int> v;

	for (int i = 0; i < 10; ++i)
		v.push_back(i);

	std::vector<int>::iterator it1 = v.begin() + 1, it5 = v.begin() + 5, it7 = v.begin() + 7;
	std::cout << "~~~~~~~ original ~~~~~~~" << std::endl;
	std::cout << "it1 = " << *it1 << " it5 = " << *it5 << " it7 = " << *it7 << std::endl << std::endl;

	v.insert(it1, 100000);
	std::cout << "~~~~~~~ v.insert(it1, 100000) ~~~~~~~" << std::endl;
	std::cout << "it1 = " << *it1 << " it5 = " << *it5 << " it7 = " << *it7 << std::endl << std::endl;

	v.erase(it1);
	std::cout << "~~~~~~~ v.erase(it1) ~~~~~~~" << std::endl;
	std::cout << "it1 = " << *it1 << " it5 = " << *it5 << " it7 = " << *it7 << std::endl << std::endl;
}

// --> after an insert, iterators stays at same "index", thus *ite changes in value
