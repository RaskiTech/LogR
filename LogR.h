#include <iostream>
#include <sstream>

#define LogR_RED         "\033[31m"
#define LogR_GREEN       "\033[32m"
#define LogR_YELLOW      "\033[33m"
#define LogR_COLOR_RESET "\033[0m "
#define LogR_WHITE       "\033[37m"

namespace LogR {
	template<typename T>
	struct Format {
		Format(const std::string& format, const T& value) : fmt(format.c_str()), value(value) {}

		//operator<<(std::ostringstream& os, const Format& fmt) {
		//	char buf[40];
		//	snprintf(buf, sizeof(buf), fmt.fmt, fmt.v, 40);
		//	return os << buf;
		//}

		const char* fmt;
		const T value;
	};

	class Logger {
	public:
		Logger() : prefix("[LOG]") {
			system("Color");
		}

		inline void SetPrefix(const char* prefix) {
			this->prefix = prefix;
		}

		template<typename... Args>
		inline void Error(Args&&... args) {
			LogColor(LogR_RED, std::forward<Args>(args)...);
		}
		template<typename... Args>
		inline void Warning(Args&&... args) {
			LogColor(LogR_YELLOW, std::forward<Args>(args)...);
		}
		template<typename... Args>
		inline void Log(Args&&... args) {
			LogColor(LogR_GREEN, std::forward<Args>(args)...);
		}
		template<typename... Args>
		inline void Success(Args&&... args) {
			LogColor(LogR_WHITE, std::forward<Args>(args)...);
		}
	private:
		template<typename... Args>
		void LogColor(const char* color, Args&&... args) {
			std::stringstream stream;
			ParseInput(stream, args...);

			std::cout << color << prefix << LogR_COLOR_RESET << stream.str() << '\n';
		}
	private:
		const char* prefix;

		//// PARSING ////

		template<typename TFirst>
		inline void ParseInput(std::ostream& os, TFirst& first) {
			TypeToString(os, first);
			os << ' ';
		}
		template<typename TFirst, typename... TRest>
		inline void ParseInput(std::ostream& os, TFirst& first, TRest&&... rest) {
			TypeToString(os, first);
			os << ' ';
			ParseInput(os, rest...);
		}


		//// TYPES TO STIRNGS ////

		template<typename T> inline void TypeToString(std::ostream& os, T& type) {
			os << type;
		}

		// Overriding:

		template<typename T>
		inline void TypeToString(std::ostream& os, Format<T>& type) {
			char buf[40];
			snprintf(buf, sizeof(buf), type.fmt, type.value, 40);
			os << buf;
		}

		//#ifdef LOGR_INCLUDE_GLM_LOGGING
		//
		//#endif
	};

}