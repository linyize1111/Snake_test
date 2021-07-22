#include "Snake.h"

Snake::Snake(float position_0x, float position_0y) {
    position_head[0] = position_0x;
    position_head[1] = position_0y;

    body_size = 3;
    speed = 7;

    for (int i = 0; i < body_size; i++) {
        direction_body[i].first = 1;
        direction_body[i].second = 0;

        position_body[i].first = position_0x - (i + 1) * 20;
        position_body[i].second = position_0y;
    }
    
    cnt = -1;
}

Snake::~Snake() {

}

void Snake::Draw(sf::RenderWindow &window) {
    
}

void Snake::snake_go(pair<float, float> direction_head,sf::RenderWindow &window) {

    //判定是否越界
    if (Snake::position_head[0] < 150 || Snake::position_head[0] > 850 ||
        Snake::position_head[1] < 100 || Snake::position_head[1] > 600) {
        cout << "Game over" << endl;
        window.close();
    }

    //頭部移動
    Snake::position_head[0] += (direction_head.first) * 20;
    Snake::position_head[1] += (direction_head.second) * 20;

    sf::RectangleShape head(sf::Vector2f(18.f, 18.f));
    head.setFillColor(sf::Color::Red);
    head.setPosition(sf::Vector2f(Snake::position_head[0], Snake::position_head[1]));
    window.draw(head);
    

    //身體移動
    for (int i = 0; i < Snake::body_size; i++) {
        Snake::position_body[i].first += (Snake::direction_body[i].first) * 20;
        Snake::position_body[i].second += (Snake::direction_body[i].second) * 20;
    }
    
    Snake::cnt++; Snake::cnt %= (Snake::body_size);
    Snake::direction_body[Snake::cnt].first = direction_head.first;
    Snake::direction_body[Snake::cnt].second = direction_head.second;

    for (int i = 0; i < Snake::body_size; i++) {
        sf::RectangleShape body(sf::Vector2f(18.f, 18.f));
        body.setPosition(sf::Vector2f(Snake::position_body[i].first, Snake::position_body[i].second));
        window.draw(body);
    }
   
    window.setFramerateLimit(Snake::speed);
}

int Snake::speed_up(int gap) {
    if (Snake::speed <= 20) Snake::speed += gap;
    else cout << "Max Speed" << endl;
    
    return Snake::speed;
}

/*
void Snake::turn(pair<float, float> direction_turn) {
    Snake::direction_body.first = direction_turn.first;
    Snake::direction_body.second = direction_turn.second;
}
*/