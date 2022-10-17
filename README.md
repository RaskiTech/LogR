# LogR [![License](https://img.shields.io/github/license/RaskiTech/LogR.svg)](https://github.com/RaskiTech/LogR/blob/master/LICENSE)
 
A lightweight single-header logging library for C++. Nothing more, nothing less. Supports formatting. You can have multiple logger instances.

License: MIT License

# Examle

```
main() {
    LogR::Logger logger;
    logger.SetPrefix("[MyLogger]");
    
    logger.Log("This is logging and", 4 - 1, "is a number."); // [MyLogger] This is logging and 3 is a number.

    const char* amount = "many";
    logger.Warning("There are", amount, "warnings."); // [MyLogger] There are many warnings.
    
    logger.Error( LogR::Format("%.2f", 3.14159), "is pi with 2 decimals." ); // [MyLogger] 3.14 is pi with 2 decimals.
}
```

# Extensions

If you have some supported libraries (below) installed, you can log their types by defining following definitions before including the library or at the top of this header file. You can also log your own types by overriding the main function with `template<> inline void LogR::Logger::TypeToString(std::ostream& os, T& type)`, where T is your type. In the function append your text to the ostream. `os << "MyData";` for example. 

Include glm types:
LOGR_INCLUDE_GLM_TYPES
