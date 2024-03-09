#include <iostream>
#include <vector>

class Maus {
public:
	int x;
	int y;
	std::vector <int> xpositions;
	std::vector <int> ypositions;
	std::vector <int> typeofclick;
	void SaveXY();
	void GetCordenates();
	void Recording();
	void Song();
	void Start();
	void LeftClick(int pX, int pY, int duration);
	void RightClick(int pX, int pY, int duration);
	


};