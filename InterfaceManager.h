#ifndef _INTERFACE_MANAGER_H_
#define _INTERFACE_MANAGER_H_

#ifndef _INTERFACE_ELEMENT_H_
#include "InterfaceElement.h"
#endif /* _INTERFACE_ELEMENT_H_ */

#ifndef _VECTOR_
#include <vector>
#endif /* _VECTOR_ */
#include <SFML/Graphics.hpp>

class InterfaceElement;
class InterfaceManager
{
public:
    InterfaceManager();
    InterfaceManager(float, float);
    void buildInterface(double);
    void drawInterface(sf::RenderWindow&);
    void updateInterace(sf::Vector2f);
    void clickedUpdateInterface(sf::Vector2f);

    static void action1();

	friend class InterfaceElement;

    ~InterfaceManager();
protected:
    float SCR_HEIGHT;
    float SCR_WIDTH;
    std::vector<InterfaceElement> interfaceVec;
    bool action1Status;
};

#endif /* _INTERFACE_MANAGER_H_ */
