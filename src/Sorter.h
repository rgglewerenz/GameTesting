#pragma once
#include "Platform/Platform.hpp"
#include <vector>
using namespace sf;
using namespace std;
class Sorter
{
public:
	void initItems(int amt_items, int speed, float maxWidth, float maxHeight);
	void UpdateSort();
	void DrawItems(RenderWindow& window);
	bool getOver()
	{
		return over;
	}
	~Sorter()
	{
		free(arr);
		free(arr_sorted);
		items.clear();
	}

private:
	void Randomize();
	void Swap(int index1, int index2);
	int* arr;
	int* arr_sorted;
	unsigned int index = 0;
	bool sorted = false;
	bool over = false;
	int speed_;
	float maxH_;
	float maxW_;
	int tick = 0;
	RectangleShape onItem;
	vector<RectangleShape> items;
};