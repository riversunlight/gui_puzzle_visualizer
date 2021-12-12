#pragma once

// 画像全体のデータ
struct picture {
	int div_x;
	int div_y;
	int select_lim;
	int select_cost;
	int swap_cost;
	int size_x;
	int size_y;
	int color_max;
	vector<vector<vector<unsigned char> > > pix;
};
