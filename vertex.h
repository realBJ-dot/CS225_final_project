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
            visited_ = false;
        }
        Vertex(string id, double latitude, double longitude) {
            id_ = id;
            latitude_ = latitude;
            longitude_ = longitude;
            visited_ = false;
        }
        void setLatitude(double latitude) {
            latitude_ = latitude;
        }
        void setLongtitude(double longitude) {
            longitude_ = longitude;
        }
        bool visited() {
            return visited_;
        }
        void visit() {
            visited_ = true;
        }
        void unvisited() {
            visited_ = false;
        }
        bool operator==(Vertex& other) const {
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
        bool operator<(const Vertex& other) const {
            if (this -> latitude_ < other.latitude_ && this -> longitude_ < other.longitude_) {
                return true;
            }
            return false;
        }
    private:
        string id_;
        double latitude_;
        double longitude_;
        bool visited_;
};