#Variables may only contain alphanumeric characters and underscores: https://cmake.org/cmake/help/book/mastering-cmake/chapter/Writing%20CMakeLists%20Files.html#variables

# set(var_1 "Text1")
# set([[var2]] "Text2")
# set("var3" "Text3")

# message(${var_1})
# message(${var2})
# message(${var3})

#The bracket and quoted syntax allows spaces within variable names, but it's a bad practice and I won't explore that further.

#-------------------------------------------------------
#Variable references
# set(one abc)        #abc
# set(two ${one}de)   #abcde
# set(three  ${two} fg) #abcde;fg
# set(four thre)    #thre
# set(five ${${four}e}) #abcde;fg

# message(${one})
# message(${two})
# message(${three})
# message(${four})
# message(${five})


#-------------------------------------------------------
#environment variables

#Your own environment variables will affect the running cmake instance.
# They won't affect the system
# set(ENV{MY_PATH} "C:/Program Files/parent/child/bin")
# message($ENV{MY_PATH})

# #You can also read enviroment variables from the system
# message($ENV{TMP})
# message($ENV{ZES_ENABLE_SYSMAN})


#-------------------------------------------------------
#Cache variables
# set(cache_var "The value" CACHE STRING "This is a cache variable")
# message(${cache_var})




#-------------------------------------------------------
#CMake defined variables
#https://cmake.org/cmake/help/latest/manual/cmake-variables.7.html
#Keep in mind that some variables don't work on scripts. They are project oriented and work when you set up a project with a proper CMakeLists.txt file.

# #Print the cmake version
message(${CMAKE_VERSION})
#Print the location of the cmake executable
message(${CMAKE_COMMAND})
#Print the location of the current list file
message(${CMAKE_CURRENT_LIST_FILE})