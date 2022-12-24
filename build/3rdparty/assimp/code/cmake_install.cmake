# Install script for directory: /Users/andrewcrane/Documents/TitanRendererTesting/3rdparty/assimp/code

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
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
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/objdump")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "libassimp5.2.5" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES
    "/Users/andrewcrane/Documents/TitanRendererTesting/lib/Debug/libassimpd.5.2.5.dylib"
    "/Users/andrewcrane/Documents/TitanRendererTesting/lib/Debug/libassimpd.5.dylib"
    )
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libassimpd.5.2.5.dylib"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libassimpd.5.dylib"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      if(CMAKE_INSTALL_DO_STRIP)
        execute_process(COMMAND "/usr/bin/strip" -x "${file}")
      endif()
    endif()
  endforeach()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "libassimp5.2.5" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/Users/andrewcrane/Documents/TitanRendererTesting/lib/Debug/libassimpd.dylib")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libassimpd.dylib" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libassimpd.dylib")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" -x "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libassimpd.dylib")
    endif()
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "assimp-dev" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/assimp" TYPE FILE FILES
    "/Users/andrewcrane/Documents/TitanRendererTesting/3rdparty/assimp/code/../include/assimp/anim.h"
    "/Users/andrewcrane/Documents/TitanRendererTesting/3rdparty/assimp/code/../include/assimp/aabb.h"
    "/Users/andrewcrane/Documents/TitanRendererTesting/3rdparty/assimp/code/../include/assimp/ai_assert.h"
    "/Users/andrewcrane/Documents/TitanRendererTesting/3rdparty/assimp/code/../include/assimp/camera.h"
    "/Users/andrewcrane/Documents/TitanRendererTesting/3rdparty/assimp/code/../include/assimp/color4.h"
    "/Users/andrewcrane/Documents/TitanRendererTesting/3rdparty/assimp/code/../include/assimp/color4.inl"
    "/Users/andrewcrane/Documents/TitanRendererTesting/build/3rdparty/assimp/code/../include/assimp/config.h"
    "/Users/andrewcrane/Documents/TitanRendererTesting/3rdparty/assimp/code/../include/assimp/ColladaMetaData.h"
    "/Users/andrewcrane/Documents/TitanRendererTesting/3rdparty/assimp/code/../include/assimp/commonMetaData.h"
    "/Users/andrewcrane/Documents/TitanRendererTesting/3rdparty/assimp/code/../include/assimp/defs.h"
    "/Users/andrewcrane/Documents/TitanRendererTesting/3rdparty/assimp/code/../include/assimp/cfileio.h"
    "/Users/andrewcrane/Documents/TitanRendererTesting/3rdparty/assimp/code/../include/assimp/light.h"
    "/Users/andrewcrane/Documents/TitanRendererTesting/3rdparty/assimp/code/../include/assimp/material.h"
    "/Users/andrewcrane/Documents/TitanRendererTesting/3rdparty/assimp/code/../include/assimp/material.inl"
    "/Users/andrewcrane/Documents/TitanRendererTesting/3rdparty/assimp/code/../include/assimp/matrix3x3.h"
    "/Users/andrewcrane/Documents/TitanRendererTesting/3rdparty/assimp/code/../include/assimp/matrix3x3.inl"
    "/Users/andrewcrane/Documents/TitanRendererTesting/3rdparty/assimp/code/../include/assimp/matrix4x4.h"
    "/Users/andrewcrane/Documents/TitanRendererTesting/3rdparty/assimp/code/../include/assimp/matrix4x4.inl"
    "/Users/andrewcrane/Documents/TitanRendererTesting/3rdparty/assimp/code/../include/assimp/mesh.h"
    "/Users/andrewcrane/Documents/TitanRendererTesting/3rdparty/assimp/code/../include/assimp/ObjMaterial.h"
    "/Users/andrewcrane/Documents/TitanRendererTesting/3rdparty/assimp/code/../include/assimp/pbrmaterial.h"
    "/Users/andrewcrane/Documents/TitanRendererTesting/3rdparty/assimp/code/../include/assimp/GltfMaterial.h"
    "/Users/andrewcrane/Documents/TitanRendererTesting/3rdparty/assimp/code/../include/assimp/postprocess.h"
    "/Users/andrewcrane/Documents/TitanRendererTesting/3rdparty/assimp/code/../include/assimp/quaternion.h"
    "/Users/andrewcrane/Documents/TitanRendererTesting/3rdparty/assimp/code/../include/assimp/quaternion.inl"
    "/Users/andrewcrane/Documents/TitanRendererTesting/3rdparty/assimp/code/../include/assimp/scene.h"
    "/Users/andrewcrane/Documents/TitanRendererTesting/3rdparty/assimp/code/../include/assimp/metadata.h"
    "/Users/andrewcrane/Documents/TitanRendererTesting/3rdparty/assimp/code/../include/assimp/texture.h"
    "/Users/andrewcrane/Documents/TitanRendererTesting/3rdparty/assimp/code/../include/assimp/types.h"
    "/Users/andrewcrane/Documents/TitanRendererTesting/3rdparty/assimp/code/../include/assimp/vector2.h"
    "/Users/andrewcrane/Documents/TitanRendererTesting/3rdparty/assimp/code/../include/assimp/vector2.inl"
    "/Users/andrewcrane/Documents/TitanRendererTesting/3rdparty/assimp/code/../include/assimp/vector3.h"
    "/Users/andrewcrane/Documents/TitanRendererTesting/3rdparty/assimp/code/../include/assimp/vector3.inl"
    "/Users/andrewcrane/Documents/TitanRendererTesting/3rdparty/assimp/code/../include/assimp/version.h"
    "/Users/andrewcrane/Documents/TitanRendererTesting/3rdparty/assimp/code/../include/assimp/cimport.h"
    "/Users/andrewcrane/Documents/TitanRendererTesting/3rdparty/assimp/code/../include/assimp/importerdesc.h"
    "/Users/andrewcrane/Documents/TitanRendererTesting/3rdparty/assimp/code/../include/assimp/Importer.hpp"
    "/Users/andrewcrane/Documents/TitanRendererTesting/3rdparty/assimp/code/../include/assimp/DefaultLogger.hpp"
    "/Users/andrewcrane/Documents/TitanRendererTesting/3rdparty/assimp/code/../include/assimp/ProgressHandler.hpp"
    "/Users/andrewcrane/Documents/TitanRendererTesting/3rdparty/assimp/code/../include/assimp/IOStream.hpp"
    "/Users/andrewcrane/Documents/TitanRendererTesting/3rdparty/assimp/code/../include/assimp/IOSystem.hpp"
    "/Users/andrewcrane/Documents/TitanRendererTesting/3rdparty/assimp/code/../include/assimp/Logger.hpp"
    "/Users/andrewcrane/Documents/TitanRendererTesting/3rdparty/assimp/code/../include/assimp/LogStream.hpp"
    "/Users/andrewcrane/Documents/TitanRendererTesting/3rdparty/assimp/code/../include/assimp/NullLogger.hpp"
    "/Users/andrewcrane/Documents/TitanRendererTesting/3rdparty/assimp/code/../include/assimp/cexport.h"
    "/Users/andrewcrane/Documents/TitanRendererTesting/3rdparty/assimp/code/../include/assimp/Exporter.hpp"
    "/Users/andrewcrane/Documents/TitanRendererTesting/3rdparty/assimp/code/../include/assimp/DefaultIOStream.h"
    "/Users/andrewcrane/Documents/TitanRendererTesting/3rdparty/assimp/code/../include/assimp/DefaultIOSystem.h"
    "/Users/andrewcrane/Documents/TitanRendererTesting/3rdparty/assimp/code/../include/assimp/ZipArchiveIOSystem.h"
    "/Users/andrewcrane/Documents/TitanRendererTesting/3rdparty/assimp/code/../include/assimp/SceneCombiner.h"
    "/Users/andrewcrane/Documents/TitanRendererTesting/3rdparty/assimp/code/../include/assimp/fast_atof.h"
    "/Users/andrewcrane/Documents/TitanRendererTesting/3rdparty/assimp/code/../include/assimp/qnan.h"
    "/Users/andrewcrane/Documents/TitanRendererTesting/3rdparty/assimp/code/../include/assimp/BaseImporter.h"
    "/Users/andrewcrane/Documents/TitanRendererTesting/3rdparty/assimp/code/../include/assimp/Hash.h"
    "/Users/andrewcrane/Documents/TitanRendererTesting/3rdparty/assimp/code/../include/assimp/MemoryIOWrapper.h"
    "/Users/andrewcrane/Documents/TitanRendererTesting/3rdparty/assimp/code/../include/assimp/ParsingUtils.h"
    "/Users/andrewcrane/Documents/TitanRendererTesting/3rdparty/assimp/code/../include/assimp/StreamReader.h"
    "/Users/andrewcrane/Documents/TitanRendererTesting/3rdparty/assimp/code/../include/assimp/StreamWriter.h"
    "/Users/andrewcrane/Documents/TitanRendererTesting/3rdparty/assimp/code/../include/assimp/StringComparison.h"
    "/Users/andrewcrane/Documents/TitanRendererTesting/3rdparty/assimp/code/../include/assimp/StringUtils.h"
    "/Users/andrewcrane/Documents/TitanRendererTesting/3rdparty/assimp/code/../include/assimp/SGSpatialSort.h"
    "/Users/andrewcrane/Documents/TitanRendererTesting/3rdparty/assimp/code/../include/assimp/GenericProperty.h"
    "/Users/andrewcrane/Documents/TitanRendererTesting/3rdparty/assimp/code/../include/assimp/SpatialSort.h"
    "/Users/andrewcrane/Documents/TitanRendererTesting/3rdparty/assimp/code/../include/assimp/SkeletonMeshBuilder.h"
    "/Users/andrewcrane/Documents/TitanRendererTesting/3rdparty/assimp/code/../include/assimp/SmallVector.h"
    "/Users/andrewcrane/Documents/TitanRendererTesting/3rdparty/assimp/code/../include/assimp/SmoothingGroups.h"
    "/Users/andrewcrane/Documents/TitanRendererTesting/3rdparty/assimp/code/../include/assimp/SmoothingGroups.inl"
    "/Users/andrewcrane/Documents/TitanRendererTesting/3rdparty/assimp/code/../include/assimp/StandardShapes.h"
    "/Users/andrewcrane/Documents/TitanRendererTesting/3rdparty/assimp/code/../include/assimp/RemoveComments.h"
    "/Users/andrewcrane/Documents/TitanRendererTesting/3rdparty/assimp/code/../include/assimp/Subdivision.h"
    "/Users/andrewcrane/Documents/TitanRendererTesting/3rdparty/assimp/code/../include/assimp/Vertex.h"
    "/Users/andrewcrane/Documents/TitanRendererTesting/3rdparty/assimp/code/../include/assimp/LineSplitter.h"
    "/Users/andrewcrane/Documents/TitanRendererTesting/3rdparty/assimp/code/../include/assimp/TinyFormatter.h"
    "/Users/andrewcrane/Documents/TitanRendererTesting/3rdparty/assimp/code/../include/assimp/Profiler.h"
    "/Users/andrewcrane/Documents/TitanRendererTesting/3rdparty/assimp/code/../include/assimp/LogAux.h"
    "/Users/andrewcrane/Documents/TitanRendererTesting/3rdparty/assimp/code/../include/assimp/Bitmap.h"
    "/Users/andrewcrane/Documents/TitanRendererTesting/3rdparty/assimp/code/../include/assimp/XMLTools.h"
    "/Users/andrewcrane/Documents/TitanRendererTesting/3rdparty/assimp/code/../include/assimp/IOStreamBuffer.h"
    "/Users/andrewcrane/Documents/TitanRendererTesting/3rdparty/assimp/code/../include/assimp/CreateAnimMesh.h"
    "/Users/andrewcrane/Documents/TitanRendererTesting/3rdparty/assimp/code/../include/assimp/XmlParser.h"
    "/Users/andrewcrane/Documents/TitanRendererTesting/3rdparty/assimp/code/../include/assimp/BlobIOSystem.h"
    "/Users/andrewcrane/Documents/TitanRendererTesting/3rdparty/assimp/code/../include/assimp/MathFunctions.h"
    "/Users/andrewcrane/Documents/TitanRendererTesting/3rdparty/assimp/code/../include/assimp/Exceptional.h"
    "/Users/andrewcrane/Documents/TitanRendererTesting/3rdparty/assimp/code/../include/assimp/ByteSwapper.h"
    "/Users/andrewcrane/Documents/TitanRendererTesting/3rdparty/assimp/code/../include/assimp/Base64.hpp"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "assimp-dev" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/assimp/Compiler" TYPE FILE FILES
    "/Users/andrewcrane/Documents/TitanRendererTesting/3rdparty/assimp/code/../include/assimp/Compiler/pushpack1.h"
    "/Users/andrewcrane/Documents/TitanRendererTesting/3rdparty/assimp/code/../include/assimp/Compiler/poppack1.h"
    "/Users/andrewcrane/Documents/TitanRendererTesting/3rdparty/assimp/code/../include/assimp/Compiler/pstdint.h"
    )
endif()

