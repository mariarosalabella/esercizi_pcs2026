#pragma once
#include <ostream>

template<typename T>
class unidirected_edge {
	T primo_nodo;
	T secondo_nodo;
	public:
	    unidirected_edge(const T& primo, const T& secondo) {  //costruttore
		    if (primo < secondo) {
				primo_nodo = primo;
				secondo_nodo = secondo;
			}
			else {
				primo_nodo = secondo;
				secondo_nodo = primo;    //così il primo nodo è sempre minore del secondo
			}
		}
		
		//metodi che restituiscono primo e secondo nodo
		T from() const {
			return primo_nodo;
		}
		
		T to() const {
			return secondo_nodo;
		}
		
		//operatore < per rendere gli archi ordinabili
		bool operator< (const unidirected_edge& other) const {
			if (primo_nodo != other.primo_nodo) {
				return primo_nodo < other.primo_nodo;
			}
			return secondo_nodo < other.secondo_nodo;
		}
		
		//operatore == per stabilire se due archi sono uguali 
		bool operator== (const unidirected_edge& other) const {
			return primo_nodo == other.primo_nodo && secondo_nodo == other.secondo_nodo; //basta confrontare primo con primo e secondo con secondo, siccome primo < secondo
		}
};
		
//operatore << per la stampa
template<typename T>
std::ostream& operator<< (std::ostream& os, const unidirected_edge<T>& arco) {
	os << "(" << arco.from() << "," << arco.to() << ")";
	return os;
}
		
