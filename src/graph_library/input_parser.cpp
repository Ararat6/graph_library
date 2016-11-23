#include "input_parser.hpp"
#include <stdlib.h>

graph* input_parser::create_graph(std::string &file_path)
{
	m_vertices_count = 0;
	graph* current_graph = m_graphs[file_path];
	if(NULL == current_graph) {
		current_graph = new graph();
	} else {
		return current_graph;
	}

	std::string line;
	std::stringstream buffer;
	read_file(file_path, buffer);

//	if("" != buffer) {
		if(getline( buffer, line )) { 
			std::istringstream iss(line);

			if(!init_parameter(line, current_graph)) {
				//TODO generate exp
				return NULL;
			}
		} else {
			std::cout << "buferr read exception" << std::endl;
			return NULL;
		}
		if(parse_graph(buffer, current_graph)) {
			if( m_vertices_count != current_graph->get_vertices_count()) {
				std::cout << "exception graph  creation count" << std::endl;
				return NULL; 
			} else {
				return current_graph;
			}
		} else {
			std::cout << "exception graph  creation " << std::endl;
			return NULL;
		}

/*	} else {
		//genereta excp
		return NULL;
	}*/
}

void input_parser::read_file(const std::string& file_path, std::stringstream& buffer)
{
	std::fstream input_file;
	input_file.open(file_path.c_str());
	if(input_file) {
		buffer << input_file.rdbuf();
		input_file.close();
	} 
}

bool input_parser::init_parameter(std::string first_line, graph* current_graph)
{
	std::istringstream iss(first_line);
	std::string str_direction ;
	if(iss >> str_direction) {
		if ( 0 == str_direction.compare("0") ) {
			current_graph->set_direction(undirected);
		}
		else if	( 0 == str_direction.compare("1") ) {
			//int direction = atoi(str_directi on.c_str());
			current_graph->set_direction(directed);
		} else {
			//TODO generate excp
			std::cout << "Incorrect input format, for directon set (1) or (0) " << std::endl;
			return false;
		}
	} else {
		std::cout << "Incorrect input format" << std::endl;
		return false;
	}
	std::string str_vertex_count ;
	if(iss >> str_vertex_count) {
		int int_vertex_count;
		int_vertex_count = atoi(str_vertex_count.c_str());
		if(int_vertex_count > 1) {
			m_vertices_count = int_vertex_count;
		} else {
			//TODO generate excp   
			std::cout << "Incorrect input format, for count " << std::endl;
			return false;
		}
	} else {
		//TODO generate excp
		std::cout << "Incorrect input format, for count " << std::endl;
		return false;
	}
	std::string str_weight ;
	if(iss >> str_weight) {
		if ( 0 == str_weight.compare("1") ) {
			current_graph->set_edge_weight(weighted);
		}
		else if	( 0 == str_weight.compare("0") ) {
			current_graph->set_edge_weight(unweighted);
		} else {
			//TODO generate excp
			std::cout << "Incorrect input format, for edge weight set (1) or (0) " << std::endl;
			return false;
		}
	} else {
		std::cout << "Incorrect input format, for edge weight set (1) or (0) " << std::endl;
		return false;
	}
	

	std::string word;
	if(iss >> word){
		//TODO excp
		std::cout << "Don't input more arguments in line of about your graph" << std::endl;
		return false;
	}

	return true;
}		

bool input_parser::parse_graph(std::stringstream& buffer, graph* current_graph)
{
	std::string line;
	int weight;
	bool is_weighted = false;
	int words_count = 2;
	if(current_graph->get_edge_weight() == weighted) {
		words_count = 3;
	    is_weighted = true;
	}

	while(getline(buffer, line)) {
		std::istringstream iss(line);
		std::string word = "";
		int weight = 0;
		vertex* source = NULL; 
		vertex* destination = NULL;
		
		int i = 1;
		while(i <= words_count && iss >> word ) {
			if(NULL == destination) {
				if(NULL == source) {
					source = current_graph->add_vertex(word);
				}
				else { 
					destination = current_graph->add_vertex(word); 
				}
			}
		   	else {
				weight = atoi(word.c_str()); 
				if(0 >= weight && (0 != word.compare("0"))){ 
					//TODO excp
					std::cout << "enter weight positiv integer"	<< std::endl;
					return false;
				}	
			}
			++i;
		}
		if(iss >> word){
			//TODO excp
			std::cout << "Don't input more arguments " << std::endl;
			return false;
		}
		if( NULL == destination) {
			//TODO excp
			std::cout << "Please input correct vertices " << std::endl;
			return false;
		}
		if(is_weighted){
			current_graph->add_edge(source, destination, weight);
		} else {
			current_graph->add_edge(source, destination);
		}
	}
	return true;
}

