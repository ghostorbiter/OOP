#include "history.h"

history::history(const card& c) {	// right at the beginning we enter the current picture in the history (index 0)
	h[0] = c;
	num = 1;
}

void history::write(const card& c)
{
	if (this->num == n)
	{
		for (int i = 0; i < n - 1; i++)
		{
			this->h[i] = h[i + 1];
		}
		this->num--;
	}

	this->h[this->num] = c;
	this->num++;
}

card history::undo()
{
	if (num == 1) {
		return h[0];
	}
	num--;
	return h[num-1];
}
// if we only have 1 card in the history (num == 1), we return it
// otherwise we return one before last
// (there is always at least 1 picture left in the history)