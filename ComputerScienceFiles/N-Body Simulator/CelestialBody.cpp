#include "Universe.h"

sf::Sprite CelestialBody::returnSprite()
{
    return m_sprite;
}

CelestialBody::CelestialBody(double xposInput, double yposInput,double xvelInput,double yvelInput,double massInput,string planetFileNameInput)
{
    xpos = xposInput;
    ypos = yposInput;
    xvel = xvelInput;
    yvel = yvelInput;
    mass = massInput;
    planetFileName = planetFileNameInput;
    
    
    m_texture.loadFromFile(planetFileName);
    m_sprite.setTexture(m_texture);
    
    
m_sprite.setPosition(xpos,ypos);
    
   
}


void CelestialBody::draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        // You can draw other high-level objects
        target.draw(m_sprite, states);
        
        
    }



void CelestialBody::print()
{
    cout << xpos << endl;
    cout << ypos << endl;
    cout << xvel << endl;
    cout << yvel << endl;
    cout << mass << endl;
    cout << planetFileName << endl;
    
}


void CelestialBody::changeXvel(double newXvel)
{
    xvel = newXvel;
}

void CelestialBody::changeYvel(double newYvel)
{
    yvel = newYvel;
}


double CelestialBody::getXvel(){
    return xvel;
}

double CelestialBody::getYvel(){
    return yvel;
}

double CelestialBody::getXpos(){
    return xpos; //(xpos * (universe.windowSizeX)) / (universe.universeRadius * (double)2)
}

double CelestialBody::getYpos(){
    return ypos;
}

double CelestialBody::getMass(){
    return mass;
}

string CelestialBody::getPlanetFileName()
{
    return planetFileName;
}

void CelestialBody::changeXpos(double newXpos)
{
    xpos = newXpos;
}

void CelestialBody::changeYpos(double newYpos)
{
    ypos = newYpos;
}

void CelestialBody::changePosition(double newXpos, double newYpos)
{
    m_sprite.setPosition(newXpos,newYpos);
}
