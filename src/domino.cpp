
//
//  main.cpp
//  Domino
//
//  Created by Vitor Hugo Maciel on 27/03/18.
//  Copyright © 2018 Vitor Hugo Maciel. All rights reserved.
//


#include <iostream>
#include "z3++.h"
#include <vector>

using namespace z3;

typedef struct Piece{


    int right, left;            //sides of piece


} piece;


int main(int argc, const char * argv[]) {


    std::vector<piece> p;
    piece v;
    int tam, a, b;


    do{
        std::cout << "Number of Pieces:" << std::endl;      //get number of pieces
        std::cin >> tam;
        if (tam<=1)
            std::cout << "Invalid Number" << std::endl;         //invalid number of pieces
    }while (tam<=1);


    for(int i=0; i<tam; i++){
        std::cout << "Piece " << i+1 << ":" << std::endl;       //store the data
        std::cin >> a >> b;
        v.left = a;
        v.right = b;
        p.push_back(v);


        std::cout << std::endl;

    }

    while(true){
	    context c;              //generate context for the constraints


	    std::vector<expr> f, r, l, flipped;
	    solver s(c);

	    for(int i=0; i<tam; i++){
			f.push_back(c.int_const(("f"+std::to_string(i)).c_str()));      //spaces for the domino pieces
			l.push_back(c.int_const(("l"+std::to_string(i)).c_str()));      //sides of piece
			r.push_back(c.int_const(("r"+std::to_string(i)).c_str()));
			flipped.push_back(c.bool_const(("flipped"+std::to_string(i)).c_str()));         //flipped piece

	    }


	    for(int i=0; i<tam; i++){
			s.add(f[i]>=0 && f[i]<tam);         //allocate all spaces
			for(int j=i+1; j<tam; j++){
				s.add(f[i] != f[j]);            //no space can be equal / occupy the same place

		    }
		}


	    for(int i=0; i<tam-1; i++){         //fitting pieces constraints
		s.add(r[i]==l[i+1] || r[i]==0 || l[i+1]==0);                //piece right side must be equal to next piece left side
		                //piece left side must be equal to the previous piece right side

	    }

	    for(int i=0; i<tam; i++){
			for(int j=0; j<tam; j++){
				s.add(ite(flipped[i], implies(f[i]==j, r[i]==p[j].left), implies(f[i]==j, r[i]==p[j].right)));
				s.add(ite(flipped[i], implies(f[i]==j, l[i]==p[j].right), implies(f[i]==j, l[i]==p[j].left)));

			}
	    }
	    
		if(s.check()==sat){             //check and print
		    std::cout << s.check() << std::endl;
		    model m = s.get_model();

		    for(int i=0; i<tam; i++){
		        std::cout << "position " << i+1 << " - " << "piece " << m.eval(f[i]+1);
		        std::cout << "   \tflipped: " << m.eval(flipped[i]) << std::endl;

		    }

		    std::cout << std::endl;

		    for(int i=0; i<tam; i++){
		        std::cout << "[" << m.eval(l[i]) << "|" << m.eval(r[i]) << "] ";
		    }

		    std::cout << "\n\n";
		    break;
		    
		}
		else{
		
		    v.left = 0;
		    v.right = 0;
		    p.push_back(v);
		    tam++;
		}
    }










    return 0;








}
