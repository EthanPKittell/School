#include "FibLFSR.h"

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

void transform( sf::Image& image, FibLFSR* seed);

// display an encrypted copy of the picture, using the LFSR
// to do the encryption
int main(int argc, char* argv[])
{
	string inputFileName;
	string outputFileName;
	string seedValue;
	if (argc == 4)
	{
	inputFileName = argv[1];
	outputFileName = argv[2];
	seedValue = argv[3];
	cout << inputFileName << endl;
	cout << outputFileName << endl;
	cout << seedValue << endl;
	}
	else 
	{
		cout << "incorrect number of inputs" << endl;
	}

	sf::Image image;
	FibLFSR seed(seedValue);
	if (!image.loadFromFile(inputFileName)){
		return -1;
	}

	transform(image, &seed);

	sf::Vector2u size = image.getSize();
	sf::RenderWindow window(sf::VideoMode(size.x, size.y), outputFileName);

	sf::Texture texture;
	texture.loadFromImage(image);

	sf::Sprite sprite;
	sprite.setTexture(texture);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear(sf::Color::White);
		window.draw(sprite);
		window.display();
	}

	// fredm: saving a PNG segfaults for me, though it does properly
	//   write the file
	if (!image.saveToFile(outputFileName)){
		return -1;
	}

	return 0;
}



// transforms image using FibLFSR
void transform( sf::Image& image, FibLFSR* seed)
{


// p is a pixelimage.getPixel(x, y);
	sf::Color p;

	sf::Vector2u size = image.getSize();
	// create photographic negative image of upper-left 200 px square
	for (int x = 0; x< (int)size.x; x++) {
		for (int y = 0; y< (int)size.y; y++) {
			p = image.getPixel(x, y);
			p.r = p.r ^ seed->generate(8);
			p.g = p.g ^ seed->generate(8);
			p.b = p.b ^ seed->generate(8);
			image.setPixel(x, y, p);
		}
	}

}
