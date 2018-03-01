
//
// Disclaimer:
// ----------
//
// This code will work only if you selected window, graphics and audio.
//
// Note that the "Run Script" build phase will copy the required frameworks
// or dylibs to your application bundle so you can execute it on any OS X
// computer.
//
// Your resource files (images, sounds, fonts, ...) are also copied to your
// application bundle. To get the path to these resources, use the helper
// function `resourcePath()` from ResourcePath.hpp
//

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

// Here is a small helper for you! Have a look.
#include "ResourcePath.hpp"
#include <unistd.h>
#include <iostream>
using namespace std;
using namespace sf;
int main(int, char const**)
{
    //Creating the window           Width | Height
    RenderWindow window(sf::VideoMode(800, 600), "Window");
    
    //Load the sprites texture from file
    Texture texture;
    if (!texture.loadFromFile(resourcePath() + "icon.png")) {
        return EXIT_FAILURE;
    }
    //Create the sprite and set the texture
    Sprite sprite(texture);
    
    //While window is open
    while (window.isOpen())
    {
 
        Event event;
        //Check for keypress/mousemove/ect
        while (window.pollEvent(event))
        {
            //On escape key press close the window.
            if (event.type == Event::Closed)
            {
                window.close();
            }
            //Move sprite in right direction
            if (event.type == Event::KeyPressed && event.key.code == Keyboard::Right) 
            {
                cout << "Right";
                Vector2f pos = sprite.getPosition();
                sprite.setPosition(pos.x+5, pos.y);
            }
            //Move sprite in left direction
            if (event.type == Event::KeyPressed && event.key.code == Keyboard::Left)
            {
                cout << "Left";
                Vector2f pos = sprite.getPosition();
                sprite.setPosition(pos.x-5, pos.y);
            }
            //Move sprite in upwards direction
            if (event.type == Event::KeyPressed && event.key.code == Keyboard::Up)
            {
                cout << "Up";
                Vector2f pos = sprite.getPosition();
                sprite.setPosition(pos.x, pos.y-5);
            }
            //Move sprite in downwards direction
            if (event.type == Event::KeyPressed && event.key.code == Keyboard::Down)
            {
                cout << "Down";
                Vector2f pos = sprite.getPosition();
                sprite.setPosition(pos.x, pos.y+5);
            }
            
            
        }

        window.clear(Color::White);
        window.draw(sprite);
        window.display();
        
        //sleep(milliseconds(10));
    }
    
    return 0;
}


//int main(int, char const**)
//{
//
//
//    // Create the main window
//    sf::RenderWindow window(sf::VideoMode(800, 600), "Window");
//
//    sf::Clock clock1;
//    usleep(1000000);
//    std::cout << (clock1.getElapsedTime().asSeconds());
//
//    // Set the Icon
//    sf::Image icon;
//    if (!icon.loadFromFile(resourcePath() + "icon.png")) {
//        return EXIT_FAILURE;
//    }
//    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
//
//    // Load a sprite to display
//    sf::Texture texture;
//    if (!texture.loadFromFile(resourcePath() + "cute_image.jpg")) {
//        return EXIT_FAILURE;
//    }
//    sf::Sprite sprite(texture);
//
//    // Create a graphical text to display
//    sf::Font font;
//    if (!font.loadFromFile(resourcePath() + "sansation.ttf")) {
//        return EXIT_FAILURE;
//    }
//    sf::Text text("Hello SFML", font, 50);
//    text.setFillColor(sf::Color::Black);
//
//    // Load a music to play
//    sf::Music music;
//    if (!music.openFromFile(resourcePath() + "nice_music.ogg")) {
//        return EXIT_FAILURE;
//    }
//
//    // Play the music
//    music.play();
//
//    // Start the game loop
//    while (window.isOpen())
//    {
//        // Process events
//        sf::Event event;
//        while (window.pollEvent(event))
//        {
//            // Close window: exit
//            if (event.type == sf::Event::Closed) {
//                window.close();
//            }
//
//            // Escape pressed: exit
//            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
//                window.close();
//            }
//        }
//
//        // Clear screen
//        window.clear();
//
//        // Draw the sprite
//        window.draw(sprite);
//
//        // Draw the string
//        window.draw(text);
//
//        // Update the window
//        window.display();
//    }
//
//    return EXIT_SUCCESS;
//}

