#include "Shoption.h"

ShoptionCharge::ShoptionCharge() {
	int r = rand() % 100;
	if (r < 10) {
		charge = fact.GenerateCharge(RAREC);
		cost = rand() % 12 + 130;
	}
	else if (r < 20) {
		charge = fact.GenerateCharge(UNCOMMONC);
		cost = rand() % 12 + 80;
	}
	else {
		charge = fact.GenerateCharge(COMMONC);
		cost = rand() % 12 + 50;

	}
	font.loadFromFile("arial.ttf");
	costText.setFont(font);
	costText.setString(to_string(cost));
	costText.setCharacterSize(18);
	icon = &charge->icon;

}

ShoptionCharge::~ShoptionCharge() {

}


void ShoptionCharge::Draw(RenderWindow* w) {
	charge->DrawUnder(w);
	w->draw(costText);
}

void ShoptionCharge::DrawOver(RenderWindow* w) {

	charge->DrawOver(w);
}

Charge* ShoptionCharge::getCharge() {
	return charge;
}

void ShoptionCharge::SetPosition(int x, int y) {
	charge->icon.setPosition(x, y);
	costText.setPosition(charge->icon.getPosition() + Vector2f(20, 200));
}

void ShoptionCharge::Update(Time t) {
	vector<Artefact*> a;
	charge->Update(t, a);
}