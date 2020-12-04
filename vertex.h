/**
 * @file vertex.h
 * Definition and (minimal) implementation of an vertex class.
 */

#pragma once

#include <string>


using std::string;


/**
 * Represents an Vertex in a graph; used by the Graph class.
 * included latitude and longitude variable for working with the openflight dataset
 */
class Vertex {
    public:
        string getId() const{
            return id_;
        }
        float getLatitude() const{
            return latitude_;
        }
        float getLongtitude() const{
            return longitude_;
        }
        // constructor based on id of Vertex
        // can be used for other datasets
        Vertex(string id) {
            id_ = id;
            latitude_ = 0;
            longitude_ = 0;
        }
        // constructor based on id, latitude and longitude of Vertex
        // used mainly for openflight dataset
        Vertex(string id, float latitude, float longitude) {
            id_ = id;
            latitude_ = latitude;
            longitude_ = longitude;
        }
        void setLatitude(float latitude) {
            latitude_ = latitude;
        }
        void setLongtitude(float longitude) {
            longitude_ = longitude;
        }
        // copy constructor
        Vertex(const Vertex& other) {
            id_ = other.id_;
            latitude_ = other.latitude_;
            longitude_ = other.longitude_;
        }
        Vertex& operator=(const Vertex& other) {
            if (this != &other) {
                id_ = other.id_;
                latitude_ = other.latitude_;
                longitude_ = other.longitude_;
            }
            return *this;
        }
        bool operator==(const Vertex& other) const {
            if (this -> id_ != other.id_) {
                return false;
            }
            return true;
        }
        bool operator!=(Vertex& other) const {
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
        // < operator
        // written for use of map on vertex
        bool operator<(const Vertex& other) const {
            if (this -> latitude_ < other.latitude_ && this -> longitude_ < other.longitude_) {
                return true;
            }
            return false;
        }
    private:
        string id_;
        float latitude_;
        float longitude_;
};

#include "hash.cpp"