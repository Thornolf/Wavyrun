#ifndef RYTHM_H_
#define RYTHM_H_

#include	<SFML/Graphics.hpp>
#include	<SFML/System/Clock.hpp>
#include	<vector>
#include	"HUD.hpp"

class	RLetter
{
public:
  char	_letter;
  int	_x;
  sf::Text	_text;
  sf::RectangleShape _rect;
  bool		_isSet;
};

class	Rythm
{
  sf::Font	_font;
  int		_i;
public:
  std::vector<RLetter>	_l;
  int		_nb;
  Rythm(sf::Clock c);
  Rythm();
  void move_rythm(sf::Clock c, sf::RenderWindow *);
  void	event_rythm(HUD *hud);
  Rythm	generate(sf::Clock);
};

#endif
