using namespace std;
#include <vector>
#include "picture.h"
#include "answer.h"
#include "current_cost.h"

void draw(vector<vector<DynamicTexture> > &tex, picture &pic, vector<int> &rotate, Current_cost &ccost) {
    const static int PSIZE = 680 / pic.div_y;
	const static int ax = 20, ay = 20; // 余白
	const static Font font(30);

	// 画面表示
	for (int y = 0; y < pic.div_y; y++) {
		for (int x = 0; x < pic.div_x; x++) {
			tex[y][x].resized(PSIZE).rotated(90_deg * rotate[y * pic.div_x + x]).draw(x * PSIZE + ax, y * PSIZE + ay);
		}
	}

	// 設定、現在コストの表示
	font(
		U"画面サイズ      :", pic.div_x, U"x", pic.div_y, U"\n",
		U"選択コストレート:", pic.select_cost, U"\n",
		U"交換コストレート:", pic.swap_cost,U"\n"
	).draw(720, 0);
	font(
		U"選択コスト:", ccost.select_cost, U"/", ccost.max_sel_cost, U"\n",
		U"交換コスト:", ccost.swap_cost, U"/", ccost.max_swap_cost, U"\n"
	).draw(720, 130);
}
