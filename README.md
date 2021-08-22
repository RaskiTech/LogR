# LogR [![License](https://img.shields.io/github/license/RaskiTech/LogR.svg)](https://github.com/RaskiTech/LogR/blob/master/LICENSE)
 
A lightweight single-header logging library for C++. Nothing more, nothing less. Supports formatting.

License: MIT License

# Examle

```
main() {
    LogR::Logger logger;
    logger.SetPrefix("[MyLogger]");
    
	engineLogger.Log("This is logging and", 4 - 1, "is a number."); // This is logging and 3 is a number.

	const char* amount = "many";
	engineLogger.Warning("There are", amount, "warnings."); // There are many warnings.
	
	engineLogger.Error( LogR::Format("%.2f", 3.14159), "is pi with 2 decimals." ); // 3.14 is pi with 2 decimals.
}
```
