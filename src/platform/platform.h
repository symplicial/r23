/*
 * r23
 *
 * Copyright (C) 2023 symplicial
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */
#pragma once

#include <string>

#ifdef _WIN32
#include "win32.h"
#endif

/* Interfaces for platform-specific things, like windowing, input, and audio.
 * It is preferable that we keep all the platform-independent interface
 * combined in one structure and leave it to the platform-specific code to sort
 * out, because there may be quite non-trivial relationships between all of
 * these elements. */

 /* To implement everything for a platform, one must implement all the classes
  * and define the following structs:
  * - PlatformData
  * - WindowData
  *
  * The platform-specific code should also contain the entry point of the
  * program and call `run`.
  */

/* A generic window interface. */
class Window {
  WindowData data;
public:
  Window(WindowData _data);

  std::string getTitle() const;
  void setTitle(std::string title);

  int getWidth() const;
  void setWidth(int width);

  int getHeight() const;
  void setHeight(int height);

  /* Returns zero if the window should stay open, non-zero otherwise. */
  int update();
};

class Platform {
  PlatformData data;
public:
  Platform(PlatformData _data);

  Window makeWindow(std::string title, int width, int height);
};
