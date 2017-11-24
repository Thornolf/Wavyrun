#ifndef	HUD_H_
#define HUD_H_

#include	<SFML/Graphics.hpp>
#include	<SFML/Window.hpp>

class	HUD
{
  sf::Font	font;
  sf::Text	text;
public:
  int		score;
  HUD();
  ~HUD();
  void	aff_score(sf::RenderWindow *, sf::Clock);
};

#endif
