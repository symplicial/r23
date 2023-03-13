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
#include "context.h"

/* --- PhysicalDevice --- */
PhysicalDevice::PhysicalDevice(VkPhysicalDevice _device) : device(_device) {

}

std::string PhysicalDevice::getName() const {
  VkPhysicalDeviceProperties properties;
  vkGetPhysicalDeviceProperties(this->device, &properties);
  return std::string(properties.deviceName);
}

uint32_t PhysicalDevice::getGraphicsQueueFamilyIndex() const {
  uint32_t queueFamilyCount;
  vkGetPhysicalDeviceQueueFamilyProperties(this->device, &queueFamilyCount, nullptr);

  std::vector<VkQueueFamilyProperties> queueFamilies(queueFamilyCount);
  vkGetPhysicalDeviceQueueFamilyProperties(this->device, &queueFamilyCount, queueFamilies.data());

  for (uint32_t i = 0; i < queueFamilyCount; ++i) {
    if (queueFamilies[i].queueFlags & VK_QUEUE_GRAPHICS_BIT)
      return i;
  }

  /* TODO: Handle the case in which there is no graphics queue family. */
  return -1;
}

/* --- Context --- */
Context::Context() {
  VkApplicationInfo appInfo{};
  appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
  appInfo.pApplicationName = "r23";
  appInfo.applicationVersion = VK_MAKE_VERSION(0, 0, 1);
  appInfo.pEngineName = "r23";
  appInfo.engineVersion = VK_MAKE_VERSION(0, 0, 1);
  appInfo.apiVersion = VK_API_VERSION_1_0;

  VkInstanceCreateInfo instanceInfo{};
  instanceInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
  instanceInfo.pApplicationInfo = &appInfo;

  /* TODO: Check for error. */
  vkCreateInstance(&instanceInfo, nullptr, &this->instance);
}

Context::~Context() {
  /* TODO: Only do this if we created this device. */
  vkDestroyDevice(this->device, nullptr);

  vkDestroyInstance(this->instance, nullptr);
}

std::vector<PhysicalDevice> Context::listDevices() const {
  uint32_t physicalDeviceCount;

  /* TODO: Check for error. */
  vkEnumeratePhysicalDevices(this->instance, &physicalDeviceCount, nullptr);

  std::vector<VkPhysicalDevice> physicalDevices(physicalDeviceCount);
  std::vector<PhysicalDevice> devices{};

  /* TODO: Check for error. */
  vkEnumeratePhysicalDevices(this->instance, &physicalDeviceCount, physicalDevices.data());
  for (uint32_t i = 0; i < physicalDeviceCount; ++i) {
    devices.emplace_back(PhysicalDevice(physicalDevices[i]));
  }

  return devices;
}

void Context::useDevice(PhysicalDevice dev) {
  /* TODO: Destroy the old logical device if it exists. */

  VkDeviceQueueCreateInfo queueInfo{};
  queueInfo.sType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
  queueInfo.queueFamilyIndex = dev.getGraphicsQueueFamilyIndex();
  queueInfo.queueCount = 1;

  VkPhysicalDeviceFeatures features{};

  VkDeviceCreateInfo deviceInfo{};
  deviceInfo.sType = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;
  deviceInfo.pQueueCreateInfos = &queueInfo;
  deviceInfo.queueCreateInfoCount = 1;
  deviceInfo.pEnabledFeatures = &features;

  /* TODO: Check for error. */
  vkCreateDevice(dev.device, &deviceInfo, nullptr, &this->device);
}
