#pragma once
#include "Entity.h"
#include <vector>
#include <queue>
#include <assert.h>

// This defines minimum number of available deleted entities before any entity number will be re-used
const int MIN_QUEUE_LENGTH = 1024;

// Keeps track of entities.
class EntityManager
{
public:
	EntityManager(){ };

	Entity createEntity()
	{
		unsigned id;
		if (_repeatQueue.size() < MIN_QUEUE_LENGTH)
		{
			_repeatCount.push_back(0);
			id = _repeatCount.size() - 1;
      assert(id < INDEX_MAX);
		}
		else
		{
			unsigned idI = _repeatQueue.front();
			_repeatQueue.pop();
			unsigned idR = _repeatCount[idI];
			id = (idR << INDEX_BITS) | idI;
		}
		return { id };
	}

	bool alive(Entity e) const
	{
		return _repeatCount[e.getIndex()] == e.getRepeat();
	};

	void deleteEntity(Entity e)
	{
		unsigned i = e.getIndex();
    assert(i < _repeatCount.size());
		_repeatCount[i]++;
		_repeatQueue.push(i);
	}
private:
	std::vector<unsigned char> _repeatCount;
	std::queue<unsigned> _repeatQueue;
};
