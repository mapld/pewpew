#pragma once
#include "Transform.h"
#include <glm/vec3.hpp>
#include <vector>
#include <stdio.h>
#include <glm/glm.hpp>

class Collision
{
public:
  Collision(){};
  Collision(Transform* transformSystem){ _transformSystem = transformSystem; };

  struct Data
  {
    std::vector<Entity> entities;
    std::vector<glm::vec3> sizes;
    std::vector<glm::vec3> prevPos;
    unsigned n = 0;
  };

  void addBoxCollider(Entity e,glm::vec3 size, glm::vec3 offset = glm::vec3(0,0,0))
  {
    assert(_map.find(e) == _map.end());
    _data.entities.push_back(e);
    _data.sizes.push_back(size);
    _data.prevPos.push_back(_transformSystem->getPosition(e));
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
        glm::vec3 newpos;
        for(int index2 = index1 + 1; index2 < _data.n; index2++)
          {
            // printf("Checking for collision between index %d and index %d \n", index1, index2);
            glm::vec3 pos1 = _transformSystem->getPosition(_data.entities[index1]);
            glm::vec3 pos2 = _transformSystem->getPosition(_data.entities[index2]);
            glm::vec3 size1 = _data.sizes[index1];
            glm::vec3 size2 = _data.sizes[index2];

            glm::vec3 br1 = pos1 + size1;
            glm::vec3 br2 = pos2 + size2;
            if ((pos1.x < br2.x && br1.x > pos2.x) && (pos1.y < br2.y && br1.y > pos2.y))
              {
                printf("Collision detected\n");

                glm::vec3 vel1 = _transformSystem->getVelocity(_data.entities[index1]);
                printf("velocity: (%f,%f)\n", vel1.x, vel1.y);
                glm::vec3 oldpos1 = _data.prevPos[index1];
                glm::vec3 oldbr1 = oldpos1 + size1;

                glm::vec3 distance;
                distance.x = (vel1.x > 0) ? pos2.x - oldbr1.x : br2.x - oldpos1.x;
                distance.y = (vel1.y > 0) ? pos2.y - oldbr1.y : br2.y - oldpos1.y;
                distance.z = 0;

                printf("distance: (%f,%f)\n", distance.x, distance.y);

                // distance / velocity, limit lower one
                glm::vec3 timeToHit;
                timeToHit.x = distance.x / vel1.x;
                timeToHit.y = distance.y / vel1.y;
                printf("timeToHit: (%f,%f)\n", timeToHit.x, timeToHit.y);

                float t = static_cast<float>(deltaTime) / 1000.0f;
                glm::vec3 newDelta1 = t * vel1;
                if (timeToHit.y >= 0 && !glm::isinf(timeToHit.y) && (timeToHit.y < timeToHit.x || timeToHit.x < 0))
                  {
                    printf("test1\n");
                    newDelta1.y = distance.y;
                  }
                else if (timeToHit.x >= 0 && !glm::isinf(timeToHit.x) && (timeToHit.y < timeToHit.x || glm::isinf(timeToHit.y)))
                  {
                    printf("test2\n");
                    newDelta1.x = distance.x;
                  }
                else
                  {
                    printf("test3\n");
                    // fuzzy calculation of incoming collision (not caused by own velocity)
                    glm::vec3 oldpos2 = _data.prevPos[index2];
                    glm::vec3 vel2 = pos2 - oldpos2;
                    printf("velocity2: (%f,%f)\n", vel2.x, vel2.y);
                    distance.x = (vel2.x > 0) ? pos1.x - br2.x : pos2.x - br1.x ;
                    distance.y = (vel2.y > 0) ? pos1.y - br2.y : pos2.y - br1.y ;
                    distance = -1.0f * distance;
                    printf("distance: (%f,%f)\n", distance.x, distance.y);
                    if(distance.x < distance.y)
                      {
                        if(vel2.x > 0)
                          newDelta1.x += distance.x;
                        else
                          newDelta1.x -= distance.x;
                      }
                    else
                      {
                        if(vel2.y > 0)
                          newDelta1.y += distance.y;
                        else
                          newDelta1.y -= distance.y;
                      }
                  }

                newpos = oldpos1 + newDelta1;
                // printf("old position: (%f , %f)\n", oldpos1.x, oldpos1.y);
                // printf("new position: (%f , %f)\n", newpos1.x, newpos1.y);
                _transformSystem->setPosition(_data.entities[index1], newpos);
              }
            else
              {
                newpos = pos1;
              }
          }
        _data.prevPos[index1] = newpos;
      }
  }

  // TODO: destruction / garbage collection

private:
  Transform* _transformSystem;
  Data _data;
  std::unordered_map<Entity,unsigned> _map;

};
