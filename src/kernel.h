#ifndef _H_KERNEL
#define _H_KERNEL

//Headers
#include "cell.h"
//Libs
#include <fstream>
#include <filesystem> //C++ 17
#include <signal.h> 
#include <unistd.h>

#define EXTENSION_ER 257
#define NO_FILE_ER 258
#define INTERFACE_OR_ER 259
#define INTERFACE_TYPE_ER 260
#define INTERFACE_PARAM_ER 261

namespace fs = std::filesystem;


class Kernel {

    public:
        void readSpice(std::string filePath);

    private:
        

};

#endif