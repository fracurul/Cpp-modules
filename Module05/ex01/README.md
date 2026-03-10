# Ex01 - Form

## Overview

Extends ex00 by introducing the `Form` class.
Forms have grade requirements for signing and executing, and can only be signed
by Bureaucrats with sufficient authority.


## Description

A Form has:
- **Name** (const, cannot be changed)
- **Signed status** (boolean, starts as false)
- **Grade required to sign** (const, 1-150)
- **Grade required to execute** (const, 1-150)

## Features

### Form class:

- Constructor with name and grade validation.
- Custom exception classes:
	- `GradeTooHighException` (grade < 1)
	- `GradeTooLowException` (grade > 150 or insufficient to sign)
- Getters: `getName()`, `isSigned()`, `getGradeToSign()`, `getGradeToExecute()`
- `beSigned(Bureaucrat&)` ==> Signs the form if bureaucrat has sufficient grade.
- Overloaded insertion operator `<<` for output.

### Bureaucrat extension:

- `signForm(Form&)` - Attempts to sign a form and prints result

## Exceptions thrown

- Form constructor (invalid grades)
- `beSigned()` - Bureaucrat grade too low to sign

## Exception handling

Use `try-catch` blocks to capture and handle exceptions:
```cpp
try
{
	Bureaucrat bob("Bob", 100);
	Form topSecret("TopSecret", 50, 25);

	bob.signForm(topSecret); //Will fail and throw exception
}
catch (const std::exception& e)
{
	std::cout << "Error: " << e.what() << std::endl;
}
```

## Key concepts

- Class interaction and dependencies.
- Forward declaration.
- Business logic validation.
- State management (signed/unsigned)

## Usage

```bash
make
./form
```