cmake_minimum_required (VERSION 2.8)

# #该命令是用来向工程添加多个指定头文件的搜索路径
include_directories (inc)
file(GLOB INC_LIST ${CMAKE_CURRENT_SOURCE_DIR}/inc/*.h)
execute_process(COMMAND  cp -R ${INC_LIST}  ${PROJECT_SOURCE_DIR}/include)

aux_source_directory (src SRC_LIST)
message("SRC_LIST: ${SRC_LIST}")
get_filename_component(CURRENT_FOLDER ${CMAKE_CURRENT_SOURCE_DIR} NAME)
message("CURRENT_FOLDER: ${CURRENT_FOLDER}")
if(SHARED_TYPE)
    add_library (${CURRENT_FOLDER}_shared SHARED  ${SRC_LIST})
    # 设置最终的库文件名字
    set_target_properties (${CURRENT_FOLDER}_shared PROPERTIES OUTPUT_NAME "${CURRENT_FOLDER}")
else()
      #生成文件名为testFunc的静态库
      add_library (${CURRENT_FOLDER}_static STATIC ${SRC_LIST})
      # 设置最终的库文件名字
      set_target_properties (${CURRENT_FOLDER}_static PROPERTIES OUTPUT_NAME "${CURRENT_FOLDER}")
  
endif()
# 设置库文件的默认输出路径为lib
set (LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib/common)
