#define _GLIBCXX_USE_CXX11_ABI 0

#include <cstdlib>
#include <string>
#include <fstream>
#include <ncurses.h>
#include <iostream>
#include "Home.h"
#include "window.h"
<<<<<<< HEAD
int main(int argc, char** argv) {
    startProgramX();
    Home Menu;
    Menu.userInterface();
    if (Menu.getSelect() != Home::empty){
        std::cout<<"HOURRAY! 2"<<std::endl;
    }
    Menu.launcher();
     stopProgramX();
=======
#include "Level.h"
#include "Save.h"

int main(int argc, char** argv) {
    startProgramX();
    std::cout<<"COUCOU J'ARRIVE"<<std::endl;
    Save ouiuoiu;
    std::cout<<"AYE"<<std::endl;
    rectangle A;
    rectangle B;
    rectangle C;
    A.x.x=20;
    A.x.y=20;
    A.y.x=20;
    A.y.y=20;
    B.x.x=20;
    B.x.y=20;
    B.y.x=20;
    B.y.y=20;
    std::cout<<"AYE2"<<std::endl;
    std::vector<Brick> bric;
    std::cout<<"AYE3"<<std::endl;
    std::vector<Ball> bal;
    std::cout<<"AYE4"<<std::endl;
    std::vector<Paddle> pad;
    std::cout<<"AYE5"<<std::endl;
    Level Test(25,1,1,A,B,bric,bal,pad,0,5,2);
    std::cout<<"AYE6"<<std::endl;
   // save.writeSave(Test);
    stopProgramX();
    std::cout<<"coucou";
>>>>>>> 2baa47a768861420483e90688cf2e811ce9ad6bd
    return 0;
}

