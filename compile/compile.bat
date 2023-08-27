cd ../

g++ -c Hasher/Block.cpp -o Build/Objects/Block.o

g++ -c test.cpp -o Build/Objects/test.o

cd Build/Objects/

g++ test.o Block.o -o ../Debug/test.exe