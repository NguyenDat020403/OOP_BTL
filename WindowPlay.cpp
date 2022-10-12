#include "WindowPlay.h"

void WindowPlay(){

//Dong cua so Menu tao ra cua so moi - Cua so "Play"
	RenderWindow window(VideoMode(650, 504), "The Chess!");
	Texture t1,t2,t3,t4;
	t1.loadFromFile("images/figures.png"); // quan co
	t2.loadFromFile("images/board.png"); // ban co
	t3.loadFromFile("images/a1.png"); // background
	
	t4.loadFromFile("images/back2.png");				    
	SoundBuffer moveself;// Am thanh cua moi nuoc di
	moveself.loadFromFile("move-self.wav");
	Sound sfx;
	sfx.setBuffer(moveself);
						
	for(int i=0;i<32;i++) f[i].setTexture(t1);
	Sprite sBoard(t2); 
	Sprite sBoard1(t3),back(t4);
	
	back.setPosition(550,430);
	loadPosition();
						
	bool isMove=false;
	float dx=0, dy=0;
	Vector2f oldPos,newPos;
	string str;
	int n=0; 
	// Bat su kien ban phim va chuot
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
		window.draw(sBoard1);
		window.draw(sBoard); /// ve ban co 
		window.draw(back);
		for(int i=0;i<32;i++) f[i].move(offset);// 
		for(int i=0;i<32;i++) window.draw(f[i]); window.draw(f[n]);
		for(int i=0;i<32;i++) f[i].move(-offset);
		window.display();
	}
}
