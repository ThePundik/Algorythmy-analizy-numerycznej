#include <iostream>
#include <thread>
#include <chrono>

int main() {
    std::string heart[] = {
        "   ❤❤❤❤      ❤❤❤❤️   ",
        " ❤️❤️❤️❤️❤️❤️❤️❤️  ❤️❤️❤️❤️❤️❤️❤️❤️ ",
        "❤️❤️❤️❤️❤️❤️❤️❤️❤️❤️❤️❤️❤️❤️❤️❤️❤️❤️❤️❤️",
        " ❤️❤️❤️❤️❤️❤️❤️❤️❤️❤️❤️❤️❤️❤️❤️❤️❤️❤️ ",
        "  ❤️❤️❤️❤️❤️❤️❤️❤️❤️❤️❤️❤️❤️❤️❤️❤️  ",
        "    ❤️❤️❤️❤️❤️❤️❤️❤️❤️❤️❤️❤️    ",
        "      ❤️❤️❤️❤️❤️❤️❤️❤️      ",
        "        ❤️❤️❤️❤️❤️        ",
        "         ❤️❤️         "
    };

    for (const std::string& line : heart) {
        std::cout << line << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }

    return 0;
}