#include "vertex.h"

/**
 * simple hash function for Vertex
 * use std::hash on the id of Vertex
 * written for unordered_map of Vertex used in graph
 */
namespace std
{
    template <>
    struct hash<Vertex>
    {
        size_t operator()(const Vertex& k) const
        {
            return (std::hash<std::string>()(k.getId()));
        }
    };
}