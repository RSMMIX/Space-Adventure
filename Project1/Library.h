#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <time.h>
#include <cmath>

using namespace std;
using namespace sf;

extern int currentScene;

inline float lenght(Vector2f vec)
{
	return sqrtf(vec.x * vec.x + vec.y * vec.y);
}

inline Vector2f normalize(Vector2f vec)
{
	float len = sqrtf(vec.x * vec.x + vec.y * vec.y);
	if (len != 0)
		return vec / len;
	return vec;
}

#define PI 3.14159265
inline Vector2f rotateVector(Vector2f dir, float angle)
{
	if (dir == Vector2f(0, 0))
		return Vector2f(0, 0);
	float nx = dir.x * cos((angle)*PI / 180) - dir.y * sin((angle)*PI / 180);
	float ny = dir.x * sin((angle)*PI / 180) + dir.y * cos((angle)*PI / 180);
	return Vector2f(nx, ny);
}

struct ScoreData
{
	string name;
	int score;
};
#define FILENAME "Leaderboards.txt"
extern ScoreData scoreData[6];

inline void sortScore()
{
	for (int i = 0; i < 6; i++)
	{
		for (int j = i + 1; j < 6; j++)
		{
			if (scoreData[j].score > scoreData[i].score)
			{
				ScoreData temp = scoreData[i];
				scoreData[i] = scoreData[j];
				scoreData[j] = temp;
			}
		}
	}
}

inline void readScoreFile()
{
	fstream file(FILENAME, ios::app | ios::in);
	for (int i = 0; i < 5; i++)
	{
		string tempname;
		string tempscore;
		if (!getline(file, tempname))
			return;
		if (!getline(file, tempscore))
			return;
		scoreData[i] = { tempname, stoi(tempscore) };
	}
	file.close();
	sortScore();
}

inline void addScore(string name, int score)
{
	scoreData[5] = { name, score };
	sortScore();
	fstream file(FILENAME, ios::out);
	for (int i = 0; i < 5; i++)
	{
		file << scoreData[i].name << endl << scoreData[i].score << endl;
	}
	file.close();
}