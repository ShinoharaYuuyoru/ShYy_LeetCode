#include <iostream>

using namespace std;

class Line
{
private:
	double length;

public:
	void setLength(double len)
	{
		length = len;
		cout << "Object is being created, length = " << len << endl;
	}

	double getLength()
	{
		return length;
	}

	Line()
	{
		cout << "Object is being created." << endl;

		length = 0;
	}
	~Line()
	{
		cout << "Object is being deleted." << endl;
	}
};

int main()
{
	Line line;

	line.setLength(6.21635);
	cout << "Length of line: " << line.getLength() << endl;

	return 0;
}