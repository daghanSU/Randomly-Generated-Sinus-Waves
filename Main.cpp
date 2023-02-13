#include <iostream>
#include <SFML/Graphics.hpp>
#include "Wave.h"

using namespace sf;
using namespace std;

int main() {

	RenderWindow* window = new RenderWindow(VideoMode(600, 400), "Waves");
	window->setFramerateLimit(60);

	srand(time(0));

	vector<Wave>waves;

	for (int i = 0; i < 5; i++) {
		double rand_amp = rand() % 80 + 20;
		double rand_period = rand() % 500 + 100;
		waves.push_back(Wave(rand_amp, rand_period, 1));
	}
	
	double r = 5;

	while (window->isOpen()) {
		Event event;
		while (window->pollEvent(event)) {
			if (event.type == Event::Closed)
				window->close();
		}

		for (int i = 0; i < waves.size(); i++) {
			waves[i].update();
		}

		window->clear();

		for (double i = 0; i < window->getSize().x; i++) {
			double y = 0;

			for (Wave wave:waves) {
				y += wave.f(i);
			}
			
			CircleShape temp(r);
			temp.setPosition(i, y + window->getSize().y / 2);
			window->draw(temp);
		}

		window->display();
	}

	return 0;
}