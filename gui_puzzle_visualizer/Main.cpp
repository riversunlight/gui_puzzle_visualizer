/*
* 第32回高専プロコン競技部門
* 操作実行GUI
* Input.txtの操作をproblem.ppmで動かす
*/
using namespace std;
#include <Siv3D.hpp> // OpenSiv3D v0.6.3
#include <vector>
#include <string>
#include <utility>
#include "picture.h"
#include "answer.h"
#include "current_cost.h"
#include "input_data.h"
#include "draw.h"
#include "operate.h"
#include "change_rotate.h"

void Main()
{
	Window::Resize(Size(1280, 720));

	picture pic;
	answer ans;
	Current_cost ccost;
	vector<vector<DynamicTexture> > tex;
	vector<int> rotate;
	int ex = 1;
	input_data(pic, ans, tex, ccost);
	rotate = change_rotate(ans, pic);
	while (System::Update()) {
		if (ex) {
			if (swap_operate(ans, pic, tex, rotate, ccost))
				ex = 0;
		}
		draw(tex, pic, rotate, ccost);
		if (KeyEscape.down())
			System::Exit();
	}
}
