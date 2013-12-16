#ifndef CLASSES
#define CLASSES
class Image
{

public:

	sf::Image image1;       //An image file to load from
	sf::Sprite sprite;      //A sprite to draw on screen

	int x;  //Coordinates that can be used to check position and collisions
	int y;
	int x2;
	int y2;

	int speed;      //An int that determines how fast sprites should move

	void Move(float x, float y) {
		sprite.move(x,y);
	}
};



// PlayerShip class derives from Image and adds the canShoot variable.

class PlayerShip: public Image
{

public:

	bool canShoot;  //this variable helps control the rate at which the player shoots.
	//It becomes true when a certain time after the last shot has elapsed.

	PlayerShip()
	{
		image1.loadFromFile("nave.png");
		//sprite.setOrigin(image1);
		sprite.setPosition(350,475);
		x = 350;
		y = 475;
		speed = 6;
		canShoot = true;        //At the beginning of the game the player is ready to shoot.
	}

	void Move(float a, float b)
	{
		sprite.move(a,b);
		x += a;
		y += b;
	}

}player;



// This class contains data that concerns all bullets in the game.

class BulletData
{
public:

	int nextBullet; // Holds the number for the next available bullet.

	BulletData()
	{
		nextBullet = 0;
	}

	void Next(int totalBullets)     //This function selects the next available bullet.
	{
		if (nextBullet < totalBullets) nextBullet += 1;
		if (nextBullet == totalBullets) nextBullet = 0; // If the total has been
		// reached, go back to the
		// first bullet.
	}
}bData;



// The main application class. It handles all "global" variables and functions.

class App
{
public:

	sf::RenderWindow window;
	sf::Event event;
	sf::Clock bulletClock;

	int totalBullets;

	App()
	{
		totalBullets = 7;
	}



	// The following function checks if 0.1 seconds have passed since the last
	// shot was fired.

	void CheckBulletClock()
	{
		//if (bulletClock.getElapsedTime() > 0.1)	{
			bData.Next(totalBullets);
			player.canShoot = true;
			bulletClock.restart();
		//}
	}

}app;



class Bullet: public Image
{

public:

	bool exists;

	Bullet()
	{
		image1.loadFromFile("bala1.png");
		//sprite.setImage(image1);
		exists = false;
	}

	void Shoot()
	{
		exists = true;
		sprite.setPosition((player.x + 20),(player.y + 5));
		y = (player.y + 5);

		player.canShoot = false;

		app.bulletClock.restart();
	}

	void Move(float a, float b)
	{
		sprite.move(a,b);
		y += b;

		if (y < (player.y - 480)) //This part of the function destroys the bullet when
			// it reaches a certain point.
		{
			exists = false;
		}
	}

}bullet[7];

#endif