using namespace std;
#include <vector>
#include "picture.h"

void next_place(int& next_x, int& next_y, int& sel_x, int& sel_y, char& s, picture& pic) {
	switch (s) {
	case 'R':
		next_x = (sel_x + 1 + pic.div_x) % pic.div_x;
		next_y = sel_y;
		break;
	case 'L':
		next_x = (sel_x - 1 + pic.div_x) % pic.div_x;
		next_y = sel_y;
		break;
	case 'U':
		next_x = sel_x;
		next_y = (sel_y - 1 + pic.div_y) % pic.div_y;
		break;
	case 'D':
		next_x = sel_x;
		next_y = (sel_y + 1 + pic.div_y) % pic.div_y;
		break;
	}
}
