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

//#include <iostream>
//#include <string>
//
//using namespace std;
//
//int main()
//{
//	string str1("123456");
//	string str2("abcdefghijklmn");
//	string str;
//	str.assign(str1);
//	cout << str << endl;
//	str.assign(str1, 3, 3);
//	cout << str << endl;
//	str.assign(str1, 2, str1.npos);
//	cout << str << endl;
//	str.assign(5, 'X');
//	cout << str << endl;
//
//	string::iterator itB;
//	string::iterator itE;
//	itB = str1.begin();
//	itE = str1.end();
//	str.assign(itB, (--itE));
//	cout << str << endl;
//	
//	str = str1;
//	cout << str << endl;
//	str.erase(3);
//	cout << str << endl;
//	str.erase(str.begin(), str.end());
//	cout << ":" << str << ":" << endl;
//	
//	str.swap(str2);
//	cout << str << endl;
//
//	string A("ello");
//	string B("H");
//	B.insert(1, A);
//	cout << B << endl;
//
//	A = "ello";
//	B = "H";
//	B.insert(1, "yanchy", 3);
//	cout << "Insert: " << B << endl;
//
//	A = "ello";
//	B = "H";
//	B.insert(1, A, 2, 2);
//	cout << "Insert: " << B << endl;
//
//	A = "ello";
//	B = "H";
//	B.insert(1, 5, 'I');
//	cout << "Insert: " << B << endl;
//	
//	A = "ello";
//	B = "H";
//	string::iterator it = B.begin() + 1;
//	const string::iterator itF = A.begin();
//	const string::iterator itG = A.end();
//	B.insert(it, itF, itG);
//	cout << "Insert: " << B << endl;
//
//	A = "ello";
//	B = "H";
//	B.append(A);
//	cout << "Append: " << B << endl;
//
//	A = "ello";
//	B = "H";
//	B.append("12345", 2);
//	cout << "Append: " << B << endl;
//
//	A = "ello";
//	B = "H";
//	B.append("12345", 2, 3);
//	cout << "Append: " << B << endl;
//
//	A = "ello";
//	B = "H";
//	B.append(10, 'a');
//	cout << "Append: " << B << endl;
//
//	A = "ello";
//	B = "H";
//	B.append(A.begin(), A.end());
//	cout << "Append: " << B << endl;
//
//	return 0;
//}

//#include <iostream>
//
//using namespace std;
//
//class Shape
//{
//protected:
//	int width;
//	int height;
//
//public:
//	void setWidth(int w)
//	{
//		width = w;
//	}
//
//	void setHeight(int h)
//	{
//		height = h;
//	}
//};
//
//class PaintCost
//{
//public:
//	int getCost(int area)
//	{
//		return area * 70;
//	}
//};
//
//class Rectangle : public Shape, public PaintCost
//{
//public:
//	int getArea()
//	{
//		return (width * height);
//	}
//};
//
//int main()
//{
//	Rectangle Rect;
//	int area;
//	int cost;
//
//	Rect.setWidth(5);
//	Rect.setHeight(7);
//
//	area = Rect.getArea();
//	cost = Rect.getCost(area);
//
//	cout << "Total area: " << area << endl;
//	cout << "Total coast: " << cost << endl;
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
//	void setLength(double l)
//	{
//		length = l;
//	}
//	void setBreadth(double b)
//	{
//		breadth = b;
//	}
//	void setHeight(double h)
//	{
//		height = h;
//	}
//
//	double getVolume()
//	{
//		return length * breadth* height;
//	}
//
//	Box operator+(const Box& b)
//	{
//		Box box;
//		box.length = this->length + b.length;
//		box.breadth = this->breadth + b.breadth;
//		box.height = this->height + b.height;
//
//		return box;
//	}
//};
//
//int main()
//{
//	Box box1;
//	Box box2;
//	Box box3;
//	double box3Volume = 0.0;
//
//	box1.setLength(5.0);
//	box1.setBreadth(6.0);
//	box1.setHeight(7.0);
//
//	box2.setLength(8.0);
//	box2.setBreadth(9.0);
//	box2.setHeight(10.0);
//
//	box3 = box1 + box2;
//
//	box3Volume = box3.getVolume();
//	cout << "Box 3 volume is: " << box3Volume << endl;
//
//	return 0;
//}

//#include <iostream>
//
//using namespace std;
//
//class Shape
//{
//protected:
//	double width;
//	double height;
//
//public:
//	Shape(double w, double h)
//	{
//		width = w;
//		height = h;
//	}
//	~Shape()
//	{
//
//	}
//
//	virtual double area()
//	{
//		cout << "Parent class area: " << endl;
//
//		return 0;
//	}
//	// virtual double area() = 0;
//};
//
//class Rectangle :public Shape
//{
//public:
//	Rectangle(double w, double h) :Shape(w, h)
//	{
//
//	}
//
//	double area()
//	{
//		cout << "Rectangle class area: " << endl;
//
//		return (width * height);
//	}
//};
//
//class Triangle :public Shape
//{
//public:
//	Triangle(double w, double h) :Shape(w, h)
//	{
//
//	}
//
//	double area()
//	{
//		cout << "Triangle class area: " << endl;
//
//		return (width * height / 2);
//	}
//};
//
//int main()
//{
//	Shape* shape;
//	Rectangle rec(10, 7);
//	Triangle tri(20, 8);
//
//	shape = &rec;
//	cout << shape->area() << endl;
//
//	shape = &tri;
//	cout << shape->area() << endl;
//
//	return 0;
//}

//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int main()
//{
//	vector<string> v(3, "hi");
//
//	vector<string>::iterator it;
//	for (it = v.begin(); it < v.end(); it++)
//	{
//		cout << *it << endl;
//	}
//
//	return 0;
//}

//#include <iostream>
//#include <vector>
//#include <queue>
//
//using namespace std;
//
//int main()
//{
//	//priority_queue<pair<int, int>> coll;	// Big heap.
//	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> coll;	// Small heap.
//	pair<int, int> a(3, 4);
//	pair<int, int> b(3, 5);
//	pair<int, int> c(4, 3);
//	coll.push(c);
//	coll.push(a);
//	coll.push(b);
//
//	while (coll.empty() != 1)
//	{
//		cout << coll.top().first << "\t" << coll.top().second << endl;
//		coll.pop();
//	}
//
//	return 0;
//}
