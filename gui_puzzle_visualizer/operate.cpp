using namespace std;
#include <vector>
#include <utility>
#include "picture.h"
#include "answer.h"
#include "utility_gpv.h"

int swap_operate(answer &ans, picture &pic, vector<vector<DynamicTexture> > &tex, vector<int> &rotate) {
	static int sel_x = -1, sel_y = -1, line = 0, move = -1;
	int next_x, next_y;
	
	if (sel_x == -1) {
		sel_x = ans.sel_place[0].first;
		sel_y = ans.sel_place[0].second;
	}
	move++;
	if (move == ans.move_operate[line].size()) {
		line++;
		if (line == ans.sel_place.size())
			return 1;
		move = 0;
		sel_x = ans.sel_place[line].first;
		sel_y = ans.sel_place[line].second;
		
	}
	next_place(next_x, next_y, sel_x, sel_y, ans.move_operate[line][move], pic);
	swap(tex[sel_y][sel_x], tex[next_y][next_x]);
	swap(rotate[sel_y * pic.div_x + sel_x], rotate[next_y * pic.div_x + next_x]);
	sel_x = next_x;
	sel_y = next_y;
	return 0;
}
