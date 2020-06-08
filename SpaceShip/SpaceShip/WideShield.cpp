#include "Charge.h"

WideShield::WideShield() {
	chargeTex.loadFromFile("Textures/charges/wideShield.png");
	icon.setTexture(chargeTex);
	icon.setScale(1, 1);

	damage = 7;
	cost = 2;
	effectTime = 500000;
}

WideShield::~WideShield() {

}

void WideShield::Fire(Gun* g, vector<vector<Tile*>> grid, vector<Gun*> guns) {
	int row = g->row;
	//shield above
	if (row > 0) {
		guns[row - 1]->shield->Boost(damage);
	}
	//targetted gun
	g->shield->Boost(damage);
	//shield below
	if (row < 4) {
		guns[row + 1]->shield->Boost(damage);
	}
}