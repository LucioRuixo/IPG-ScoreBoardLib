#ifndef SCORE_BOARD_LIB_H
#define SCORE_BOARD_LIB_H
#include <list>
using namespace std;

class ScoreBoard
{
	bool isSortedMax2Min;
	list<float> *scores;
	list<float>::iterator iterator;

public:
	ScoreBoard();
	~ScoreBoard();
	void insert(float score);
	void erase(unsigned int position);
	void eraseFirst();
	void eraseLast();
	void eraseHighest();
	void eraseLowest();
	void extract(unsigned int position, float &score);
	void extractFirst(float &score);
	void extractLast(float &score);
	void extractHighest(float &score);
	void extractLowest(float &score);
	void sortMax2Min();
	void sortMin2Max();
	void fillArray(float array[], int arraySize);
	void fillArray(float array[], int arraySize, bool sortMax2Min);
	void clear();
	int getSize();
	float get(unsigned int position);
	float getFirst();
	float getLast();
	float getHighest();
	float getLowest();
	bool sortedMax2Min();
	bool empty();
	list<float> getStdList();
	list<float>::iterator getIterator();
};

#endif //SCORE_BOARD_LIB_H