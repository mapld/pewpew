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

void InputHandler::handleKeyEvent(SDL_KeyboardEvent kbe)
{
  Key key = Key(kbe.keysym.scancode,kbe.keysym.mod);
  if (_actionAwaitingMap != A_NONE && kbe.type == SDL_KEYDOWN)
    {
      bindKey(_actionAwaitingMap,key);
      _actionAwaitingMap = A_NONE;
    }

  auto search = _keymap.find(key);
  if(search == _keymap.end())
    {
      printf("No key binding for key with code %d \n",key.code);
      return;
    }

  Action act = search->second;
  if(kbe.type == SDL_KEYDOWN)
    {
      _actionDown[act] = true;
    }
  else
    {
      _actionDown[act] = false;
    }
}

bool InputHandler::isActionDown(Action action)
{
  return _actionDown[action];
}

void InputHandler::bindKeyToNext(Action action)
{
  _actionAwaitingMap = action;
}
