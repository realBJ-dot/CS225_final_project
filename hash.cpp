#include "vertex.h"

namespace std
{
    template <>
    struct hash<Vertex>
    {
        size_t operator()(const Vertex& k) const
        {
            // Compute individual hash values for two data members and combine them using XOR and bit shifting
            return (std::hash<std::string>()(k.getId()));
        }
    };
}