#左边是目标，右边是我们需要依赖的文件
#然后换行以后的是我们执行的语法

cacu:add.o sub.o main.o
	gcc -o cacu add/add.o sub/sub.o main.o
add.o:add/add.cpp add/add.h
	gcc -c -o add/add.o add/add.cpp
sub.o:sub/sub.cpp sub/sub.h
	gcc -c -o sub/sub.o sub/sub.cpp
main.o:main.cpp add/add.h sub/sub.h
	gcc -c -o main.o main.cpp -Iadd -Isub
clean:
	rm -f cacu add/add.o sub/sub.o main.o

