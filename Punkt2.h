

class Punkt2
{
	double x{ 0.0 };
	double y{ 0.0 };

public:
	//settery
	void setX(double _x);
	void setY(double _y);

	//gettery
	double getX();
	double getY();

	//współrzędne biegunowe
	double getRadius();
	double getAngle();

	//odległość punktu od punktu _p
	double getDistance(Punkt2 _p = { 0.0,0.0 });

}
