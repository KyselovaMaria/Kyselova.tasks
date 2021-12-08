#include "Polygone2D.h"

Polygone2D::Polygone2D(Point2D* points, int count)
{
	this->points = points;
	this->count = count;
}

Point2D* Polygone2D::getPoints()
{
	return points;
}

int Polygone2D::getCount()
{
	return count;
}

void Polygone2D::setPoints(Point2D* points)
{
	this->points = points;
}

void Polygone2D::setCount(int count)
{
	this->count = count;
}

bool Polygone2D::is_convex()
{
	Point2D* list = points;
	bool f = true;
	for (int i = -2; i < count - 1; i++)
	{
		double a = list[i].distance(list[i + 1]);
		double b = list[i + 1].distance(list[i + 2]);
		double c = list[i].distance(list[i + 2]);
		if (a * a + b * b > c * c)
			f = false;
	}
	return f;
}

vector<Triangle2D> Polygone2D::triangulation()
{

	double* x = new double[count];
	double* y = new double[count];

	for (int i = 0; i < count; i++) {
		x[i] = points[i].getX();
		y[i] = points[i].getY();
	}

	int* triangulation = polygon_triangulate(10, x, y);

	std::vector<Triangle2D> triangles;

	for (int i = 0; i < 3 * (count - 2); i += 3) {
		Point2D a(points[triangulation[i]]);
		Point2D b(points[triangulation[i + 1]]);
		Point2D c(points[triangulation[i + 2]]);

		triangles.emplace_back(a, b, c);
	}
	delete[]x;
	delete[]y;

	delete[] triangulation;

	return triangles;
}

double Polygone2D::calculateArea()
{
	double* x = new double[count];
	double* y = new double[count];

	for (int i = 0; i < count; i++) {
		x[i] = points[i].getX();
		y[i] = points[i].getY();
	}

	double area = polygon_area(count, x, y);
	delete[]x;
	delete[]y;

	return area;
}