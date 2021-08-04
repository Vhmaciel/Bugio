//Headers
#include "cell.h"
//Libs
#include <fstream>
#include <experimental/filesystem> //C++ 17
#include <signal.h> 
#include <unistd.h>

namespace fs = std::experimental::filesystem;
int teste = 1;

void signalHandler(sig_atomic_t);

class Kernel {

    public:
        void readSpice(fs::path filePath);

    private:
        

};