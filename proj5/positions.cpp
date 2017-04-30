#include <iostream>
#include <cmath>
#include <math.h>
#include "positions.h"

using namespace std;

Position::Position() 
{
    myRadius = 1.0;
    myAngleInRadians = 0.0;
}

Position::Position(float r) 
{
    myRadius = r;
    myAngleInRadians = 0.0;
}

Position::Position(float r, float thetaInRadians) 
{
    myRadius = r;
    myAngleInRadians = thetaInRadians;
}


void Position::SetAbsolutePosition (float r, float thetaInRadians)
{
    myRadius = r;
    myAngleInRadians = thetaInRadians;
}

void Position::IncrementPosition (float rChange, float angularDistChange)
{
    myRadius += rChange;
    if(myRadius < 1){
        myRadius = 1;
    }
    myAngleInRadians += angularDistChange/myRadius;

}

void Position::Print()
{
    cout << "   Radius in meters " << myRadius << "\n";
    cout << "   Angle in radians " << myAngleInRadians << "\n";
}

bool Position::Sees(Position pos) 
{
    float catRadius = myRadius;
    float catAngle = myAngleInRadians;
    float mouseAngle = pos.myAngleInRadians; 

    return (catRadius) * cos(catAngle - mouseAngle) >= 1;
}

bool Position::IsAtStatue()
{
    return myRadius == 1;
}


bool Position::IsBetween (Position pos1, Position pos2)
{
    float angleB = myAngleInRadians;
    float angleA = pos1.myAngleInRadians;
    float angleC = pos2.myAngleInRadians; 
    return cos (angleB - angleA) > cos (angleC - angleA) && cos (angleC - angleB) > cos (angleC - angleA);
}

// added from positions.h

bool Position::operator== (Position coords) {
    return coords.myRadius == myRadius && coords.myAngleInRadians == myAngleInRadians;
}


ostream& operator<< (std::ostream &out, Position &pos) {
    return out << "Radius in meters is " << pos.myRadius << " & " << "Angle in radians is " << pos.myAngleInRadians;
}


