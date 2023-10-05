# Scripts can be run with the command below: 
#     cmake -P <script_name>.cmake

# The message command. How it's generally used
# message("The sky is blue")

#[=[
    The message command. How it's generally used
    message("The sky is blue")
#]=]

#[====[
    The message command. How it's generally used
    message("The sky is blue")
#]====]

#Bracket arguments. Can be used to print multiple lines
# message([=[The
#     sky
#     is blue
# ]=])


#------------------------------------------------------------------------

#2.Quoted arguments and escapce sequences
# #Escaping characters
# message("The sky is blue: \" \n my friend")
# #Multiple lines in quoted arguments. New to me
# message("With great power... 
#             comes great responsibility")
# #Variable evaluation
# message("The cmake version is ${CMAKE_VERSION}")


#------------------------------------------------------------------------
# #3.Unquoted arguments. spaces and semicolons act as separatoers
message(The\ sky\ is\ blue) # One argument, the spaces are escaped
message(Two arguments) # Two arguments: the space acts as a separator
message(The;sky;is;blue) # Four arguments: The ; acts as a separator