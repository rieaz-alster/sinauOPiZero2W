# How To Build To OPi Zero 2W

## Preparations and Assumptions
Suppost you are started with:
1. Fresh installed desktop Linux, preferably Ubuntu
2. OPi Zero 2W with fresh balenaEtched OPi Linux image

## For desktop
1. Install VSCode
   - Install extensions:
     - CMake
     - C++
     - CodeGPT (optional)
2. Install gcc
   ```
   sudo apt-get build-essential
   ```
3. Install aarch64-gcc
4. Create simple hello world app
    ```
    #include <iostream>

    int main() {
        std::cout << "Hello, OPi Zero 2W world!" << std::endl;
        return 0;
    }
    ```