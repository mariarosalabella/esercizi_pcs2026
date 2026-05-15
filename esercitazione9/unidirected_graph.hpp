#pragma once

#include "unidirected_edge.hpp"

#include <unordered_map>
#include <set>
#include <vector>
#include <map>


template<typename T>
class unidirected_graph {
	std::unordered_map<T, std::set<T>> adj_list;  //rappresento il grafo come coppie (nodo, vicini)
	std::vector<unidirected_edge<T>> archi;   //vettore di archi, per ottimizzare l'accesso
	std::map<unidirected_edge<T>, int> indici;  //memorizzo le coppie (arco, posizione)
	
	public:
	    unidirected_graph() {  //costruttore di default
		}
		
		unidirected_graph(const unidirected_graph& other)  //costruttore di copia
			: adj_list(other.adj_list), 
			  archi(other.archi),
			  indici(other.indici) 
			{}
			
		void add_edge(const unidirected_edge<T>& arco) {
			if (indici.find(arco) != indici.end())  //controllo che non esista già
				return;
	        
			adj_list[arco.from()].insert(arco.to());
		    adj_list[arco.to()].insert(arco.from());
			
			indici[arco] = archi.size();
			archi.push_back(arco);
		}
		
		
		std::set<T> neighbours(const T& nodo) const{
			auto itor = adj_list.find(nodo);
			if (itor == adj_list.end()) {
				return {};
			}
			return (*itor).second;
		}
		
		//restituisce tutti gli archi
		std::vector<unidirected_edge<T>> all_edges() const {
			return archi;
		}
		
		//restituisce tutti i nodi
		std::set<T> all_nodes() const {
			std::set<T> nodi;
			
			for (auto it = adj_list.begin(); it != adj_list.end(); it++) {
				nodi.insert((*it).first); //prendo i nodi chiave
				for (auto itor = (*it).second.begin(); itor != (*it).second.end(); itor++) {
					nodi.insert(*itor); //per ciascun nodo chiave, prendo i vicini a uno a uno
				}
			}
			return nodi;
		}
		
		
		int edge_number(const unidirected_edge<T>& arco) const{
			auto it = indici.find(arco);
			if (it == indici.end())
				return -1;
			return (*it).second;
		}
		
		
		unidirected_edge<T> edge_at(int indice) const {
			return archi.at(indice);  //accede al vector controllando che l'indice sia valido
		}
		
		
		unidirected_graph operator-(const unidirected_graph& other) const {
			unidirected_graph risultato;
			
		    for (auto arco = archi.begin(); arco != archi.end(); arco++) {
				if (other.indici.find(*arco) == other.indici.end()) {
					risultato.add_edge(*arco);
				}
			}
			return risultato;
		}

};
