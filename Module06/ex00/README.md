# Scalar Type Converter

## Description

A C++ program that performs scalar type conversions. It automatically detects the input type (character, integer, floating-point number, or special value) and converts the value to all other scalar data types.

## Supported Types

- **char**: Single character (a-z, A-Z, etc.)
- **int**: Integer numbers (-2147483648 to 2147483647)
- **float**: Decimal numbers (suffix 'f')
- **double**: Double precision decimal numbers

## Features

- Automatic input type detection
- Conversion to all scalar types
- Special value handling (inf, -inf, nan)
- Range limit validation
- Custom output formatting per type


## Class

**ScalarConvert**
- Static class for performing scalar type conversions
- Main method: `convert(const std::string& input)`
- Private methods for type detection and formatted output

## Behavior

The program:
1. Receives a string as an argument
2. Detects the data type (char, int, float, double)
3. Converts it to all types
4. Prints the results with corresponding formatting

## Technical Notes

- Implemented in **C++98**
- Uses static type casting (`static_cast`)
- Handles overflow/underflow exceptions
- Respects the limits of each data type


## Usage

```bash
./convert <value>
```

### Examples

```bash
./convert 42
./convert 42.0
./convert 42.0f
./convert "'a'"
./convert inf
./convert -inf
./convert nan
```
