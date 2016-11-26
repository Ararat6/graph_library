#include "algorithm.hpp"

void algorithm::set_search_type(search* c_search)
{
    m_search = c_search;
}

void algorithm::set_shortest_path_type(shortest_path* c_shortest )
{
    m_shortest_path = c_shortest;
}

/*std::vector<vertex*>*/void algorithm::traverse()
{
	//return m_search;


}

int algorithm::get_shortest_path()
{
    m_shortest_path->short_path();
}

algorithm::algorithm()
    :m_search(NULL)
    ,m_shortest_path(NULL)
{
}
