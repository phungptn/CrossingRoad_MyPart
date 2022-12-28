#ifndef SRC_INCLUDES_VEHICLE_VEHICLE_HPP
#define SRC_INCLUDES_VEHICLE_VEHICLE_HPP
#include <SFML/Graphics.hpp>
class CVEHICLE {
private:
	int mX, mY;
public:
	virtual void Move(int, int);
};

class CCAR : public CVEHICLE {
public:
	void Move(int, int);
};

class CTRUCK : public CVEHICLE {
public:
	void Move(int, int);
};
#endif // SRC_INCLUDES_VEHICLE_VEHICLE_HPP
