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
#include "main.h"
#include "context.h"
#include "log.h"

int run(Platform plat) {
  Logger logger = Logger();
  Window mainWindow = plat.makeWindow("Test Window", 1280, 720);
  Context ctx = Context();

  std::vector<PhysicalDevice> physicalDevices = ctx.listDevices();
  logger.log(Info, "Found the following graphics devices:");
  for (const PhysicalDevice &dev : physicalDevices) {
    logger.log(Info, dev.getName());
  }
  
  /* TODO: Use a system to rank the devices and choose the best. */
  logger.log(Info, "Using device: " + physicalDevices[0].getName());
  ctx.useDevice(physicalDevices[0]);

  while (mainWindow.update() == 0) {

  }

  return 0;
}
