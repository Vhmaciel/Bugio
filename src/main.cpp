//Headers
#include "kernel.h"
//Libs

//Global variables
int teste = 1;

void signalHandler(int signal){
    teste = 0;
    std::cout << std::endl << "Program was interrupted" << std::endl; 
};

int main(int argc,char *argv[]){

    if (argc!=2) 
        exit(1);

    struct sigaction sigIntHandler;

    sigIntHandler.sa_handler = signalHandler;
    sigemptyset(&sigIntHandler.sa_mask);
    sigIntHandler.sa_flags = 0;

    sigaction(SIGINT, &sigIntHandler, NULL);

    while(teste){



    }




   return 0;

}