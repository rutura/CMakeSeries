#The if command
#https://cmake.org/cmake/help/latest/command/if.html

#[==[

Conditions with the if command
    . Generally, you pass the non dereferenced variable as a condition to the if command
    .  Here is my understanding of the command:
        . If the variable is undefined: evaluate to false
        . If the variable is defined and set to false: evaluate to false
        . Otherwise evaluate to true
#]==]

# set(VAR1 TRUE)
# if(VAR1)
#     message("VAR1 is true")
# else()
#     message("VAR1 is false")
# endif()

#--------------------------------------------------------------

#Directly passing TRUE or FALSE in an if command
#The only way I can get this to print "VAR2 is true" is to set VAR2 to 1
#We keep this in mind and move on for now. Avoid in practice
# set(VAR2 TRUE)
# if(${VAR2})
#     message("VAR2 is true")
# else()
#     message("VAR2 is false")
# endif()


#--------------------------------------------------------------
#Variable expansion cmake docs: 
#https://cmake.org/cmake/help/latest/command/if.html#variable-expansion

# set(var1 OFF)
# set(var2 "var1")
# if(${var2})
#     message("var2 is true")
# else()
#     message("var2 is false")
# endif()

# if(var2)
#     message("var2 is true")
# else()
#     message("var2 is false")
# endif()


#--------------------------------------------------------------
#Other checks we can do
#https://cmake.org/cmake/help/latest/command/if.html#comparisons

# #EQUAL
if(2 EQUAL 1)
    message("2 EQUAL 1")
else()
    message("2 NOT EQUAL 1")
endif()


# #LESS
set(DOG "Cow")
set(PIG "Dog")

# if(PIG LESS DOG)
#     message("PIG LESS THAN DOG")
# else()
#     message("PIG NOT LESS THAN DOG")
# endif()


# #STRLESS_EQUAL
if(PIG STRLESS_EQUAL DOG)
    message("PIG LESS THAN OR EQUAL TO DOG")
else()
    message("PIG NOT LESS THAN OR EQUAL TO DOG")
endif()