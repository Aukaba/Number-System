START
  INITIALIZE total_decimal_sum = 0
  
  // 1. Get number of inputs
  LOOP:
    PROMPT user for number_of_inputs
    IF number_of_inputs < 3 THEN
      PRINT "Please enter at least 3 inputs."
    ELSE
      BREAK LOOP
  
  // 2. Process each input
  FOR i = 1 to number_of_inputs:
    LOOP to validate base:
      PROMPT user for base (2, 8, 10, 16)
      IF base is valid THEN BREAK LOOP
      ELSE PRINT "Invalid base"

    LOOP to validate number:
      PROMPT user for number_string
      TRY:
        CONVERT number_string to decimal_value using selected base
        BREAK LOOP
      CATCH:
        PRINT "Invalid input for the selected base. Try again."
    
    // 3. Convert and display individual results
    CALCULATE binary_val, octal_val, hex_val from decimal_value
    PRINT individual conversions (Binary, Octal, Decimal, Hexadecimal)
    
    ADD decimal_value to total_decimal_sum
  ENDFOR

  // 4. Calculate and display final result (Sum)
  CALCULATE final_bin, final_oct, final_hex from total_decimal_sum
  PRINT "Final Result (Sum of all inputs)"
  PRINT final_bin, final_oct, total_decimal_sum, final_hex
END