//============================================================================
// Name        : Message.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <String>
#include "Message.h"
Node::Node( unsigned int id, std::string frag){
	this->identifier = id;
	this->fragment = frag;
	this->p_next = nullptr;
}

std::string Node::get_fragment(){
	 return Node::fragment;
}
Node *Node::get_next(){
	return this->p_next;
}
//message member functions
Message::Message(){
	this->head = nullptr;
}
Message::~Message(){
	Node *p_Node = head;
	Node *next;
	while (p_Node != nullptr){
		next = p_Node->get_next();
		delete p_Node;
		p_Node = next;
	}
	delete this->head;
	this->head = nullptr;
}
void Message::insert(unsigned int id, std::string fragment){
	bool linked = false;
	Node *p_Node = new Node(id, fragment);
	if (this->head == nullptr){
		this->head = p_Node;
		linked = true;
	}else if(this->head->identifier > id){
		p_Node->p_next = head;
		this->head = p_Node;
		linked = true;
	}
	Node *n_current = this->head;

	while(n_current && !linked){
		if(n_current->get_next() != nullptr && id < n_current->get_next()->identifier){
			p_Node->p_next = n_current->get_next();
			n_current->p_next = p_Node;
			linked = true;
		}
		if (n_current->get_next() != nullptr){
			n_current = n_current->get_next();
		}else{
			break;
		}
	}
	if (!linked){
		n_current->p_next = p_Node;
		p_Node->p_next = nullptr;
	}
}
void Message::print_message(){
	Node *p_Node = this->head;
	unsigned int id = 0;
	while(true){
		if(this->head == nullptr){
			std::cout << "???" << std::endl;
			break;
		}else if(p_Node->get_next() == nullptr && p_Node->get_fragment() != "EOT"){
			std::cout << p_Node->get_fragment() << " ???" << std::endl;
			break;
		}else{
			if (p_Node != nullptr){
				if(id != p_Node->identifier){
					std::cout << "...";
					if(p_Node->get_next() != nullptr ){
						std::cout << " ";
					}else if(p_Node->get_fragment() == "EOT" && id != p_Node->identifier){
						std::cout << " ";
					}
				}else{
					if (p_Node->get_fragment() != "EOT"){
						std::cout << p_Node->get_fragment();
					}
					if(p_Node->get_next() != nullptr && p_Node->get_next()->get_fragment() != "EOT"){
						std::cout << " ";
					}else if(p_Node->get_next() != nullptr && p_Node->get_next()->get_fragment() == "EOT"){
						if(id + 1 < p_Node->get_next()->identifier)
						std::cout << std::endl;
						break;
					}
					if(p_Node->get_next() != nullptr){
						p_Node = p_Node->get_next();
					}
				}

			}else{
				break;
			}
			++id;

		}
	}
}
int main() {
	Message *msg = new Message();
	int id{0};
	std::string frag{};
	while(id != -2){
		std::cin >> id;
		if (id == -1){
			msg->print_message();
		}else if(id >= 0){
			std::cin >> frag;
			msg->insert(id, frag);
		}
	}
	return 0;
}
