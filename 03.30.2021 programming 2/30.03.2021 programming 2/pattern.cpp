#include "pattern.h"
#include "card.h"


pattern::pattern(int sx, element el) : sx(sx), el(el) {}

void pattern::paint(card& c) const {	// "draws" a line pattern in the card table 
	if (c.size() <= 0 || sx < 0)
		return;
	for (int i = 0; i < c.size(); i++) {
		c(sx, i) = el;
	}
}