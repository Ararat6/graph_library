#include "input_parser.hpp"
#include <stdlib.h>

//TODO
graph* input_parser::create_graph(const std::string &file_path)
{
	m_vertices_count = 0;
    m_line = 0;
	graph* current_graph = m_graphs[file_path];
	if(NULL == current_graph) {
		current_graph = new graph();
		m_graphs[file_path] = current_graph;
	} else {
		return current_graph;
	}
	std::string line;
	std::stringstream buffer;
	read_file(file_path, buffer);



	if(getline( buffer, line )) { 
		std::istringstream iss(line);
        ++m_line;
		if(! set_graph_type(line, current_graph)) {
			//TODO generate exp
			return NULL;
		}
	} else {
        std::cout << "\033[1;31m" <<  " fatal error: " << "\033[0m";
		std::cout << "Buferr read exception, not input file or empty file\n" << std::endl;
		return NULL;
	}




	if(parse_graph(buffer, current_graph)) {
		if( m_vertices_count != current_graph->get_vertices_count()) {
            std::cout << "graph.txt:1:\033[1;31m" <<  " error: " << "\033[0m";
			std::cout << "Exception graph  creation, set correct count of vertices\n" << std::endl;
			return NULL; 
		} else {
			return current_graph;
		}
	} else {
        std::cout << "graph.txt:" << m_line << ":\033[1;31m" <<  " error: " << "\033[0m";
		std::cout << "Exception graph  creation \n" << std::endl;
		return NULL;
	}
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

bool input_parser::set_graph_type(const std::string first_line, graph* current_graph)
{
	std::istringstream iss(first_line);
	std::string str_direction;
	if (iss >> str_direction) {
		if ( 0 == str_direction.compare("0") ) {
			current_graph->set_direction(undirected);
		}
		else if	( 0 == str_direction.compare("1") ) {
			//int direction = atoi(str_directi on.c_str());
			current_graph->set_direction(directed);
		} else {
			//TODO generate excp
            std::cout << "graph.txt:" << m_line << ":\033[1;31m" <<  " error: " << "\033[0m";
			std::cout << "Incorrect input format, for directon set (1) or (0) \n" << std::endl;
			return false;
		}
	} else {
        std::cout << "graph.txt:" << m_line << ":\033[1;31m" <<  " error: " << "\033[0m";
		std::cout << "Incorrect input format, set graph type\n" << std::endl;
		return false;
	}
	std::string str_vertex_count;
	if(iss >> str_vertex_count) {
		int int_vertex_count;
		int_vertex_count = atoi(str_vertex_count.c_str());
		if(int_vertex_count > 1) {
			m_vertices_count = int_vertex_count;
		} else {
			//TODO generate excp   
            std::cout << "graph.txt:" << m_line << ":\033[1;31m" <<  " error: " << "\033[0m";
			std::cout << "Incorrect input format, for count \n" << std::endl;
			return false;
		}
	} else {
		//TODO generate excp
        std::cout << "graph.txt:" << m_line << ":\033[1;31m" <<  " error: " << "\033[0m";
		std::cout << "Incorrect input format, for count \n" << std::endl;
		return false;
	}
	std::string str_weight;
	if(iss >> str_weight) {
		if ( 0 == str_weight.compare("1") ) {
			current_graph->set_edge_weight(weighted);
		}
		else if	( 0 == str_weight.compare("0") ) {
			current_graph->set_edge_weight(unweighted);
		} else {
			//TODO generate excp
            std::cout << "graph.txt:" << m_line << ":\033[1;31m" <<  " error: " << "\033[0m";
			std::cout << "Incorrect input format, for edge weight set (1) or (0) \n" << std::endl;
			return false;
		}
	} else {
        std::cout << "graph.txt:" << m_line << ":\033[1;31m" <<  " error: " << "\033[0m";
		std::cout << "Incorrect input format, for edge weight set (1) or (0) \n" << std::endl;
		return false;
	}


	std::string word;
	if(iss >> word){
		//TODO excp
        std::cout << "graph.txt:" << m_line << ":\033[1;31m" <<  " error: " << "\033[0m";
		std::cout << "Don't input more arguments in line of about your graph\n" << std::endl;
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
		weight = 0;
        ++m_line;
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
                    std::cout << "graph.txt:" << m_line << ":\033[1;31m" <<  " error: " << "\033[0m";
					std::cout << "Enter weight positiv integer\n"	<< std::endl;
					return false;
				}	
			}
			++i;
		}
		if(iss >> word){
			//TODO excp
            std::cout << "graph.txt:" << m_line << ":\033[1;31m" <<  " error: " << "\033[0m";
			std::cout << "Don't input more arguments \n" << std::endl;
			return false;
		}

		if( NULL == destination) {
			//TODO excp
            std::cout << "graph.txt:" << m_line << ":\033[1;31m" <<  " error: " << "\033[0m";
			std::cout << "Input correct pair of vertices \n" << std::endl;
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

