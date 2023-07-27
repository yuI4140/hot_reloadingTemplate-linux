set -xe
gcc -ggdb -fPIC -shared -o ./lib/mylib.so ./src/myLib.c
gcc -ggdb -L ./lib/ -o bin/main src/main.c src/loader.c -ldl
LD_LIBRARY_PATH="./lib/*" ./bin/main
#x86_64-w64-mingw32-gcc -Wall -Wextra -Werror -I./headers -o ./bin/main ./src/main.c
