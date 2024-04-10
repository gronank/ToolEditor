# Install script for directory: C:/Users/ander/source/repos/ToolEditor/vcpkg_installed/x64-windows/vcpkg/blds/imgui-node-editor/src/v0.9.3-4d38c2e147.clean

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Users/ander/source/repos/ToolEditor/vcpkg_installed/x64-windows/vcpkg/pkgs/imgui-node-editor_x64-windows/debug")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "OFF")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "C:/Users/ander/source/repos/ToolEditor/vcpkg_installed/x64-windows/vcpkg/blds/imgui-node-editor/x64-windows-dbg/imgui-node-editor.lib")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/unofficial-imgui-node-editor/unofficial-imgui-node-editor-config.cmake")
    file(DIFFERENT _cmake_export_file_changed FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/unofficial-imgui-node-editor/unofficial-imgui-node-editor-config.cmake"
         "C:/Users/ander/source/repos/ToolEditor/vcpkg_installed/x64-windows/vcpkg/blds/imgui-node-editor/x64-windows-dbg/CMakeFiles/Export/302a0b4208dc37fb4e286b55af0dacf1/unofficial-imgui-node-editor-config.cmake")
    if(_cmake_export_file_changed)
      file(GLOB _cmake_old_config_files "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/unofficial-imgui-node-editor/unofficial-imgui-node-editor-config-*.cmake")
      if(_cmake_old_config_files)
        string(REPLACE ";" ", " _cmake_old_config_files_text "${_cmake_old_config_files}")
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/unofficial-imgui-node-editor/unofficial-imgui-node-editor-config.cmake\" will be replaced.  Removing files [${_cmake_old_config_files_text}].")
        unset(_cmake_old_config_files_text)
        file(REMOVE ${_cmake_old_config_files})
      endif()
      unset(_cmake_old_config_files)
    endif()
    unset(_cmake_export_file_changed)
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/unofficial-imgui-node-editor" TYPE FILE FILES "C:/Users/ander/source/repos/ToolEditor/vcpkg_installed/x64-windows/vcpkg/blds/imgui-node-editor/x64-windows-dbg/CMakeFiles/Export/302a0b4208dc37fb4e286b55af0dacf1/unofficial-imgui-node-editor-config.cmake")
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/unofficial-imgui-node-editor" TYPE FILE FILES "C:/Users/ander/source/repos/ToolEditor/vcpkg_installed/x64-windows/vcpkg/blds/imgui-node-editor/x64-windows-dbg/CMakeFiles/Export/302a0b4208dc37fb4e286b55af0dacf1/unofficial-imgui-node-editor-config-debug.cmake")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "C:/Users/ander/source/repos/ToolEditor/vcpkg_installed/x64-windows/vcpkg/blds/imgui-node-editor/x64-windows-dbg/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
