mkdir ./build
cd ./build
conan install ..
cmake ..
#CXX=clang++ CC=clang cmake ..
make -j4
echo "starting tests"
./bin/range
