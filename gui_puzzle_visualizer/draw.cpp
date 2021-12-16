﻿using namespace std;
#include <vector>
#include "picture.h"
#include "answer.h"

void draw(vector<vector<DynamicTexture> > &tex, picture &pic, vector<int> &rotate) {
    const int PSIZE = 680 / pic.div_y;
	const int ax = 20, ay = 20;
	for (int y = 0; y < pic.div_y; y++) {
		for (int x = 0; x < pic.div_x; x++) {
			tex[y][x].resized(PSIZE).rotated(90_deg * rotate[y * pic.div_x + x]).draw(x * PSIZE + ax, y * PSIZE + ay);
		}
	}
}
