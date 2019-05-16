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
