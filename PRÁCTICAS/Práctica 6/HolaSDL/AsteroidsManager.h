#pragma once
#include "GameObject.h"
#include "Observable.h"
#include "Observer.h"
#include "ImageRenderer.h"
#include "CircularMotionPhysics.h"
#include"DeActivateOnBorderExit.h"
#include "RotationPhysics.h"
#include "OManager.h"
#include "BasicMotionPhysics.h"
#include "Asteroid.h"
#include "GameManager.h"

const double ROTATION_ANGLE = 5;
class AsteroidsManager : public GameObject, public Observer, public Observable, public OManager<Asteroid>
{
	const int ASTEROIDS_NUM = 5;
public:
	AsteroidsManager(SDLGame* game, GameManager* gm);
	virtual ~AsteroidsManager();
	virtual void handleInput(Uint32 time, const SDL_Event& event) {}; //No hace nada
	virtual void update(Uint32 time);
	virtual void render(Uint32 time);
	virtual vector<Asteroid*>& getAsteroids() { return objs_; };
	virtual void receive(Message* msg);
private:
	void initializeObject(Asteroid* o);
	Asteroid* getAsteroid();
	void initAsteroids();

	GameManager* gm_;
	ImageRenderer asteroidImage_;
	DeActivateOnBorderExit deactiveOnExitBordersPhysics_;
	RotationPhysics rotationPhysics_;
	BasicMotionPhysics posPhysics_;
	int numOfasteroids_;
	void addAsteroid();
	void disableAsteroids();
	Vector2D getRandomVelocity();

	Uint32 timePassed;
	Uint32 timeInterval;
};

