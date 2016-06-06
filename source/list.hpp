#ifndef BUW_LIST_HPP
#define BUW_LIST_HPP

#include <cstddef>

// List.hpp

template <typename T>
class List;

template <typename T>
class ListNode{
public:
	ListNode() : m_value(), m_prev(nullptr), m_next(nullptr) {}

	ListNode(T const& v, ListNode* prev, ListNode* next) : m_value(v), m_prev(prev), m_next(next) {}
	T m_value;
	ListNode* m_prev;
	ListNode* m_next;
};

template <typename T>
	struct ListIterator{
		typedef ListIterator <T> Self;
		
		typedef T value_type;
		typedef T* pointer;
		typedef T& reference;
		typedef ptrdiff_t difference_type;
		typedef std::forward_iterator_tag iterator_category;
		
		friend class List<T>;
	
		ListIterator(): m_node{nullptr} {} // implemented yet

		ListIterator(ListNode<T>* n): m_node{n} {} // implemented yet

		reference operator*() const {
			return m_node -> m_value;
		} // implemented yet

		pointer operator->() const {
			return &(m_node -> m_value);
		} // implemented yet

		Self& operator++() {
			if (m_node != nullptr){
				m_node = m_node -> m_next;
			}
			return *this;
		} // implemented yet

		Self operator++(int) {
			Self neu = *this;
			++(*this);
			return neu;
		} // implemented yet

		bool operator==(const Self& x) const {
			return m_node == x.m_node;
		}// not implemented yet

		bool operator!=(const Self& x) const {
			return m_node != x.m_node;
		} // not implemented yet

		Self next () const{
			if (m_node){
				return ListIterator(m_node->m_next);
			}
			else{
				return ListIterator(nullptr);
			}
		}

		Self prev () const{
    		if (m_node){
    			return ListIterator(m_node->m_prev);
    		}
    		else{
    			return ListIterator(nullptr);
    		}
		}

	private:
		// The Node the iterator is pointing to
		ListNode <T>* m_node = nullptr;
	};

template <typename T>
class ListConstIterator
{
	friend class List<T>;
public:
// not implemented yet
private:
	ListNode <T>* m_node = nullptr;
};


template <typename T>
class List
{
public:
	//default-Kontruktor
	List():
		m_size{0},
		m_first{nullptr},
		m_last{nullptr}
	{}

	//copy constructor
	List(List<T> const& a):
		m_size{0},
		m_first{nullptr},
		m_last{nullptr}
	{
		for (ListIterator<T> ai = a.begin(); ai != a.end(); ++ai){
  			push_back(*ai);
  		}
	}

	//move constructor
 	List(List&& l1):
 		m_size {l1.m_size},
 		m_first {l1.m_first}, //Diebstahl!!!!!!
 		m_last {l1.m_last}
 	{
    	l1.m_size = 0;
    	l1.m_first = nullptr;
    	l1.m_last = nullptr; //leer geräumte Bude
	}

	//Zuweisungsoperator
	List<T>& operator=(List<T> l1) { // copy-construct by passing by-value
    	swap(l1); // member-swap
    	return *this;
  	}

    //member-swaps contents of list with *this
  	void swap(List<T>& l1) {
    	std::swap(m_size, l1.m_size);
    	std::swap(m_first, l1.m_first);
    	std::swap(m_last, l1.m_last);
	}

	//swap
  	friend void swap(List<T>& l1, List<T>& l2) {
    	l1.swap(l2);
  	}

	//Ist Liste leer?
	bool empty() const{
		return m_size == 0;
	}

	//Gibt Größe der Liste zurück
	std::size_t size() const{
		return m_size;
	}

	//front
	T const& front() const{
		return m_first -> m_value;
	}

	//back
	T const& back() const{
		return m_last -> m_value;
	}

	//push_back
	void push_back(T const& wert){
		if (m_size == 0){
			ListNode<T>* neu = new ListNode<T>(wert, nullptr, nullptr);
			m_first = m_last = neu;
		}
		else{
			ListNode<T>* neu = new ListNode<T>(wert, m_last, nullptr);
			m_last->m_next = neu;
			m_last = neu;
		}
		m_size++;
	}

	//push_front
	void push_front(T const& wert){
		if (m_size == 0){
			ListNode<T>* neu = new ListNode<T>(wert, nullptr, nullptr);
			m_last = m_first = neu;
		}
		else{
			ListNode<T>* neu = new ListNode<T>(wert, nullptr, m_first);
			m_first->m_prev = neu;
			m_first = neu;
		}
		m_size++;
	}

	//pop_back
	void pop_back(){
		if (m_size <= 1){
			assert(m_last != nullptr);
			delete m_last;
			m_first = nullptr;
			m_last = nullptr;
			m_size = 0;
		}
		else {
			ListNode<T>* neu = m_last;
			m_last = m_last->m_prev;
			m_last->m_next = nullptr;
			delete neu;
			m_size--;
		}
	}

	//pop_front
	void pop_front(){
		if (m_size <= 1){
			assert(m_first != nullptr);
			delete m_first;
			m_first = nullptr;
			m_last = nullptr;
			m_size = 0;
		}
		else {
			ListNode<T>* neu = m_first;
			m_first = m_first->m_next;
			m_first->m_prev = nullptr;
			delete neu;
			m_size--;
		}
	}

	//clear
	void clear(){
		while (m_size > 0){
			pop_front();
		}
	}

	//insert
	void insert(ListIterator <T> platz, T const& wert){
		if (platz == begin()){
			push_front(wert);
		}
		else{
			if (platz == end()){
				push_back(wert);
			}
			else{ //Ausweichzeiger
				ListNode <T>* neu = new ListNode<T>(wert, platz.prev().m_node, platz.m_node);
				platz.prev().m_node -> m_next = neu;
				platz.m_node -> m_prev = neu;
				++m_size;
			}
		}
	}

	//reverse
	void reverse(){
		List<T> neu(*this); //Ausweichliste
		clear();			//Bereinigen der eigentlichen Liste
		for (ListIterator <T> i = neu.begin(); i != neu.end(); ++i){
			push_front(*i);	//Eintrag der Ausweichliste in Liste
		}
	}

	// iterator points to m_first
  	ListIterator<T> begin() const {
  		return iterator {m_first};
  	}

  	// iterator points to the element behind m_last
  	ListIterator<T> end() const {
  		return iterator {};
  	}


	typedef T value_type;
	typedef T* pointer;
	typedef const T* const_pointer;
	typedef T& reference;
	typedef const T& const_reference;
	typedef ListIterator <T> iterator;
	typedef ListConstIterator <T> const_iterator;
	
	friend struct ListIterator <T>;
	friend class ListConstIterator <T>;

// not implemented yet
private:
	std::size_t m_size = 0;
	ListNode <T>* m_first = nullptr;
	ListNode <T>* m_last = nullptr;
};

template<typename T>
bool operator ==(List<T> const& xs, List<T> const& ys){
  	ListIterator<T> yi = ys.begin();
	for (ListIterator<T> xi = xs.begin(); xi != xs.end(); ++xi){
  		if (*xi != *yi){
  			return false;
  		}
  		++yi;
  	}
  	return true;
}

template<typename T>
bool operator !=(List<T> const& xs, List<T> const& ys){
	return !(xs == ys);
}
//reverse
template<typename T>
List<T> reverse(List<T> const& liste){
	List<T> neu;		//neue Liste
	for (ListIterator <T> i = liste.begin(); i != liste.end(); ++i){
		neu.push_front(*i);	//Eintrag der Übergabe-Liste in neue Liste
	}
	return neu;
}

#endif // #define BUW_LIST_HPP
