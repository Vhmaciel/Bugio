#include <iostream>
#include <fstream>
#include <experimental/filesystem> //C++ 17
#include <string>
#include "cell.h"
namespace fs = std::experimental::filesystem;


class Kernel {

    public:
        void readSpice(fs::path filePath);

    private:
        

};