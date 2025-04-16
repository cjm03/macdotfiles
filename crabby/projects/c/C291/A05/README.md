1. Macros:
    Maximum length of request line to parse
    Maximum length of header to store in array
    Size of 'pair' (for conciseness)
    Maximum amount of headers to allow
    Declare a buffer size for fretrvs

2. Functions:
    - Need function to parse request
        - Should return void
        - Should accept a file from standard input
        - Needs to begin by determining the validity of the first line
            - Ensure proper METHOD URI VERSION
        - Store header if it is correct
        - Iterate through each line and put header/value pairs into array
        - Print out required information
    - Need function to iterate through headers
        - Should return void
        - Print header value pairs to stderr and format correctly
        - Needs to account for POST content
    - Need function to lookup headers
        - Not sure if will need to use

3. Main:
    - Call function to parse request
    - Call function to iterate through headers
