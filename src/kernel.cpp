
#include "kernel.h"


void Kernel::readSpice(fs::path filePath){

    std::ifstream spiceFile;
    std::string line, extension;

    extension = filePath.extension();

    try{
        if(extension == ".sp" || extension == ".cir" || extension == ".spc" || extension == ".spi" || extension == ".sps" || extension == ".inc" || extension == ".lib"){

        }else
            throw;

    }catch(...){
        std::cout <<  "ERROR: File extension is not valid" << std::endl;

    }


    spiceFile.open(filePath);

    if(!spiceFile.is_open()){
        std::cout << "ERROR: File opening error" << std::endl;      //usar outra classe posteriormente para tratamento de erros
        return;
    }

    while(getline (spiceFile,line)){



    }


    spiceFile.close();


}