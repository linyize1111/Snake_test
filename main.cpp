#include <SFML/Graphics.hpp>
#include <SFML/audio.hpp>
#include <iostream>
#include <String>
#include "Snake.h"

using namespace std;

#define length_x 700 //35 lines 
#define length_y 500 //25 lines 

int space[35][25];


int main() {
    sf::RenderWindow window(sf::VideoMode(1000, 700), "SNAKE",!sf::Style::Titlebar);
    //window.setMouseCursorVisible(false);

    sf::Font font;
    font.loadFromFile("Snowday.ttf");

    sf::Text title,string_min;
    title.setFont(font);
    title.setString("SNAKE GAME");
    title.setFillColor(sf::Color::White);
    title.setCharacterSize(80);

    sf::VertexArray lines_x(sf::Lines, 52), lines_y(sf::Lines, 72);
    
    
    for (int i = 0; i < 52; i += 2) {
        lines_x[i].position = sf::Vector2f(150, 100 + 20 * i / 2);
        lines_x[i + 1].position = sf::Vector2f(150 + length_x, 100 + 20 * i / 2);
        lines_x[i].color = sf::Color::Green; lines_x[i+1].color = sf::Color::Green;
    }
    
    for (int i = 0; i < 72; i += 2) {
        lines_y[i].position = sf::Vector2f(150 + 20 * i / 2, 100);
        lines_y[i + 1].position = sf::Vector2f(150 + 20 * i / 2, 100 + length_y);
        lines_y[i].color = sf::Color::Green; lines_y[i+1].color = sf::Color::Green;
    }

    for (int i = 0; i < 35; i++) {
        for (int j = 0; j < 25; j++){
            space[i][j] = 0;
        }
    }
    
    sf::Texture texture_background;
    texture_background.loadFromFile("background_pic.jpg");

    sf::Sprite
        background(texture_background);

    sf::Music music_background;

    music_background.openFromFile("music_1.wav");
    music_background.setLoop(true);

    background.setScale(sf::Vector2f(5.0f, 5.0f));
    background.setOrigin(sf::Vector2f(100, 100));

    Snake snake(431.f, 381.f);

    pair<int, int> direction;
    direction.first = 1;
    direction.second = 0;
    music_background.play();
    while (window.isOpen()) {
        sf::Event event;


        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            direction.first = 0; direction.second = -1;
            cout << "changed" << endl;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            direction.first = 0; direction.second = 1;
            cout << "changed" << endl;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            direction.first = -1; direction.second = 0;
            cout << "changed" << endl;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            direction.first = 1; direction.second= 0;
            cout << "changed" << endl;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            snake.speed_up(1);
        }

        window.clear();
        window.draw(background);
        window.draw(title);
        window.draw(lines_x);
        window.draw(lines_y);
        snake.snake_go(direction, window) ;
        window.display();
    }
    return 0;
}