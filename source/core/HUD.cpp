#include	<SFML/Window.hpp>
#include	<string>
#include	"../include/HUD.hpp"
#include	<iostream>

HUD::HUD()
{
  int	i = 0;
  this->font.loadFromFile("./asset/arial.ttf");;
  this->text.setFont(this->font);
  this->text.setCharacterSize(30);
  this->text.setColor(sf::Color(255, 255, 255));
  this->text.setPosition(1240, 680);
  this->text.setString("0");
  this->score = 0;
}

HUD::~HUD()
{
}

void	HUD::aff_score(sf::RenderWindow *window, sf::Clock c)
{
  std::string s;
  sf::Time	t;
  static sf::Time	t2;
  static int test = 0;
  static int len2;
  int		len = 0;

  s = std::to_string(score);
  if (test == 0)
    {
      len2 = s.length();
      test = 1;
      t2 = c.getElapsedTime();
    }
  t = c.getElapsedTime();
  if ((t2.asMilliseconds() + 500.00f) < t.asMilliseconds())
    {
      t2 = t;
      this->score += 1;
    }
  len = s.length();
  if ((len2 + 1) <= len)
    {
      this->text.setPosition(this->text.getPosition().x - (len * 5), 680);
      len2 = s.length();
    }
  this->text.setString(s.c_str());
  window->draw(this->text);
}
