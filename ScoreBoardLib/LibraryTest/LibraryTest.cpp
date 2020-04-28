#include <iostream>
#include "ScoreBoardLib.h"
using namespace std;

int main()
{
    ScoreBoard* sb = new ScoreBoard();

    sb->insert(5);
    sb->insert(8);
    sb->insert(1);
    sb->clear();
}