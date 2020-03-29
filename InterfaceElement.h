#ifndef _INTERFACE_ELEMENT_H_
#define _INTERFACE_ELEMENT_H_

#include <iostream>
#include <SFML/Graphics.hpp>


class InterfaceElement
{
public:
    InterfaceElement();
    InterfaceElement(float, float, float, float, sf::Color, bool);

    void draw(sf::RenderTarget&);
    void update(sf::Vector2f mouse);
    ~InterfaceElement();
protected:
    sf::RectangleShape _shape;
    sf::Color _color;
    bool _clickable;
};

#endif /* _INTERFACE_ELEMENT_H_ */

