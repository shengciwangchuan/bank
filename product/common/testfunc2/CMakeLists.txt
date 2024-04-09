cmake_minimum_required (VERSION 2.8)

# #该命令是用来向工程添加多个指定头文件的搜索路径
include_directories (inc)

# execute_process(COMMAND cp -R ${CMAKE_CURRENT_SOURCE_DIR}/inc ${CMAKE_CURRENT_SOURCE_DIR}/../../lib/common/inc)
# execute_process(COMMAND cp -R ${CMAKE_CURRENT_SOURCE_DIR}/inc ${PROJECT_SOURCE_DIR}/lib/common)

# add_custom_target(CopyTask
#   COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_SOURCE_DIR}/inc ${CMAKE_CURRENT_SOURCE_DIR}/../../lib/common/inc
#   )
aux_source_directory (src SRC_LIST)
# get_filename_component(FOLDER_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)

##生成文件名为testFunc的静态库
add_library (testfunc2_static STATIC ${SRC_LIST})

# 设置最终的库文件名字
set_target_properties (testfunc2_static PROPERTIES OUTPUT_NAME "testfunc2")

# 设置库文件的默认输出路径为lib
set (LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib/common)
