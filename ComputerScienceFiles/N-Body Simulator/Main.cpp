#include "Universe.h"


int main(int argc, char *argv[])
{
  string fileName;
  int rows;
  double universeRadius;
  string planetFileName;
  Universe universe;
  double totalTime;
  double deltaTime;

  totalTime = atof(argv[1]);
  deltaTime = atof(argv[2]);

    //sees how many of planet stats are being initialized
  cin >> rows;
  cin >> universeRadius;

  universe.universeRadius = universeRadius;

  sf::RenderWindow window(sf::VideoMode(600,600), "sfml window");
  sf::View view2(sf::Vector2f(0.f, 0.f), sf::Vector2f(600, 600));
 
 universe.windowSizeX = window.getSize().x;
 universe.windowSizeY = window.getSize().y;

  for(int i = 0; i < rows; i++)
  {


  cin >> universe;

  }

   
   while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed)
                window.close();
        }
      window.setView(view2);
        //clears the window to update the sprite
      
      
          while(totalTime > 0){

            window.clear();

            universe.step(deltaTime);

            //universe.celestialBodyVector[i].print();
            for (int i = 0; i < rows;i++){

              window.draw(universe.celestialBodyVector[i]);
                

            }
            
            totalTime = totalTime - deltaTime;
            window.display();
            universe.printPlanetValues();
          }
    }
    
   
 
    return 0;
    
}
