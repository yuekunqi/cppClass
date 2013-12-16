#include <iostream>
#include "SFML/Graphics.hpp"
#include "nave_v2.h"
int main()
{

	app.window.create(sf::VideoMode(800,600,32),"Window");
	app.window.setFramerateLimit(60);
	void ProcessInput();
	void EndProgram();
	void DrawBullet(int numOfBullets);
	void MoveBullet(int numOfBullets);
	while (app.window.isOpen())	{
		app.window.clear();			//Clear the screen
		app.window.draw(player.sprite);		//Draw the player
		DrawBullet(app.totalBullets);		//Draw the existing bullets
		app.window.display();			//Display the sprites
		ProcessInput();				//Process the user's input
		MoveBullet(app.totalBullets);		//Move the existing bullets
		if (player.canShoot == false) app.CheckBulletClock(); //The player cannot shoot at any given time. There should
		EndProgram();		//Check if the user wishes to exit (it's separated from ProcessInput 
	}
	return 0;
}
void ProcessInput()
{
	/*if (app.window.getInput().IsKeyDown(sf::Key::Left)) player.Move(-6,0);
	if (app.window.getInput().IsKeyDown(sf::Key::Right)) player.Move(6,0);
	if (app.window.getInput().IsKeyDown(sf::Key::Space))
	{
		if (!bullet[bData.nextBullet].exists) bullet[bData.nextBullet].Shoot();
	}*/
}



//EndProgram awaits for the user to produce an event. If that event is clicking on the X button
//or pressing alt-f4 (sf::Event::Closed) the window closes.

void EndProgram()
{
	while(app.window.pollEvent(app.event))
	{
		if (app.event.type == sf::Event::Closed)
			app.window.close();
	}
}



//DrawBullet simply draws all existing bullet in the screen. It receives the total number of
//bullets and cycles through them to check if they exist at the time.

void DrawBullet(int numOfBullets)
{
	for (int i = 0; i < numOfBullets; i++)
	{
		if (bullet[i].exists) app.window.draw(bullet[i].sprite);
	}
}



//Same concept as before, but this functions moves the bullets up the screen.

void MoveBullet(int numOfBullets)
{
	for (int i = 0; i < numOfBullets; i++)
	{
		if (bullet[i].exists) bullet[i].Move(0,-10);
	}
}