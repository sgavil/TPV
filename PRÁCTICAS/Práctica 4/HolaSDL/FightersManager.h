#pragma once
#include "GameObject.h"
#include "Observer.h"
#include "CircularMotionPhysics.h"
#include "AcelerationInputComponent.h"
#include "ImageRenderer.h"
#include "RotationInputComponent.h"
#include "GunInputComponent.h"
#include "BadgeRenderer.h"
#include "BasicMotionPhysics.h"
#include <vector>


class FightersManager : public GameObject,public Observer
{
	enum badges
	{
		FasterBulletsBadge,SuperBulletBadge,MultiBulletsBadge
	};
public:
	
	FightersManager(SDLGame* game, Observer* bulletsMamager);
	virtual ~FightersManager();
	virtual void handleInput(Uint32 time, const SDL_Event& event);
	virtual void update(Uint32 time);
	virtual void render(Uint32 time);
	Fighter* getFighter();
	virtual void receive(Message* msg);
private:
	Fighter fighter_;
	CircularMotionPhysics circulrMotoionComp_;
	AcelerationInputComponent accelerationComp_;
	ImageRenderer renderComp_;
	RotationInputComponent rotationComp_;
	GunInputComponent gunComp1_;
	GunInputComponent gunComp2_;

	std::vector<BadgeRenderer>badges_;
	/*BadgeRenderer superBulletsRenderer_;
	BadgeRenderer badgeRenderer_;
	BadgeRenderer multiBulletsBadge_;*/
	BasicMotionPhysics basicMotionComp_;

	void initializeBadges();
};

