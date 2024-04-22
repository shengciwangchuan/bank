cmake_minimum_required (VERSION 2.8)

# 设置目标二进制可执行文件的存放位置为bin/
set (EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin/app)

# 设置头文件加载路径
include_directories (${PROJECT_SOURCE_DIR}/include)
# 设置库加载路径
link_directories(${PROJECT_SOURCE_DIR}/lib/common)
# 加载库文件
link_libraries(testfunc)
link_libraries(testfunc2)

#生成的elf文件的名字叫main，使用的源文件是SRC_LIST
get_filename_component(CURRENT_FOLDER ${CMAKE_CURRENT_SOURCE_DIR} NAME)

#把当前路径下的所有源文件放在存储在APP_SRC_LIST变量中
aux_source_directory (src APP_SRC_LIST)
add_executable(${CURRENT_FOLDER} ${APP_SRC_LIST})
