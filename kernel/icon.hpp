/**
 * @file icon.hpp
 *
 * 表示領域を表すIconクラスを提供する。
 */

#pragma once

#include "graphics.hpp"

unsigned int terminal_button_layer_id;
const int icon_w = 15;
const int icon_h = 24;
const PixelColor IconTransparentColor{0, 0, 1};
void DrawTerminalIcon(PixelWriter& writer, Vector2D<int> pos);
void InitializeTerminalIcon();