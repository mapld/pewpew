#pragma once
#include "Transform.h"
#include <glm/vec3.hpp>
#include <vector>
#include <stdio.h>

class Collision
{
public:
  Collision(){};
  Collision(Transform* transformSystem){ _transformSystem = transformSystem; };

  struct Data
  {
    std::vector<Entity> entities;
    std::vector<glm::vec3> sizes;
    unsigned n = 0;
  };

  void addBoxCollider(Entity e,glm::vec3 size, glm::vec3 offset = glm::vec3(0,0,0))
  {
    assert(_map.find(e) == _map.end());
    _data.entities.push_back(e);
    _data.sizes.push_back(size);
    _data.n++;
    _map[e] = _data.n - 1;
  }

  void updateCollisions(Uint32 deltaTime)
  {
    // Starting with a dumb n^2 solution
    // TODO: buckets / grid
    // TODO: layers
    // TODO: only process things that have moved this frame
    for(int index1 = 0; index1 < _data.n - 1; index1++)
      {
        for(int index2 = index1 + 1; index2 < _data.n; index2++)
          {
            printf("Checking for collision between index %d and index %d \n", index1, index2);
            glm::vec3 pos1 = _transformSystem->getPosition(_data.entities[index1]);
            glm::vec3 pos2 = _transformSystem->getPosition(_data.entities[index2]);
            glm::vec3 size1 = _data.sizes[index1];
            glm::vec3 size2 = _data.sizes[index2];

            glm::vec3 br1 = pos1 + size1;
            glm::vec3 br2 = pos2 + size2;
            if (pos1.x < br2.x && br1.x > pos2.x)
              {
                if (pos1.y < br2.y && br1.y > pos2.y)
                  {
                    printf("Collision detected\n");
                    // Collision detected
                    // Adjust position
                    // TODO: chain reaction bugs
                    float t = static_cast<float>(deltaTime) / 1000.0f;

                    // glm::vec3 center1 = pos1 + (size1/2);
                    // glm::vec3 center2 = pos2 + (size2/2);
                    // glm::vec3 diff = center1 - center2;

                    glm::vec3 vel1 = _transformSystem->getVelocity(_data.entities[index1]);
                    glm::vec3 oldPos1 = pos1 - vel1;

                    glm::vec3 distance;
                    distance.x = (vel1.x > 0) ? pos2.x - br1.x : br2.x - pos1.x;
                    distance.y = (vel1.y > 0) ? pos2.y - br1.y : br2.y - pos1.y;
                    distance.z = 0;

                    // distance / velocity, limit lower one
                    glm::vec3 timeToHit = distance / vel1;
                    // if a value is negative, the velocity and distance are opposite and a collision can't happen in that direction. Checking for that and for the lowest value of timeToHit
                    glm::vec3 newVel1 = vel1;
                    if (timeToHit.x < 0 || (timeToHit.y > 0 && timeToHit.y < timeToHit.x))
                      {
                        newVel1.y = distance.y;
                      }
                    else
                      {
                        newVel1.x = distance.x;
                      }


                    glm::vec3 newpos1 = oldPos1 + newVel1;
                    printf("old position: (%f , %f)\n", oldPos1.x, oldPos1.y);
                    printf("new position: (%f , %f)\n", newpos1.x, newpos1.y);
                    _transformSystem->setPosition(_data.entities[index1], newpos1);
                  }
              }
          }
      }
  }

  // TODO: destruction / garbage collection

private:
  Transform* _transformSystem;
  Data _data;
  std::unordered_map<Entity,unsigned> _map;

};
