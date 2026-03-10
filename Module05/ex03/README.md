# Ex03 - Intern

## Overview

Implements the Factory design pattern. The `Intern` class can dynamically
create any of the three concrete forms based on a string name, without
needing to know the specific form type at compile time.

## Description

The Intern class:
- Has a single method `makeForm(formName, target)`.
- Takes a form name (string) and target (string).
- Returns a pointer to the appropriate `AForm` subclass.
- Returns `NULL` if the form name is unknown.

### Supported Forms

The Intern can create:
- **Shrubbery creation** ==> ShrubberyCreationForm.
- **Robotomy request** ==> RobotomyRequestForm.
- **Presidential pardon** ==> PresidentialPardonForm.

## Features

- `makeForm(const std::string& formName, const std::string& target)` ==> Creates form dynamically
- Uses function pointer table for efficient form creation.
- Prints confirmation or error message.
- Memory allocated with `new` (caller must `delete`)

## Implementation

Uses a table of function pointers (Factory pattern)
```cpp
struct FormEntry {
	const char* name;
	AForm* (*create)(const std::string&);
};

static const FormEntry table[] = {
	{"shrubbery creation", createShrubbery},
	{"robotomy request", createRobotomy},
	{"presidential pardon", createPresidential}
};
```

## Exception handling

The Intern itself doesn't throw exceptions. It returns `NULL` for unknown forms.

```cpp
Intern intern;
AForm* form = intern.makeForm("unknown", "target");

if (!form) {
    std::cout << "Form creation failed!" << std::endl;
} else {
    // Process form
    delete form;
}
```

## Memory Management

**Important:** `makeForm()` returns a dynamically allocated pointer.
The caller is responsible for deleting it!

```cpp
AForm* form = intern.makeForm("shrubbery creation", "home");
// ... use form ...
delete form;  //Required!
```

## Key concepts

- Factory pattern - Creates objects without specifying exact class.
- Function pointers - Store and call functions dynamically.
- Dynamic polymorphism - Return base class pointer to derived objects.
- Memory management - Caller owns returned pointer.
- Lookup tables - Efficient string-to-function mapping.

## Usage

```bash
make
./intern
```