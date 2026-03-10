# Ex00 - Bureaucrat

## Overview

Introduction to exception handling in C++. Implementation of `Bureaucrat` class
with custom exception and grade validation.

## Description

A Bureaucrat has:
- **Name** (const, cannot be changed)
- **Grade** (valid range: 1 to 150)
	- Grade 1 = highest grade.
	- Grade 150 = lowest grade.

## Features

- Constructor with name and grade validation.
- Custom exception classes:
	- `GradeTooHighException` (grade < 1)
	- `GradeTooLowException` (grade > 150)
- Grade manipulation methods:
	- `incrementGrade()` ==> Increases grade (decreases number)
	- `decrementGrade()` ==> Decreases grade (increases number)
- Getters: `getName()`, `getGrade()`
- Overloaded insertion operator `<<` for output.

## Exceptions thrown

- Constructor (invalid grade)
- `incrementGrade` (would exceed grade 1)
- `decrementGrade` (would exceed grade 150)

## Exception handling

Use `try-catch` blocks to capture and handle exceptions:
```cpp
try
{
	Bureaucrat bob("Bob", 0); //Throws GradeTooHighException
}
catch (const std::exception& e)
{
	std::cout << "Error: " << e.what() << std::endl;
}
```

## Key concepts

- Custom exceptions classes inheriting from `std::exception`.
- `throw()` specification (C++98)
- `try-catch` blocks.
- Const correctness

## Usage

```bash
make
./bureaucrat
```