#include <iostream>
#include "headers/DrawWindow.h"
#include "SFML/Graphics.hpp"
#include "headers/Menu.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(600, 600), "Welcome to the fabulous world of Spirographs");
	Menu menu(window.getSize().x, window.getSize().y);
    DrawWindow draw;

	while (window.isOpen())
	{
		sf::Event event;

		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::KeyReleased:
				switch (event.key.code)
				{
				case sf::Keyboard::Up:
					menu.MoveUp();
					break;

				case sf::Keyboard::Down:
					menu.MoveDown();
					break;

				case sf::Keyboard::Return:
					switch (menu.GetPressedItem())
					{
					case 0:
						draw.mainWindow();
						break;
					case 1:
						std::cout << "Option button has been pressed" << std::endl;
						break;
					case 2:
						window.close();
						break;
					}
					break;
				}
				break;
			case sf::Event::Closed:
				window.close();
				break;
			}
		}

		window.clear();

		menu.draw(window);
		window.display();
	}
}

/*#include <SFML/Graphics.hpp>

int main(){
    sf::RenderWindow window(sf::VideoMode(800,600),"Window",
    sf::Style::Titlebar | sf::Style::Close);
    sf::Font arial;
    arial.loadFromFile("resources/arial.ttf");
    sf::Text t;
    t.setFillColor(sf::Color::White);
    t.setFont(arial);
    std::string s = "This is text that you type: ";
    t.setString(s);

    while(window.isOpen()){
        sf::Event event;

        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                window.close();
            }
            if (event.type == sf::Event::TextEntered){
                if (event.text.unicode < 128){
                    s += static_cast<char>(event.text.unicode);
                } else {
                    // Time to consider sf::String or some other unicode-capable string
            }
}
        }
        t.setString(s);
        window.clear(sf::Color::Black);
        window.draw(t);
        window.display();
    }
}*/
