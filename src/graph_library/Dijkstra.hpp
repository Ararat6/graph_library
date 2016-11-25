#ifndef _DIJKSTRA_HPP_
#define _DIJKSTRA_HPP_

#include "shoortest_path.hpp"
#include "graph.hpp"
#include <vector>
#include <string>
#include <queue>
#include <map>


class Dijkstra: public shoortest_path
{ 
	int m_distance;
	graph* m_graph;
	vertex* source_vertex;
	vertex* destination_vertex;

private:
	void set_distance(int);
	vertex* find_vertex(std::string);
	bool short_path_to_map(std::vector<edge*>::iterator it, std::map<vertex*,int>& v_map, bool check);

public:
	int get_distance() const;

public:
//	void set_target_graph(graph* , std::string&);
    void set_target_graph(graph* , const std::string&, const std::string&);
	void shortest_path();

};

#endif //_DIJKSTRA_HPP_
