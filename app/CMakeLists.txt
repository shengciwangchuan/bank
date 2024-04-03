#cmake_minimum_required (VERSION 2.8)

#project (demo)

#以下方法二选一
#1，把当前路径下的所有源文件放在存储在SRC_LIST变量中
#aux_source_directory(. SRC_LIST)
##2，把当前路径下的部分源文件放在存储在SRC_LIST变量中
#set( SRC_LIST
#	 ./main.c
#	 ./testFunc1.c
#	 ./testFunc.c)

# #该命令是用来向工程添加多个指定头文件的搜索路径
# include_directories (test_func test_func1)

# #把当前路径文件夹下的所有源文件放在存储在SRC_LIST变量中
# aux_source_directory (test_func SRC_LIST)
# aux_source_directory (test_func1 SRC_LIST1)

# #向当前工程添加当前存放源文件的子目录
# add_subdirectory (src)

## 生成文件名为testFunc_shared的动态库
#add_library (testFunc_shared SHARED ${SRC_LIST})

##生成文件名为testFunc_static的静态库
#add_library (testFunc_static STATIC ${SRC_LIST})
# 设置目标二进制可执行文件的存放位置为bin/
#set (EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
# 设置库文件的默认输出路径为lib
#set (LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)
# 设置最终的库文件名字
#set_target_properties (testFunc_shared PROPERTIES OUTPUT_NAME "testFunc")
#set_target_properties (testFunc_static PROPERTIES OUTPUT_NAME "testFunc")
#  在指定目录下查testFunc库，并把库的绝对路径存放到变量TESTFUNC_LIB
# find_library(TESTFUNC_LIB testFunc HINTS ${PROJECT_SOURCE_DIR}/testFunc/lib)

#表示最终要生成的elf文件的名字叫main，使用的源文件是SRC_LIST
# add_executable(main ${SRC_LIST})
# 把目标文件与库文件进行链接
# target_link_libraries (main ${TESTFUNC_LIB})
# 添加编译选项
#add_compile_options(-std=c++11 -Wall) 
#设置MYDEBUG为OFF
#option(MYDEBUG "enable debug compilation" OFF)
# if(MYDEBUG)
#     add_executable(main2 main2.c)
# else()
#     message(STATUS "Currently is not in debug mode")   
# endif()
# 此方法避免到文件中修改MYDEBUG的值
#cmake .. -DMYDEBUG=ON

# 添加定义
# option有变化，要么删除上次执行cmake时产生的缓存文件，要么把所有的option都显式的指定其值
#add_definitions(-DWWW1)