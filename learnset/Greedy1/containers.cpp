#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::string containers;
    int caseNumber = 1;
    
    while (std::cin >> containers && containers != "end") {
        std::vector<char> stacks;

        for (char container : containers) {
            bool placed = false;
            
            for (char &top : stacks) {
                if (container <= top) {
                    top = container;
                    placed = true;
                    break;
                }
            }
            
            if (!placed) {
                stacks.push_back(container);
            }
        }

        std::cout << "Case " << caseNumber++ << ": " << stacks.size() << std::endl;
    }
    // fuck this shit man
    return 0;
}
