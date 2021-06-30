#include <iostream>
#include <string>
#include <vector>


enum TransType {PMOS, NMOS};

struct Transistor{

	std::string name;
    int drain, gate, source;
	TransType type;
	float length, width;	

};

class Cell {


	private:
		std::string cellName; 
		std::vector<Transistor> trans;


};