# all: hello hello2
# # 先执行它的依赖项再执行它本身
# hello: ready
# 	@echo "hello Makefile"
# # 默认执行第一个目标，第二个不执行
# hello2:
# 	@echo "hello dafei"
# ready:
# 	@echo "I'm ready"
# main: main.o
# # 编译生成obj文件
# # 链接程序，@是转义符号，表示改动做目标名，^表示目标的所有依赖
#   @echo "linking $@ dependences $^"
# 	@g++ -o $@ $^
# .cpp.o:
# # 表示这是一个目标，把.cpp文件编译为.o文件
#   @echo "compiling $< => $@"
# 	@g++ -c -o $@ $<
# clean:
# 	@rm -rf *.o main
LINK = @echo linking $@  && g++

# 编译c++
GCC = @echo compiling $@ && g++

#编译c
GC = @echo compiling $@ && gcc

# 生成静态库
AR = @echo generating static library $@ && ar crv

FLAGS = -g -DDEBUG -W -Wall -fPIC
GCCFLAGS = 
DEFINES = 

# 指出头文件目录
HRADER = -I./

# 需要引用的库文件
LIBS = 
LINKFLAGS = 

# 加入更多头文件
# HRADER += -I./

# 需要so文件的话就加进来
# LIBS += -lrt
# 需要写多线程程序
LIBS += -pthread

# 对应目标
OBJECT := main.o

# 多个目标
# OBJECT := main.o \
#           other.o

# 二进制文件路径
BIN_PATH = ./

TARGET = main

# 链接使用，这里会引用库文件
$(TARGET) : $(OBJECT)
	$(LINK) $(FLAGS) $(LINKFLAGS) -o $@ $^ $(LIBS)

# 编译cpp用这个目标
.cpp.o:
	$(GCC) -c $(HRADER) $(FLAGS) $(GCCFLAGS) -fpermissive -o $@ $<

# 编译c用这个目标
.c.o:
	$(GC) -c $(HEADER) $(FLAGS) -fpermissive -o $@ $<

# 将生成的$(TARGET)复制到$(BIN_PATH)下
install: $(TARGET)
	cp $(TARGET) $(BIN_PATH)
clean:
	rm -rf $(TARGET) *.o *.so *.a
	