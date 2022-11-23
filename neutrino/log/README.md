# Logging

This module provides a simple logging utility that
can be used to output messages.  
The messages has associated `neutrino::log::SeverityLevel` that indicate
their importance and **tags** that indicate their domain.

To log message use one of the `neutrino::log::*` funcitons. This functions
returns a temporary object that behaves like the `std::ostream`.

``` cpp
log::debug("log_tag") << "message_1" << std::endl;
log::info("log_tag") << "message_2" << std::endl;
log::warning("log_tag") << "message_3" << std::endl;
```

By default there is no logger implementation, so no messages would be logged.  
Call the `neutrino::log::set_logger` function to set logger class that would 
be processing messages. Provided logger must be derived from the 
`neutrino::log::Logger` class.

``` cpp
class MyLogger : public neutrino::log::Logger
{
public:
    void add_message(neutrino::log::SeverityLevel level,
                     const std::string& tag,
                     const std::string& message) override
    {
        // implementation
    }
};

neutrino::log::set_logger(std::make_unique<MyLogger>());
```
 
The [Logging](./) module provides an implementation of logger:
`neutrino::log::StreamLogger` that can print messages to any output
stream.

``` cpp
set_logger(std::make_unique<neutrino::log::StreamLogger>(std::cout));
```
