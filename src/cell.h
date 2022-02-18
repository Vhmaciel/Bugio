#ifndef _H_CELL
#define _H_CELL

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

	public:
		void clear();

	private:
		std::string cellName; 
		std::vector<Transistor> trans;


};

class Lib {

	private:
		std::string name;
		std::vector<Cell> cell;
		
};

#endif