#include "Sorter.h"
void Sorter::initItems(int amt_items, int speed, float maxW, float maxH)
{
	//This is the const for the speed of the sorting algo
	speed_ = speed;

	//allocates the right amt of memory to the arr
	arr = (int*)malloc(amt_items * sizeof(int));
	arr_sorted = (int*)malloc(amt_items * sizeof(int));

	maxW_ = maxW;
	maxH_ = maxH;

	float width = maxW_ / amt_items;
	float height = maxH_ / amt_items;
	//Initlizes the items in the vector
	for (int i = 0; i < amt_items; i++)
	{
		//Adds the new y value to the arr obj
		arr[i] = i;
		arr_sorted[i] = i;
		//Sets the size of the rectangles
		RectangleShape temp;
		Vector2f vec_size;
		vec_size.x = width;
		vec_size.y = i * height;

		//Sets the Pos of the rectangles
		Vector2f vec_pos;
		vec_pos.x = i * width;
		vec_pos.y = (((amt_items) * (maxH / amt_items)) - vec_size.y);

		//Sets the RectangleShape to the Items added
		temp.setPosition(vec_pos);
		temp.setSize(vec_size);
		temp.setFillColor(Color::White);

		items.push_back(temp);
	}
	Randomize();
}

//Used to draw the rectagles to the screen
void Sorter::DrawItems(RenderWindow& window)
{
	int amt_items = items.size();

	RectangleShape onIndex;
	Vector2f size_vec;
	Vector2f pos_vec;

	size_vec.y = maxH_;
	pos_vec.y = (((amt_items) * (maxH_ / amt_items)) - size_vec.y);

	size_vec.x = items[0].getSize().x;
	onIndex.setSize(size_vec);
	onIndex.setFillColor(Color::Red);

	unsigned int index_ = 0;
	for (RectangleShape a : items)
	{
		//cout << a.getSize().y << endl;
		if (arr_sorted[index_] == arr[index_])
		{
			a.setFillColor(Color::Green);
		}

		window.draw(a);
		if (index == index_)
		{
			pos_vec.x = a.getPosition().x;
			onIndex.setPosition(pos_vec);
			if (!over)
				window.draw(onIndex);
		}
		index_++;
	}
}

//Used to randomize the list
void Sorter::Randomize()
{
	srand(1);
	for (unsigned int i = 0; i < items.size(); i++)
	{
		Swap(rand() % items.size(), rand() % items.size());
	}
}

//Used to swap elements of the list
void Sorter::Swap(int pos1, int pos2)
{
	if (pos1 == pos2)
	{
		return;
	}

	//Temp var for swaping
	int tempint = arr[pos1];
	RectangleShape temprect(items[pos1]);

	//Creates 2 temp vec postions
	Vector2f newpos1(items[pos1].getPosition());
	Vector2f newpos2(items[pos2].getPosition());

	//Swaps the ints
	arr[pos1] = arr[pos2];
	arr[pos2] = tempint;

	//Swaps the Rectangles
	items[pos1] = items[pos2];
	items[pos2] = temprect;

	//Swaps their positions
	newpos2.x = newpos1.x;
	newpos1.x = items[pos1].getPosition().x;
	items[pos1].setPosition(newpos2);
	items[pos2].setPosition(newpos1);
}

void Sorter::UpdateSort()
{
	if (tick % speed_ != 0)
	{
		tick++;
		return;
	}

	if (index >= items.size() - 1)
	{
		index = 0;
		if (sorted == true)
			sorted = false;
		else
			over = true;
	}

	if (items[index].getSize().y > items[index + 1].getSize().y)
	{
		Swap(index, index + 1);
		sorted = true;
	}

	index++;
	tick++;
}