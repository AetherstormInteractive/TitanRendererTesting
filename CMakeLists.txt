cmake_minimum_required (VERSION 3.8)

project ("TitanRendererTesting")

add_subdirectory ("TitanRendererTesting")

add_subdirectory("3rdparty/json")
add_subdirectory("3rdparty/glad")
add_subdirectory("3rdparty/entt")
add_subdirectory("3rdparty/glm")
add_subdirectory("3rdparty/assimp")
add_subdirectory("3rdparty/tinyobj")
add_subdirectory("3rdparty/sdl2")

set_target_properties(TitanRendererTesting nlohmann_json glad EnTT glm assimp tinyobjloader PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/lib"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/lib"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin"
)