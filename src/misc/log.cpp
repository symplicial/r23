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
#include "log.h"

#include <chrono>

Logger::Logger() : out(logPath) {

}

Logger::~Logger() {
  this->out.close();
}

void Logger::log(LogLevel level, std::string message) {
  switch (level) {
  case Info:
    this->out << "[INFO]";
    break;
  case Debug:
    this->out << "[DEBUG]";
    break;
  case Warning:
    this->out << "[WARNING]";
    break;
  case Error:
    this->out << "[ERROR]";
    break;
  }

  auto now = std::chrono::system_clock::now();
  std::time_t nowTime = std::chrono::system_clock::to_time_t(now);

  out << "[" << std::put_time(std::localtime(&nowTime), "%H:%M:%S") << "]";
  out << " ";
  out << message;
  out << "\n";
}
