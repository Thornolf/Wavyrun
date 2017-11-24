#include "include/Block.hpp"
#include "include/Parralax.hpp"
#include "include/HUD.hpp"
#include "include/Rythm.hpp"
#include <SFML/Audio.hpp>
#include <iostream>

int	main(void) {

  sf::RenderWindow window(sf::VideoMode(1280, 720), "Wavy'Run");
  sf::Texture bg;
  sf::Texture background;
  sf::Clock c;
  sf::RectangleShape delim(sf::Vector2f(1, 200));
  sf::Music musicAmbiance;
  sf::Time t;
  sf::Vector2f velocity(sf::Vector2f(0, 0));
  sf::Texture bloc;
  sf::Texture textureChara;
  bool isGrouned = false;
  const float gravity = 3.5f;
  int groundHeight = 490;
  window.setFramerateLimit(30);

  if (!musicAmbiance.openFromFile("asset/son/champ.ogg")) {
	  exit (EXIT_FAILURE);
  }
  delim.setPosition(50, 0);
  delim.setFillColor(sf::Color(255, 255, 255));

	if (!textureChara.loadFromFile("asset/image/player.png")) {
		exit (EXIT_FAILURE);
	}
	if (!bg.loadFromFile("asset/image/sand.png")) {
		exit (EXIT_FAILURE);
	}
	if (!background.loadFromFile("asset/image/blue_land.png")) {
		exit (EXIT_FAILURE);
	}
	if (!bloc.loadFromFile("asset/image/sand.png")) {
		exit (EXIT_FAILURE);
	}

	Parralax par(-90, 50.00, background);
	sf::Sprite bl(bloc);
	sf::Sprite rect(textureChara);

	rect.setPosition(60, 450);
	bl.setPosition(0, 540);
	float	movespeed = 2000.0f, jumpspeed =50.0f;

	Block *block = new Block(par, bg, 3, 100.0f, c);
	Rythm r[50];
	sf::Sprite v[block->getPlat().size()];
	HUD hud;
	musicAmbiance.play();
	rect.setTextureRect(sf::IntRect(0, 0, 112, 160));
	sf::Time anim;
	int m = 0;
	int	lok = 0;
	int	nb_gh = 0;
	sf::Time gh;
	anim = c.getElapsedTime();
	while (window.isOpen()) {
		  sf::Event event;
		par.move_parralax(c, window);
		  t = c.getElapsedTime();
		//   std::cout << "IMPORTANT >> " << r[nb_gh]._l[r[nb_gh]._l.size()]._x << std::endl;
		  if ((gh.asSeconds() + 20) < t.asSeconds())
		    {
		      gh = c.getElapsedTime();
		      nb_gh++;
		    }
		  if ((anim.asMilliseconds() + 1.00f) < t.asMilliseconds())
		    {
		      lok += 2;
		      if (lok > 128)
			lok = 0;
		    }
		  if ((anim.asMilliseconds() + 100.00f) < t.asMilliseconds())
		    {
		      if (m == 0)
			{
		    //   std::cout << m << std::endl;
			  rect.setTextureRect((sf::IntRect(112, 0, 112, 160)));
			  m = 1;
			}
		      else if (m == 1)
			{
		    //   std::cout << m << std::endl;
			  rect.setTextureRect(sf::IntRect(0, 0, 112, 160));
			  m = 0;
			}
		      if (isGrouned == false)
			{
			  rect.setTextureRect(sf::IntRect(0, 160, 112, 170));
			}
		      anim = c.getElapsedTime();
		    }
		  while (window.pollEvent(event)) {
		    if (event.type == sf::Event::Closed) {
		    	window.close();
		    }
		    r[nb_gh].event_rythm(&hud);
		  }
		/*
		*	Les déplacements du perso
		*/
		float tmp = jumpspeed;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && isGrouned) {
			velocity.y = -tmp;
			// std::cout << "jump : " << jumpspeed << std::endl;
			isGrouned = false;
		}
		if (rect.getPosition().y + rect.getScale().y < groundHeight || velocity.y < 0) {
			velocity.y += gravity;
		}
		else {
			rect.setPosition(rect.getPosition().x, groundHeight - rect.getScale().y);
			velocity.y = 0;
			isGrouned = true;
		}
		rect.move(0 , velocity.y);

		for (unsigned int i = 0; i < block->getPlat().size(); i++) {
			for (unsigned int j = 0; j < block->getPlat().size(); j++) {
				v[j] = block->getPlat().back();
				block->getPlat().pop_back();
			}
			if (rect.getGlobalBounds().intersects(v[i].getGlobalBounds())) {
				velocity.y = 0;
				isGrouned = true;
			}
		}

		r[nb_gh].move_rythm(c, &window);
		block->moveBlock(c, &window);
		// window.draw(par.getImg());
		std::vector<sf::Sprite> plat;

		plat = block->getPlat();

		for(int i = 0; i < plat.size(); i++) {
		  window.draw(plat[i]);
		  //std::cout << 60 << " --> " << plat[i].getPosition().x << std::endl;
		//   if (plat[i].getPosition().x < 60)
		//     {
		//       if ((plat[i].getPosition().y - 128) < 60)
			//  std::cout << "COLLISION" << std::endl;
		//     }
		}
		int i = 0;
		while (i < r[nb_gh]._nb)
		  {
		    window.draw(r[nb_gh]._l[i]._rect);
		    window.draw(r[nb_gh]._l[i]._text);
		    i++;
		  }
		  Rythm *r = new Rythm(c);
		i = 0;
		while (i < 11)
		  {
		    bl.setPosition((i * 128 - lok), 640);
		    window.draw(bl);
		    i++;
		  }
	 	hud.aff_score(&window, c);
		window.draw(rect);
		window.draw(delim);
		window.display();
		// window.clear();
		// if (block.getPos() > 600) {
		// 	block2.moveBlock(, window);
		// }
	}
	return (0);
}
