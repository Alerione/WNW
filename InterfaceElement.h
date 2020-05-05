#ifndef _INTERFACE_ELEMENT_H_
#define _INTERFACE_ELEMENT_H_

#include "InterfaceManager.h"
#include <iostream>
#include <SFML/Graphics.hpp>

class InterfaceManager;
class InterfaceElement
{
public:
    InterfaceElement();
    InterfaceElement(float, float, float, float, sf::Color, bool);

    void draw(sf::RenderTarget&);
    void update(sf::Vector2f);
    bool clickedUpdate(sf::Vector2f, InterfaceManager&);
    void setTexture(sf::Texture*);

    void setAction(void(*newaction)(InterfaceManager&));

    ~InterfaceElement();

    friend class InterfaceManager;
protected:
    sf::RectangleShape _shape;
    sf::Color _color;
    bool _clickable;
    void (*action)(InterfaceManager&);
};

#endif /* _INTERFACE_ELEMENT_H_ */

