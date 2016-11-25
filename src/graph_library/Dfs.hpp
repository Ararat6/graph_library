#ifndef _DFS_HPP_
#define _DFS_HPP_

#include "graph.hpp"
#include <string>


class Dfs: public search
{
	graph* target_graph;
	std::string target_vertex;

public:
	    void set_target_graph(graph* , std::string& );
	    void traverse();

};

#endif //_BFS_HPP_
