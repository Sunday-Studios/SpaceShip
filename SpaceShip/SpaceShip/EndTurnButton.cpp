#include "Button.h"

EndTurnButton::EndTurnButton() {
	buttTex.loadFromFile("endTurn.png");
	icon.setTexture(buttTex);
	icon.setPosition(700, 700);
}

EndTurnButton::~EndTurnButton() {

}

void EndTurnButton::OnClick(Combat* combat) {
	combat->AdvanceTurn();
}