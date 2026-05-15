#pragma once

#include "unidirected_graph.hpp"

#include <map>
#include <queue>
#include <vector>
#include <set>

#include <functional>  //per std::greater
#include <limits>

template<typename T>
std::pair<std::map<T,int>, std::map<T, T>> dijkstra(const unidirected_graph<T>& G, const T& source) {
	std::map<T, int> dist; //distanze minime
	std::map<T, T> pred; //predecessori
	
	std::set<T> reached; //tiene traccia dei nodi già visitati
	
	for (const T& nodo : G.all_nodes()) {
		dist[nodo] = std::numeric_limits<int>::max();
		pred[nodo] = nodo;
	}
	
	dist[source] = 0;
	pred[source] = source;
	
	//inizializzo la priority queue: (distanza, nodo)
	std::priority_queue<std::pair<int, T>,  //tipo elementi
                    	std::vector<std::pair<int,T>>, //contenitore
						std::greater<std::pair<int, T>>>  //comparatore
						pq;
	
	
	for (const T& nodo : G.all_nodes()) {
		pq.push(std::pair<int,T>(dist[nodo], nodo));
	}
	while (! pq.empty()) {
		T u = pq.top().second; //estraggo il nodo che è primo per priorità
		pq.pop();  //lo tolgo dalla coda
		
		
		if (reached.find(u) == reached.end()) {
			reached.insert(u);
			for (const T& v : G.neighbours(u)) {
				int peso = 1;
				if (dist[v] > dist[u] + peso) {
					dist[v] = dist[u] + peso;
					pred[v] = u;
					
		        pq.push(std::pair<int,T>(dist[v],v));
				}
			}
		}	
	}
	return {dist, pred};
}

