#pragma once

#include <SFML/audio.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <utility>
#include <algorithm>
#include <Windows.h>
using namespace std;

class Snake
{
public:
	Snake(float position_0x,float position_0y);
	~Snake();

	void Draw(sf::RenderWindow &window);
	void turn(pair<float, float> direction_turn);
	void snake_go(pair<float, float> dirction_present, sf::RenderWindow& window);
	int speed_up(int gap);

	int body_size = 3;
	int speed;
	int cnt;
	vector<pair<float, float>> direction_body{ body_size };
	vector<pair<float, float>> position_body{ body_size };
	float position_head[2];

private:
	
};


