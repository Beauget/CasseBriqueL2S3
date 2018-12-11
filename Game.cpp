#include "Game.h"
#include "window.h"
Game::Game()
  :m_level(),m_timer(),m_pause(true),m_help(false)
{
}

Game::Game(const Game& orig)
  :m_level(orig.getLevel()),m_timer(orig.getTimer()),m_pause(orig.getPause()),m_help(orig.getHelp())
{
}

Game::~Game() {
  m_level.~Level();
}

level Game::getLevel()const{return m_level;}
timer Game::getTimer()const{return m_timer;}
bool Game::getPause()const{return m_pause;}
bool Game::getHelp()const{return m_help;}

void Game::setLevel(Level newLevel){m_level=newLevel;}
void Game::setLevel(timer newTimer){m_level=newTimer;}
void Game::setPause(bool newPause){m_pause=newPause;}
void Game::setHelp(bool newHelp){m_help=newHelp;}


bool Game::update(){
  //update tout les objets dans un certain ordre + gérer la pause/aide
  if(this->getPause()==true){
    std::cout<<"Paused"<<std::endl; //On le display sur le plateau de jeu
    return true
  }
  else{
    //update chaque objets
    for(size_t i=0;i<m_level.m_NbBrick; i++){
      m_level.TabBrick[i].hit();
    }
    for(size_t i=0;i<m_level.m_NbBall; i++){
      m_level.TabBall[i].collide();
    }
    for(size_t i=0;i<m_level.m_NbPaddle; i++){
      m_level.TabPaddle[i].move();
    }

    timer new_timer=(this->getTimer().c)+1;  //Pas sur de faire une struct timer ???
    this->setTimer(new_timer);
  }
  return false;
}

bool Game::quit(int key){
  if((key=getch())=='q')
    //quitter la partie et revenir au menu
    this->~Game();
}

bool Game::interrupt(int key){
  if(this->getPause==false){
    if((key=getch())=='h'){
      this->setPause(true);
      this->setHelp(true);
      //do stuff and display help
      
    return true;
    }
    else if((key=getch())=='p'){
      this->setPause(true);
      //stop stuff et c'est bon je crois parce que l'update se fera pas
      //Il faut juste stopper le timer
      
      return true;
    }
  }
  else{
    if((key=getch())=='h'){
      this->setPause(false);
      this->setHelp(false);
      //do stuff
      Window helpScreen;
      
      return true;
    }
    else if((key=getch())=='p'){
      this->setPause(false);
      //resume stuff, ça c'est bon
      
      return true;
    }
  }
  return false;
}

bool Game::launch(int key){
  if((key=getch())==' '){
    this->update();
    return true;
  }
  else return false;
}

//Une fct void runGame() ?????
void runGame(Game &testGame){
  startProgramX();;
  int ch;
  do{
  Window gameScreen(50,50,1,1,'|');
  gameScreen.print();
  }while((ch=getch())!='q') 
  stopProgramX();
}


int main(){
  Game testGame;
  runGame(&testGame);
  return 0;
}