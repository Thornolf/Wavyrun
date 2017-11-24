#ifndef	PARALAX_H_
#define PARALAX_H_

#include <SFML/Graphics.hpp>

class	Parralax {
protected:
  int	_x;
  int	_y;
  float	_speed;
  sf::Sprite img;
  sf::Time _t;
public:
  Parralax(int y, float speed, sf::Texture &);
  ~Parralax();
  void	move_parralax(sf::Clock &c, sf::RenderWindow& window);
  sf::Sprite	&getImg();
  sf::Time 	getTime() const;
};

#endif
