#ifndef _INTERFACE_MANAGER_H_
#define _INTERFACE_MANAGER_H_

#ifndef _INTERFACE_ELEMENT_H_
#include "InterfaceElement.h"
#endif /* _INTERFACE_ELEMENT_H_ */

#ifndef _VECTOR_
#include <vector>
#endif /* _VECTOR_ */
#include <SFML/Graphics.hpp>

#ifndef __WNW_TextureManagerClass_
#include "TextureManager.h"
#endif /* __WNW_TextureManagerClass_ */

#include "TavernBuilding.h"
#include "WellBuilding.h"
#include "StablesBuilding.h"

class InterfaceElement;
class InterfaceManager
{
public:
    InterfaceManager();
    InterfaceManager(float, float);
    void buildInterface(double);
    void drawInterface(sf::RenderWindow&);
    void updateInterace(sf::Vector2f, std::vector <Building*>&, TileMap&, int&);
    void clickedUpdateInterface(sf::Vector2f, InterfaceManager&);

    static void button1action(InterfaceManager&);
    static void button1action_button1(InterfaceManager&);
    static void cat1Building1(InterfaceManager&);
    static void cat1Building2(InterfaceManager&);
    static void cat1Building3(InterfaceManager&);

	friend class InterfaceElement;

    ~InterfaceManager();

protected:

    TextureManager interfaceTextureManager;
    TileMap *tileMap;
    std::vector <Building*> *buildings;
	int *bcounter;

    static float SCR_HEIGHT;
    static float SCR_WIDTH;
    static float interfaceHeight;
    std::vector<InterfaceElement> interfaceVec;
    std::vector<InterfaceElement> interfacePopVec;
    std::vector<InterfaceElement> interfacePop2Vec;
    
    bool button1actionStatus;
    bool button1action_button1Status;

    
};

#endif /* _INTERFACE_MANAGER_H_ */
