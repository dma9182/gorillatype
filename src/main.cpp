// Copyright 2020 Arthur Sonzogni. All rights reserved.
// Use of this source code is governed by the MIT license that can be found in
// the LICENSE file.
#include <memory>  // for allocator, __shared_ptr_access
#include <string>  // for char_traits, operator+, string, basic_string

#include "ftxui/component/app.hpp"             // for Component, App
#include "ftxui/component/captured_mouse.hpp"  // for ftxui
#include "ftxui/component/component.hpp"       // for Input, Renderer, Vertical
#include "ftxui/component/component_base.hpp"  // for ComponentBase
#include "ftxui/component/component_options.hpp"  // for InputOption
#include "ftxui/dom/elements.hpp"  // for text, hbox, separator, Element, operator|, vbox, border
#include "ftxui/util/ref.hpp"  // for Ref

int main() {
  using namespace ftxui;

  // The data:
  std::string first_name;
  std::string last_name;

  // The basic input components:
  Component input_first_name = Input(&first_name, "literal string");

  // The component tree:
  auto component = Container::Vertical({
      input_first_name,
  });

  // Tweak how the component tree is rendered:
  auto renderer = Renderer(component, [&] {
    return vbox({
               hbox(text("Input : "), input_first_name->Render()),
               separator(),
               text("Output : " + first_name),
           }) |
           border;
  });

  auto screen = App::TerminalOutput();
  screen.Loop(renderer);
}
