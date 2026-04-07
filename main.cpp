#include <iostream>
#include "src.hpp"

void test_invoked(int argc, char** argv) {
    std::cout << "argc: " << argc << std::endl;
    for (int i = 0; i < argc; ++i) {
        std::cout << "argv[" << i << "]: " << argv[i] << std::endl;
    }
}

int main() {
    final::shell s;
    s.run(1, "ls -al /usr/bin", test_invoked);
    s.run(2, "  echo   hello   world  ", test_invoked);
    
    auto running = s.getRunningList();
    std::cout << "Running PIDs: ";
    for (int pid : running) {
        std::cout << pid << " ";
    }
    std::cout << std::endl;

    s.subprocessExit(1, 0);
    s.subprocessExit(2, 0);

    return 0;
}
