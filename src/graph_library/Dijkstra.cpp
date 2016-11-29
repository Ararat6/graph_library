#include "Dijkstra.hpp"

void Dijkstra::set_distance(int dist)
{
    m_distance = dist;
}

vertex* Dijkstra::find_vertex(const std::string target_vertex)
{
    return m_graph->get_vertex_by_name(target_vertex);
}

bool Dijkstra::short_path_to_map(std::vector<base_edge*>::const_iterator it, 
								 std::map<vertex*,int>& v_map)
{
    int first_weight = v_map[(*it)->get_destination_vertex()];
    int new_weight = (*it)->get_weight() + v_map[(*it)->get_source_vertex()];

	vertex* d_vertex = (*it)->get_destination_vertex();
	vertex* s_vertex = (*it)->get_source_vertex();
	std::vector<vertex*>* s_path = s_vertex->get_shortest_path();

	if (first_weight == 0 || 
		(first_weight > new_weight)) {
		v_map[(*it)->get_destination_vertex()] = new_weight;
		d_vertex->set_shortest_path(s_path);
		return true;
	}
	return false;

}

bool Dijkstra::short_path_to_map_un(std::vector<base_edge*>::const_iterator it, 
		   							std::map<vertex*,int>& v_map)
{
	int first_weight = v_map[ (*it) -> get_source_vertex() ];
	int new_weight = (*it)->get_weight() + v_map[(*it)->get_destination_vertex()];
	
	vertex* d_vertex = (*it)->get_destination_vertex();
	vertex* s_vertex = (*it)->get_source_vertex();
	std::vector<vertex*>* d_path = d_vertex->get_shortest_path();

	if(!(*it) -> get_source_vertex()->get_visited()){
		if(first_weight == 0 || first_weight > new_weight){
			v_map[(*it)->get_source_vertex()] = new_weight;
			s_vertex->set_shortest_path(d_path);
			return true;
		}   
	}     
	return false;
} 

void Dijkstra::find_distance()
{
    std::cout << "source = " <<  source_vertex->get_name() <<"\n";//
    std::cout << "destinatioan = " << destination_vertex->get_name()<<"\n";//
    vertex* curr_vertex;
    std::queue<vertex*> que;
    que.push(source_vertex); 
    std::map<vertex*, int> v_map;

    while(!que.empty()){
        curr_vertex = que.front();
        //std::cout<< "curr_vertex = " << curr_vertex->get_name() <<"\n";
        que.pop();

        std::vector<base_edge*>::const_iterator it_begin = curr_vertex->get_edges()->begin();
        std::vector<base_edge*>::const_iterator it_end = curr_vertex->get_edges()->end();
        bool check = true;
        for(; it_begin != it_end; ++it_begin){
			if( m_graph->get_direction() == directed
					&& (*it_begin)->get_source_vertex() == curr_vertex) {
				check = short_path_to_map(it_begin, v_map);
				if(check == true){
					que.push((*it_begin)->get_destination_vertex());
					check = false;
				}
			} else {
				if((*it_begin)->get_source_vertex() == curr_vertex){
					check = short_path_to_map(it_begin, v_map);
					if(check == true){
						check = false;
						que.push((*it_begin)->get_destination_vertex());
					} 
				} else {
					check = short_path_to_map_un(it_begin, v_map);
					if(check == true) {
						que.push((*it_begin)->get_source_vertex());
						check = false;
					}
				} 

			}
        }
    }
    set_distance(v_map[destination_vertex]);
	show_shortest_path();
}

void Dijkstra::set_target_graph(graph* c_graph, 
		 						const std::string& source,
							   	const std::string& destination)
{
    m_graph = c_graph;
    source_vertex = find_vertex(source);
	source_vertex->set_visited(true);
    destination_vertex = find_vertex(destination);
}

void Dijkstra::show_shortest_path()
{
	std::vector<vertex*>* path = destination_vertex->get_shortest_path();

	std::vector<vertex*>::iterator it = path->begin();
	std::vector<vertex*>::iterator end = path->end();

	std::cout << "Shortest path = ";
	if(0 == path->size()) {
		std::cout << "0 : Not path betwen source and destination ";
	}

	for(;it != end ; ++it) {
		std::cout << (*it)->get_name() << " " ;
	}
	std::cout << "\n";
}

int  Dijkstra::short_distance()
{
    find_distance();
    return m_distance;
}

Dijkstra::Dijkstra()
    :m_distance(0)
{
}
