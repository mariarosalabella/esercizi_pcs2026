#pragma once
#include <vector>
#include <list>

template<typename T>
class pila {
	std::vector<T> lifo; 
	public: 
	    pila() {  //costruttore di default
		}  
		
	void put(const T& x) {
		lifo.push_back(x);
	}
	
	T get() {
		if (lifo.empty()) {
			throw "Errore: stack vuoto!";
		}
		T last = lifo.back();  //accede all'ultimo elemento
		lifo.pop_back();
		return last;
	}
	
	bool empty() const {
		return lifo.empty();
	}	
};


template<typename T>
class coda {
	std::list<T> fifo;
	public:
	    coda() { //costruttore di default
		}
	
	void put(const T& x) {
		fifo.push_back(x);
	}
	
	T get() {
		if (fifo.empty()) {
			throw "Errore: coda vuota!";
		}
		T first = fifo.front();  //accede al primo elemento
		fifo.pop_front();
		return first;
	}
	
	bool empty() const {
		return fifo.empty();
	}
};