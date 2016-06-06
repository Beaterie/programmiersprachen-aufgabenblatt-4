#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <math.h>
#include "Vec2.hpp"
#include "color.hpp"
#include "circle.hpp"
#include "List.hpp"

TEST_CASE("test_of_List", "[List]"){
	List<int> l1;
	REQUIRE(l1.size() == 0);
	REQUIRE(l1.empty() == true);
}

TEST_CASE("test_of_push_and_pop_back", "[back]"){
	List<int> l2;
	REQUIRE(l2.size() == 0);
	REQUIRE(l2.empty() == true);
	l2.push_back(4);
	REQUIRE(l2.front() == 4);
	REQUIRE(l2.back() == 4);
	REQUIRE(l2.size() == 1);
	l2.push_back(5);
	REQUIRE(l2.front() == 4);
	REQUIRE(l2.back() == 5);
	REQUIRE(l2.size() == 2);
	l2.pop_back();
	REQUIRE(l2.front() == 4);
	REQUIRE(l2.back() == 4);
	REQUIRE(l2.size() == 1);
	l2.pop_back();
	REQUIRE(l2.size() == 0);
	REQUIRE(l2.empty() == true);
}

TEST_CASE("test_of_push_and_pop_front", "[front]"){
	List<int> l3;
	REQUIRE(l3.size() == 0);
	REQUIRE(l3.empty() == true);
	l3.push_front(4);
	REQUIRE(l3.front() == 4);
	REQUIRE(l3.back() == 4);
	REQUIRE(l3.size() == 1);
	l3.push_front(5);
	REQUIRE(l3.front() == 5);
	REQUIRE(l3.back() == 4);
	REQUIRE(l3.size() == 2);
	l3.pop_front();
	REQUIRE(l3.front() == 4);
	REQUIRE(l3.back() == 4);
	REQUIRE(l3.size() == 1);
	l3.pop_front();
	REQUIRE(l3.size() == 0);
	REQUIRE(l3.empty() == true);
}

TEST_CASE("should be empty after clearing", "[modifiers]"){
	List<int> list;
	list.push_front(1);
	list.push_front(2);
	list.push_front(3);
	list.push_front(4);
	list.clear();
	REQUIRE(list.empty() == true);
}

TEST_CASE("should be an empty range after default construction", "[iterators]"){
	List<int> list;
	auto b = list.begin();
	auto e = list.end();
	REQUIRE(b == e);
}

TEST_CASE("provide acces to the first element with begin", "[iterators]"){
	List<int> list;
	list.push_front(42);
	REQUIRE(42 == *list.begin());
}

TEST_CASE("compare", "[Vergleich zweier Listen]"){
	List<int> l1;
	List<int> l2;
	List<int> l3;
	l1.push_front(2);
	l1.push_front(4);
	l1.push_front(6);
	l2.push_front(2);
	l2.push_front(4);
	l2.push_front(6);
	l3.push_front(2);
	l3.push_front(5);
	l3.push_front(6);
	REQUIRE(l1 == l2);
	REQUIRE(!(l1 == l3));
	REQUIRE(!(l1 != l2));
	REQUIRE(l1 != l3);
}

TEST_CASE("copy constructor", "[constructor]"){
	List<int> list;
	list.push_front(1);
	list.push_front(2);
	list.push_front(3);
	list.push_front(4);
	List<int> list2{list};
	REQUIRE(list == list2);
}

TEST_CASE("insert", "[insert]"){
	List<int> l1;
	l1.push_back(1);
	l1.push_back(2);
	l1.push_back(3);
	for (ListIterator <int> i = l1.begin(); i != l1.end(); ++i){
		l1.insert(i,7);
	}
	List<int> l2;
	l2.push_back(7);
	l2.push_back(1);
	l2.push_back(7);
	l2.push_back(2);
	l2.push_back(7);
	l2.push_back(3);
	REQUIRE(l1 == l2);
}

TEST_CASE("reverse", "[reverse]"){
	List<int> l1;
	l1.push_back(1);
	l1.push_back(2);
	l1.push_back(3);
	REQUIRE(l1.front() == 1);
	REQUIRE(l1.back() == 3);
	REQUIRE(l1.size() == 3);
	l1.reverse();
	REQUIRE(l1.front() == 3);
	REQUIRE(l1.back() == 1);
	REQUIRE(l1.size() == 3);
	List<int> l2{reverse(l1)};
	REQUIRE(l2.front() == 1);
	REQUIRE(l2.back() == 3);
	REQUIRE(l2.size() == 3);
}

TEST_CASE("move constructor", "[constructor]"){
	List<int> list;
	list.push_front(1);
	list.push_front(2);
	list.push_front(3);
	list.push_front(4);
	List<int> list2(std::move(list));
	REQUIRE(0 == list.size());
	REQUIRE(list.empty());
	REQUIRE(4 == list2.size());
}

TEST_CASE("Liste in Vektor", "[L in V]") {
	List<int> l1;
	l1.push_back(1); 
	l1.push_back(2); 
	l1.push_back(3); 
	l1.push_back(4); 
	l1.push_back(5);
	std::vector<unsigned int> v1(l1.size());
	std::copy(l1.begin(), l1.end(), std::begin(v1));
	REQUIRE(1 == v1[0]);
	REQUIRE(2 == v1[1]);
	REQUIRE(3 == v1[2]);
	REQUIRE(4 == v1[3]);
	REQUIRE(5 == v1[4]);
}

TEST_CASE("zuweisungsop", "[zop]") {
	List<int> l1 {}; 
	l1.push_back(1); 
	l1.push_back(2); 
	l1.push_back(3); 
	l1.push_back(4); 
	l1.push_back(5);
	List<int> l2 {}; 
	l2.push_back(6); 
	l2.push_back(7); 
	l2.push_back(8); 
	l2.push_back(9); 
	l2.push_back(10);

	l1.swap(l2);
	ListIterator<int> i = l1.begin();
	REQUIRE(6 == *i);
	++i;
	REQUIRE(7 == *i);
	++i; 
	REQUIRE(8 == *i);
	++i;
	REQUIRE(9 == *i);
	++i; 
	REQUIRE(10 == *i);
	ListIterator<int> p = l2.begin();
	REQUIRE(1 == *p);
	++p;
	REQUIRE(2 == *p);
	++p; 
	REQUIRE(3 == *p);
	++p;
	REQUIRE(4 == *p);
	++p; 
	REQUIRE(5 == *p);

	swap(l1, l2);
	ListIterator<int> q = l1.begin();
	REQUIRE(1 == *q);
	++q;
	REQUIRE(2 == *q);
	++q; 
	REQUIRE(3 == *q);
	++q;
	REQUIRE(4 == *q);
	++q; 
	REQUIRE(5 == *q);
	ListIterator<int> w = l2.begin();
	REQUIRE(6 == *w);
	++w;
	REQUIRE(7 == *w);
	++w; 
	REQUIRE(8 == *w);
	++w;
	REQUIRE(9 == *w);
	++w; 
	REQUIRE(10 == *w);

	l2 = l1;
	ListIterator<int> k = l2.begin();
	REQUIRE(1 == *k);
	++k;
	REQUIRE(2 == *k);
	++k; 
	REQUIRE(3 == *k);
	++k;
	REQUIRE(4 == *k);
	++k; 
	REQUIRE(5 == *k);
	ListIterator<int> r = l1.begin();
	REQUIRE(1 == *r);
	++r;
	REQUIRE(2 == *r);
	++r; 
	REQUIRE(3 == *r);
	++r;
	REQUIRE(4 == *r);
	++r; 
	REQUIRE(5 == *r);
}


int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}