/**
 * @file vertex.h
 * Definition and (minimal) implementation of an vertex class.
 */

#pragma once

#include <string>

using std::string;


/**
 * Represents an edge in a graph; used by the Graph class.
 *
 * @author Sean Massung
 * @date Spring 2012
 */
class Vertex {
    public:
        string getId() const{
            return id_;
        }
        int getLatitude() const{
            return latitude_;
        }
        int getLongtitude() const{
            return longitude_;
        }
        Vertex(string id) {
            id_ = id;
            latitude_ = 0;
            longitude_ = 0;
        }
        Vertex(string id, int latitude, int longitude) {
            id_ = id;
            latitude_ = latitude;
            longitude_ = longitude;
        }
        bool operator==(Vertex& other) const
        {
            if (this -> id_ != other.id_) {
                return false;
            }
            if (this -> latitude_ != other.latitude_) {
                return false;
            }
            if (this -> longitude_ != other.longitude_) {
                return false;
            }
            return true;
        }
        bool operator!=(Vertex& other) const
        {
            if (this -> id_ == other.id_) {
                return false;
            }
            if (this -> latitude_ == other.latitude_) {
                return false;
            }
            if (this -> longitude_ == other.longitude_) {
                return false;
            }
            return true;
        }
        bool operator<(const Vertex& other) const
        {
            if (this -> latitude_ < other.latitude_ && this -> longitude_ < other.longitude_) {
                return true;
            }
            return false;
        }
    private:
        string id_;
        double latitude_;
        double longitude_;
};