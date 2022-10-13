
#include "play.h"
#include "Menu.h"
#include "WindowPlay.h"

int main()
{
	//Tao khung window hien thi menu
	RenderWindow window(VideoMode(650, 504), "MENU");
	//Background menu
	Texture m1;
	m1.loadFromFile("C:\\Users\\DatNgu\\Desktop\\OOP_BTL\\images\\m1.png");
	Sprite M1(m1);
	Menu menu(650,504);
	//Bat su kien tu ban phim or chuot
	while (window.isOpen())
	{
		
		Event event;

		while (window.pollEvent(event))
		{
			
			switch (event.type)
			{
			case Event::KeyReleased:
				switch (event.key.code)
				{
				case Keyboard::Up:
					menu.MoveUp();
					break;

				case Keyboard::Down:
					menu.MoveDown();
					break;
				case Keyboard::Escape:{
					window.close();
					break;
				}
				case Keyboard::Return:
					switch (menu.GetPressedItem())
					{
					case 0:{		
						WindowPlay();
						break;
					} 
					case 1:{
						
						Font font;
						if (!font.loadFromFile("C:\\Users\\DatNgu\\Desktop\\chess\\font\\rockston.ttf"))
						{
						}
						Text c,c1;
						c.setFont(font);c1.setFont(font);
						c.setString("Dang phat trien");c1.setString("<-Back");
						c.setFillColor(Color::White);c1.setFillColor(Color::Red);
						c.setPosition(290,150);c1.setPosition(700,400);
						window.clear();
						window.draw(M1);
						window.draw(c);		
						window.draw(c1);						
						window.display();
						while(window.isOpen()){
							Event event1;
							while(window.pollEvent(event1)){
								if (event1.type == Event::Closed)
						                window.close();
								if(event1.type == Event::KeyPressed){
									if (event1.key.code == Keyboard::Return)
									{
										window.clear();
										window.draw(M1);
										menu.draw(window);
										window.display();
										
									}
								}
							}
						}
						
						
						break;
					}
					case 2:
						window.close();
						break;
					}
				}

				break;
			case sf::Event::Closed:
				window.close();

				break;

			}
		}

		window.clear();
		window.draw(M1);
		menu.draw(window);
		window.display();
	}
}
