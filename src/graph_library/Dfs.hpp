#ifndef _DFS_HPP_
#define _DFS_HPP_

#include "graph.hpp"
#include "search.hpp"
#include <string>


class Dfs: public search
{
	graph* target_graph;
	std::string target_vertex;

public:
	    void set_target_graph(graph* , const std::string& );
	    void traverse();

};

#endif //_DFS_HPP_
