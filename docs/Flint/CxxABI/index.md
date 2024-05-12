---
title: CxxABI
description: Wrapper around usefull C++/C low level functions
generator: doxide
---


# CxxABI

**class CxxABI**



Wrapper around usefull C++/C low level functions

Got demangle, backtrace...

!!! tip
    
    This class is only made of static functions. It does not contain constructor, nor destructor
    This means that you don't need to instanciate it, and only use it as if it was a namespace.
    


## Functions

| Name | Description |
| ---- | ----------- |
| [demangle](#demangle) | Demangle a C++ name. |
| [getFuncInfos](#getFuncInfos) | Get functions infos from symbol extraction |
| [getBacktrace](#getBacktrace) | Retreive the execution trace |

## Function Details

### demangle<a name="demangle"></a>
!!! function "static std::string demangle(const char&#42; name)"

    
    
    Demangle a C++ name.
    
    This is usefull for : Class names, backtrace...
    
    :material-keyboard-return: **Return**
    :    string containing : demangled name, or original name, if demangle did not work
    
    

### getBacktrace<a name="getBacktrace"></a>
!!! function "static std::vector&lt;std::pair&lt;std::string, std::size_t&gt;&gt; getBacktrace()"

    
    
    Retreive the execution trace
    
    :material-keyboard-return: **Return**
    :    Vector of pair<pair<string, size_t>, string>. I'll explain
    
    The idea is to retrieive the file, line, and function. So that's what we do :
    pair or : (file, line), function
    
    !!! warning
        
        To correctly grab function names, you will need to add compilation flag "-rdynamic"
        See this lib's CMakeLists.txt for implementation.
        This will export ALL symbols.
        If NOT done, you will get offsets from binary. It's ok, but quite disgusting on output.
        
    

### getFuncInfos<a name="getFuncInfos"></a>
!!! function "static std::pair&lt;std::string, std::size_t&gt; getFuncInfos(const char&#42; symbolInfos)"

    
    
    Get functions infos from symbol extraction
    
    :material-keyboard-return: **Return**
    :    A pair with the function names demangled, and the offset from the function
    
    !!! warning
        
        The function name is not EXACTLY the real name of the function.
        Also, the offset DOES NOT correspond to the line number, but the offset of instructions
        
    

