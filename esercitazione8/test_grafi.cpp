#include <iostream> 

#include "unidirected_graph.hpp"

int main() {
//test unidirected_edge
    unidirected_edge<int> a1(7,2);
    if (a1.from() != 2) {
	    std::cout << "Errore: from() dovrebbe restituire 2\n";
    }
    else {
	    std::cout << "Test su from() superato\n";
    }

    if (a1.to() != 7) {
	    std::cout << "Errore: to() dovrebbe restituire 7\n";
    }
    else {
	    std::cout << "Test su to() superato\n";
    }
	
    unidirected_edge<int> a2(2,7);
    if (a1 == a2) {
	    std::cout << "Test sull'operatore == superato\n";
    }
    else {
		std::cout << "Errore: gli archi dovrebbero essere uguali\n";
	}
	
	unidirected_edge<int> a3(1,3);
	if (a3 < a1) {
		std::cout << "Test sull'operatore < superato\n";
	}
	else {
		std::cout << "Errore nell'operatore <\n";
	}
	
//test unidirected_graph
    unidirected_graph<int> g;
	
	g.add_edge(unidirected_edge<int>(1,2));
	g.add_edge(unidirected_edge<int>(2,3));
	g.add_edge(unidirected_edge<int>(1,3));
	
	//test duplicati
	g.add_edge(unidirected_edge<int>(3,2));
	if (g.all_edges().size() != 3) {
		std::cout << "Errore: un arco è stato inserito due volte\n";	
	}
	else {
		std::cout << "Test sui duplicati superato\n";
	}
	
	//test neighbours
	std::set<int> vicini1 = g.neighbours(1);
	if (vicini1.count(2) == 1 && vicini1.count(3) == 1) {
		std::cout << "Test su neighbours superato\n";
	}
	else {
		std::cout << "Errore in neighbours\n";
	}
	
	//test all_nodes
	std::set<int> nodi = g.all_nodes();
	if (nodi.size() == 3) {
		std::cout << "Test su all_nodes superato\n";
	}
	else {
		std::cout << "Errore in all_nodes\n";
	}
	
	//test edge_number 
	int indice = g.edge_number(unidirected_edge<int>(1,2));
	if (indice != -1) {
		std::cout << "Test su edge_number superato\n";
	}
	else {
		std::cout << "Errore: arco non trovato\n";
	}
	
	//test edge_at
	unidirected_edge<int> arco = g.edge_at(indice);
	if (arco == unidirected_edge<int>(1,2)) {
		std::cout << "Test su edge_at superato\n";
	}
	else {
		std::cout << "Errore in edge_at\n";
	}
	
	//test operator-
	unidirected_graph<int> h;
	h.add_edge(unidirected_edge<int>(1,3));
	
	unidirected_graph<int> differenza = g - h;
	
	if (differenza.all_edges().size() == 2) {
		std::cout << "Test operatore - superato\n";
	}
	else {
		std::cout << "Errore nell'operatore -\n";
	}
	
	return 0;
}