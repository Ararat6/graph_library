#include "vertex.hpp"

const std::vector<base_edge*>* vertex::get_edges() const
{
	return &m_edges;
}

void vertex::add_edge(base_edge* node_edge)
{
	//assert(TODO);
    m_edges.push_back(node_edge);
}

int vertex::get_degree() const
{
    return m_degree;
}

void vertex::add_degree()
{
	m_degree++;
}

std::string vertex::get_name() const
{
    return m_name;
}

void vertex::set_visited(const bool is_visited)
{
	m_is_visited = is_visited;
}

bool vertex::get_visited() const
{
	return m_is_visited;
}

vertex::vertex(const std::string& name):m_degree(0)
{
    m_name = name;
}

vertex::~vertex()
{
	std::vector<base_edge*>::iterator it = m_edges.begin();
	std::vector<base_edge*>::iterator end = m_edges.end();
	for(; it !=end; ++it ) {
		if(NULL != *it) {
			delete *it;
		}
	}
}










