#include <graph_library/graph.hpp>
#include <graph_library/weighted_edge.hpp>
#include <graph_library/base_edge.hpp>
#include <graph_library/edge.hpp>
#include <graph_library/input_parser.hpp>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

int main()
{	
	
	/*std::string file_path = "./graph.txt";
	input_parser pars;
        pars.create_graph(file_path);	*/
	//TODO: make 
    std::string file_path = "./graph.txt";
    input_parser parser;
	graph* test_graph = parser.create_graph(file_path);
//    std::vector<vertex*>* vertices = parser.get_vertices();

	if(NULL != test_graph) {
		if(directed == test_graph->get_direction()){
    		std::cout << "\nDirected Graph " << "\n";
		} else {
    		std::cout << "\nUndirected Graph " << "\n";
		}
		test_graph->show_graph();
	}     


	//base_edge* ed = new edge();
	//std::cout << ed->get_weight() << std::endl;
	
	//base_edge* weighted = new weighted_edge(ed, 10);
	//std::cout << weighted->get_weight() << std::endl;

	/*algorithm* alg = new search(test_graph);
	alg -> DFS("v7");
	alg -> BFS("v7");*/
	/*shortest_path* alg = new shortest_path(test_graph);
	alg -> dijkstra("v8", "v6");
	int dist = alg -> get_distance();
	std::cout << "distance = " << dist << std::endl;*/

	
    return 0;
}



