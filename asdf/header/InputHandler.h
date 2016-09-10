#pragma once
#include <SDL.h>
#include "Entity.h"
#include <vector>
#include <map>
#include <tuple>

enum Action
  {
    A_NONE,
    A_LEFT,
    A_RIGHT,
    A_UP,
    A_DOWN,
    A_SHOOT,
    A_SIZE
  };


class InputHandler
{
public:
  struct Key
  {
    SDL_Scancode code;
    Uint16 mod;

    Key(){}
    Key(SDL_Scancode scode, Uint16 smod){code = scode, mod = smod;}

    bool operator<(const Key& rhs) const
    {
      return std::tie(code,mod) < std::tie(rhs.code, rhs.mod);
    }
    bool operator==(const Key& rhs) const
    {
      return std::tie(code,mod) == std::tie(rhs.code, rhs.mod);
    }
  };


  InputHandler() {}

  // Will set the action to true (or maybe call a callback function later) or it will map the key to the current _actionAwaitingMap if not A_NONE
  void handleKeyEvent(SDL_KeyboardEvent);

  // Will bind the action to the key
  void bindKey(Action,Key);

  // Will bind the next key pressed to the action given (via handleKeyEvent)
  void bindKeyToNext(Action);

  // Returns true if the action has been pressed down but not up yet
  bool isActionDown(Action);



private:
  bool _actionDown[A_SIZE] = {};
  std::map<Key,Action> _keymap;

  Action _actionAwaitingMap = A_NONE;
  };
