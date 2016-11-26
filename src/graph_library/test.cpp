#include "weighted_edge.hpp"
#include "input_parser.hpp"
#include "algorithm.hpp"
#include "base_edge.hpp"
#include "search.hpp"
#include "graph.hpp"
#include "edge.hpp"
#include "Dfs.hpp"
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



//    search * alg_search = new Dfs();
//    alg_search  -> set_target_graph(test_graph, "v1");



    shortest_path * alg_shortest = new Dijkstra();
    alg_shortest  -> set_target_graph(test_graph, "v1", "v6");


    std::cout << "alg short = " <<    alg_shortest -> short_path() <<  std::endl; //for local test 




/*
    algorithm* alg;

    alg -> set_shortest_path_type(alg_shortest);
    alg -> set_search_type(alg_search);

//  std::cout <<  
    alg -> get_shortest_path() 
//  << std::endl; 
    alg -> traverse();
*/
   

    return 0;
}



