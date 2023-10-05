#-------------------------------------------------------
#Variable commands: 
#[==[
    . list(APPEND <list> [<element>...])
    . option(<option_variable> "help string describing option" [initial value])
    ...

#]==]

#Working with lists
set(STUDENTS1 Steve Morion Dave) # A list of several elements
set(STUDENTS2 Curly;Boe;Victor;John) # A list of several elements
set(STUDENTS3 "Mary Lily Domz") # One string

message(${STUDENTS1})
message(${STUDENTS2})
message(${STUDENTS3})

list(LENGTH STUDENTS1 STUDENTS1_LENGTH)
message("STUDENTS1 has ${STUDENTS1_LENGTH} elements")

#Print the length of STUDENTS2
list(LENGTH STUDENTS2 STUDENTS2_LENGTH)
message("STUDENTS2 has ${STUDENTS2_LENGTH} elements")

# Print the length of STUDENTS3
list(LENGTH STUDENTS3 STUDENTS3_LENGTH)
message("STUDENTS3 has ${STUDENTS3_LENGTH} elements")

list(APPEND STUDENTS2 "Kurk")

list(LENGTH STUDENTS2 STUDENTS2_LENGTH)
message("STUDENTS2 has ${STUDENTS2_LENGTH} elements")

list(LENGTH STUDENTS3 STUDENTS3_LENGTH)
message("STUDENTS3 has ${STUDENTS3_LENGTH} elements")

list(GET STUDENTS2 2  THE_LEADER)
message("The leader is ${THE_LEADER}")


#The option command
option(OPTIMIZE "Do we want to optimize the operation?" ON)
message("Are we optimizing? ${OPTIMIZE}")

if(OPTIMIZE)
    message("We are optimizing.")
endif()

