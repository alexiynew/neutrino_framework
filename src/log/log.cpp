/**
 * @file log.cpp
 * @brief Logger implementation.
 * @author Fedorov Alexey
 * @date 08.03.2017
 */

#include <log/log.hpp>

using framework::logger::logger_implementation;
using framework::logger::log;

std::unique_ptr<logger_implementation> log::m_logger = std::unique_ptr<logger_implementation>();
