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
        // return id of the vertex
        string getId() const {
            return id_;
        }

        // return latitude of the vertex
        float getLatitude() const {
            return latitude_;
        }

        // return longitude of the vertex
        float getLongitude() const {
            return longitude_;
        }
        
        // constructor based on id of Vertex
        // can be used for other datasets
        Vertex(string id) {
            if (id.length() != 0) { 
                id_ = id;
                latitude_ = 0;
                longitude_ = 0;
            }
        }
        
        // constructor based on id, latitude and longitude of Vertex
        // used mainly for openflight dataset and dataset formatted the same way
        Vertex(string id, float latitude, float longitude) {
            id_ = id;
            latitude_ = latitude;
            longitude_ = longitude;
        }
        
        // set the latitude of the vertex
        void setLatitude(float latitude) {
            latitude_ = latitude;
        }

        // set the longitude of the vertex
        void setLongitude(float longitude) {
            longitude_ = longitude;
        }

        // custom copy constructor
        Vertex(const Vertex& other) {
            id_ = other.id_;
            latitude_ = other.latitude_;
            longitude_ = other.longitude_;
        }

        // assignment operator
        Vertex& operator=(const Vertex& other) {
            if (this != &other) {
                id_ = other.id_;
                latitude_ = other.latitude_;
                longitude_ = other.longitude_;
            }
            return *this;
        }

        // == operator
        bool operator==(const Vertex& other) const {
            // since the id of the vertices (i.e. airports) are unique
            // we consider two vertices to be the same if they have the same id
            if (this -> id_ != other.id_) {
                return false;
            }
            return true;
        }

        // != operator
        bool operator!=(Vertex& other) const {
            // since the id of the vertices (i.e. airports) are unique
            // we consider two vertices to be different if they have different id
            if (this -> id_ == other.id_) {
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

