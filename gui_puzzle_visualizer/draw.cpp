using namespace std;
#include <vector>
#include "picture.h"
#include "answer.h"

void draw(vector<vector<DynamicTexture> > &tex, answer &ans, picture &pic, vector<int> &rotate) {
    const int PSIZE = 64;
	const int ax = 20, ay = 20;
	for (int y = 0; y < pic.div_y; y++) {
		for (int x = 0; x < pic.div_x; x++) {
			tex[y][x].resized(PSIZE).rotated(90_deg * ans.rotate[y * pic.div_y + x]).draw(x * PSIZE + ax, y * PSIZE + ay);
		}
	}
}
