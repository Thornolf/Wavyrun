#include		"../include/Block.hpp"
#include 		<cstdlib>
#include 		<iostream>

Block::Block(Parralax &para, sf::Texture& text, int nbPlat, float newSpeed, sf::Clock &c) {
	int			i = 0;
	int			name = 0;

	nbPlat = rand() % 2 + 2;
	this->_isSet = false;
	this->_typeFiltre = NEUTRAL;
	this->_speed = newSpeed;
	this->_t = sf::milliseconds(0);
	setPos(0);
	setPar(para);
	std::vector<sf::Sprite> plat;
	srand(time(NULL));
	while (i < nbPlat) {
		name++;
		// std::cout << "name : " << name;
		sf::Sprite name;
		name.setTexture(text);
		name.setPosition((rand() % 1280) + 1280, rand() % 620 + 100);
		plat.push_back(name);
		i++;
	}
	_platform = plat;
}

Block::~Block() {
}

//Block::Block(const Block &obj) {
//	(void)obj;
//}

Block &Block::operator=(const Block &obj){
	(void)obj;
	return *this;
}

void		Block::setPos(int p) {
	_pos = p;
}

void 		Block::setPar(Parralax &newPar) {
	this->_par = &newPar;
}

void 		Block::setPlat(std::vector<sf::Sprite> newList) {
	this->_platform = newList;
}

int 		Block::getPos() const {
	return (this->_pos);
}

Parralax 	*Block::getPar() const {
	return (this->_par);
}

std::vector<sf::Sprite>		Block::getPlat() const {
	return (this->_platform);
}


void 		Block::moveBlock(sf::Clock newClock, sf::RenderWindow *newRenderWindow) {
  sf::Time t = newClock.getElapsedTime();


  // this->_par->move_paralax(newClock, &newRenderWindow);
  // this->_par->move_parralax(newClock, *newRenderWindow);
 if ((this->_t.asMilliseconds() + this->_speed) < t.asMilliseconds())
   {
     this->_t = newClock.getElapsedTime();
     this->_pos += 5;
     float d = 0.0f;
	 int	x, y;

    while (d <= 1285)
       {
		   for (size_t i = 0; i < this->_platform.size(); i++) {
				 this->_platform[i].move(-0.3f * t.asSeconds(), 0);
				 if (this->_platform[i].getPosition().x <= -150.0f) {
					 x = (rand() % 1280) + 1280;
					 while ((x % 128) != 0)
					 	x++;
					 y = rand() % 620;
					 while ((y % 128) != 0)
					 	y++;
					this->_platform[i].setPosition(x, y);
				 }
	 		}
			d += _pos;
       }
   }
 for (size_t i = 0; i < _platform.size(); i++) {
  	  newRenderWindow->draw(this->_platform[i]);
  }

}
