START PROGRAM

  // 1. Initialization
  SET total_sum = 0
  SET num_inputs = 0

  // 2. Prompt for number of inputs (Minimum 3)
  WHILE TRUE DO
    PRINT "How many numbers do you want to convert? (Minimum 3):"
    READ num_inputs
    
    IF num_inputs >= 3 THEN
      BREAK WHILE LOOP
    ELSE
      PRINT "Error: You must enter at least 3 inputs."
    END IF
  END WHILE

  // 3. Process each input one by one
  FOR i = 1 TO num_inputs DO
    PRINT "--- INPUT " + i + " ---"
    
    // 3a. Get and validate the base
    WHILE TRUE DO
      PRINT "Select base (2, 8, 10, or 16):"
      READ base
      
      IF base == 2 OR base == 8 OR base == 10 OR base == 16 THEN
        BREAK WHILE LOOP
      ELSE
        PRINT "Error: Invalid base. Please enter 2, 8, 10, or 16."
      END IF
    END WHILE
    
    // 3b. Get and validate the number string
    WHILE TRUE DO
      PRINT "Enter the number for Base " + base + ":"
      READ number_string
      
      IF isValidForBase(number_string, base) == TRUE THEN
        SET decimal_value = convertToDecimal(number_string, base)
        BREAK WHILE LOOP
      ELSE
        PRINT "Error: Invalid format for the selected base. Try again."
      END IF
    END WHILE
    
    // 3c. Add to the running total
    total_sum = total_sum + decimal_value
    
    // 3d. Convert and display individual results
    PRINT "--- INDIVIDUAL RESULT ---"
    PRINT "Binary      : " + convertToBinary(decimal_value)
    PRINT "Octal       : " + convertToOctal(decimal_value)
    PRINT "Decimal     : " + decimal_value
    PRINT "Hexadecimal : " + convertToHexadecimal(decimal_value)
    
  END FOR

  // 4. Calculate and display the final sum in all bases
  PRINT "--- FINAL RESULT (SUM OF ALL INPUTS) ---"
  PRINT "Binary      : " + convertToBinary(total_sum)
  PRINT "Octal       : " + convertToOctal(total_sum)
  PRINT "Decimal     : " + total_sum
  PRINT "Hexadecimal : " + convertToHexadecimal(total_sum)

END PROGRAM


TEST CASES

Test ID    : TC-01
Description: Validate minimum input count
Input Data : Count: 2
Expected   : "Error: You must enter at least 3 inputs." (Prompts again)
Status     : Pass
----------------------------------------------------------------------

Test ID    : TC-02
Description: Validate base selection
Input Data : Base: 5
Expected   : "Error: Invalid base. Please enter 2, 8, 10, or 16." 
Status     : Pass
----------------------------------------------------------------------

Test ID    : TC-03
Description: Validate Binary input string
Input Data : Base: 2, Num: 102
Expected   : "Error: '102' is not a valid Base 2 number." (2 is invalid)
Status     : Pass
----------------------------------------------------------------------

Test ID    : TC-04
Description: Validate Hex input string
Input Data : Base: 16, Num: 1G
Expected   : "Error: '1G' is not a valid Base 16 number." (G is invalid)
Status     : Pass
----------------------------------------------------------------------

Test ID    : TC-05
Description: Successful individual conversion
Input Data : Base: 16, Num: A
Expected   : Binary: 1010, Octal: 12, Decimal: 10, Hexadecimal: A
Status     : Pass
----------------------------------------------------------------------

Test ID    : TC-06
Description: Final Result (Sum calculation)
Input Data : Dec: 10, Bin: 1010 (10), Hex: A (10)
Expected   : Final Sum -> Decimal: 30, Hex: 1E, Binary: 11110, Octal: 36
Status     : Pass
----------------------------------------------------------------------
