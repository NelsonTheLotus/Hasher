cd ../

g++ -c test.cpp -o Build/Objects/test.o

cd Build/Objects/

g++ test.o -o ../Debug/test.exe

cd ../../compile/