#include <SFML/Graphics.hpp>
#include <fstream>
using std::ofstream;
using std::endl;
#include "Main.h"


//
// Defines the entry point for the application. Cross-platform support is ensured via sfml-main.lib
//
int main()
{
	// we can add more rendering extras here if necessary
	sf::RenderStates states; 
	// time is of essence
	sf::Clock clock; 
	// This output file will be used throughout the program for errors.
	ofstream outfile; 
	outfile.open("stdout.txt", std::ofstream::out);
	outfile << "=== Started. ===" << endl 
			<< "More info about errors is in stdout (SFML output)" << endl;
	
	//
	// Initialize the window
	//
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "SFML works!");
	window.setVerticalSyncEnabled(true);

	//
	// Set up a TrianglesStrip as a background vertex
	// 
	//         1-0
	//         |\|
	//         3-2
	//
	sf::VertexArray triangles(sf::TrianglesStrip, 4); 
	triangles[0].position = sf::Vector2f(WIDTH, 0); 
	triangles[1].position = sf::Vector2f(0, 0); 
	triangles[2].position = sf::Vector2f(WIDTH, HEIGHT);
	triangles[3].position = sf::Vector2f(0, HEIGHT); 

		
	if (!sf::Shader::isAvailable()) {
		// shaders are unavailable due to the graphics card not supporting it/etc

		outfile << "!! GLSL Shaders are unavailable. Exiting" << endl;
		return 1;
	}
	sf::Shader shader;
	
	if (!shader.loadFromFile("shaders/shader.vert", "shaders/shader.frag")) {
		// shaders weren't found / malformed syntax / every other imaginable reason

		outfile << "!! Couldn't load one of the two shaders, exiting " << endl <<
			"  1. shaders/shader.vert - Vertex shader" << endl <<
			"  2. shaders/shader.frag - Fragment shader" << endl <<
			"  -- Check everything - if the file exists, syntax errors, everything!" << endl;
		return 1;
	}
	states.shader = &shader;

	// Main loop
	while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
		}
		
		// expose variables to GLSL
		shader.setParameter("texture", sf::Shader::CurrentTexture);
		shader.setParameter("mouse", sf::Vector2f(sf::Mouse::getPosition(window).x, 
									 sf::Mouse::getPosition(window).y));
		shader.setParameter("time", clock.getElapsedTime().asSeconds()); 
		shader.setParameter("resolution", sf::Vector2f(WIDTH, HEIGHT));


        window.clear();
		window.draw(triangles, states); 
        window.display();
    }
	// post-running stuff
	outfile.flush();
	outfile.close();
    return 0;
}
