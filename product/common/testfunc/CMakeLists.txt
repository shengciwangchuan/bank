cmake_minimum_required (VERSION 2.8)

# #该命令是用来向工程添加多个指定头文件的搜索路径
include_directories (inc)
file(copy inc/ DESTINATION ${PROJECT_SOURCE_DIR}/lib/common/inc FOLLOW_SYMLINK_CHAIN)

aux_source_directory (src SRC_LIST)

##生成文件名为testFunc的静态库
add_library (testFunc_static STATIC ${SRC_LIST})

# 设置最终的库文件名字
set_target_properties (testFunc_static PROPERTIES OUTPUT_NAME "testFunc")

# 设置库文件的默认输出路径为lib
set (LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib/common)
