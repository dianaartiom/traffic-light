#pragma once
#include "Frame.h"
#include "Helper.h"
#include <vector>
#include "CarB.h"
#include "CarC.h"
#include "CarD.h"
#include "Helper.h"

class PedestrianB : public Frame
{
private:
	bool active;
public:
	PedestrianB(HINSTANCE hInst) : Frame(hInst,L"images/pedestrian.bmp",540,170,35,35){
		this->vX = this->vY = 0;
		this->vX  = -3;
		active = true;
	}

	virtual void update() override {
		//if(!active)
		//	return;
		this->x += vX;
		this->y += vY;
		//this->stopAtRed();

	}
	// getters
	int getX() {
		return this->x;
	};

	int getY() {
		return this->y;
	}

	int getVx() {
		return this->vX;
	}

	int getVy() {
		return this->vY;
	}

	// setters
	void setX(int _x) {
		this->x = _x;
	}

	void setY(int _y) {
		this->y = _y;
	}

	void setVx(int _v) {
		this->vX = _v;
	}

	void setVy(int _v) {
		this->vY = _v;
	}

	void stopAtRed(CarB* carB, Helper* mainHelper) {
		if (!carB->isAtRed(mainHelper)) {
			this->vX= 0;
		} else {
			this->vX = 3;
		}
	}
};
