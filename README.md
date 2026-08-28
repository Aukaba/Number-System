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
        PRINT "Error: Invalid base."
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