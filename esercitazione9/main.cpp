#include "unidirected_graph.hpp"
#include "lifo_fifo.hpp"
#include "graph_visit.hpp"
#include "recursive_dfs.hpp"
#include "dijkstra.hpp"
#include "write_graphviz.hpp"

int main() {
	unidirected_graph<int> G;
	
	G.add_edge(unidirected_edge<int>(1,2));
	G.add_edge(unidirected_edge<int>(1,4));
	G.add_edge(unidirected_edge<int>(2,3));
	G.add_edge(unidirected_edge<int>(2,5));
	G.add_edge(unidirected_edge<int>(3,6));
	G.add_edge(unidirected_edge<int>(4,5));
	G.add_edge(unidirected_edge<int>(4,7));
	G.add_edge(unidirected_edge<int>(5,6));
	G.add_edge(unidirected_edge<int>(5,8));
	G.add_edge(unidirected_edge<int>(6,9));
	G.add_edge(unidirected_edge<int>(7,8));
	G.add_edge(unidirected_edge<int>(8,9));
	
	//dfs
	auto dfsG_tree = graph_visit<int, pila>(G, 1);
	
	//dfs ricorsivo
	auto dfs_recursive_tree = recursive_dfs(G, 1);
	
	//bfs
	auto bfsG_tree = graph_visit<int, coda>(G, 1);
	
	//dijkstra
	auto [dist, pred] = dijkstra(G,1);
	unidirected_graph<int> dijkstra_tree;
	
	for (const auto& [v,p] : pred) {
		if (v != p) {  //la source ha come predecessore se stessa
			dijkstra_tree.add_edge(unidirected_edge<int>(p,v));
		}	
	}
	
	//graphviz
	write_graphviz(dfsG_tree, "dfs.dot");
    write_graphviz(bfsG_tree, "bfs.dot");
	write_graphviz(dfs_recursive_tree, "dfs_recursive.dot");
    write_graphviz(dijkstra_tree, "dijkstra.dot");
	
	return 0;
}
	
	
	