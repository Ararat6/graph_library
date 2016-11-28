#include <graph_library/graph.hpp>
#include <graph_library/weighted_edge.hpp>
#include <graph_library/base_edge.hpp>
#include <graph_library/edge.hpp>
#include <graph_library/input_parser.hpp>
#include <graph_library/algorithm.hpp>
#include <graph_library/search.hpp>
#include <graph_library/Dfs.hpp>
#include <graph_library/Bfs.hpp>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>




int main()
{	
	
	std::string file_path = "./graph.txt";
	input_parser parser;
	graph* test_graph = parser.create_graph(file_path);

	if(NULL != test_graph){

		if(directed == test_graph->get_direction()){
			std::cout << "\nDirected Graph " << "\n";
		} else {
			std::cout << "\nUndirected Graph " << "\n";
		}
		test_graph->show_graph();
	} else {

		return 0;
	}

    search * alg_search = new Bfs();
    alg_search  -> set_target_graph(test_graph, "v2");

	shortest_path * alg_shortest = new Dijkstra();
	alg_shortest  -> set_target_graph(test_graph, "v2", "v4");

	algorithm alg;

	alg.set_shortest_path_type(alg_shortest);
	std::cout << "Distance betwen source and destination = " << alg.get_shortest_path() << std::endl;
	std::cout << "\n";

	alg.set_search_type(alg_search);
	std::cout << "Travers graph from source vertex = ";
	alg.traverse();
	std::cout << "\n";

	return 0;
}



