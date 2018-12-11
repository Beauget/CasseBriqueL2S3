#include "Bonus.h"
#include <unistd.h>
#include <iostream>


Bonus::Bonus()
  :m_bonusPattern(), m_color(), m_velocity(), m_clock(), m_typeBonus()
{
}
Bonus::Bonus(rectangle newPattern, Color color, velocity newVelocity, clocks newClock, Bonus::typeBonus newType)
  :m_bonusPattern(newPattern),m_color(color),m_velocity(newVelocity), m_clock(newClock), m_typeBonus(newType)
{}

Bonus::Bonus(const Bonus& orig)
  :m_bonusPattern(orig.getBonusPattern()), m_color(orig.getColor()), m_velocity(orig.getVelocity()), m_clock(orig.getClock())
{
}

Bonus::~Bonus() {
}


void Bonus::setBonusPattern(rectangle newPattern){m_bonusPattern=newPattern;}
void Bonus::setColor(Color newColor){m_color=newColor;}
void Bonus::setVelocity(velocity newVelocity){m_velocity=newVelocity;}
void Bonus::setClock(clocks newClock){m_clock=newClock;}
void Bonus::setType(Bonus::typeBonus newType){m_typeBonus=newType;}

rectangle Bonus::getBonusPattern()const{return m_bonusPattern;}
Color Bonus::getColor()const{return m_color;}
velocity Bonus::getVelocity()const{return m_velocity;}
clocks Bonus::getClock()const{return m_clock;}
Bonus::typeBonus Bonus::getType()const{return m_typeBonus;}

bool Bonus::move(){
  rectangle new_pos;
  new_pos=getBonusPattern();
  if(getVelocity().direction.x!=0){
    new_pos.x.x=new_pos.x.x*getVelocity().accel*getVelocity().direction.x;
    new_pos.x.y=new_pos.x.y*getVelocity().accel*getVelocity().direction.x;
  }
  if(getVelocity().direction.y!=0){
    new_pos.y.y=new_pos.y.y*getVelocity().accel*getVelocity().direction.y;
    new_pos.y.x=new_pos.y.x*getVelocity().accel*getVelocity().direction.y;
  }
  this->setBonusPattern(new_pos);
  return true;
}



/*int main(){
  rectangle newBPattern;
  newBPattern.x.x=5;newBPattern.x.y=5;
  newBPattern.y.x=5;newBPattern.y.y=5;
  velocity newBVelocity;
  newBVelocity.accel=1.5;newBVelocity.direction.x=0;newBVelocity.direction.y=1;
  clocks newClock; newClock.c=20;
  Bonus b(newBPattern,WBLACK,newBVelocity,newClock,Bonus::jumpPlus);
  int ch;
  startProgramX();
  int h=50,w=50;
  Window plateau(h,w,1,6,'C');
  plateau.setCouleurBordure(BBLUE);
  do{
    for(int i=0;i<50;++i){                   //Hauteur
      for(int j= 0;j<50;++j){                //Largeur
        if(i==b.getBonusPattern().x.x && j==b.getBonusPattern().y.y)
          plateau.print(i,j,'B',BYELLOW);
        else
          plateau.print(i,j,'-',WBLACK);
      }
    }
    b.move();
    refresh();
  }while((ch=getch())!='q');
  stopProgramX();

  return 0;
}*/