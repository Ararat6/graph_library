#ifndef _BFS_HPP_
#define _BFS_HPP_

#include "graph.hpp"
#include "search.hpp"
#include <string>

class Bfs: public search
{
	graph* target_graph;
	std::string target_vertex;
public:
	void set_target_graph(graph* , const std::string& );
	void traverse();

};

#endif //_BFS_HPP_
