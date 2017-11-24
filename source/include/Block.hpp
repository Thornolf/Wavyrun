#ifndef 	_BLOCK_HPP_
#define 	_BLOCK_HPP_

#include	<vector>

#include	"../include/Parralax.hpp"
#include	"../include/Rythm.hpp"

class Block {

public:
	typedef enum 	ZONE {
	 	NEUTRAL,
		QTE,
		FAST,
		SLOW
	}				ZONE;

private:
	float						_pos;
	Parralax					*_par;
	std::vector<sf::Sprite>	_platform;
	float 					_speed;
	sf::Time 				_t;
	ZONE 					_typeFiltre;
	sf::Sprite				_filtre;
	bool					_isSet;


public:
	Block(Parralax &, sf::Texture& , int, float, sf::Clock&);
	virtual ~Block();
	//Block(const Block &);
	Block	&operator=(const Block &);

	int						getPos() const;
	Parralax*				getPar() const;
	std::vector<sf::Sprite>	getPlat() const;
	float 					getSpeed() const;

	void 					setSpeed(float);
	void					setPos(int);
	void					setPar(Parralax &);
	void 					setPlat(std::vector<sf::Sprite>);

	void					moveBlock(sf::Clock, sf::RenderWindow *);
	bool					checkBlockIntegrity();
	/* ENUM TYPE FILTE */
};

#endif 		/* !_BLOCK_HPP_ */


/*

void	Paralax::move_paralax(sf::Clock c, sf::RenderWindow* window)
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
     tmpx = this->img.getTexture()->getSize().x;
     while (d <= 1280)
       {
	 this->img.setPosition(d - this->_x, this->_y);
	 window->draw(this->img);
	 d += tmpx;
       }
   }
}

*/
