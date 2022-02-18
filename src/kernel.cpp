
#include "kernel.h"
#include <sstream>
#include <string>
#include <iostream>


void Kernel::readSpice(std::string filePath){

    std::ifstream spiceFile;
    std::string line, extension;
	const bool reading_cadence = 0;
	int lineNr = 0;

	Cell subcktCell,topCell;
    Cell *currentCell=&topCell;

    extension = fs::path(filePath).extension();   //get file extension

    try{    //test if file extension is valid
        if(extension == ".sp" || extension == ".cir" || extension == ".spc" || extension == ".spi" || extension == ".sps" || extension == ".inc" || extension == ".lib"){
            
            spiceFile.open(filePath);

            if(!spiceFile.is_open()){
                throw NO_FILE_ER;
    		}

			std::vector<std::string> wordsVector;
			std::string word;

    		while(spiceFile){
				
				lineNr++;

				std::getline(spiceFile, line);
				
				wordsVector.clear();

				std::istringstream cline(line.c_str());
            
             	while (cline>>word)
                 	wordsVector.push_back(StringToUpper(word));

				if (wordsVector[0] == "*INTERFACE")
				{
					if (wordsVector.size() == 4 || wordsVector.size() == 6)
					{
						//IOType type;
						//direction orient;
						switch (wordsVector[2][wordsVector[2].size() - 1])
						{
						case 'N':
							//orient = N;
							break;
						case 'S':
							//orient = S;
							break;
						case 'E':
							//orient = E;
							break;
						case 'W':
							//orient = W;
							break;
						default:
							throw (INTERFACE_OR_ER);
						}
						switch (wordsVector[3][0])
						{
						case 'I':
							//type = IOTYPE_INPUT;
							break;
						case 'O':
							//type = IOTYPE_OUTPUT;
							break;
						default:
							throw INTERFACE_TYPE_ER;
						}
						//topCell.insertInOut(wordsVector[1]);
						//netlist.insertInterface(wordsVector[1], orient, type, 0, 0);
					}
					else
						throw INTERFACE_PARAM_ER;

					continue;
				}

				if (reading_cadence && wordsVector[0] == "*" && wordsVector.size() == 5 && wordsVector[1] == "SUBCIRCUIT")
				{
					currentCell->clear();
					topCell.setName(wordsVector[4].substr(0, wordsVector[4].size() - 1));
				}
			}

        }else
            throw EXTENSION_ER;

    }catch(EXTENSION_ER){
        std::cout <<  "ERROR: File extension is not valid" << std::endl;
		return;

    }catch(NO_FILE_ER){
		std::cout << "ERROR: File opening error" << std::endl;
		return;
	}catch(INTERFACE_OR_ER){
		std::cout << "Line" + to_string(lineNr) + ": Interface orientation unknown.";

	}catch(INTERFACE_TYPE_ER){
		std::cout << "Line" + to_string(lineNr) + ": Interface type unknown. Use INPUT or OUTPUT";

	}catch(INTERFACE_PARAM_ER){
		std::cout << "Line" + to_string(lineNr) + ": Number of parameters for *interface is not correct";

	}






    spiceFile.close();


}


std::string StringToUpper(std::string strToConvert)
{
    std::transform(strToConvert.begin(), strToConvert.end(), strToConvert.begin(), ::toupper);

    return strToConvert;
}