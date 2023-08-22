def my_roman_numerals_converter(num)
    roman_mapping = {
      1000 => "M",
      900 => "CM",
      500 => "D",
      400 => "CD",
      100 => "C",
      90 => "XC",
      50 => "L",
      40 => "XL",
      10 => "X",
      9 => "IX",
      5 => "V",
      4 => "IV",
      1 => "I"
    }
    
    result = ""
    roman_mapping.each do |value, letter|
      while num >= value
        result += letter
        num -= value
      end
    end
    result
  end
  