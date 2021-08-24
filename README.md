# LogR
 
A lightweight single-header logging library for C++. Nothing more, nothing less. Supports formatting.

License: MIT License

# Usage

'''
main() {
    LogR::Logger logger;
    logger.SetPrefix("[MyLogger]");
    
	engineLogger.Log("This is logging and", 4 - 1, "is a number."); // This is logging and 3 is a number.

	const char* amount = "many";
	engineLogger.Warning("There are", amount, "warnings."); // There are many warnings.
	
	engineLogger.Error( LogR::Format("%.2f", 3.14159), "is pi with 2 decimals." ); // 3.14 is pi with 2 decimals.
}
'''

# Extensions

If you have some supported libraries installed, you can log their types by defining following defines before including the library, or you can just define them at the top of the file. You can also log your own types by overriding the 'void Log::TypeToString(std::ostream& os, T& type)' for your type.

Include glm types:
LOGR_INCLUDE_GLM_TYPES