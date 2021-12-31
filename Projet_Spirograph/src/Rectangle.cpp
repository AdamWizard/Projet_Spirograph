#include "Rectangle.h"

Rectangle::Rectangle(float x, float y, float width, float height)
{
        this->rectangle = new sf::RectangleShape();
        rectangle->setSize(sf::Vector2f(width,height));
        rectangle->setOrigin(width/2, height/2);
        rectangle->setOutlineThickness(1);
        rectangle->setFillColor(sf::Color::Transparent);
        rectangle->setOutlineColor(sf::Color::White);
        rectangle->setPosition(width/2, height/2);
}

Rectangle::~Rectangle()
{

}


float Rectangle::getX() const{
    return getRectangle()->getPosition().x;
}

float Rectangle::getY() const{
    return getRectangle()->getPosition().y;
}

sf::RectangleShape* Rectangle::getRectangle() const{
    return rectangle;
}

void Rectangle::setPosition(float newX, float newY){
    rectangle->setPosition(newX,newY) ;
}
