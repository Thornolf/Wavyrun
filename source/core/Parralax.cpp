#include "../include/Parralax.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

Parralax::Parralax(int y, float speed, sf::Texture& text)
{
  this->_y = y;
  this->_speed = speed;
  this->_x = 0;
  this->img.setTexture(text);
  this->_t = sf::milliseconds(0);
}

Parralax::~Parralax()
{
}

sf::Sprite	&Parralax::getImg()
{
  return (this->img);
}

void	Parralax::move_parralax(sf::Clock &c, sf::RenderWindow& window)
{
  sf::Time t = c.getElapsedTime();

 if ((this->_t.asMilliseconds() + this->_speed) < t.asMilliseconds())
   {
     this->_t = c.getElapsedTime();
     if (this->_x > 1280)
       this->_x = 0;
     this->_x += 2;
     int tmpx;
     int d;
     d = 0;
     int u;
     u = 0;
     tmpx = this->img.getTexture()->getSize().x;
     while (u < 3)
       {
	 this->img.setPosition(d - this->_x, this->_y);
	 window.draw(this->img);
	 d += tmpx;
	 u++;
       }
   }
}

sf::Time 	Parralax::getTime() const {
	return (this->_t);
}
