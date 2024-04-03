cmake_minimum_required (VERSION 2.8)

#把当前路径下的所有源文件放在存储在APP_SRC_LIST变量中
aux_source_directory (src APP_SRC_LIST)

# 设置目标二进制可执行文件的存放位置为bin/
set (EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin/app)

#生成的elf文件的名字叫main，使用的源文件是SRC_LIST
add_executable(main ${APP_SRC_LIST})

