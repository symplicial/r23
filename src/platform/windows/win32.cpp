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
#include "platform.h"
#include "win32.h"

const char *windowClassName = "DEFAULT";

/* --- Window --- */
Window::Window(WindowData _data) : data(_data) {

}

std::string Window::getTitle() const {

}

void Window::setTitle(std::string title) {

}

int Window::getWidth() const {

}

void Window::setWidth(int width) {

}

int Window::getHeight() const {

}

void Window::setHeight(int height) {

}

int Window::update() {
  MSG msg;
  bool shouldClose = GetMessage(&msg, NULL, 0, 0);
  TranslateMessage(&msg);
  DispatchMessage(&msg);
  return shouldClose ? 0 : 1;
}


/* --- Platform --- */
Platform::Platform(PlatformData _data) : data(_data) {

}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch(msg)
    {
        case WM_CLOSE:
            DestroyWindow(hwnd);
        break;
        case WM_DESTROY:
            PostQuitMessage(0);
        break;
        default:
            return DefWindowProc(hwnd, msg, wParam, lParam);
    }
    return 0;
}

Window Platform::makeWindow(std::string title, int width, int height) {
  HWND hWnd = CreateWindowEx(0, windowClassName, title.c_str(), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, width, height,
      CW_USEDEFAULT, NULL, NULL, this->data.hInstance, NULL);
  ShowWindow(hWnd, SW_NORMAL);
  Window window = Window(WindowData(hWnd));
  return window;
}


/* --- Entry Point --- */
int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hInstPrev, PSTR cmdline, int cmdshow) {
  Platform plat = Platform(PlatformData(hInst));

  WNDCLASS windowClass = { };
  windowClass.lpfnWndProc = WndProc;
  windowClass.hInstance = hInst;
  windowClass.lpszClassName = windowClassName;
  RegisterClass(&windowClass);

  return run(plat);
}
