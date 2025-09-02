#include <SFML/Graphics.hpp>
using namespace sf;
#include <iostream>
using namespace std;

class Object
{
    public:
        Vector2f pos = Vector2f(100,100);
        Vector2f scale = Vector2f(1,1);
        float speed = 100.0f;
        void spawn(Sprite &asset, RenderWindow &window)
        {
            //asset.setPosition(pos);
            asset.setScale(scale);
           
            window.draw(asset);
        }
        void update(Sprite &obj, Time &tickrate)
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
                obj.move({-speed*tickrate.asSeconds(), 0.0f});
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
                obj.move({speed*tickrate.asSeconds(), 0.0f});
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
                obj.move({0.f, -speed*tickrate.asSeconds()});
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
                obj.move({0.f, speed*tickrate.asSeconds()});
            
        }

};

class Game
{
    public:
        void start()
        {
            
            //assets
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

};

int main()
{
    Game game;
    game.start();
}
