#ifndef _SUBGRAPH_HPP_
#define _SUBGRAPH_HPP_

#include "graph.hpp"
#include "vertex.hpp"
#include <vector>
#include <queue>
#include <iostream>

class subgraph
{

private:
	graph* m_big_graph;
	graph* m_small_graph;

private:
	bool min_bisection(std::vector<vertex*>& vertices_big
                        , std::vector<vertex*>& vertices_small);
    bool match(vertex* c_vertex, vertex* out_vertex
                    , std::vector<vertex *>& vertices_small);
    bool search_sub_graph(vertex* D1, vertex* SmD1
                    , std::vector<vertex*>& vertices_small);
    vertex* get_lowest_vertex(graph* current_graph);
    bool equal_vertices (vertex* v1, vertex* v2);
    std::vector<vertex*> BFS (graph* );

public:
	void set_target_graphs(graph* big_graph, graph* small_graph);
	bool is_contain_subgraph();
public:
    subgraph();

};



#endif //_SUBGRAPH_HPP_
