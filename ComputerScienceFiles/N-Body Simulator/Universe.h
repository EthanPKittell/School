#include "CelestialBody.h"

class Universe
{
public:


void setRadius(double radius)
{
    universeRadius = radius;
}

//helper functions for fixing x and y pos

double fixXpos(double xposVar)
{
    return xposVar * ((universeRadius * 2.0) / windowSizeX);
    
}
double fixYpos(double yposVar)
{
    return  yposVar * ((universeRadius * 2.0) / windowSizeY);
}



void printPlanetValues()
{

cout << celestialBodyVector.size() << endl;
cout << universeRadius << endl;
for (int i = 0; i < (int)celestialBodyVector.size(); i++)
{
  cout << left << setw(14) << fixXpos(celestialBodyVector[i].getXpos()) << " ";
  cout << left << setw(14) << fixYpos(celestialBodyVector[i].getYpos()) << " ";
  cout << left << setw(14) << celestialBodyVector[i].getXvel() << " ";
  cout << left << setw(14) << celestialBodyVector[i].getXvel() << " ";
  cout << left << setw(14) << celestialBodyVector[i].getMass() << " ";
  cout << left << setw(14) << celestialBodyVector[i].getPlanetFileName() << " " << endl;
  
}


}





friend istream& operator>>(istream& in, Universe& universe){


  double xpos;
  double ypos;
  double xvel;
  double yvel;
  double mass;
  string planetFileName;

    in >> xpos;
    in >> ypos;
    in >> xvel;
    in >> yvel;
    in >> mass;
    in >> planetFileName;


       
    xpos = (xpos * (universe.windowSizeX)) / (universe.universeRadius * (double)2);
    ypos = (ypos * (universe.windowSizeY)) / (universe.universeRadius * (double)2);

      
      CelestialBody *planet = new CelestialBody(xpos,ypos,-xvel,-yvel,mass,planetFileName);
      
      universe.celestialBodyVector.push_back(*planet);
      
  
      

return in;

}


void step(double delta)
{
double r;
double Force;
const double G = 6.67e-11;
double Xforce;
double Yforce;
double Xacceleration;
double Yacceleration;


for (int i = 0; i < (int)celestialBodyVector.size(); i++)
{


  //for comparing the netforce of all the celestial bodies
  for (int n = 0; n < (int)celestialBodyVector.size(); n++)
  {
    if (i != n)
    {    
    //change in position for both compare planets
    double deltaX = fixXpos(celestialBodyVector[n].getXpos()) - fixXpos(celestialBodyVector[i].getXpos());
    double deltaY = fixYpos(celestialBodyVector[n].getYpos()) - fixYpos(celestialBodyVector[i].getYpos());

      r = sqrt((pow(deltaX, 2)) + (pow(deltaY, 2)));

    //These set the forces on the object by all other objects

      Force = (G * celestialBodyVector[i].getMass() * celestialBodyVector[n].getMass())/ pow(r,2);

      Xforce += Force * (deltaX / r);

      Yforce += Force * (deltaY / r);

    }
  }

    //This calculates the acceleration
      Xacceleration = Xforce / celestialBodyVector[i].getMass();
      Yacceleration = Yforce / celestialBodyVector[i].getMass();
      //apply all forces here

      //changes the x and y velocity
      celestialBodyVector[i].changeXvel(celestialBodyVector[i].getXvel() + Xacceleration * delta);
      celestialBodyVector[i].changeYvel(celestialBodyVector[i].getYvel() + Yacceleration * delta);

      //calculates the new x and y position in the universe
      celestialBodyVector[i].changeXpos(fixXpos(celestialBodyVector[i].getXpos()) + celestialBodyVector[i].getXvel() * delta);
      celestialBodyVector[i].changeYpos(fixYpos(celestialBodyVector[i].getYpos()) + celestialBodyVector[i].getYvel() * delta);


      //fixes the xpos and ypos to fit the screen
      celestialBodyVector[i].changeXpos((celestialBodyVector[i].getXpos() * windowSizeX) / (universeRadius * (double)2));
      celestialBodyVector[i].changeYpos((celestialBodyVector[i].getYpos() * windowSizeY) / (universeRadius * (double)2));

      

      celestialBodyVector[i].changePosition(celestialBodyVector[i].getXpos(),celestialBodyVector[i].getYpos());


      Xforce = 0;
      Yforce = 0;
      Force = 0;
}


}




double getRadius(){
    return universeRadius;
}

double universeRadius;

 vector<CelestialBody> celestialBodyVector;

 double windowSizeX;
 double windowSizeY;

};


