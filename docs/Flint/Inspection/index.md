---
title: Inspection
description: Base class to implement simplet self-reflexion in C++
generator: doxide
---


# Inspection

**template &lt;typename T&gt; class Inspection**



Base class to implement simplet self-reflexion in C++

:material-code-tags: **Template parameter** `T`
:    Child class itself

!!! tip
    
    When creating a child class, define as follow :
    ```cpp
    class ChildClass: public Inspection<ChildClass>
    ```
    This will extand the ChildClass with the self-reflexion class Inspection

!!! warning
    
    If the class you want to extand as a reflected class will be a parent class
    (I.E. You will create childs of this "target" class), you might want to
    mark inheritence as **virtual**.
    This is needed if your child class _also_ need to be reflected.
    This way, there is no confilict between the parent reflexion, and the child reflexion.
    


## Operators

| Name | Description |
| ---- | ----------- |
| [operator<<](#operator_u003c_u003c) | Overload the operator << to use the str method of the object |

## Functions

| Name | Description |
| ---- | ----------- |
| [getClassName](#getClassName) | Return the name of the reflected class |
| [str](#str) | Return a string representation of the class |

## Operator Details

### operator<<<a name="operator_u003c_u003c"></a>

!!! function "std::ostream&amp; operator&lt;&lt;(std::ostream&amp; os, const Inspection&lt;T&gt;&amp; obj)"

    Overload the operator << to use the str method of the object
    
    :material-code-tags: **Template parameter** `T`
    :    Reflected class
    
    :material-location-enter: **Parameter** `os`
    :    Reference of ostream (I.E. std::cout, std::cerr...)
    
    :material-location-enter: **Parameter** `obj`
    :    Object reference to be displayed
    
    :material-keyboard-return: **Return**
    :    Param os
    
    

## Function Details

### getClassName<a name="getClassName"></a>
!!! function "virtual std::string getClassName() const final"

    
    
    Return the name of the reflected class
    
    :material-keyboard-return: **Return**
    :    The demangled name of the class, or just the name, if demangleing failed
    
    

### str<a name="str"></a>
!!! function "virtual std::string str() const"

    
    
    Return a string representation of the class
    
    !!! tip
        
        This function is not intended to be used.
        This is because this functions display the reflection.
        You might prefer to override this function in yout child
        class to display informations that are more relevant to
        your specific class.
    
    !!! example
        
        You have a Macro available to make the str function really
        easilly :
        ```cpp
        display_attr(attribute)
        ```
        Which will automaticly translate to
        ```cpp
        Flint::Colors::F_BLUE << "attribute" << Flint::Colors::RESET << "=" << Flint::Colors::RED << this->attribute << Flint::Colors::RESET
        ```
        There is also a `make_str` macro, which you can use as follow :
        ```cpp
        return make_str("a=12" << ", " << "b=5");
        ```
        that becomes
        ```cpp
        return ({std::stringstream ss; ss << "<" << this->getClassName() << " at " << std::hex << this << ": " << "a=12" << ", " << "b=5" << ">"; ss.str()})
        ```
        It means you can define the str function of your class as like that :
        ```cpp
        // Provided you have 3 attributes called a, b and c
        return make_str(display_attr(a) << ", " << display_attr(b) << ", " << display_attr(c));
        ```
    
    :material-keyboard-return: **Return**
    :    The string representation of the class
    
    

