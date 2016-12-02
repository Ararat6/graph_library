#include "subgraph.hpp"

void subgraph::set_target_graphs(graph* big_graph, graph* small_graph)
{
	m_big_graph = big_graph;
	m_small_graph = small_graph;
}

bool subgraph::is_contain_subgraph()
{
	if(m_big_graph->get_vertices_count() 
		< m_small_graph->get_vertices_count()) {
		return false;
	}

	vertex* lowest_vertex_in_big = lowest_vertex_in_graph(m_big_graph);
	vertex* lowest_vertex_in_small = lowest_vertex_in_graph(m_small_graph);
	std::vector<vertex*> vertices_big = BFS(lowest_vertex_in_big);
	std::vector<vertex*> vertices_small = BFS(lowest_vertex_in_small);

	if(min_bisection(vertices_big, vertices_small)) {
		std::cout << "Found subgraph" << std::endl;
		return true;
	} else {
		std::cout << "Not found subgraph" << std::endl;
		return false;
	}
}

bool subgraph::min_bisection(std::vector<vertex*>& vertices_big,
		std::vector<vertex*>& vertices_small)
{
	std::vector<vertex*> half1;
	std::vector<vertex*> half2;
	unsigned int SIZE = vertices_big.size();
	for(unsigned i = 0; i < SIZE; ++i) {
		if(i < (SIZE/2  + SIZE%2)){
			half1.push_back(vertices_big[i]);
		} else {
			half2.push_back(vertices_big[i]);
		}
	}


	for(int i = half1.size() - 1; i >= 0; i--) {
		std::vector<base_edge*>::const_iterator it = half1[i]->get_edges()->begin();
		std::vector<base_edge*>::const_iterator end = half1[i]->get_edges()->end();

		for( ; it != end; it++) {
			for(unsigned  j = 0; j < half2.size(); j++) {
				if((*it)->get_destination_vertex()->get_name() == half2[j]->get_name()
						|| (*it)->get_source_vertex()->get_name() == half2[j]->get_name() ) {

					if(match(half1[i], half2[j], vertices_small)) {


					}

				}
			}
		}
	}

}

bool match(vertex* c_vertex, vertex* out_vertex, std::vector<vertex *>& vertices_small) {

	for(unsigned i = 0; i < vertices_small.size(); i++) {

		if(!vertices_small[i]->get_visited() && equal_vertices(c_vertex, vertices_small[i])) {
			c_vertex->set_visited(true);
			vertices_small[i]->set_visited(true);

			if(search_sub_graph(c_vertex, vertices_small[i], vertices_small)){
				return true;
			}
			for(unsigned k = 0; k < vertices_small.size(); k++) {
				vertices_small[k]->set_visited(false);
			}
		}
	}

	return false;
}


bool equal_vertices (vertex* v1, vertex* v2) {
	return (v1->get_name() == v2->get_name());
}



std::vector<vertex*> BFS (graph* )
{
	SDG -> resetMarks(); // set all marks 0
	std::queue<DepGraphNode *> q;


	for (auto itr = SDG->getVectBeginIterator(), end = SDG->getVectEndIterator(); itr != end; itr++) {
		if((*itr)->getInDepCount() == 0) {
			//sortedNodes.push_back(*itr);
			q.push(*itr);
			(*itr)->setMark(1);
		}
	}

	while (!q.empty()) {
		DepGraphNode * currentNode = q.front();
		sortedNodes.push_back(currentNode);
		q.pop();// pop front

		for (DependenceGraph::iterator out = SDG -> outDepBegin(currentNode); out != SDG -> outDepEnd(currentNode); ++out) {
			DepGraphNode* ni = out->getSink();
			if (!ni->getMark())
			{
				ni->setMark(1);
				q.push(ni);
			}
		}

	}
}

