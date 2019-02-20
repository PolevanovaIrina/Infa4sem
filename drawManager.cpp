#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "drawManager.hpp"


void DrawManager::init() {
    sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode(800, 612), "My window");
    this->window = window;

    sf::Texture* texture = new sf::Texture;
    texture->loadFromFile("logo1.jpg");
    sf::Sprite* bg = new sf::Sprite(*texture);
    this->bg = bg;

    std::string s;
    this->font.loadFromFile("arial.ttf");
    sf::Text text(s, font, 15);
}

void DrawManager::draw() {
    window->clear();
    window->draw(*this->bg);
    window->draw(*this->text);
    window->display();
}

void DrawManager::destroy(){
    window->close();
}

DrawManager::~DrawManager(){
    free(this->window);
    free(this->bg);
    free(this->text);
}

void DrawManager::SetText(std::string s){
    if(this->text != NULL) {
        free(this->text);
    }
    this->text = new sf::Text(s, this->font, 15);
    sf::FloatRect textBounds = this->text->getGlobalBounds();
    if(textBounds.height > 600) {
        this->text->setPosition(0, 600 - textBounds.height);
    }
    text->setFillColor(sf::Color::Green);
}
