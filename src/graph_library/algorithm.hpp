#ifndef _ALGORITHM_HPP_
#define _ALGORITHM_HPP_

#include "search.hpp"
#include "shortest_path.hpp"


class algorithm
{

private:
	shearch* m_srearch;
	shortest_path* m_shortest_path;

Public:
	/**Setting type of serarching  algorithm*/
	void set_search_type(shearch* );
	/**Setting type of  shortest path algorithm*/
	void set_short_type(shortest_path* ); 
	/**       */
	std::vector<vertex*> travers();
	int shortest_path(); 
public:
	algorithm(); 

};


#endif//_ALGORITHM_H_
