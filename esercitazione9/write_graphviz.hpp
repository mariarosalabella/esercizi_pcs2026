#pragma once
#include <fstream>

template<typename T>
void write_graphviz(const unidirected_graph<T>& G, const std::string& filename) {

    std::ofstream f(filename);

    f << "graph G {\n";

    for (const auto& u : G.all_nodes()) {
        for (const auto& v : G.neighbours(u)) {

            if (u < v) {
                f << "    " << u << " -- " << v << ";\n";
            }
        }
    }
    f << "}\n";
}