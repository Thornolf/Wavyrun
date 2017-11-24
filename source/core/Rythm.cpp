#include	"../include/Rythm.hpp"
#include	<cstdlib>
#include	<iostream>
#include	<math.h>
#include	"../include/HUD.hpp"

Rythm		Rythm::generate(sf::Clock c)
{
  Rythm	*ret = new Rythm;

  sf::Time	t;
  float		s;
  int		nb_t;
  RLetter	gen;
  int		a;
  t = c.getElapsedTime();
  if (ret->_font.loadFromFile("./asset/arial.ttf"))
	exit(EXIT_FAILURE);
  s = t.asSeconds() / 10;
  a = std::floor(s);
  nb_t = rand() % 3;
  nb_t += a + 1;
  if (nb_t == 0)
	nb_t = 1;
  ret->_i = 0;
  gen._x = 1280;
  gen._text.setFont(ret->_font);
  int	i = 0;
  int x;
  x = 1280 / nb_t;
  while (i < nb_t)
	{
	  gen._letter = rand() % 25;
	  gen._letter += 65;
	  gen._rect.setSize(sf::Vector2f(90, 70));
	  gen._rect.setFillColor(sf::Color(255, 255, 255, 0.5));
	  gen._rect.setOutlineThickness(10.00);
	  gen._rect.setOutlineColor(sf::Color::White);
	  gen._isSet = false;
	  char str[2];
	  str[0] = gen._letter;
	  str[1] = '\0';
	  const char *s = str;
	  gen._text.setCharacterSize(70);
	  gen._text.setPosition(1110 + (x * i + (rand() % x)), 10);
	  gen._text.setColor(sf::Color::White);
	  gen._text.setString(s);
	  ret->_l.push_back(gen);
	  i++;
	}
  ret->_nb = nb_t;
  return (*ret);
}

Rythm::Rythm()
{
  sf::Clock	c;
  sf::Time	t;
  float		s;
  int		nb_t;
  RLetter	gen;
  int		a;
  t = c.getElapsedTime();
  if (!this->_font.loadFromFile("./asset/arial.ttf"))
    exit(EXIT_FAILURE);
  s = t.asSeconds() / 10;
  a = std::floor(s);
  nb_t = rand() % 3;
  nb_t += a + 2;
  if (nb_t == 0)
    nb_t = 1;
  this->_i = 0;
  gen._x = 1280;
  gen._text.setFont(this->_font);
  int	i = 0;
  int x;
  x = 1280 / nb_t;
  while (i < nb_t)
    {
      gen._letter = rand() % 25;
      gen._letter += 65;
      gen._rect.setSize(sf::Vector2f(90, 70));
      gen._rect.setFillColor(sf::Color(255, 255, 255, 0.5));
      gen._rect.setOutlineThickness(10.00);
      gen._rect.setOutlineColor(sf::Color::White);
      gen._isSet = false;
      char str[2];
      str[0] = gen._letter;
      str[1] = '\0';
      const char *s = str;
      gen._text.setCharacterSize(70);
      gen._text.setPosition(1110 + (x * i + (rand() % x)), 10);
      gen._text.setColor(sf::Color::White);
      gen._text.setString(s);
      this->_l.push_back(gen);
      i++;
    }
  this->_nb = nb_t;
}

Rythm::Rythm(sf::Clock c)
{
  sf::Time	t;
  float		s;
  int		nb_t;
  RLetter	gen;
  int		a;
  t = c.getElapsedTime();
  if (!this->_font.loadFromFile("./asset/arial.ttf"))
    exit(EXIT_FAILURE);
  s = t.asSeconds() / 10;
  a = std::floor(s);
  nb_t = rand() % 3;
  nb_t += a + 1;
  if (nb_t == 0)
    nb_t = 1;
  this->_i = 0;
  gen._x = 1280;
  gen._text.setFont(this->_font);
  int	i = 0;
  int x;
  x = 1280 / nb_t;
  while (i < nb_t)
    {
      gen._letter = rand() % 25;
      gen._letter += 65;
      gen._rect.setSize(sf::Vector2f(90, 70));
      gen._rect.setFillColor(sf::Color(255, 255, 255, 0.5));
      gen._rect.setOutlineThickness(10.00);
      gen._rect.setOutlineColor(sf::Color::White);
      gen._isSet = false;
      char str[2];
      str[0] = gen._letter;
      str[1] = '\0';
      const char *s = str;
      gen._text.setCharacterSize(70);
      gen._text.setPosition(1110 + (x * i + (rand() % x)), 10);
      gen._text.setColor(sf::Color::White);
      gen._text.setString(s);
      this->_l.push_back(gen);
      i++;
    }
  this->_nb = nb_t;
}

void	Rythm::move_rythm(sf::Clock c, sf::RenderWindow *window)
{
  int	i = 0;

  int x;
  sf::Time	t;
  static sf::Time      t2;
  static int j = 0;

  if (j == 0)
    {
      t2 = c.getElapsedTime();
      j = 1;
    }
  t = c.getElapsedTime();
  if ((t2.asMilliseconds() + (20.00f - (t.asMilliseconds() / 6000))) < t.asMilliseconds())
    {
      i = 0;
      while (i < this->_nb)
	{
	  x = this->_l[i]._text.getPosition().x - 5;
	  this->_l[i]._x = x;
	  //std::cout << "GET THAT JOB : " << x << std::endl;
  	  this->_l[i]._text.setPosition(x, 10);
	  this->_l[i]._rect.setPosition(x - 30, 20);
	  i++;
	}
      t2 = c.getElapsedTime();
    }
}

void	Rythm::event_rythm(HUD *hud)
{
  if (sf::Keyboard::isKeyPressed(static_cast<sf::Keyboard::Key>(this->_l[this->_i]._letter - 65)))
    {
      int a;
      int	b;
      a = 50 - (this->_l[this->_i]._rect.getPosition().x + 45);
      if (a < 0)
	a *= -1;
      if (a > 45)
	{
	  this->_l[this->_i]._rect.setFillColor(sf::Color(255, 0, 0, 0.5));
	  this->_l[this->_i]._rect.setOutlineThickness(10.00);
	  this->_l[this->_i]._rect.setOutlineColor(sf::Color(255, 0, 0));
  	  this->_l[this->_i]._text.setColor(sf::Color(255, 0, 0));
	  this->_l[this->_i]._isSet = true;
	  this->_i++;
	}
      else if (this->_l[this->_i]._isSet == false)
	{
	  this->_l[this->_i]._rect.setFillColor(sf::Color(0, 255, 0, 0.5));
	  this->_l[this->_i]._rect.setOutlineThickness(10.00);
	  this->_l[this->_i]._rect.setOutlineColor(sf::Color(0, 255, 0));
  	  this->_l[this->_i]._text.setColor(sf::Color(0, 255, 0));
	  this->_i++;
	  int p;
	  p = a - 45;
	  if (p < 0)
	    p *= -1;
	  hud->score += p;
  	}
    }
}
