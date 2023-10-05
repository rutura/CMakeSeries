# Macro that mimicks the return mechanism in languages like C++
# macro(ModifyGlobalVariables VAR1 VAR2)
#     set(${VAR1} "New Value for VAR1" )
#     set(${VAR2} "New Value for VAR2" )
# endmacro()

# # Define two global variables
# set(GLOBAL_VAR1 "Original Value for VAR1")
# set(GLOBAL_VAR2 "Original Value for VAR2")

# message("Before mcro call:")
# message("GLOBAL_VAR1: ${GLOBAL_VAR1}")
# message("GLOBAL_VAR2: ${GLOBAL_VAR2}")

# # Call the function to modify the global variables
# ModifyGlobalVariables(GLOBAL_VAR1 GLOBAL_VAR2)

# message("After macro call:")
# message("GLOBAL_VAR1: ${GLOBAL_VAR1}")
# message("GLOBAL_VAR2: ${GLOBAL_VAR2}")


#------------------------------------------------------------
#Set up a macro that increments a variable

macro(IncrementVariable VAR)
    math(EXPR ${VAR} "${${VAR}} + 1")
    # set(${VAR} ${${VAR}} PARENT_SCOPE)
endmacro()

# Define a variable
set(MyVariable 0)

# Call the macro to increment the variable
IncrementVariable(MyVariable)
#Print the value in the variable
message("MyVariable: ${MyVariable}")

# Call the macro to increment the variable
IncrementVariable(MyVariable)
#Print the value in the variable
message("MyVariable: ${MyVariable}")


# #Write a loop that calls the IncrementVariable function twice
foreach(loop_var RANGE 1)
    message("loop_var: ${loop_var}")
    IncrementVariable(MyVariable)
endforeach()

message("MyVariable: ${MyVariable}")