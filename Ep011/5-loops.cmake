
#Foreach Loop
# # Define a list of names
set(names "Alice" "Bob" "Charlie" "David" "Eve")

# Iterate through the list of names using a foreach loop
# foreach(name ${names})
#     message("Name: ${name}")
# endforeach()


# While Loop
# Define a list of names
set(names "Alice" "Bob" "Charlie" "David" "Eve")

# Get the number of names in the list
list(LENGTH names num_names)

# Initialize a counter variable
set(counter 0)

# Create a while loop to iterate through the list of names
while(counter LESS num_names)
    list(GET names ${counter} name)

    # Print the name
    message("Name: ${name}")

    # Increment the counter
    math(EXPR counter "${counter} + 1")
endwhile()
