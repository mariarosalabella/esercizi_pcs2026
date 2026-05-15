#pragma once
#include "lifo_fifo.hpp"
#include "unidirected_graph.hpp"
#include <set>

template<typename T, template<typename> class contenitore>
unidirected_graph<T> graph_visit(const unidirected_graph<T>& G, const T& source) {
	contenitore<T> c;
	unidirected_graph<T> albero;  
	std::set<T> reached;  //per tenere traccia dei nodi già visitati
	
	c.put(source);
	reached.insert(source);
	
	while (! c.empty()) {
		T u = c.get();
		std::set<T> vicini = G.neighbours(u);
		
		for (auto it = vicini.begin(); it != vicini.end(); it++) {
			const T& w = *it;
			if (reached.find(w) == reached.end()) { //controllo che non sia stato visitato
				reached.insert(w);
				c.put(w);
				
				albero.add_edge(unidirected_edge<T>(u,w));
			}
		}
	}
	return albero;
}

