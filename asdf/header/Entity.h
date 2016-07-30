#pragma once
#include <unordered_map>

struct Entity
{
	unsigned id;

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