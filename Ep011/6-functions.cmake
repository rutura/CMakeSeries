# A function that mimicks the return mechanism in languages like C++
# function(ModifyGlobalVariables VAR1 VAR2)
#     set(${VAR1} "New Value for VAR1" PARENT_SCOPE )
#     set(${VAR2} "New Value for VAR2" PARENT_SCOPE )
# endfunction()

# # Define two global variables
# set(GLOBAL_VAR1 "Original Value for VAR1")
# set(GLOBAL_VAR2 "Original Value for VAR2")

# message("Before function call:")
# message("GLOBAL_VAR1: ${GLOBAL_VAR1}")
# message("GLOBAL_VAR2: ${GLOBAL_VAR2}")

# # Call the function to modify the global variables
# ModifyGlobalVariables(GLOBAL_VAR1 GLOBAL_VAR2)

# message("After function call:")
# message("GLOBAL_VAR1: ${GLOBAL_VAR1}")
# message("GLOBAL_VAR2: ${GLOBAL_VAR2}")


#------------------------------------------------------------
#A function that increments a variable

function(IncrementVariable VAR)
    math(EXPR ${VAR} "${${VAR}} + 1")
    set(${VAR} ${${VAR}} PARENT_SCOPE)
endfunction()

# Define a variable
set(MyVariable 0)

# Call the function to increment the variable
IncrementVariable(MyVariable)
#Print the value in the variable
message("MyVariable: ${MyVariable}")

# # Call the function to increment the variable
IncrementVariable(MyVariable)
#Print the value in the variable
message("MyVariable: ${MyVariable}")


# # A loop that calls the IncrementVariable function twice
foreach(loop_var RANGE 1)
    message("loop_var: ${loop_var}")
    IncrementVariable(MyVariable)
endforeach()

message("MyVariable: ${MyVariable}")