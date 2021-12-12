//データの読み込み
using namespace std;
#include <vector>
#include <string>
#include <iostream>
#include <utility>
#include "picture.h"
#include "answer.h"

// 16進数を10進数に変更(1桁)
int h2d(char num) {
	if (num >= '0' && num <= '9')
		return num - '0';
	return num - 'A' + 10;
}

void input_data(picture &pic, answer &ans, vector<vector<DynamicTexture> > &tex) {
	FILE* fp;
	errno_t err;
	int tmp, line, piece_size, piece_num;

	/*ppmファイル読み込み*/
	err = fopen_s(&fp, "problem.ppm", "rb");
	if (err != 0) assert(0);
	char magic_number[10];
	fscanf_s(fp, "%s\n", magic_number, 10);
	if (strcmp(magic_number, "P6") != 0) {
		fclose(fp);
		assert(0);
	}
	fscanf_s(fp, "# %d %d\n", &pic.div_x, &pic.div_y);
	fscanf_s(fp, "# %d\n", &pic.select_lim);
	fscanf_s(fp, "# %d %d\n", &pic.select_cost, &pic.swap_cost);
	fscanf_s(fp, "%d %d\n", &pic.size_x, &pic.size_y);

	fread(&tmp, 4, 1, fp);
	pic.pix = vector<vector<vector<unsigned char>>>(pic.size_y, vector<vector<unsigned char>>(pic.size_x, vector<unsigned char>(3)));

	for (int i = 0; i < pic.size_y; i++) {
		for (int j = 0; j < pic.size_x; j++) {
			for (int k = 0; k < 3; k++) {
				fread(&pic.pix[i][j][k], 1, 1, fp);
			}
		}
	}

	fclose(fp);

	/*解答ファイル読み込み*/
	err = fopen_s(&fp, "submit.txt", "r");
	if (err != 0) assert(0);
	char buf[1000000];
	fscanf_s(fp, "%s\n", buf, 256);
	ans.rotate.resize(pic.div_x * pic.div_y);
	for (int i = 0; i < pic.div_x * pic.div_y; i++)
		ans.rotate[i] = buf[i] - '0';

	fscanf_s(fp, "%d\n", &line);
	ans.sel_place.resize(line);
	ans.move_operate.resize(line);
	for (int i = 0; i < line; i++) {
		int move;
		fscanf_s(fp, "%s\n", buf, 256);
		ans.sel_place[i].first = h2d(buf[0]);
		ans.sel_place[i].second = h2d(buf[1]);
		fscanf_s(fp, "%d\n", &move);
		fscanf_s(fp, "%s\n", buf, 1000000);
		for (int j = 0; j < move; j++)
			ans.move_operate[i] += buf[j];
	}
	fclose(fp);

	/*断片画像データの格納*/
	tex.resize(pic.div_y);
	for (int i = 0; i < pic.div_y; i++)
		tex[i].resize(pic.div_x);

	piece_num = pic.div_x * pic.div_y;
	piece_size = pic.size_x / pic.div_x;
	for (int i = 0; i < pic.div_y; i++) {
		for (int j = 0; j < pic.div_x; j++) {
			Image pieceimg(piece_size, piece_size, Palette::White);
			int origin_x = j * piece_size;
			int origin_y = i * piece_size;
			for (int y = 0; y < piece_size; y++) {
				for (int x = 0; x < piece_size; x++) {
					pieceimg[y][x] = Color(pic.pix[origin_y + y][origin_x + x][0], pic.pix[origin_y + y][origin_x + x][1], pic.pix[origin_y + y][origin_x + x][2]);
				}
			}
			tex[i][j] = DynamicTexture(pieceimg);
		}
	}
}
