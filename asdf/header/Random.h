#pragma once
#include <stdlib.h>

namespace alrm_random
{
  float floatInRange(float min, float max)
  {
    float r = min + (static_cast<float>(rand()) / static_cast<float>(RAND_MAX/(max-min)));
    return r;
  }
}
