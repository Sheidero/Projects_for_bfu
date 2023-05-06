cmake_minimum_required(VERSION 3.15) # Проверка версии CMake.
									 # Если версия установленой программы
									 # старее указаной, произойдёт аварийный выход.

set(PROJECT_NAME lab_12)				 # имя проекта		 
project("${PROJECT_NAME}")


set(CMAKE_CXX_STANDARD 17)			 # устанавливаем 17 стандарт языка
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)


add_definitions(-DSFML_STATIC)		 # дефайны

include_directories("ext/SFML/include/")	# добавляем директории
link_directories("ext/SFML/lib/")	
add_executable("${PROJECT_NAME}" main.cpp)

target_link_libraries("${PROJECT_NAME}" libsfml-audio.dylib
libsfml-graphics.dylib
libsfml-network.dylib
libsfml-system.dylib
libsfml-window.dylib)