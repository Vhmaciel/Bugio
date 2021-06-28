#include <iostream>
#include <string>


enum TransType {PMOS, NMOS};

struct Transistor{

	std::string name;
    int drain, gate, source;
	TransType type;
	float length, width;	

};