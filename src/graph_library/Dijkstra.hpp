#ifndef _DIJKSTRA_HPP_
#define _DIJKSTRA_HPP_

#include "shortest_path.hpp"
#include "algorithm.hpp"
#include "graph.hpp"
#include <vector>
#include <string>
#include <queue>
#include <map>

class Dijkstra: public shortest_path
{ 
    int m_distance;
    graph* m_graph;
    vertex* source_vertex;
    vertex* destination_vertex;

private:
    void set_distance(int);
    bool short_path_to_map(std::vector<base_edge*>::const_iterator it, std::map<vertex*,int>& v_map);

private:
    void find_distance();
    vertex* find_vertex(const std::string);

public:
    //	void set_target_graph(graph* , std::string&);
    void set_target_graph(graph* , const std::string&, const std::string&);

public:
    int short_path();

public:
    Dijkstra();

};

#endif //_DIJKSTRA_HPP_
