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
#include <vector>
#include <vulkan/vulkan.h>

/* The data associated to a physical device. */
class PhysicalDevice {
  friend class Context;
  VkPhysicalDevice device;
public:
  PhysicalDevice(VkPhysicalDevice _device);

  std::string getName() const;

  uint32_t getGraphicsQueueFamilyIndex() const;
};

/* A graphics context. */
class Context {
  VkInstance instance;
  VkDevice device;
public:
  Context();
  ~Context();

  std::vector<PhysicalDevice> listDevices() const;

  void useDevice(PhysicalDevice dev);
};
