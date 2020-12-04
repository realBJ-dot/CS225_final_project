#include "cmath"

/**
 * function that calculates distance between two points based on latitude and longitude
 * used code from CS 125 mp
 * @param latitude1 latitude of first point
 * @param longitude1 longitude of first point
 * @param latitude2 latitude of second point
 * @param longitude2 longitude of second point
 */ 
double distance_helper(double latitude1, double longitude1, double latitude2, double longitude2) {
    const double latDistanceScale = 110574;
    const double lngDistanceScale = 111320;
    const double degToRad = M_PI / 180;
    double latRadians = degToRad * latitude1;
    double latDistance = latDistanceScale * (latitude1 - latitude2);
    double lngDistance = lngDistanceScale * (longitude1 - longitude2) * cos(latRadians);
    return sqrt(latDistance * latDistance + lngDistance * lngDistance);
}
   