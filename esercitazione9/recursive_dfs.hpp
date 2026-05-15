#pragma once

#include "unidirected_graph.hpp"
#include <set>

template<typename T>
void dfs_ausiliaria(const unidirected_graph<T>& G, const T& source, std::set<T>& reached, unidirected_graph<T>& albero) {
	reached.insert(source);
	
	std::set<T> vicini = G.neighbours(source);
	for (auto it = vicini.begin(); it != vicini.end(); it++) {
		T w = *it;
		if (reached.find(w) == reached.end()) {
			albero.add_edge(unidirected_edge<T>(source,w));
			
			dfs_ausiliaria(G, w, reached, albero);  //chiamata ricorsiva
		}
	}
}

template<typename T>
unidirected_graph<T> recursive_dfs(const unidirected_graph<T>& G, const T& source) {
	unidirected_graph<T> albero; 
	std::set<T> reached;
	
	if (G.all_nodes().find(source) != G.all_nodes().end()) {
		dfs_ausiliaria(G, source, reached, albero);
	}
	return albero;
}