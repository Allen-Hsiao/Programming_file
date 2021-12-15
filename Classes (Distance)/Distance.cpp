#include <iostream>
#include <cmath>
using namespace std;

#include "Distance.h"

/* Constructs a default Distance of 0 (0 feet and 0.0 inches)
*/
Distance::Distance(){
    feet = 0;
    inches = 0;
}


/* Constructs a distance of ft feet and in inches,
    unless in >= 12, in which case the values of feet and inches
    are adjusted accordingly. A Distance will always be positive.
    Just convert negative inches to positive. Don't subtract from feet.
*/
Distance::Distance(unsigned ft, double in){
    // 1 feet = 12 inches
    int convert_feet = 0;
    in = abs(in);
    if (in >= 12){
        convert_feet = floor(in/12);
        in = in - convert_feet*12;
    }
    feet = ft + convert_feet;
    inches = in;
}


/* Constructs a distance of 0 ft and in inches, 
    unless in >= 12, in which case the values of feet and inches
    are adjusted accordingly. A Distance will always be positive.
    Just convert negative inches to positive. Don't subtract from feet.
*/
Distance::Distance(double in){
    // 1 feet = 12 inches
    int convert_feet = 0;
    in = abs(in);
    if (in >= 12){
        convert_feet = floor(in/12);
        in = in - convert_feet*12;
    }
    feet = convert_feet;
    inches = in;
}


/* Returns just the feet portion of the Distance
*/
unsigned Distance::getFeet() const{
    return feet;
}


/* Returns just the inches portion of the Distance
*/
double Distance::getInches() const{
    return inches;
}


/* Returns the entire distance as the equivalent amount of inches.
    (e.g., 4 feet 3.5 inches would be returned as 51.5 inches)
*/
double Distance::distanceInInches() const{
    return (feet*12 + inches);
}


/* Returns the entire distance as the equivalent amount of feet.
    (e.g., 3 feet 6 inches would be returned as 3.5 feet)
*/
double Distance::distanceInFeet() const{
    double convert_feet = 0;
    convert_feet = inches/12;
    return feet + convert_feet;
}


/* Returns the entire distance as the equivalent amount of meters.
    1 inch equals 0.0254 meters.
    (e.g., 2 feet 8.12 inches would be returned as 0.815848 meters)
*/
double Distance::distanceInMeters() const{
    double total_inches = 0;
    total_inches = feet*12 + inches;
    return total_inches*0.0254;
}


/* Returns the sum of 2 Distances.
*/
Distance Distance::operator+(const Distance &rhs) const{
    Distance total_dis;
    int convert_feet = 0;
    total_dis.feet = feet + rhs.feet;
    total_dis.inches = inches + rhs.inches;
    
    if (total_dis.inches >= 12 ){
        convert_feet = floor(total_dis.inches/12);
        total_dis.inches = total_dis.inches - convert_feet*12;
    }
    total_dis.feet += convert_feet;

    return total_dis;
}


/* Returns the difference between 2 Distances.
*/
Distance Distance::operator-(const Distance &rhs) const{
    Distance total_dis;
    double total_inches = 0;
    
    total_inches = abs((feet*12 + inches) - (rhs.feet*12 + rhs.inches));
    
    if (total_inches >= 12){
        total_dis.feet = floor(total_inches/12);
        total_dis.inches = total_inches - total_dis.feet*12;
    }
    else{
        total_dis.feet = 0;
        total_dis.inches = total_inches;
    }
    return total_dis;    
}


/* Outputs to the stream out the Distance in the format: 
    feet' inches'' (i.e. 3' 3.41'')
*/
ostream & operator<<(ostream &out, const Distance &rhs){
    out << rhs.feet;
    out << "' ";
    out << rhs.inches;
    out << "\"";
    return out;
}

/* Used by the 2 parameterized constructors to convert any negative values to positive and
    inches >= 12 to the appropriate number of feet and inches.
*/
void Distance::init(){
    inches = abs(inches);
    Distance(feet, inches);
}


unsigned feet;
double inches;    