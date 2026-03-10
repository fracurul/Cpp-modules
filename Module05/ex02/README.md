# Ex02 - Abstract Forms (AForm)

## Overview

Introduces polymorphism and abstract classes. `AForm` becomes an abstract base
class with pure virtual functions, and three concrete form types inherit from it,
each with specific behaviors and grade requirements.

## Description

### AForm (Abstract Base Class)
- Abstract class with pure virtual function `executeAction()`.
- Contains common form attributes and behavior.
- Cannot be instantiated directly.
- New method: `execute(Bureaucrat const & executor) const` validates and executes.
- New exception: `FormNotSignedException`

### Concrete Forms

#### 1.ShrubberyCreationForm
- **Target:** Any string.
- **Grade to sign:** 145.
- **Grade to execute:** 137.
- **Action:** Creates a file `<target>_shrubbery` with ASCII trees.

#### 2.RobotomyRequestForm
- **Target:** Any string.
- **Grade to sign:** 72.
- **Grade to execute:** 45.
- **Action:** Makes drilling noises, 50% success rate for robotomization.

#### 3.PresidentialPardonForm
- **Target:** Any string.
- **Grade to sign:** 25.
- **Grade to execute:** 5.
- **Action:** Announces presidential pardon by Zaphod Beeblebrox.

## Features

### AForm class:

- Pure virtual method: `virtual void executeAction() const = 0;`
- `execute(Bureaucrat const & executor) const` ==> Validates conditions before execution:
	- Form must be signed.
	- Executor must have sufficient grade.
- Three exception types:
	- `GradeTooHighException`
	- `GradeTooLowException`
	- `FormNotSignedException`

### Bureaucrat extension:

- `executeForm(AForm& form)` - Attempts to execute a form.

## Execution requirements

A form can be executed if:
1. The form is **signed**.
2. The executor's grade is **high enough** (<= gradeToExecute)

```cpp
Bureaucrat alice("Alice", 50);
ShrubberyCreationForm tree("home");

tree.beSigned(alice);     // Alice signs it (grade 50 < 145)
alice.executeForm(tree);  // Alice executes it (grade 50 < 137)
// Creates file: home_shrubbery
```

## Exceptions thrown

- AForm constructor - Invalid grades (< 1 or > 150)
- `execute()` - Form not signed or executor grade too low.
- Specific forms - File creation errors (ShrubberyCreationForm)

## Exception handling

Use `try-catch` blocks to capture and handle exceptions:
```cpp
try
{
	Bureaucrat bob("Bob", 100);
	PresidentialPardonForm pardon("Criminal");

	pardon.beSigned(bob);	  //Fails! bob's grade (100) > required (25)
	bob.executeForm(pardon); //Throws: grade too low to sign
}
catch (const std::exception& e)
{
	std::cout << "Error: " << e.what() << std::endl;
}
```
## Key concepts

- Abstract classes - Classes with pure virtual functions.
- Pure virtual functions - `virtual void method() = 0;`.
- Polymorphism - Base class pointer/reference to derived objects.
- Inheritance hierarchy - AForm => Concrete forms.
- Virtual destructors - Proper cleanup in inheritance.

## Usage

```bash
make
./execute
```