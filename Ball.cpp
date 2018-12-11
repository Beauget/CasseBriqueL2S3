#include "Ball.h"

Ball::Ball()
  :m_ballPattern(), m_color(), m_velocity(), m_resistance()
{
}


Ball::Ball(const Ball& orig)
  :m_ballPattern(orig.m_ballPattern), m_color(orig.m_color), m_resistance(orig.m_resistance)
{
}
Ball::Ball(rectangle pattern,Color color,velocity velocity,int resistance)
  :m_ballPattern(pattern),m_color(color),m_velocity(velocity),m_resistance(resistance)
{
}
Ball::~Ball()
{
}

void Ball::setBallPattern(rectangle newPattern){m_ballPattern=newPattern;}
void Ball::setColor(Color newColor){m_color=newColor;}
void Ball::setVelocity(velocity newVelocity){m_velocity=newVelocity;}
void Ball::setResistance(int newResistance){m_resistance=newResistance;}


rectangle Ball::getBallPattern()const{return m_ballPattern;}
Color Ball::getColor()const{return m_color;}
velocity Ball::getVelocity()const{return m_velocity;}
int Ball::getResistance()const{return m_resistance;}

bool Ball::collide(Ball &ball){
  this->move(); bool haveCollided=false;
  rectangle new_pattern=this->getBallPattern();
  velocity new_velocity=this->getVelocity();
  if((this->getBallPattern().x.x==ball.getBallPattern().x.x)
     && (this->getBallPattern().x.y==ball.getBallPattern().x.y)){
    new_pattern.x.x=(this->getBallPattern().y.x);
    new_pattern.x.y=(this->getBallPattern().y.y);
    new_velocity.direction.x=-new_velocity.direction.x;
    haveCollided=true;
  }
  else
    if((this->getBallPattern().y.x==ball.getBallPattern().y.x)
       && (this->getBallPattern().y.y==ball.getBallPattern().y.y)){
      new_pattern.y.x=(this->getBallPattern().x.x);
      new_pattern.y.y=(this->getBallPattern().x.y);
      new_velocity.direction.y=-new_velocity.direction.y;
      haveCollided=true;
    } 
  this->setBallPattern(new_pattern);
  return haveCollided;    
}

bool Ball::collide(Brick &brick){
  this->move(); bool haveCollided=false;
  rectangle new_pattern=this->getBallPattern();
  velocity new_velocity=this->getVelocity();
  if((this->getBallPattern().x.x==brick.getBrickPattern().x.x)
     && (this->getBallPattern().x.y==brick.getBrickPattern().x.y)){
    new_pattern.x.x=(this->getBallPattern().y.x);
    new_pattern.x.y=(this->getBallPattern().y.y);
    new_velocity.direction.x=-new_velocity.direction.x;
    haveCollided=true;
  }
  else
    if((this->getBallPattern().y.x==brick.getBrickPattern().y.x)
       && (this->getBallPattern().y.y==brick.getBrickPattern().y.y)){
      new_pattern.y.x=(this->getBallPattern().x.x);
      new_pattern.y.y=(this->getBallPattern().x.y);
      new_velocity.direction.y=-new_velocity.direction.y;
      haveCollided=true;
    } 
  this->setBallPattern(new_pattern);
  return haveCollided;    
}

bool Ball::collide(Paddle &paddle){
  this->move(); bool haveCollided=false;
  rectangle new_pattern=this->getBallPattern();
  velocity new_velocity=this->getVelocity();
  if((this->getBallPattern().x.x==paddle.getPaddlePattern().x.x)
     && (this->getBallPattern().x.y==paddle.getPaddlePattern().x.y)){
    new_pattern.x.x=(this->getBallPattern().y.x);
    new_pattern.x.y=(this->getBallPattern().y.y);
    new_velocity.direction.x=-new_velocity.direction.x;
    haveCollided=true;
  }
  else
    if((this->getBallPattern().y.x==paddle.getPaddlePattern().y.x)
       && (this->getBallPattern().y.y==paddle.getPaddlePattern().y.y)){
      new_pattern.y.x=(this->getBallPattern().x.x);
      new_pattern.y.y=(this->getBallPattern().x.y);
      new_velocity.direction.y=-new_velocity.direction.y;
      haveCollided=true;
    } 
  this->setBallPattern(new_pattern);
  return haveCollided;    
}

bool Ball::move(){
  rectangle new_pos;bool isMoving=false;
  new_pos=getBallPattern();
  if(getVelocity().direction.x!=0){
    new_pos.x.x=(new_pos.x.x*getVelocity().accel*getVelocity().direction.x);
    isMoving=true;
  }
  if(getVelocity().direction.y!=0){
    new_pos.y.y=(new_pos.y.y*getVelocity().accel*getVelocity().direction.y);
    isMoving=true;
  }
  this->setBallPattern(new_pos);
  return isMoving;
}
