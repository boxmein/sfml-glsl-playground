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
	int width = WIDTH, height = HEIGHT; 
	bool fullscreen = false, paused = false; 
	// we can add more rendering extras here if necessary
	sf::RenderStates states; 
	// time is of essence
	sf::Clock clock; 
	// This output file will be used throughout the program for errors.
	ofstream outfile; 
	outfile.open("stdout.txt", std::ofstream::out);
	outfile << "=== Started. ===" << endl 
			<< "SFML should output more into standard output if an error occurs!" << endl;
	
	//
	// Initialize the window
	//
    sf::RenderWindow window(sf::VideoMode(width, height, sf::VideoMode::getDesktopMode().bitsPerPixel), "SFML works!");
	window.setVerticalSyncEnabled(true);
	// 60 is a decent limit
	window.setFramerateLimit(60);

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
	while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            switch (event.type) {
			case sf::Event::Closed:
				window.close(); 
				break;
			case sf::Event::Resized:
				width = event.size.width; 
				height = event.size.height;
				break;
			case sf::Event::KeyPressed:
				if (event.key.code == sf::Keyboard::F11) {
					if (fullscreen) {
						window.create(sf::VideoMode(width = WIDTH, height = HEIGHT), "SFML works!");
						fullscreen = false;
						outfile << "-- Releasing from fullscreen, setting new width: " << width << "; height: " 
							    << height << endl << "   Fullscreen is now false!" << endl;
					}
					else {
						// get all the possible fullscreen video modes, ordered best to worst
						std::vector<sf::VideoMode> fsmodes = sf::VideoMode::getFullscreenModes();
						// take the best
						width = fsmodes[0].width;
						height = fsmodes[0].height; 
						outfile << "-- Creating fullscreen window with width: " << width << "; height: " << height
							    << endl << "   Fullscreen is now true!" << endl;
						sf::VideoMode ournew(width, height, fsmodes[0].bitsPerPixel);
						window.create(ournew, "SFML works!", sf::Style::Fullscreen);
						fullscreen = true;
					}
				}
				// Escape key exits fullscreen
				else if (event.key.code == sf::Keyboard::Escape)
				{
					if (fullscreen) {
						window.create(sf::VideoMode(width = WIDTH, height = HEIGHT), "SFML works!");
						fullscreen = false;
						outfile << "-- Releasing from fullscreen, setting new width: " << width << "; height: " 
							    << height << endl << "   Fullscreen is now false!" << endl;
					}
				}
				// Space key pauses
				else if (event.key.code == sf::Keyboard::Space)
				{
					paused = !paused;
				}
				break;
			}
		}
		
		// expose variables to GLSL
		if (!paused) {
			
		shader.setParameter("texture", sf::Shader::CurrentTexture);
		shader.setParameter("mouse", sf::Vector2f(sf::Mouse::getPosition(window).x, 
									 sf::Mouse::getPosition(window).y));
		shader.setParameter("time", clock.getElapsedTime().asSeconds()); 
		shader.setParameter("resolution", sf::Vector2f(width, height));


        window.clear();
		window.draw(triangles, states); 
		}
        window.display();
    }
	// post-running stuff
	outfile.flush();
	outfile.close();
    return 0;
}

