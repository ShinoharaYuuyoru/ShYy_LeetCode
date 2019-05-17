//#include <iostream>
//
//using namespace std;
//
//class Line
//{
//private:
//	double length;
//
//public:
//	void setLength(double len)
//	{
//		length = len;
//		cout << "Object is being created, length = " << len << endl;
//	}
//
//	double getLength()
//	{
//		return length;
//	}
//
//	Line() : length(0)
//	{
//		cout << "Object is being created." << endl;
//	}
//	~Line()
//	{
//		cout << "Object is being deleted." << endl;
//	}
//};
//
//int main()
//{
//	Line line;
//
//	line.setLength(6.21635);
//	cout << "Length of line: " << line.getLength() << endl;
//
//	return 0;
//}

//#include <iostream>
//
//using namespace std;
//
//class Box
//{
//private:
//	double length;
//	double breadth;
//	double height;
//
//public:
//	Box(double l, double b, double h): length(l), breadth(b), height(h)
//	{
//		cout << "Constructor called." << endl;
//	}
//	~Box()
//	{
//		cout << "Constructor closed." << endl;
//	}
//
//	double Volume()
//	{
//		return length * breadth* height;
//	}
//	
//	bool compare(Box box)
//	{
//		return this->Volume() > box.Volume();
//	}
//};
//
//int main()
//{
//	Box box1(3.3, 1.2, 1.5);
//	Box box2(8.7, 5.2, 4.5);
//
//	if (box1.compare(box2))
//	{
//		cout << "box1 is bigger." << endl;
//	}
//	else
//	{
//		cout << "box2 is equal or bigger." << endl;
//	}
//
//	return 0;
//}

//#include <iostream>
//
//using namespace std;
//
//template<typename T1, typename T2>
//class Point
//{
//private:
//	T1 m_x;
//	T2 m_y;
//
//public:
//	Point(T1 x, T2 y) : m_x(x), m_y(y)
//	{
//		// Constructor. Empty.
//	}
//	~Point()
//	{
//		// Destructor. Empty.
//	}
//
//	void setX(T1 x)
//	{
//		m_x = x;
//	}
//	void setY(T2 y)
//	{
//		m_y = y;
//	}
//	T1 getX() const
//	{
//		return m_x;
//	}
//	T2 getY() const
//	{
//		return m_y;
//	}
//};
//
//int main()
//{
//	Point<int, int> p1(10, 20);
//	cout << "x = " << p1.getX() << ", y = " << p1.getY() << endl;
//
//	Point<int, const char*> p2(10, "东经180度");
//	cout << "x = " << p2.getX() << ", y = " << p2.getY() << endl;
//
//	Point<const char*, const char*> *p3 = new Point<const char*, const char*> ("东经180度", "北纬210度");
//	cout << "x = " << p3->getX() << ", y = " << p3->getY() << endl;
//
//	return 0;
//}

//#include <iostream>
//#include <string>
//
//using namespace std;
//
//int main()
//{
//	string str("12345678");
//	char ch[] = "abcdefgh";
//	string a;	// Empty string.
//	string str_1(str);	// Copy str.
//	string str_2(str, 2, 5);	// Copy 5 characters from the 2nd element.
//	string str_3(ch, 5);	// Copy first 5 characters from ch.
//	string str_4(5, 'X');	// Set a string with 5 X. "XXXXX".
//	string str_5(str.begin(), str.end());	// Copy str. The same as str_1.
//	string str_6(ch, 2, 5);	// Copy 5 characters from the 2nd element.
//
//	cout << str << endl;
//	cout << a << endl;
//	cout << str_1 << endl;
//	cout << str_2 << endl;
//	cout << str_3 << endl;
//	cout << str_4 << endl;
//	cout << str_5 << endl;
//	cout << str_6 << endl;
//
//	return 0;
//}

//#include <iostream>
//#include <string>
//
//using namespace std;
//
//int main()
//{
//	string str("12345678");
//	int size = str.size();
//	int length = str.length();
//	int maxSize = str.max_size();
//	int capacity = str.capacity();
//	cout << str << endl;
//	cout << size << endl;
//	cout << length << endl;
//	cout << maxSize << endl;
//	cout << capacity << endl;
//
//	string str_custom = str;
//	// About the .reserve():
//	// 1. If the para is smaller than the original capacity, this will make no effect.
//	// 2. If the para is bigger than the original capacity, the capacity will be expanded to a [(n*16 - 1), n=1, 2, 3, ...] capacity, like 15, 31, 47.
//	str_custom.reserve(20);
//	// About the .resize():
//	// 1. If the para is smaller than the original capacity, the original string will be cut to the size.
//	// 2. If the para is bigger than the original capacity, the empty spaces of the new string should be filled with the character given in the 2nd para.
//	// e.g. str_custom.resize(20, 'a');
//	str_custom.resize(5);
//	size = str_custom.size();
//	length = str_custom.length();
//	maxSize = str_custom.max_size();
//	capacity = str_custom.capacity();
//	cout << str_custom << endl;
//	cout << size << endl;
//	cout << length << endl;
//	cout << maxSize << endl;
//	cout << capacity << endl;
//
//	return 0;
//}

#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str1("123456");
	string str2("abcdefghijklmn");
	string str;
	str.assign(str1);
	cout << str << endl;
	str.assign(str1, 3, 3);
	cout << str << endl;

}