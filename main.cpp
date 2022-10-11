
#include "play.h"
#include "Menu.h"


int main()
{
	RenderWindow window(sf::VideoMode(852, 480), "SFML WORK!");
	Texture h1;
	h1.loadFromFile("C:\\Users\\DatNgu\\Desktop\\menu dhinh\\images\\WallPaper.jpg");
	Sprite H1(h1);
	Menu menu(window.getSize().x, window.getSize().y);

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
				case Keyboard::Return:
					switch (menu.GetPressedItem())
					{
					case 0:{
						
							window.close();
							RenderWindow window(VideoMode(800, 504), "The Chess! (press SPACE)");
						    Texture t1,t2;
						    t1.loadFromFile("images/figures.png"); 
						    t2.loadFromFile("images/board.png");
							sf::SoundBuffer moveself;
							moveself.loadFromFile("move-self.wav");
							sf::Sound sfx;
							sfx.setBuffer(moveself);
						
						    for(int i=0;i<32;i++) f[i].setTexture(t1);
						    Sprite sBoard(t2); 
						
						    loadPosition();
						
						    bool isMove=false;
						    float dx=0, dy=0;
						    Vector2f oldPos,newPos;
						    string str;
						    int n=0; 
						
						    while (window.isOpen())
						    {
						        Vector2i pos = Mouse::getPosition(window) - Vector2i(offset);
						
						        Event event;
						        while (window.pollEvent(event))
						        {
						            if (event.type == Event::Closed)
						                window.close();
						            /////keo tha//////
						            if (event.type == Event::MouseButtonPressed){
						            	if (event.mouseButton.button == Mouse::Left)
						                  for(int i=0;i<32;i++)
						                  if (f[i].getGlobalBounds().contains(pos.x,pos.y))
						                      {
						                       isMove=true; n=i;
						                       dx=pos.x - f[i].getPosition().x;
						                       dy=pos.y - f[i].getPosition().y;
						                       oldPos  =  f[i].getPosition();
						                      }
									}
						                
						
						             if (event.type == Event::MouseButtonReleased)
						               {
						               	if (event.mouseButton.button == Mouse::Left)
						                 {
						                  isMove=false;
						                  Vector2f p = f[n].getPosition() + Vector2f(size/2,size/2);
						                  
						                  newPos = Vector2f( size*int(p.x/size), size*int(p.y/size) );
						                  
						                  str = toChessNote(oldPos)+toChessNote(newPos);
						                  
						                  move(str); 
						                  
						                  if (oldPos!=newPos) position+=str+" ";
						                  
						                  f[n].setPosition(newPos);         
										  sfx.play();        
						                 }                      
										} 
						        }  
						    if (isMove) f[n].setPosition(pos.x-dx,pos.y-dy);
						
						    ////// draw  ///////
						    window.clear(); // xoa mnan hinh
						    window.draw(sBoard); /// ve ban co 
						    for(int i=0;i<32;i++) f[i].move(offset);// 
						    for(int i=0;i<32;i++) window.draw(f[i]); window.draw(f[n]);
						    for(int i=0;i<32;i++) f[i].move(-offset);
						    window.display();
						    }
						break;
					} 
					case 1:{
						
						Font font;
						if (!font.loadFromFile("C:\\Users\\DatNgu\\Desktop\\chess\\font\\rockston.ttf"))
						{
							// handle error
						}
						Text c,c1;
						c.setFont(font);c1.setFont(font);
						c.setString("Dang phat trien");c1.setString("<-Back");
						c.setFillColor(Color::White);c1.setFillColor(Color::Red);
						c.setPosition(290,150);c1.setPosition(700,400);
						while(window.isOpen()){
							Event event;
							while(window.pollEvent(event)){
								if (event.type == Event::Closed)
						                window.close();
								if(event.type == Event::KeyPressed){
									if (event.key.code == Keyboard::Return)
									{
										window.clear();
										window.draw(H1);
										window.draw(c);		
										window.draw(c1);						
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
		window.draw(H1);
		menu.draw(window);

		window.display();
	}
}
