#pragma once
#include <SFML/Graphics.hpp>
#include "Charge.h"
#include "ChargeFactory.h"
#include <vector>
using namespace sf;
using namespace std;
class RewardScreen
{
public: 
	RewardScreen(RenderWindow* w,Player* p, bool bBoss);
	~RewardScreen();
	void Draw();
	void MouseDown(Vector2f m);
	void MouseUp(Vector2f m);
	void MoveMouse(Vector2f m);
	PICK_STATE CheckState();
private:
	int optCount = 3;
	Player* player;
	PICK_STATE phase = PICKING;
	RenderWindow* window;
	vector<Charge*> options;
	ChargeFactory fact;
	Sprite space;
	Texture spaceTex;
	Sprite prompt;
	Texture promptTex;
	Sprite skip;
	Texture skipTex;
};

