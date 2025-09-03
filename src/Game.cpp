#include <SFML/Graphics.hpp>
#include "gameobjects.hpp"
#include <iostream>
#include "game.hpp"
using namespace std;
using namespace sf;


void Game::start() 
{
    // Assets
    Texture playerTex;
            if(!playerTex.loadFromFile("assets/konata.jpeg"))
            {
                cout<< "Texture could not be loaded" << endl;
            }
            playerTex.setSmooth(true);
            Sprite player(playerTex);
            Sprite ground(playerTex);
            ground.setPosition(Vector2f(100,500));
            
            //creates objects
            Object Player;//player object
            Player.pos = Vector2f(100,100);
            Player.scale = Vector2f(0.1f,0.1f);



            // create the window
            RenderWindow window(VideoMode({800, 600}), "My window");
            Clock clock;
            Time timeSinceLastUpdate = Time::Zero;
            Time TIME_PER_FRAME = seconds( 1.0f / 60.0f );

            // run the program as long as the window is open
            while (window.isOpen())
            {
                // check all the window's events that were triggered since the last iteration of the loop
                while (const std::optional event = window.pollEvent())
                {
                    // "close requested" event: we close the window
                    if (event->is<Event::Closed>())
                        window.close();
                }
                timeSinceLastUpdate += clock.restart();
                while (timeSinceLastUpdate > TIME_PER_FRAME)
                {
                    timeSinceLastUpdate -= TIME_PER_FRAME;
                    if(player.getGlobalBounds().findIntersection(ground.getGlobalBounds()))
                    {
                        cout<< "Collision!"<< endl;
                    }
                    Player.update(player,TIME_PER_FRAME);
                
                }

                // clear the window with black color
                window.clear(Color::Black);

                // draw everything here...
                Player.spawn(player,window);
                window.draw(ground);
                // window.draw(...);
                

                // end the current frame
                window.display();
            }
}
