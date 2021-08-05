#ifndef _H_KERNEL
#define _H_KERNEL

//Headers
#include "cell.h"
//Libs
#include <fstream>
#include <filesystem> //C++ 17
#include <signal.h> 
#include <unistd.h>

namespace fs = std::filesystem;


class Kernel {

    public:
        void readSpice(std::string filePath);

    private:
        

};

#endif