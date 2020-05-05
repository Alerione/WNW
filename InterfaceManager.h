#ifndef _INTERFACE_MANAGER_H_
#define _INTERFACE_MANAGER_H_

#ifndef _INTERFACE_ELEMENT_H_
#include "InterfaceElement.h"
#endif /* _INTERFACE_ELEMENT_H_ */

#ifndef _VECTOR_
#include <vector>
#endif /* _VECTOR_ */
#include <SFML/Graphics.hpp>

#include "ResourceManager.h"

class InterfaceElement;
class InterfaceManager
{
public:
    InterfaceManager(float, float);
    void buildInterface(double);
    void drawInterface(sf::RenderWindow&);
    void updateInterace(sf::Vector2f, std::vector <Building*>&, TileMap&, int&);
    void clickedUpdateInterface(sf::Vector2f, InterfaceManager&);
	void getResources(ResourceList* list);
	void updateResources();

    static void button1action(InterfaceManager&);
    static void button1action_button1(InterfaceManager&);
    static void button1action_button2(InterfaceManager&);
    static void cat1Building1(InterfaceManager&);
    static void cat1Building2(InterfaceManager&);
    static void cat1Building3(InterfaceManager&);
    static void cat1Building4(InterfaceManager&);
    static void cat2Building1(InterfaceManager&);
    static void cat2Building2(InterfaceManager&);
    static void infoBarAction(InterfaceManager&, Building*);

    void setResourceInterfaceValue(int, std::string&);

	friend class InterfaceElement;

    ~InterfaceManager();

protected:
	InterfaceManager();
	std::vector<sf::Text> interfacePrev;
    TileMap *tileMap;
    std::vector <Building*> *buildings;
	int *bcounter;
	ResourceList *Resources;

    static float SCR_HEIGHT;
    static float SCR_WIDTH;
    static float interfaceHeight;
    std::vector<InterfaceElement> interfaceVec;
    std::vector<InterfaceElement> interfacePopVec;
    std::vector<InterfaceElement> interfacePop2Vec;
    std::vector<InterfaceElement> interfaceIcons;
    std::vector<InterfaceElement> infoBar;
    std::vector<sf::Text> infoBarTexts;
    sf::Font font;
    std::vector<sf::Text> interfaceTexts;
    
    bool button1actionStatus;
    bool button1action_button1Status;
    bool button1action_button2Status;
    bool infoBarShowed;
	Building* InfobarGrab;
    
};

#endif /* _INTERFACE_MANAGER_H_ */
