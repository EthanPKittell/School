#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <math.h>
#include <iomanip>
using namespace std;


//must be drawable
class CelestialBody : public sf::Drawable
{
public:

CelestialBody(double xposInput, double yposInput,double xvelInput,double yvelInput,double massInput,string planetFileNameInput);

void changeXvel(double newXvel);

void changeYvel(double newYvel);

void changeXpos(double newXpos);

void changeYpos(double newYpos);

double getXvel();

double getYvel();

double getXpos();

double getYpos();

double getMass();

void changePosition(double newXpos, double newYpos);

string getPlanetFileName();

//This function just confirms the data going into the object
void print();

sf::Sprite returnSprite();



private:

virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    
    sf::Sprite m_sprite;
    sf::Texture m_texture;
    sf::VertexArray m_vertices;

    double xpos;
    double ypos;
    double xvel;
    double yvel;
    double mass;
    string planetFileName;
};


