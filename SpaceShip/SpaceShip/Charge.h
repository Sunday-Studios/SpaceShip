#pragma once
#include <SFML/Graphics.hpp>
#include "Gun.h"
#include "Tile.h"
#include <iostream>
class Gun;
using namespace sf;
using namespace std;


class Charge 
{
public:
	Charge();
	virtual ~Charge() = default;
	virtual void Fire(Gun* g,vector<vector<Tile*>> grid,vector<Gun*> guns) { cout << "base" << endl; }
	virtual void Update(Time t);
	virtual void StartTimer(Time t) {};
	virtual void Draw(RenderWindow* w);
	int getCost() { return cost; };
	static Charge* Create() { return new Charge(); };
	Sprite icon;
	Sprite chargeEffect;
	int handPos = 0;
	Vector2f restPos;
protected:
	int cost =0;
	float damage;
	int width;
	Texture chargeTex;
	Texture chargeEffTex;
	float timer;
	float effectTime = 0;
	bool bEffectVisible = false;
};


class BasicCharge : public Charge {
public:
	BasicCharge();
	~BasicCharge();
	static Charge* Create() { return new BasicCharge(); };
	void Fire(Gun* g, vector<vector<Tile*>> grid, vector<Gun*> guns);

};

class BasicShield : public Charge {
public:
	BasicShield();
	~BasicShield();
	static Charge* Create() { return new BasicShield(); };
	void Fire(Gun* g, vector<vector<Tile*>> grid, vector<Gun*> guns);

};

class EasyBomb : public Charge {
public:
	EasyBomb();
	~EasyBomb();
	static Charge* Create() { return new EasyBomb(); };
	void Fire(Gun* g, vector<vector<Tile*>> grid, vector<Gun*> guns);
};

class WideShield : public Charge {
public:
	WideShield();
	~WideShield();
	static Charge* Create() { return new WideShield(); };
	void Fire(Gun* g, vector<vector<Tile*>> grid, vector<Gun*> guns);
};