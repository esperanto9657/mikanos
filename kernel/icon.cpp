#include "icon.hpp"
#include "layer.hpp"

const char terminal_icon_shape[icon_h][icon_w + 1] = {
  "@              ",
  "@@             ",
  "@.@            ",
  "@..@           ",
  "@...@          ",
  "@....@         ",
  "@.....@        ",
  "@......@       ",
  "@.......@      ",
  "@........@     ",
  "@.........@    ",
  "@..........@   ",
  "@...........@  ",
  "@............@ ",
  "@......@@@@@@@@",
  "@......@       ",
  "@....@@.@      ",
  "@...@ @.@      ",
  "@..@   @.@     ",
  "@.@    @.@     ",
  "@@      @.@    ",
  "@       @.@    ",
  "         @.@   ",
  "         @@@   ",
};

void DrawTerminalIcon(PixelWriter* pixel_writer, Vector2D<int> position) {
  for (int dy = 0; dy < icon_h; ++dy) {
    for (int dx = 0; dx < icon_w; ++dx) {
      if (terminal_icon_shape[dy][dx] == '@') {
        pixel_writer->Write(position + Vector2D<int>{dx, dy}, {0, 0, 0});
      } else if (terminal_icon_shape[dy][dx] == '.') {
        pixel_writer->Write(position + Vector2D<int>{dx, dy}, {255, 255, 255});
      } else {
        pixel_writer->Write(position + Vector2D<int>{dx, dy}, IconTransparentColor);
      }
    }
  }
}

void InitializeTerminalIcon(){
  auto terminal_icon_window = std::make_shared<Window>(
      icon_w, icon_h, screen_config.pixel_format);
  terminal_icon_window->SetTransparentColor(IconTransparentColor);
  DrawTerminalIcon(terminal_icon_window->Writer(), {0, 0});

  auto mouse_layer_id = layer_manager->NewLayer()
    .SetWindow(terminal_icon_window)
    .ID();

  layer_manager->UpDown(mouse_layer_id, std::numeric_limits<int>::max());
}