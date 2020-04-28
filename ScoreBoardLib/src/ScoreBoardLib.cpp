#include <iostream>
#include <functional>
#include "ScoreBoardLib.h"

ScoreBoard::ScoreBoard()
{
    isSortedMax2Min = true;
	scores = new list<float>();
    iterator = scores->begin();
}
 
ScoreBoard::~ScoreBoard()
{
	delete scores;
}
 
void ScoreBoard::insert(float score)
{
    scores->push_back(score);
    isSortedMax2Min ? scores->sort(greater<float>()) : scores->sort();
}
 
void ScoreBoard::erase(unsigned int position)
{
    if (scores->size() > 0)
    {
        if (position < 0)
            position = 0;

        if (position > scores->size() - 1)
            position = scores->size() - 1;

        iterator = scores->begin();
        advance(iterator, position);
        scores->erase(iterator);
    }
}
 
void ScoreBoard::eraseFirst()
{
    if (scores->size() > 0)
    {
        iterator = scores->begin();
        scores->erase(iterator);
    }
}
 
void ScoreBoard::eraseLast()
{
    if (scores->size() > 0)
    {
        iterator = scores->begin();
        advance(iterator, scores->size() - 1);
        scores->erase(iterator);
    }
}
 
void ScoreBoard::eraseHighest()
{
    if (scores->size() > 0)
    {
        isSortedMax2Min ? eraseFirst() : eraseLast();
    }
}
 
void ScoreBoard::eraseLowest()
{
    if (scores->size() > 0)
    {
        !isSortedMax2Min ? eraseFirst() : eraseLast();
    }
}
 
void ScoreBoard::extract(unsigned int position, float &score)
{
    if (scores->size() > 0)
    {
        if (position < 0)
            position = 0;

        if (position > scores->size() - 1)
            position = scores->size() - 1;

        iterator = scores->begin();
        advance(iterator, position);
        score = *iterator;
        scores->erase(iterator);
    }
}
 
void ScoreBoard::extractFirst(float &score)
{
    if (scores->size() > 0)
    {
        iterator = scores->begin();
        score = *iterator;
        scores->erase(iterator);
    }
}
 
void ScoreBoard::extractLast(float &score)
{
    if (scores->size() > 0)
    {
        iterator = scores->begin();
        advance(iterator, scores->size() - 1);
        score = *iterator;
        scores->erase(iterator);
    }
}
 
void ScoreBoard::extractHighest(float &score)
{
    if (scores->size() > 0)
    {
        score = *iterator;
        isSortedMax2Min ? eraseFirst() : eraseLast();
    }
}
 
void ScoreBoard::extractLowest(float &score)
{
    if (scores->size() > 0)
    {
        score = *iterator;
        !isSortedMax2Min ? eraseFirst() : eraseLast();
    }
}
 
void ScoreBoard::sortMax2Min()
{
    if (scores->size() > 0 && !isSortedMax2Min)
    {
        scores->sort(greater<float>());
        isSortedMax2Min = true;
    }
}
 
void ScoreBoard::sortMin2Max()
{
    if (scores->size() > 0 && isSortedMax2Min)
    {
        scores->sort();
        isSortedMax2Min = false;
    }
}
 
void ScoreBoard::fillArray(float array[], int arraySize)
{
    if (scores->size() > 0)
    {
        iterator = scores->begin();

        for (int i = 0; i < arraySize; i++)
        {
            array[i] = *iterator;
            iterator++;
        }
    }
}
 
void ScoreBoard::fillArray(float array[], int arraySize, bool sortMax2Min)
{
    if (scores->size() > 0)
    {
        iterator = scores->begin();

        if (sortMax2Min)
        {
            if (isSortedMax2Min)
            {
                for (int i = 0; i < arraySize; i++)
                {
                    array[i] = *iterator;
                    iterator++;
                }
            }
            else
            {
                advance(iterator, scores->size() - 1);

                for (int i = 0; i < arraySize; i++)
                {
                    array[i] = *iterator;
                    iterator--;
                }
            }
        }
        else
        { 
            if (!isSortedMax2Min)
            {
                for (int i = 0; i < arraySize; i++)
                {
                    array[i] = *iterator;
                    iterator++;
                }
            }
            else
            {
                advance(iterator, scores->size() - 1);

                for (int i = 0; i < arraySize; i++)
                {
                    array[i] = *iterator;
                    iterator--;
                }
            }
        }
    }
}

void ScoreBoard::clear()
{
    scores->clear();
}
 
int ScoreBoard::getSize()
{
    return scores->size();
}
 
float ScoreBoard::get(unsigned int position)
{
    if (scores->size() > 0)
    {
        iterator = scores->begin();
        advance(iterator, position - 1);
        return *iterator;
    }

    return NULL;
}
 
float ScoreBoard::getFirst()
{
    if (scores->size() > 0)
    {
        iterator = scores->begin();
        return *iterator;
    }

    return NULL;
}
 
float ScoreBoard::getLast()
{
    if (scores->size() > 0)
    {
        iterator = scores->begin();
        advance(iterator, scores->size() - 1);
        return *iterator;
    }

    return NULL;
}
 
float ScoreBoard::getHighest()
{
    if (scores->size() > 0)
    {
        if (isSortedMax2Min)
        {
            return getFirst();
        }
        else
        {
            return getLast();
        }
    }

    return NULL;
}
 
float ScoreBoard::getLowest()
{
    if (scores->size() > 0)
    {
        if (!isSortedMax2Min)
        {
            return getFirst();
        }
        else
        {
            return getLast();
        }
    }

    return NULL;
}

bool ScoreBoard::sortedMax2Min()
{
    return isSortedMax2Min;
}

bool ScoreBoard::empty()
{
    return scores->empty();
}

list<float> ScoreBoard::getStdList()
{
    return *scores;
}

list<float>::iterator ScoreBoard::getIterator()
{
    return iterator;
}