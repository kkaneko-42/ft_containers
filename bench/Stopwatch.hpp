#ifndef STOPWATCH_HPP
#define STOPWATCH_HPP
#define GETTIME_ERR_MSG "Stopwatch: gettimeofday failed"

#include <iostream>
#include <exception>
#include <ctime>
#include <sys/time.h>

class Stopwatch
{
    public:
        Stopwatch( void );
        Stopwatch( const Stopwatch& other );
        ~Stopwatch( void );
        
        Stopwatch& operator=( const Stopwatch& other );

        double getElapsedMilliseconds( void );
        bool getIsRunning( void ) const;

        void start( void );
        void reset( void );
        void restart( void );
        // TODO: implement stop()

    private:
        struct timeval start_time_;
        struct timeval stop_time_;
        bool is_running_;
};

#endif
