using namespace std;
#include <vector>
#include <utility>
#include "picture.h"
#include "answer.h"
#include "utility_gpv.h"


// 最終的にどこに来るか
vector<int> change_rotate(answer &ans, picture &pic) {
	int sel_x, sel_y, next_x, next_y;
	vector<int> final_place(pic.div_y * pic.div_x);
	vector<int> res(pic.div_x * pic.div_y);
	for (int i = 0; i < pic.div_x * pic.div_y; i++)
			final_place[i] = i;

	for (int i = 0; i < ans.sel_place.size(); i++) {
	    sel_x = ans.sel_place[i].first;
	    sel_y = ans.sel_place[i].second;
		for (int j = 0; j < ans.move_operate[i].size(); j++) {
			next_place(next_x, next_y, sel_x, sel_y, ans.move_operate[i][j], pic);
			swap(final_place[sel_y * pic.div_x + sel_x], final_place[next_y * pic.div_x + next_x]);
			sel_x = next_x;
			sel_y = next_y;
		}
	}

	for (int i = 0; i < pic.div_x * pic.div_y; i++)
		res[final_place[i]] = ans.rotate[i];
	return res;
}
