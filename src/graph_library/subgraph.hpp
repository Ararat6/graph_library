#ifndef _SUBGRAPH_HPP_
#define _SUBGRAPH_HPP_

#include "graph.hpp"

class subgraph
{

private:
	graph* m_big_graph;
	graph* m_small_graph;

private:
	min_bisection();

public:
	void set_target_graphs(graph* big_graph, graph* small_graph);
	bool is_contain_subgraph();
	
};



#endif //_SUBGRAPH_HPP_
