// Copyright 2020 Arthur Sonzogni. All rights reserved.
// Use of this source code is governed by the MIT license that can be found in
// the LICENSE file.
#include <ftxui/dom/deprecated.hpp>
#include <memory>  // for allocator, __shared_ptr_access
#include <string>  // for char_traits, operator+, string, basic_string
#include <vector>
#include <algorithm>
#include <utility>
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
  std::string inputString;
  std::string prompt = "The quick brown fox jumps over the lazy dog";
  std::vector<Element> elements = {};

  // The basic input components:
  // we dont show this into the terminal yo
  Component inputKeyboard = Input(&inputString, "literal string");

  // The component tree:
  auto component = Container::Vertical({
      inputKeyboard,
  });

  // Tweak how the component tree is rendered:
  auto renderer = Renderer(component, [&] {

    for(size_t i = 0; i < prompt.size(); i++){
        Color charColor;

        if (i < inputString.size()) {
          if (inputString[i] == prompt[i]){
            charColor = Color::RGB(224,224,232);
          }
          else {
            charColor = Color::RGB(255,92,112);
          }
        }
        else {
          charColor = Color::RGB(85,85,99);
        }
    if(inputString.size()){
      elements[i] = text(inputString.substr(i, 1)) | color(charColor);
    }
    else {
    elements.push_back(text(prompt.substr(i,1)) | color(charColor));
    }
    
  }

    return hbox(std::move(elements));

  });

  

  auto screen = App::TerminalOutput();
  screen.Loop(renderer);
}
