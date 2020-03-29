#include "InterfaceElement.h"



InterfaceElement::InterfaceElement()
{
}

InterfaceElement::InterfaceElement(float xpos_, float ypos_, float xsize_, float ysize_, sf::Color color_, bool clickable_)
{
    _clickable = clickable_;
    _shape.setSize(sf::Vector2f(xsize_, ysize_));
    _shape.setPosition(sf::Vector2f(xpos_, ypos_));
    _shape.setFillColor(color_);
}

void InterfaceElement::draw(sf::RenderTarget& target_)
{
    target_.draw(_shape);
}

void InterfaceElement::update(sf::Vector2f mouse_)
{
    if (this->_clickable == true)
    {
        if (_shape.getGlobalBounds().contains(mouse_))
        {
            std::cout << "interface najechany" << std::endl;
        }
    }

}

InterfaceElement::~InterfaceElement()
{
}
