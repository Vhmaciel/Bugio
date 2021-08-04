//Headers
#include "kernel.h"
//Libs



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