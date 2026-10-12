#include <iostream>
#include <string>
#include <chrono>
#include <algorithm>
#include <vector>
#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>
#include <ftxui/component/component.hpp>
#include <ftxui/component/app.hpp>

// TODO:
// 1. change font color based on input
// 2, detect keyboard input
// 3. add cursor

int main() {
  using namespace ftxui;

  /* std::vector<std::string> entries = {
      "Entry 1",
      "Entry 2",
      "Entry 3"
  };
  int selected = 0;

  auto menu = Menu(&entries, &selected);

  auto component = menu | border;

  auto app = App::TerminalOutput();
  app.Loop(component);
  */
  const std::string prompt = "The quick brown fox jumps over the lazy dog";
  std::string input;
  std::vector<Element> typedString = { };

  size_t mismatch = 0;


  Component inputKeyboard = Input(&input);

  inputKeyboard |= CatchEvent([&](Event event) {
      return event.is_character() && !std::isdigit(event.character()[0]);
  });

  auto component = Container::Horizontal({
      inputKeyboard
  });

  for(size_t i = 0; i < prompt.size(); i++){
      typedString.push_back(text(prompt.substr(i,1)) | color(Color::RGB(85,85,99)));
  }

  for(size_t i = 0; i < std::min(input.size(), prompt.size()); i++){
      if(input[i] == prompt[i]) {
          typedString[i] = text(input.substr(i,1)) | color(Color::White);
      }
      if(input[i] != prompt[i]) {
          typedString[i] = text(input.substr(i,1)) | color(Color::Red);
      }
  }

  //std::cout << prompt << '\n';

  auto start = std::chrono::steady_clock::now();
  //std::getline(std::cin, input);
  auto end = std::chrono::steady_clock::now();
  auto elapsed = std::chrono::duration<double>(end-start);

  auto first_char = text("a") | color(Color::Red);
  auto second_char = text("b") | color(Color::Green);
  auto third_char = text("c") | color(Color::Blue);
  auto fourth_char = text("d") | color(Color::White);

  for(size_t i = 0; i < std::min(input.size(), prompt.size()); i++){
      mismatch+=(input[i]!=prompt[i]);
  }

  float accuracy = static_cast<float>(input.size()-mismatch)/input.size();
  double rawWpm = static_cast<double>(input.size())*12/elapsed.count();
  double wpm = static_cast<double>(input.size()-mismatch)*12/elapsed.count();


  auto renderer = Renderer(component, [&]{
      return vbox({
        hbox({typedString}),
        separator(),
        hbox(text("Input : "), inputKeyboard->Render()),
      });
      border;
  });

  auto screen = App::TerminalOutput();
  screen.Loop(renderer);

  /*
  std::cout << "Mismatches : " << mismatch << '\n';
  std::cout << "Character Entered : " << input.size() << '\n';
  std::cout << "Prompt length : " << prompt.length() << '\n';
  std::cout << "Accuracy : " << accuracy << '\n';
  std::cout << "Time Elapsed : " << elapsed << '\n';
  std::cout << "Raw WPM : " << rawWpm << '\n';
  std::cout << "WPM : " << wpm << '\n';
  */
  return 0;
}
