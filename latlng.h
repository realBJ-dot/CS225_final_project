#include "cmath"
/*
class LatLng is based on an idea in cs125 calculating the distance between two points given their latitudes and longitudes.
*/
class LatLng {
    public:
    LatLng(double Lat, double Lng): latitude(Lat), longitude(Lng) {
    }
    double distance_helper(LatLng one, LatLng another) {
        const double latDistanceScale = 110574;
        const double lngDistanceScale = 111320;
        const double degToRad = M_PI / 180;
        double latRadians = degToRad * one.latitude;
        double latDistance = latDistanceScale * (one.latitude - another.latitude);
        double lngDistance = lngDistanceScale * (one.longitude - another.longitude) * cos(latRadians);
        return sqrt(latDistance * latDistance + lngDistance * lngDistance);
    }
    double distance(double oneLat, double oneLng,
                                  double anotherLat, double anotherLng) {
                                      return distance_helper(LatLng(oneLat, oneLng), LatLng(anotherLat, anotherLng));
                                  }
    private:
    double latitude;
    double longitude;
};