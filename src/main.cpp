#include <SFML/Graphics.hpp>

#include "Game.h"

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 800

void managerInputs(Player &p1, Player &p2) {
    // Player 1
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        p1.setVelocity(p1.velocity().x, -1);
    }
    
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        p1.setVelocity(-1, p1.velocity().y);
    }
    
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        p1.setVelocity(1, p1.velocity().y);
    }
    
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        p1.setVelocity(p1.velocity().x, 1);
    }
    
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        p1.boost();
    } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) == false) {
        p1.chargeBoost();
    }
    
    
    // Player 2
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        p2.setVelocity(p2.velocity().x, -1);
    }
    
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        p2.setVelocity(-1, p2.velocity().y);
    }
    
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        p2.setVelocity(1, p2.velocity().y);
    }
    
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        p2.setVelocity(p2.velocity().x, 1);
    }
    
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) {
        p2.boost();
    } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) == false) {
        p2.chargeBoost();
    }
}


int main (int argc, const char * argv[])
{
    sf::RenderWindow window(sf::VideoMode::getFullscreenModes()[0], "UltraPong", sf::Style::Fullscreen);
    window.setFramerateLimit(60);
    
    window.setMouseCursorVisible(false);
    
    Game game(window);
    
    game.loadResources();
    
    Randomizer rd;
    
    Player p, p2;
    
    p.setFillColor(sf::Color(255,0,0));
    p.setPosition(rd.frandom(SCREEN_WIDTH, 0.0f), rd.frandom(SCREEN_HEIGHT, 0.0f));
    
    p2.setFillColor(sf::Color(0,0,255));
    p2.setPosition(rd.frandom(SCREEN_WIDTH, 0.0f), rd.frandom(SCREEN_HEIGHT, 0.0f));
    
    sf::Clock clock;
    
    sf::RectangleShape shapePlayBtn1, shapePlayBtn2;
    shapePlayBtn1.setSize(sf::Vector2f(0,100));
    shapePlayBtn2.setSize(sf::Vector2f(0,100));
    
    shapePlayBtn1.setPosition(100, window.getSize().y - 200);
    shapePlayBtn2.setPosition(100, window.getSize().y - 500);
    
    shapePlayBtn1.setFillColor(sf::Color(255,0,0,155));
    shapePlayBtn2.setFillColor(sf::Color(0,255,0,155));
    
    sf::RectangleShape shapeQuitButton;
    shapeQuitButton.setSize(sf::Vector2f(0,100));
    shapeQuitButton.setFillColor(sf::Color(0,0,255, 155));
    
    shapeQuitButton.setPosition(window.getSize().x - 100, window.getSize().y - 350);
    
    sf::Clock clockIntro;
    
    p.setVelocity(rd.frandom(1.0f, -1.0f), rd.frandom(1.0f, -1.0f));
    p2.setVelocity(rd.frandom(1.0f, -1.0f), rd.frandom(1.0f, -1.0f));
    
    sf::Font font;
    font.loadFromFile("arial.ttf");
  
    sf::Text title;
    title.setFont(font);
    title.setString("!!!ULTRA PONG!!!");
    
    title.setCharacterSize(90);
    title.setPosition(100, 50);
    
  sf::Text singlePlayer;
  singlePlayer.setFont(font);
  singlePlayer.setString("1 Player");
  
  sf::Text multiplayer;
  multiplayer.setFont(font);
  multiplayer.setString("2 Players");
  
  singlePlayer.setPosition(shapePlayBtn1.getPosition().x + 150, shapePlayBtn1.getPosition().y + 25);
  multiplayer.setPosition(shapePlayBtn2.getPosition().x + 150, shapePlayBtn2.getPosition().y + 25);
  
  sf::Text quit;
  quit.setFont(font);
  quit.setString("Quit");
  
  quit.setPosition(shapeQuitButton.getPosition().x - 300, shapeQuitButton.getPosition().y + 25);
  
    Player cursor;
    cursor.setSpring(0.75f);
    cursor.setFillColor(sf::Color(255,255,255));
    
    while(window.isOpen()) {
        sf::Event event;
        
        while(window.pollEvent(event)) {
            switch(event.type) {
                case sf::Event::KeyPressed:
                default:
                    break;
            }
        }
        
        cursor.setPosition(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
        
        if(clockIntro.getElapsedTime().asSeconds() <= 2) {
            if(shapePlayBtn1.getSize().x < 500)
                shapePlayBtn1.setSize(sf::Vector2f(shapePlayBtn1.getSize().x + 10, shapePlayBtn1.getSize().y));
            
            if(shapeQuitButton.getSize().x < 500) {
                shapeQuitButton.setSize(sf::Vector2f(shapeQuitButton.getSize().x + 10, shapeQuitButton.getSize().y));
                shapeQuitButton.setPosition(shapeQuitButton.getPosition().x - 10, shapeQuitButton.getPosition().y);
            }
            
            if(shapePlayBtn2.getSize().x < 500) {
                shapePlayBtn2.setSize(sf::Vector2f(shapePlayBtn2.getSize().x + 10, shapePlayBtn2.getSize().y));
            }
            
        } else {
            if(shapePlayBtn1.getSize().x != 500) {
                shapePlayBtn1.setSize(sf::Vector2f(500,100));
            }
        }
        
        if(clock.getElapsedTime().asSeconds() > 2) {
            p.setVelocity(rd.frandom(1.0f, -1.0f), rd.frandom(1.0f, -1.0f));
            p2.setVelocity(rd.frandom(1.0f, -1.0f), rd.frandom(1.0f, -1.0f));
            clock.restart();
        }
        
        if(p.position().y < -100) {
            p.setPosition(p.position().x, window.getSize().y);
            p.setQueue(p.position().x, p.position().y);
        } else if(p.position().y > window.getSize().y + 100) {
            p.setPosition(p.position().x, -100);
            p.setQueue(p.position().x, p.position().y);
        }
        
        if(p.position().x < -100) {
            p.setPosition(window.getSize().x, p.position().y);
            p.setQueue(p.position().x, p.position().y);
        } else if(p.position().x > window.getSize().x + 100) {
            p.setPosition(-100, p.position().y);
            p.setQueue(p.position().x, p.position().y);
        }
        
        if(p2.position().y < -100) {
            p2.setPosition(p2.position().x, window.getSize().y + 100);
            p2.setQueue(p2.position().x, p2.position().y);
        } else if(p.position().y > window.getSize().y + 100) {
            p2.setPosition(p.position().x, -100);
            p2.setQueue(p2.position().x, p2.position().y);
        }
        
        if(p2.position().x < -100) {
            p2.setPosition(window.getSize().x + 100, p2.position().y);
            p2.setQueue(p2.position().x, p2.position().y);
        } else if(p2.position().x > window.getSize().x + 100) {
            p2.setPosition(-100, p2.position().y);
            p2.setQueue(p2.position().x, p2.position().y);
        }
        
        
        p.updatePosition();
        p2.updatePosition();
        
        if(shapePlayBtn1.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)
           && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            game.initMatch();
            
            game.setNBPlayer(1);
            
            if(game.run()) {
                game.exit();
            }
        }
        
        if(shapeQuitButton.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)
           && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            game.exit();
        }
        
        
        if(shapePlayBtn2.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)
           && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            game.initMatch();
            
            game.setNBPlayer(2);
            
            if(game.run()) {
                game.exit();
            }
        }
        
        cursor.updatePosition();
 
        
        window.clear();
        
        p.render(window);
        
        p2.render(window);
        
        window.draw(shapePlayBtn1);
        window.draw(shapePlayBtn2);
        window.draw(shapeQuitButton);
        
        window.draw(title);
      
        window.draw(singlePlayer);
        window.draw(multiplayer);
      
				window.draw(quit);
        
        cursor.render(window);
        window.display();
        

        
    }
    
    return EXIT_SUCCESS;
}
