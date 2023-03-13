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

#include <fstream>
#include <string>

const std::string logPath = "log.txt";

enum LogLevel {
  Info,
  Debug,
  Warning,
  Error
};

class Logger {
  std::ofstream out;
public:
  Logger();
  ~Logger();

  void log(LogLevel level, std::string message);
};
