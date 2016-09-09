#include "../header/InputHandler.h"

// possibly more effective to just store two maps, one for each direction
void InputHandler::bindKey(Action action,Key key)
{
  for ( std::map<Key,Action>::iterator it = _keymap.begin(); it != _keymap.end(); )
    {
      if(it->second == action)
        {
          it = _keymap.erase(it);
        }
      else
        {
          ++it;
        }
    }
  _keymap[key] = action;
}
