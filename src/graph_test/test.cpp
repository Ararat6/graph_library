#include <graph_library/graph.hpp>
#include <graph_library/input_parser.hpp>
#include <graph_library/algorithm.hpp>
#include <graph_library/search.hpp>
#include <graph_library/Dfs.hpp>
#include <graph_library/Bfs.hpp>
#include <graph_library/graph_exception.hpp>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <cassert>

int main()
{	
	std::string file_path = "./graph.txt";
	input_parser parser;
	graph* test_graph;
	try {
		test_graph = parser.create_graph(file_path);
		assert(NULL != test_graph);
		if(directed == test_graph->get_direction()){
			std::cout << "\nDirected Graph " << "\n";
		} else {
			std::cout << "\nUndirected Graph " << "\n";
		}
		test_graph->show_graph();
		search* alg_search = new Dfs();
		assert(NULL != alg_search);
		alg_search->set_target_graph(test_graph, "v1");
		shortest_path* alg_shortest = new Dijkstra();
		assert(NULL != alg_shortest);
		alg_shortest->set_target_graph(test_graph, "v1", "v77");

		algorithm alg;
		alg.set_shortest_path_type(alg_shortest);
		std::cout << "Distance between source and destination = " 
						<< alg.get_shortest_path() << std::endl;
		std::cout << "\n";

		alg.set_search_type(alg_search);
		std::cout << "Traverse graph from source vertex = ";
		alg.traverse();
		std::cout << "\n";
	
	} catch (graph_exception& e) {
		std::cout << e.what() << "\n\n";	
		return 1;	
	}
	return 0;
}

