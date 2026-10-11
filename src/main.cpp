#include <iostream>
#include <string>
#include <chrono>
#include <algorithm>

int main() {
  const std::string prompt = "The quick brown fox jumps over the lazy dog";
  std::string input;

  size_t mismatch = 0;

  std::cout << prompt << '\n';

  auto start = std::chrono::steady_clock::now();
  std::getline(std::cin, input);
  auto end = std::chrono::steady_clock::now();
  auto elapsed = std::chrono::duration<double>(end-start);

  for(size_t i = 0; i < std::min(input.size(), prompt.size()); i++){
      mismatch+=(input[i]!=prompt[i]);
  }

  float accuracy = static_cast<float>(input.size()-mismatch)/input.size();
  double rawWpm = static_cast<double>(input.size())*12/elapsed.count();
  double wpm = static_cast<double>(input.size()-mismatch)*12/elapsed.count();

  std::cout << "Mismatches : " << mismatch << '\n';
  std::cout << "Character Entered : " << input.size() << '\n';
  std::cout << "Prompt length : " << prompt.length() << '\n';
  std::cout << "Accuracy : " << accuracy << '\n';
  std::cout << "Time Elapsed : " << elapsed << '\n';
  std::cout << "Raw WPM : " << rawWpm << '\n';
  std::cout << "WPM : " << wpm << '\n';

  return 0;
}
