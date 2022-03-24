#include <iostream>
using namespace std;
const int MAX_SIZE = 100;
void readData(char src[MAX_SIZE][MAX_SIZE], const int sizeY, const int sizeX); 
void printData(const char src[MAX_SIZE][MAX_SIZE], const int sizeY, const int sizeX);
int isOneAtGivenYX(const int y, const int x, const char src[MAX_SIZE][MAX_SIZE], const int sizeY, const int sizeX);
char characterForYX(const int y, const int x, const char src[MAX_SIZE][MAX_SIZE], const int sizeY, const int sizeX);
void transformData(char dst[MAX_SIZE][MAX_SIZE], char src[MAX_SIZE][MAX_SIZE], const int sizeY, const int sizeX);
void swap(char dst[MAX_SIZE][MAX_SIZE], char src[MAX_SIZE][MAX_SIZE], const int sizeY, const int sizeX); //function swaps all the elements of the both functions so in the next iteration the loop would work properly
int main()
{
	char src[MAX_SIZE][MAX_SIZE];
	char dst[MAX_SIZE][MAX_SIZE];
	int sizeY, sizeX, how_many;
	cin >> sizeY >> sizeX;
	readData(src, sizeY, sizeX);
	cin >> how_many;
	printData(src, sizeY, sizeX);
	for (int i = 0; i < how_many; i++)
	{
		transformData(dst, src, sizeY, sizeX);
		printData(dst, sizeY, sizeX);
		swap(dst, src, sizeY, sizeX);
	}
}
void readData(char src[MAX_SIZE][MAX_SIZE], const int sizeY, const int sizeX)
{
	for (int y = 0; y < sizeY; y++)
	{
		for (int x = 0; x < sizeX; x++)
		{
			cin >> src[y][x];
		}
	}
}
void printData(const char src[MAX_SIZE][MAX_SIZE], const int sizeY, const int sizeX)
{
	for (int y = 0; y < sizeY; y++)
	{
		for (int x = 0; x < sizeX; x++)
		{
			cout << src[y][x];
		}
		cout << endl;
	}
}
int isOneAtGivenYX(const int y, const int x, const char src[MAX_SIZE][MAX_SIZE], const int sizeY, const int sizeX)
{
	if (y < 0 || y >= sizeY)
	{
		return 0;
	}
	else if (x < 0 || x >= sizeX)
	{
		return 0;
	}
	else if ( (src[y][x] == 'X') || (src[y][x] == '0') )
	{
		return 0;
	}
	else if(src[y][x]=='1')
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
char characterForYX(const int y, const int x, const char src[MAX_SIZE][MAX_SIZE], const int sizeY, const int sizeX)
{
	int oneAbove = isOneAtGivenYX(y - 1, x, src, sizeY, sizeX);
	int oneBelow = isOneAtGivenYX(y + 1, x, src, sizeY, sizeX);
	int oneLeft = isOneAtGivenYX(y, x - 1, src, sizeY, sizeX);
	int oneRight = isOneAtGivenYX(y, x + 1, src, sizeY, sizeX);
	int oneAboveRight = isOneAtGivenYX(y - 1, x + 1, src, sizeY, sizeX);
	int oneAboveLeft = isOneAtGivenYX(y - 1, x - 1, src, sizeY, sizeX);
	int oneBelowRight = isOneAtGivenYX(y + 1, x + 1, src, sizeY, sizeX);
	int oneBelowLeft = isOneAtGivenYX(y + 1, x - 1, src, sizeY, sizeX);
	int count = oneBelowLeft + oneBelowRight + oneAboveLeft + oneAboveRight + oneRight + oneLeft + oneBelow + oneAbove;
	if (src[y][x] == 'X')
	{
		return 'X';
	}
	else if (( (count == 2 || count == 3) && (src[y][x] == '1') )|| ((src[y][x] == '0') && count == 3))
	{
		return '1';
	}
	else
	{
		return '0';
	}
}
void transformData(char dst[MAX_SIZE][MAX_SIZE], char src[MAX_SIZE][MAX_SIZE], const int sizeY, const int sizeX)
{
	for (int y = 0; y < sizeY; y++)
	{
		for (int x = 0; x < sizeX; x++)
		{
			dst[y][x] = characterForYX(y, x, src, sizeY, sizeX);
		}
	}
}
void swap(char dst[MAX_SIZE][MAX_SIZE], char src[MAX_SIZE][MAX_SIZE], const int sizeY, const int sizeX)
{
	char temp;
	for (int y = 0; y < sizeY; y++)
	{
		for (int x = 0; x < sizeX; x++)
		{
			temp = src[y][x];
			src[y][x] = dst[y][x];
			dst[y][x] = temp;
		}
	}
}