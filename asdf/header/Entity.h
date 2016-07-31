#pragma once
#include <unordered_map>

const int INDEX_BITS = 24;
const int INDEX_MAX = (1 << INDEX_BITS);
const int INDEX_BITMASK = ( 1 << INDEX_BITS ) - 1;

const int REPEAT_BITS = 8;
const int REPEAT_BITMASK = ( 1 << REPEAT_BITS ) - 1;

// Representation of an Entity 
struct Entity
{
	unsigned id;

    unsigned getIndex() { return (id & INDEX_BITMASK); }
    unsigned getRepeat() { return ( ( id >> INDEX_BITS ) & REPEAT_BITMASK); }

	bool operator==(Entity e) const
	{
		if (e.id == this->id) return true;
		else return false;
	}
};

// Define hash operator for id type
namespace std
{
	template <>
	struct hash<Entity>
	{
		std::size_t operator()(const Entity& e) const
		{
			using std::size_t;
			return ((std::hash<unsigned>()(e.id)));
		}
	};
}
