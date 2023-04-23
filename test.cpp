#include <iostream>
#include <vector>

/* testing iterator insert and erase*/
/* this test is not part of the subject. Its here as a reminder of how vector works */

int main (void)
{
	std::vector<int> v, v2;

	for (int i = 0; i < 10; ++i)
		v.push_back(i);

	v2 = v;

	std::cout << "v = " ; for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it) {std::cout << *it << " ";} std::cout << std::endl;
	std::cout << "distance(v.begin(), v.end())	= " << distance(v.begin(), v.end()) << std::endl;
	std::cout << "v.size () 			= " << v.size() << std::endl << std::endl;

	std::vector<int>::iterator it1 = v.begin() + 1, it5 = v.begin() + 5, it7 = v.begin() + 7;
	std::cout << "~~~~~~~ original ~~~~~~~" << std::endl;
	std::cout << "it1 = " << *it1 << " it5 = " << *it5 << " it7 = " << *it7 << std::endl << std::endl;

	v.insert(it1, 100000);
	std::cout << "~~~~~~~ v.insert(it1, 100000) ~~~~~~~" << std::endl;
	std::cout << "it1 = " << *it1 << " it5 = " << *it5 << " it7 = " << *it7 << std::endl << std::endl;

	v.erase(it1);
	std::cout << "~~~~~~~ v.erase(it1) ~~~~~~~" << std::endl;
	std::cout << "it1 = " << *it1 << " it5 = " << *it5 << " it7 = " << *it7 << std::endl << std::endl;

	std::cout << "~~~~~~~ comparing v and v2 v.insert(it1, 100000) ~~~~~~~" << std::endl;
		v.insert(it1, 100000);
		v2.insert(v2.begin() + distance(v2.begin(), v2.end()) / 2, 100000);
	std::cout << "v = " ; for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it) {std::cout << *it << " ";} std::cout << std::endl;
	std::cout << "v2 = " ; for (std::vector<int>::iterator it = v2.begin(); it != v2.end(); ++it) {std::cout << *it << " ";} std::cout << std::endl;
	v2 = v;
	std::cout << "v2 = " ; for (std::vector<int>::iterator it = v2.begin(); it != v2.end(); ++it) {std::cout << *it << " ";} std::cout << std::endl;
}

// --> conclusion
// --> distance of vector.begin(),vector.end() = _vector.size();
// --> after an insert, iterators stays at same "index", thus *ite changes in value
// --> =operator is a "deep copy" --> must be calling new
