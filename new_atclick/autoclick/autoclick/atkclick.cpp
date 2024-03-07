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
// lembrar de criar uma funcao para adicionar delay nos clicks, deixar com que o usuario possa definir o tempo.


};