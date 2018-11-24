//============================================================================
// Name        : Message.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Message.h"
Node::Node( unsigned int id, std::string frag){

	 Node::identifier = id;
	 Node::fragment = frag;
	 Node::p_next = *Nodes[id+1];
}

std::string Node::get_fragment(){
	 return Node::fragment;
}
Node Node::*get_next(){
	return Node::p_next;
}
//message member functions
Message::Message(){
	Message::head = nullptr;
}
Message::~Message(){

}
void Message::insert(unsigned int id, std::string fragment){

}
void print_message(){

}
int main() {
	Node Nodes = new std::string[4];

	return 0;
}
